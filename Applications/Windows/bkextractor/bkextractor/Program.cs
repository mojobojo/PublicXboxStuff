using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace bkextractor
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length < 2)
            {
                Console.WriteLine("Usage: <Filename> <out directory>");
                return;
            }

            BkArchive archive = new BkArchive();
            archive.Open(args[0]);
            archive.Extract(args[1]);
            archive.Close();
        }
    }
}
