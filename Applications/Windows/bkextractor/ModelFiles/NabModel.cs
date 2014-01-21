using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ModelFiles
{
    struct PointerTableEntry
    {
        public int ID;
        public int Offset;
    }

    class NabModel
    {
        private int MainPointerTableOffset;
        private int MainPointerTableCount;
        private PointerTableEntry[] PointerTable;

        private FileStream stream;
        private BinaryReader reader;
        private BinaryWriter writer;

        public NabModel()
        {
        }

        public void Open(string fileName)
        {
            stream = new FileStream(fileName, FileMode.Open, FileAccess.ReadWrite, FileShare.ReadWrite);
            reader = new BinaryReader(stream);
            writer = new BinaryWriter(stream);

            MainPointerTableOffset = ReadReversed32();
            MainPointerTableCount = ReadReversed32();

            reader.BaseStream.Position = MainPointerTableOffset;

            PointerTable = new PointerTableEntry[MainPointerTableCount];

            for (int i = 0; i < MainPointerTableCount; i++)
            {
                PointerTable[i].ID = ReadReversed32();
                PointerTable[i].Offset = ReadReversed32();
            }
        }

        public void TestStuff()
        {
            long startOffset = reader.BaseStream.Position;

            StreamWriter streamWriter = new StreamWriter("C:\\TestStuff.txt");

            reader.BaseStream.Position = GetPointFromPointerTableID(0x0A);

            int pointer = ReadReversed32();
            int dataSize = ReadReversed32();

            streamWriter.WriteLine("Pointer   " + pointer.ToString("X8"));
            streamWriter.WriteLine("Data Size " + dataSize.ToString("X8"));

            reader.BaseStream.Position = pointer;

            for (int i = 0; i < dataSize; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    int countMaybe = ReadReversed32();
                    int pointerL2 = ReadReversed32();
                    streamWriter.WriteLine("    Count?  " + countMaybe.ToString("X8"));
                    streamWriter.WriteLine("    Pointer " + pointerL2.ToString("X8"));

                    long savedPointer = reader.BaseStream.Position;

                    reader.BaseStream.Position = pointerL2;
                    int anotherPointer = ReadReversed32();
                    streamWriter.WriteLine("        Pointer " + anotherPointer.ToString("X8"));

                    reader.BaseStream.Position = savedPointer;
                }
            }

            streamWriter.Flush();
            streamWriter.Close();

            reader.BaseStream.Position = startOffset;
        }

        public void DumpDataSections(string dir)
        {
            long startOffset = reader.BaseStream.Position;

            StreamWriter streamWriter = new StreamWriter(dir + "\\PointerTable.txt");

            for (int i = 0; i < MainPointerTableCount; i++)
            {
                streamWriter.WriteLine("PointerTable[i].ID     = " + PointerTable[i].ID.ToString("X8"));
                streamWriter.WriteLine("PointerTable[i].Offset = " + PointerTable[i].Offset.ToString("X8"));
                streamWriter.WriteLine();
            }

            streamWriter.Flush();
            streamWriter.Close();

            for (int i = 0; i < MainPointerTableCount - 1; i++)
            {
                string name = PointerTable[i].ID.ToString("X8") + "_" + PointerTable[i].Offset.ToString("X8") + ".bin";

                int size = PointerTable[i + 1].Offset - PointerTable[i].Offset;

                reader.BaseStream.Position = PointerTable[i].Offset;
                File.WriteAllBytes(dir + "\\" + name, reader.ReadBytes(size));
            }

            reader.BaseStream.Position = PointerTable[MainPointerTableCount - 1].Offset;
            File.WriteAllBytes(
                dir + "\\" + 
                PointerTable[MainPointerTableCount - 1].ID.ToString("X8") + "_" + 
                PointerTable[MainPointerTableCount - 1].Offset.ToString("X8") + ".bin", 
                reader.ReadBytes((int)reader.BaseStream.Length - PointerTable[MainPointerTableCount - 1].Offset));

            reader.BaseStream.Position = startOffset;
        }

        private int GetPointFromPointerTableID(int id)
        {
            for (int i = 0; i < PointerTable.Length; i++)
            {
                if (PointerTable[i].ID == id)
                {
                    return PointerTable[i].Offset;
                }
            }

            throw new Exception("Could not find pointer from id");
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
