using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace caffextractor
{

    struct FileInfo
    {
        public int ID;
        public int DataOffset;
        public int DataSize;
        public byte Section;
        public byte Unknown0xD;
    }

    struct SectionInfo
    {
        public string Name;
        public int Unknown0x01;
        public int Unknown0x05;
        public int DataLength;
        public int DataLength2;
    }

    class CAFFReader
    {
        private static int SECTION_SIZE = 0x21;

        private char[] Version;
        private int SizeofHeader;
        private int HeaderChecksum;
        private int NumberOfSymbols;
        private int NumberOfFileParts;
        // 8 byte padding
        private int Unknown0x2C;
        private int Unknown0x30;
        // 0x10 byte padding
        private int Unknown0x44;
        private byte Type;
        private byte NumberOfSections;
        private byte Unknown0x4A;
        private byte Unknown0x4B;
        private int Unknown0x4C;
        private int InfoSectionSize;
        // 0xC byte padding
        private int InfoSectionSize2;
        private int UnknownDataSize;
        // 0xC byte padding
        private int UnknownDataSize2;
        private SectionInfo[] Sections;
        private List<string> SectionNames = new List<string>();
        private int SymbolsBufferSize;
        private int[] SymbolsOffsets;
        private int SymbolsStart;
        private string[] Symbols;
        private int UnknownNameSize;
        private char[] UnknownName;
        private FileInfo[] FileInfos;
        private byte[] UnknownData;

        private int DataStart;

        private FileStream stream;
        private BinaryReader reader;
        private BinaryWriter writer;

        public CAFFReader()
        {
        }

        public bool Open(string fileName)
        {
            stream = new FileStream(fileName, FileMode.Open, FileAccess.ReadWrite, FileShare.ReadWrite);
            reader = new BinaryReader(stream);
            writer = new BinaryWriter(stream);

            // make sure it is a CAFF file
            if (ReadReversed32() != 0x43414646)
            {
                reader.Dispose();
                return false;
            }

            Version = reader.ReadChars(0x10);
            SizeofHeader = ReadReversed32();
            HeaderChecksum = ReadReversed32();
            NumberOfSymbols = ReadReversed32();
            NumberOfFileParts = ReadReversed32();

            reader.BaseStream.Position += 8;
            Unknown0x2C = ReadReversed32();
            Unknown0x30 = ReadReversed32();

            reader.BaseStream.Position += 0x10;
            Unknown0x44 = ReadReversed32();
            
            Type = reader.ReadByte();
            NumberOfSections = reader.ReadByte();
            Unknown0x4A = reader.ReadByte();
            Unknown0x4B = reader.ReadByte();
            Unknown0x4C = ReadReversed32();

            reader.BaseStream.Position = 0x50;
            InfoSectionSize = ReadReversed32();

            reader.BaseStream.Position = 0x60;
            InfoSectionSize2 = ReadReversed32();
            UnknownDataSize = ReadReversed32();

            reader.BaseStream.Position = 0x74;
            UnknownDataSize2 = ReadReversed32();

            Sections = new SectionInfo[NumberOfSections];

            for (int i = 0; i < NumberOfSections; i++)
            {
                reader.BaseStream.Position = SizeofHeader + (i * SECTION_SIZE);

                reader.BaseStream.Position++;
                Sections[i].Unknown0x01 = ReadReversed32();
                Sections[i].Unknown0x05 = ReadReversed32();
                Sections[i].DataLength = ReadReversed32();

                reader.BaseStream.Position += 0x10;
                Sections[i].DataLength2 = ReadReversed32();
            }

            for (int i = 0; i < NumberOfSections; i++)
            {
                Sections[i].Name = ReadNullTerminatedString();
            }

            SymbolsBufferSize = ReadReversed32();

            SymbolsOffsets = new int[NumberOfSymbols];
            for (int i = 0; i < NumberOfSymbols; i++)
            {
                SymbolsOffsets[i] = ReadReversed32();
            }

            SymbolsStart = (int)reader.BaseStream.Position;

            Symbols = new string[NumberOfSymbols];
            for (int i = 0; i < NumberOfSymbols; i++)
            {
                reader.BaseStream.Position = SymbolsStart + SymbolsOffsets[i];
                Symbols[i] = ReadNullTerminatedString();
            }

            UnknownNameSize = ReadReversed32();
            UnknownName = reader.ReadChars(UnknownNameSize);

            FileInfos = new FileInfo[NumberOfFileParts];

            for (int i = 0; i < NumberOfFileParts; i++)
            {
                FileInfos[i].ID = ReadReversed32();
                FileInfos[i].DataOffset = ReadReversed32();
                FileInfos[i].DataSize = ReadReversed32();
                FileInfos[i].Section = reader.ReadByte();
                FileInfos[i].Unknown0xD = reader.ReadByte();
            }

            // I am unsure this is right, it seemed to be 4 byte padded?
            int padding = ((int)reader.BaseStream.Position % 4);

            if (padding != 0)
            {
                reader.BaseStream.Position += 4 - padding;
            }

            UnknownData = reader.ReadBytes(UnknownDataSize);

            DataStart = (int)reader.BaseStream.Position;

            return true;
        }

        public void DumpFileInfos(string fileName)
        {
            StreamWriter streamWriter = new StreamWriter(fileName);

            for (int i = 0; i < NumberOfFileParts; i++)
            {
                streamWriter.WriteLine("FileInfos[" + i + "].ID         " + FileInfos[i].ID.ToString("X8"));
                streamWriter.WriteLine("FileInfos[" + i + "].DataOffset " + FileInfos[i].DataOffset.ToString("X8"));
                streamWriter.WriteLine("FileInfos[" + i + "].DataSize   " + FileInfos[i].DataSize.ToString("X8"));
                streamWriter.WriteLine("FileInfos[" + i + "].Section    " + FileInfos[i].Section.ToString("X8"));
                streamWriter.WriteLine("FileInfos[" + i + "].Unknown0xD " + FileInfos[i].Unknown0xD.ToString("X8"));
                streamWriter.WriteLine();
            }

            streamWriter.Flush();
            streamWriter.Close();
        }

        public void DumpSymbols(string fileName)
        {
            StreamWriter streamWriter = new StreamWriter(fileName);

            for (int i = 0; i < NumberOfSymbols; i++)
            {
                streamWriter.WriteLine(i.ToString() + " " + Symbols[i]);
                //writer.WriteLine();
            }

            streamWriter.Flush();
            streamWriter.Close();
        }

        public void ExtractSections(string folder)
        {
            Directory.CreateDirectory(folder + "\\RawSectionDumps");
            folder += "\\RawSectionDumps";

            File.WriteAllBytes(folder + "\\unknownData.bin", UnknownData);

            reader.BaseStream.Position = DataStart;

            for (int i = 0; i < NumberOfSections; i++)
            {
                File.WriteAllBytes(folder + "\\" + Sections[i].Name, reader.ReadBytes(Sections[i].DataLength));
            }
        }

        public void ExtractFilesOld(string folder)
        {
            reader.BaseStream.Position = DataStart;

            for (int i = 0; i < NumberOfFileParts; i++)
            {
                reader.BaseStream.Position = DataStart + GetSectionOffset(FileInfos[i].Section) + FileInfos[i].DataOffset;
                File.WriteAllBytes(
                    folder + "\\" + 
                    FileInfos[i].ID.ToString("X8") + "_" + 
                    FileInfos[i].DataOffset.ToString("X8") + "_" + 
                    FileInfos[i].DataSize.ToString("X8") + "_" + 
                    FileInfos[i].Section.ToString("X8") + "_" + 
                    FileInfos[i].Unknown0xD.ToString("X8") + ".bin"
                , reader.ReadBytes(FileInfos[i].DataSize));
            }
        }

        public void ExtractFiles(string folder)
        {
            reader.BaseStream.Position = DataStart;

            for (int i = 0; i < NumberOfFileParts; i++)
            {
                reader.BaseStream.Position = DataStart + GetSectionOffset(FileInfos[i].Section) + FileInfos[i].DataOffset;

                string fileDest = GetSymbolDestFromIndex(FileInfos[i].ID, folder);
                Console.WriteLine(fileDest);

                Directory.CreateDirectory(Path.GetDirectoryName(fileDest));

                FileStream stream = new FileStream(fileDest, FileMode.Append, FileAccess.Write, FileShare.Write);
                BinaryWriter binaryWriter = new BinaryWriter(stream);

                binaryWriter.Write(reader.ReadBytes(FileInfos[i].DataSize));

                binaryWriter.Flush();
                binaryWriter.Close();
            }
        }

        public void InjectFile(string fileName, int symbolIndex)
        {
            Console.WriteLine("Injecting to " + Symbols[symbolIndex]);

            reader.BaseStream.Position = DataStart;

            long dataFileOffset = 0;

            for (int i = 0; i < NumberOfFileParts; i++)
            {
                reader.BaseStream.Position = DataStart + GetSectionOffset(FileInfos[i].Section) + FileInfos[i].DataOffset;

                if (FileInfos[i].ID == (symbolIndex + 1))
                {
                    BinaryReader br = new BinaryReader(new FileStream(fileName, FileMode.Open, FileAccess.Read, FileShare.Read));
                    br.BaseStream.Position = dataFileOffset;
                    byte[] data = br.ReadBytes(FileInfos[i].DataSize);
                    Console.WriteLine("Writing block of data size " + data.Length + " to offset " + writer.BaseStream.Position.ToString("X8"));
                    writer.Write(data);
                    dataFileOffset = br.BaseStream.Position;
                    br.Close();
                    writer.Flush();
                }
            }
        }

        public void Pack(string outFile, string folder)
        {
            //BinaryWriter binaryWriter = new BinaryWriter(new FileStream(outFile, FileMode.Create, FileAccess.Write, FileShare.Write));

            //WriteReversed32(0x43414646, writer);
            //writer.Write(Encoding.ASCII.GetBytes("07.08.06.0036\x00\x00\x00"));
            //WriteReversed32(0x78, writer);
            //WriteReversed32(0, writer); // checksum - do this later
            //WriteReversed32(NumberOfSymbols, writer);
            //WriteReversed32(0, writer); // number of file parts - do this later

            //writer.BaseStream.Position += 8;

            //WriteReversed32(Unknown0x2C, writer);
            //WriteReversed32(Unknown0x30, writer);

            //writer.BaseStream.Position = 0x44;

            //WriteReversed32(Unknown0x44, writer);
            //writer.Write((byte)Type);
            //writer.Write((byte)NumberOfSections);
            //writer.Write((byte)Unknown0x4A);
            //writer.Write((byte)Unknown0x4B);
            //WriteReversed32(Unknown0x4C, writer);

            //writer.BaseStream.Position = 0x50;
            //WriteReversed32(InfoSectionSize, writer);

            //writer.BaseStream.Position = 0x60;
            //WriteReversed32(InfoSectionSize2, writer);
            //WriteReversed32(UnknownDataSize, writer);

            //writer.BaseStream.Position = 0x74;
            //WriteReversed32(UnknownDataSize2, writer);

            //for (int i = 0; i < NumberOfSections; i++)
            //{
            //    writer.BaseStream.Position = SizeofHeader + (i * SECTION_SIZE);
            //    writer.BaseStream.Position++;

            //    WriteReversed32(Sections[i].Unknown0x01, writer);

            //    WriteReversed32(Sections[i].Unknown0x05, writer);
            //    WriteReversed32(Sections[i].DataLength, writer);

            //    writer.BaseStream.Position += 0x10;
            //    WriteReversed32(Sections[i].DataLength2, writer);
            //}

            //for (int i = 0; i < NumberOfSections; i++)
            //{
            //    writer.Write(Encoding.ASCII.GetBytes(Sections[i].Name + "\x00"));
            //}

            //WriteReversed32(SymbolsBufferSize, writer);

            //for (int i = 0; i < NumberOfSymbols; i++)
            //{
            //    WriteReversed32(SymbolsOffsets[i], writer);
            //}

            //long symStart = writer.BaseStream.Position;

            //for (int i = 0; i < NumberOfSymbols; i++)
            //{
            //    writer.BaseStream.Position = symStart + SymbolsOffsets[i];
            //    writer.Write(Encoding.ASCII.GetBytes(Symbols[i] + "\x00"));
            //}
        }

        public uint Checksum32(byte[] data, int length)
        {
            uint r11 = 0;

            for (int i = 0; i < length; i++)
            {
                uint r8 = data[i];
                uint r10 = r11 << 4;

                if ((r8 & 0x80) > 0)
                {
                    r11 = 0xFFFFFF80 | r8;
                }
                else
                {
                    r11 = r8;
                }

                r11 = r11 + r10;
                r10 = r11 & 0xF0000000;

                if (r10 != 0)
                {
                    r8 = r10 >> 24;
                    r10 = r8 | r10;
                    r11 = r10 ^ r11;
                }
            }

            return r11;
        }

        public void Close()
        {
            writer.Flush();
            stream.Close();
            stream.Dispose();
            writer.Dispose();
            reader.Dispose();
        }

        private string GetSymbolDestFromIndex(int index, string destFolder)
        {
            string path = Symbols[index - 1];
            path = path.Replace("D:\\", "");
            path = destFolder + "\\" + path;
            return path;
        }

        private int GetSectionOffset(int section)
        {
            int ret = 0;
            for (int i = 0; i < section - 1; i++)
            {
                ret += Sections[i].DataLength;
            }
            return ret;
        }

        private int BitswapInt(int i)
        {
            byte[] data = BitConverter.GetBytes(i);
            Array.Reverse(data);
            return BitConverter.ToInt32(data, 0);
        }

        private int ReadReversed32()
        {
            return BitswapInt(reader.ReadInt32());
        }

        private void WriteReversed32(int i, BinaryWriter binaryWriter)
        {
            binaryWriter.Write(BitswapInt(i));
        }

        private string ReadNullTerminatedString()
        {
            string str = "";

            char c = '\x00';
            while ((c = reader.ReadChar()) != '\x00')
            {
                str += c;
            }

            return str;
        }
    }
}
