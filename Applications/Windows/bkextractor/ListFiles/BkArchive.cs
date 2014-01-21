using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace bkextractor
{
    struct BkArchiveEntry
    {
        public int Unknown;
        public int Offset;
        public int Size;
    }

    class BkArchive
    {
        private int Unknown1;
        private int NumFilesInTable;
        private int Checksum;
        private int ChecksumTableSize;
        private int[] Checksums;
        private BkArchiveEntry[] Entrys;

        private BinaryReader reader;

        public BkArchive()
        {
        }

        public void Open(string fileName)
        {
            reader = new BinaryReader(new FileStream(fileName, FileMode.Open, FileAccess.Read, FileShare.Read));

            if (ReadReversed(reader) != 0x438CB47C)
            {
                Console.WriteLine("Invalid file");
                reader.Close();
                reader.Dispose();
            }

            Unknown1 = ReadReversed(reader);
            NumFilesInTable = ReadReversed(reader);
            Checksum = ReadReversed(reader);
            ChecksumTableSize = ReadReversed(reader);

            Checksums = new int[ChecksumTableSize];

            for (int i = 0; i < ChecksumTableSize; i++)
            {
                Checksums[i] = ReadReversed(reader);
            }

            Entrys = new BkArchiveEntry[NumFilesInTable];

            for (int i = 0; i < NumFilesInTable; i++)
            {
                Entrys[i].Unknown = ReadReversed(reader);
                Entrys[i].Offset = ReadReversed(reader);
                Entrys[i].Size = ReadReversed(reader);
            }
        }
 
        public void Extract(string dest)
        {
            if (!Directory.Exists(dest))
            {
                Directory.CreateDirectory(dest);
            }

            for (int i = 0; i < NumFilesInTable; i++)
            {
                reader.BaseStream.Position = Entrys[i].Offset;

                string outFile = dest + "\\" + Entrys[i].Offset.ToString("X2") + ".bin";
                Console.WriteLine(outFile);
                File.WriteAllBytes(outFile, reader.ReadBytes(Entrys[i].Size));
            }
        }

        public void Close()
        {
            reader.Close();
            reader.Dispose();
        }

        private int BitswapInt(int i)
        {
            byte[] data = BitConverter.GetBytes(i);
            Array.Reverse(data);
            return BitConverter.ToInt32(data, 0);
        }

        private int ReadReversed(BinaryReader br)
        {
            return BitswapInt(br.ReadInt32());
        }
    }
}
