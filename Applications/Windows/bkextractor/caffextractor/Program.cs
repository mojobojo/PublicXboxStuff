using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace caffextractor
{
    class Program
    {
        static void Extract(string FileName, string Dest)
        {
            CAFFReader CaffReader = new CAFFReader();
            CaffReader.Open(FileName);
            CaffReader.ExtractSections(Dest);
            CaffReader.DumpFileInfos(Dest + "\\fileInfos.txt");
            CaffReader.ExtractFiles(Dest);
            CaffReader.Close();
        }

        static void Main(string[] args)
        {
            if (args.Length < 3)
            {
                Console.WriteLine("Commands: ");
                Console.WriteLine("          s - Dump Sections");
                Console.WriteLine("          a - Dump Files");
                Console.WriteLine("Usage: <command> <Filename> <out directory>");
                return; 
            }

            switch (args[0])
            {
                case "s":
                    {
                        CAFFReader CaffReader = new CAFFReader();
                        CaffReader.Open(args[1]);
                        CaffReader.ExtractSections(args[2]);
                        CaffReader.DumpFileInfos(args[2] + "\\fileInfos.txt");
                        CaffReader.Close();
                        break;
                    }
                case "a":
                    {
                        CAFFReader CaffReader = new CAFFReader();
                        CaffReader.Open(args[1]);
                        CaffReader.ExtractFiles(args[2]);
                        CaffReader.DumpSymbols(args[2] + "\\symbols.txt");
                        CaffReader.Close();
                        break;
                    }
                case "r":
                    {
                        //CAFFReader CaffReader = new CAFFReader();
                        //CaffReader.Open(args[1]);
                        //CaffReader.Pack(args[3], args[2]);
                        //CaffReader.Close();
                        break;
                    }
                case "i":
                    {
                        CAFFReader CaffReader = new CAFFReader();
                        CaffReader.Open(args[1]);
                        CaffReader.InjectFile(args[2], Convert.ToInt32(args[3]));
                        CaffReader.Close();
                        break;
                    }
                default:
                    break;
            }
        }
    }
}
