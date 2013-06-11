using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace DOOM_XBLA_Asset_Extractor
{
    class Program
    {
        static void Main(string[] args)
        {
            #region info
            if (args[0] == "info")
            {
                Console.WriteLine("How to Use: Make sure you put the doom.disk in the application path.\n");
                Console.WriteLine("To unpack the files use (DISKUnpacker.exe unpack doom.disk)\n");
                Console.WriteLine("To view the list of files and thier index in the file table (DISKUnpacker.exe list doom.disk)\n");
                Console.WriteLine("Application and research by Mojobojo.\n");
            }
            #endregion

            #region list
            if (args[0] == "list")
            {
                try
                {
                    Directory.CreateDirectory(Path.GetDirectoryName(args[1]) + "\\DOOMassets\\");
                    BinaryReader br = new BinaryReader(new FileStream(args[1], FileMode.Open));
                    

                    string fName;
                    int fOffset = 0;
                    int fsize = 0;
                    int fTable = hexStringToInt(bytesToHex(br.ReadBytes(4)));

                    Console.WriteLine(fTable.ToString() + " Files in table.");

                    for (int i = 0; i < fTable; i++)
                    {
                        char chr;
                        string x = "";

                        br.BaseStream.Position = 0x4 + (i * 0x48);
                        while ((chr = br.ReadChar()) != '\0')
                        {
                            x += chr;
                        }
                        fName = x;
                        br.BaseStream.Position = 0x44 + (i * 0x48);
                        fOffset = 0x3F98 + hexStringToInt(bytesToHex(br.ReadBytes(4)));
                        fsize = hexStringToInt(bytesToHex(br.ReadBytes(4)));
                        Console.WriteLine("Index: " + i.ToString() + " " + fName);
                        //Console.WriteLine("Index: " + i.ToString());
                        //Console.WriteLine("File Offset: " + "0x" + (fOffset).ToString("X2"));
                        //Console.WriteLine("File Size: " + fsize + " Bytes");
                    }
                    br.Close();
                }
                catch (Exception x)
                {
                    Console.WriteLine(x.Message);
                }
            }
            #endregion

            #region unpack
            if (args[0] == "unpack")
            {
                try
                {
                    
                    BinaryReader br = new BinaryReader(new FileStream(args[1], FileMode.Open));
                    StreamWriter sw = new StreamWriter("C:\\files.txt");

                    string fName;
                    string fPath;
                    int fOffset = 0;
                    int fsize = 0;
                    int fTable = hexStringToInt(bytesToHex(br.ReadBytes(4)));
                    int startPosition = fTable * 0x48 + 8;

                    Console.WriteLine(fTable.ToString() + " Entries. Files start at 0x" + (startPosition + 8).ToString("X2"));

                    for (int i = 0; i < fTable; i++)
                    {
                        char chr;
                        string x = "";
                        br.BaseStream.Position = 0x4 + (i * 0x48);
                        while ((chr = br.ReadChar()) != '\0')
                        {
                            x += chr;
                        }
                        
                        fName = x;
                        
                        sw.WriteLine(fName);

                        fPath = "C:" + fName.Substring(5);

                        string str = Path.GetDirectoryName(fPath);
                        
                        Directory.CreateDirectory(str);

                        fName = Path.GetFileName(fName);

                        Console.WriteLine(fPath);

                        

                        br.BaseStream.Position = 0x44 + (i * 0x48);
                        fOffset = hexStringToInt(bytesToHex(br.ReadBytes(4)));
                        fsize = hexStringToInt(bytesToHex(br.ReadBytes(4)));

                        br.BaseStream.Position = startPosition + fOffset;
                        byte[] file = br.ReadBytes(fsize);

                        File.WriteAllBytes(fPath, file);
                    }
                    sw.Flush();
                    sw.Close();
                    br.Close();
                    Console.WriteLine("Completed all 226 items!");
                    
                }
                catch (Exception x)
                {
                    Console.WriteLine("Error while extracting!");
                    Console.WriteLine(x.Message);
                }
            }
            #endregion

            #region pack
            if (args[0] == "pack")
            {

            }
            #endregion
        }
        public static int hexStringToInt(string str)
        {
            return int.Parse(str, System.Globalization.NumberStyles.HexNumber);
        }
        public static string bytesToHex(byte[] data)
        {
            string str = "";

            for (int i = 0; i < data.Length; i++)
                str += data[i].ToString("X2");

            return str;
        }
    }
}
