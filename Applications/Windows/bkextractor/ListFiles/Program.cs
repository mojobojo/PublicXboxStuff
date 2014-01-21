using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ListFiles
{
    class Program
    {
        static int BitswapInt(int i)
        {
            byte[] data = BitConverter.GetBytes(i);
            Array.Reverse(data);
            return BitConverter.ToInt32(data, 0);
        }

        static int ReadReversed(BinaryReader br)
        {
            return BitswapInt(br.ReadInt32());
        }

        static void RecursiveFile(ref List<string> str, string dir)
        {
            foreach (string s in Directory.GetFiles(dir))
            {
                str.Add(s);
            }
            foreach (string s in Directory.GetDirectories(dir))
            {
                RecursiveFile(ref str, s);
            }
        }

        static void ExtractAllCaffFiles(string dir, string dest)
        {
            List<string> strings = new List<string>();
            RecursiveFile(ref strings, dir);

            foreach (string s in strings)
            {
                BinaryReader reader = new BinaryReader(new FileStream(s, FileMode.Open, FileAccess.Read, FileShare.Read));

                byte[] buf = reader.ReadBytes(4);
                string begin = Encoding.ASCII.GetString(buf);

                reader.Close();
                reader.Dispose();

                if (begin == "CAFF")
                {
                    bool directoryExsists = true;
                    int directoryNum = 0;
                    string outPut = "";

                    while (directoryExsists)
                    {
                        string name = Path.GetFileName(s);
                        outPut = dest + "\\" + name + "_data_" + directoryNum.ToString();

                        if (!Directory.Exists(outPut))
                        {
                            Directory.CreateDirectory(outPut);
                            directoryExsists = false;
                        }

                        directoryNum++;
                    }

                    caffextractor.CAFFReader caffReader = new caffextractor.CAFFReader();
                    caffReader.Open(s);
                    caffReader.ExtractFiles(outPut);
                    caffReader.Close();
                }
            }
        }

        static void ExtractAllArchiveFiles(string dir, string dest)
        {
            List<string> strings = new List<string>();
            RecursiveFile(ref strings, dir);

            foreach (string s in strings)
            {
                BinaryReader reader = new BinaryReader(new FileStream(s, FileMode.Open, FileAccess.Read, FileShare.Read));

                int magic = ReadReversed(reader);

                reader.Close();
                reader.Dispose();

                if (magic == 0x438CB47C)
                {
                    string name = Path.GetFileName(s);
                    string outPut = dest + "\\" + name + "_data";
                    Directory.CreateDirectory(outPut);

                    bkextractor.BkArchive bkArchive = new bkextractor.BkArchive();
                    bkArchive.Open(s);
                    bkArchive.Extract(outPut);
                    bkArchive.Close();
                }
            }
        }

        static void Main(string[] args)
        {
            ExtractAllCaffFiles(@"C:\BkExtracted", @"C:\BkExtractedMassive");
            ExtractAllCaffFiles(@"C:\Users\mojobojo\Desktop\Banjo Kazooie NB", @"C:\BkExtractedMassive");
        }
    }
}
