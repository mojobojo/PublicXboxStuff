using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace UnrealConfigTool
{
    class Program
    {
        enum DataModes
        {
            Null,
            Ascii,
            Unicode
        }

        enum ProcessModes
        {
            Null,
            Unpack,
            Pack
        }

        static int GetBeInt(BinaryReader br)
        {
            int tmp = br.ReadInt32();
            return 
                (int)((tmp & 0x000000FF) << 24)|
                (int)((tmp & 0x0000FF00) << 8) |
                (int)((tmp & 0x00FF0000) >> 8) |
                (int)((tmp & 0xFF000000) >> 24)
                ;
        }

        static int GetInvertedBeInt(BinaryReader br)
        {
            return ~GetBeInt(br);
        }

        static void PutBeInt(BinaryWriter bw, int i)
        {
            int p = 
                (int)((i & 0x000000FF) << 24)|
                (int)((i & 0x0000FF00) << 8) |
                (int)((i & 0x00FF0000) >> 8) |
                (int)((i & 0xFF000000) >> 24)
                ;

            bw.Write((int)p);
        }

        static void PutInvertedBeInt(BinaryWriter bw, int i)
        {
            PutBeInt(bw, ~i);
        }

        static void UnpackUnicode(string FileName, string OutDir)
        {
            BinaryReader reader = new BinaryReader(new FileStream(FileName, FileMode.Open, FileAccess.Read, FileShare.Read));

            if (!reader.BaseStream.CanRead)
            {
                Console.WriteLine("Unable to open file " + FileName);
                return;
            }

            Directory.CreateDirectory(OutDir);

            StreamWriter TocWriter = new StreamWriter(OutDir + "\\TOC.txt");

            if (!TocWriter.BaseStream.CanWrite)
            {
                Console.WriteLine("Unable to create table of contents file");
                return;
            }

            int FilesCount = GetBeInt(reader);

            // Loop for each file
            for (int i = 0; i < FilesCount; i++)
            {
                int IniFileNameSize = GetInvertedBeInt(reader);
                string IniFileName = UnicodeEncoding.Unicode.GetString(reader.ReadBytes(IniFileNameSize * 2));
                reader.BaseStream.Position += 2;

                TocWriter.WriteLine(IniFileName);
                TocWriter.Flush();

                string OutFileName = OutDir + "\\" + IniFileName.Replace("..\\", "");
                
                Directory.CreateDirectory(Path.GetDirectoryName(OutFileName));
                StreamWriter writer = new StreamWriter(OutFileName);

                if (!writer.BaseStream.CanWrite)
                {
                    Console.WriteLine("Unable to create File " + OutFileName);
                    return;
                }

                int NumOfSections = GetBeInt(reader);

                // loop for each section in the file
                for (int x = 0; x < NumOfSections; x++)
                {
                    int SectionNameSize = GetInvertedBeInt(reader);
                    string SectionName = UnicodeEncoding.Unicode.GetString(reader.ReadBytes(SectionNameSize * 2));

                    writer.WriteLine(string.Format("[{0}]", SectionName));
                    writer.Flush();

                    reader.BaseStream.Position += 2;

                    int SettingCount = GetBeInt(reader);

                    // loop for each setting in the section
                    for (int y = 0; y < SettingCount; y++)
                    {
                        int KeySize = GetInvertedBeInt(reader);
                        string Key = UnicodeEncoding.Unicode.GetString(reader.ReadBytes(KeySize * 2));
                        reader.BaseStream.Position += 2;

                        int ValueNameSize = GetInvertedBeInt(reader);

                        string Value = "";
                        if (ValueNameSize != -1)
                        {
                            Value = UnicodeEncoding.Unicode.GetString(reader.ReadBytes(ValueNameSize * 2));
                            reader.BaseStream.Position += 2;

                            string ValNew = "";
                            for (int e = 0; e < Value.Length; e++)
                            {
								// This is a workaround for the setting values that contain line endings.
                                char c = Value[e];
                                if (c == '\r')
                                {
                                    ValNew += "\\x0D";
                                }
                                else if (c == '\n')
                                {
                                    ValNew += "\\x0A";
                                }
                                else
                                {
                                    ValNew += c.ToString();
                                    
                                }
                            }

                            writer.WriteLine(string.Format("{0}={1}", Key, ValNew));
                        }
                        else
                            writer.WriteLine(string.Format("{0}=", Key));
                            
                        writer.Flush();
                    }
                }
            }

            TocWriter.Close();
            reader.Close();
        }

        static void UnpackAscii(string FileName, string OutDir)
        {
        }

        static void PackUnicdoe(string FileName, string InDir)
        {
            BinaryWriter writer = new BinaryWriter(new FileStream(FileName, FileMode.Create, FileAccess.Write, FileShare.Write));

            if (!writer.BaseStream.CanWrite)
            {
                Console.WriteLine("Unable to create file " + FileName);
                return;
            }

            StreamReader TocReader = new StreamReader(InDir + "\\TOC.txt");

            if (!TocReader.BaseStream.CanRead)
            {
                Console.WriteLine("Unable to open the Table of Contents file");
                return;
            }

            List<string> FilesList = new List<string>();
            while (!TocReader.EndOfStream)
            {
                string line = TocReader.ReadLine();

                if (line == "")
                    break;

                FilesList.Add(line);
            }

            PutBeInt(writer, FilesList.Count);

            foreach (string str in FilesList)
            {
                PutInvertedBeInt(writer, str.Length);
                writer.Write(Encoding.Unicode.GetBytes(str));
                writer.Write((short)0);

                string InFileName = InDir + "\\" + str.Replace("..\\", "");
                StreamReader IniReader = new StreamReader(InFileName);

                if (!IniReader.BaseStream.CanRead)
                {
                    Console.WriteLine("Unable to open file " + InFileName);
                    return;
                }

                List<string> IniData = new List<string>();

                while (!IniReader.EndOfStream)
                    IniData.Add(IniReader.ReadLine());

                //Count the number of sections, kinda ghetto, but works
                int SectionsCount = 0;
                foreach (string s in IniData)
                {
                    if (s == "")
                        continue;

                    if (s.StartsWith("["))
                        SectionsCount++;
                }

                PutBeInt(writer, SectionsCount);

                for (int i = 0; i < IniData.Count; i++)
                {
                    string data = IniData[i];

                    if (data == "")
                        continue;

                    if (data.StartsWith("["))
                    {
                        string SectionName = data.Substring(data.IndexOf('[') + 1, data.IndexOf(']') - 1);
                        int SectionNameLength = SectionName.Length;
                        PutInvertedBeInt(writer, SectionNameLength);
                        writer.Write(Encoding.Unicode.GetBytes(SectionName));
                        writer.Write((short)0);

                        int SecStart = i + 1;

                        string s = "";
                        List<string> Settings = new List<string>();
                        while (true)
                        {
                            if (SecStart >= IniData.Count)
                                break;

                            s = IniData[SecStart];

                            if (s.StartsWith("["))
                                break;

                            SecStart++;
                            if (s == "")
                                continue;

                            Settings.Add(s);
                        }

                        PutBeInt(writer, (int)Settings.Count);

                        foreach (string set in Settings)
                        {
                            string key = set.Substring(0, set.IndexOf('='));
                            string value = set.Substring(set.IndexOf('=') + 1).Replace("\\x0A", "\n").Replace("\\x0D", "\r");

                            PutInvertedBeInt(writer, key.Length);
                            writer.Write(Encoding.Unicode.GetBytes(key));
                            writer.Write((short)0);

                            if (value.Length != 0)
                            {
                                PutInvertedBeInt(writer, value.Length);
                                writer.Write(Encoding.Unicode.GetBytes(value));
                                writer.Write((short)0);
                            }
                            else
                            {
                                PutBeInt(writer, 0);
                            }
                        }
                    }
                }
            }
        }

        static void PackAscii(string FileName, string OutDir)
        {
        }

        static void Main(string[] args)
        {
            if (args.Length < 4)
            {
                Console.WriteLine(
                    "Unreal Config Tool (C) Mojobojo 2011\n" +
		         	"Usage:\n\n" +
		           	"Unpack  /u\n" +
			        "Pack    /p\n" +
			        "Unicode /n\n" +
			        "Ascii   /a\n\n" +
			        "UnrealConfigTool <options> <in/out file> <in/out dir>\n"
                    );

                return;
            }

            ProcessModes ProcessMode = ProcessModes.Null;
            DataModes DataMode = DataModes.Null;
            string InOutFileName;
            string InOutDir;

            int i = 0;
            for ( ; i < args.Length; i++)
            {
                if (args[i][0] == '/')
                {
                    switch (args[i][1])
                    {
                        case 'u':
                        case 'U':
                            ProcessMode = ProcessModes.Unpack;
                            break;
                        case 'p':
                        case 'P':
                            ProcessMode = ProcessModes.Pack;
                            break;
                        case 'n':
                        case 'N':
                            DataMode = DataModes.Unicode;
                            break;
                        case 'a':
                        case 'A':
                            DataMode = DataModes.Ascii;
                            break;
                        default:
                            Console.WriteLine("Unknown command");
                            break;
                    }
                }
                else
                    break;
            }

            InOutFileName = args[i++];
            InOutDir = args[i++];

            if (ProcessMode == ProcessModes.Unpack)
            {
                if (DataMode == DataModes.Unicode)
                    UnpackUnicode(InOutFileName, InOutDir);
                else if (DataMode == DataModes.Ascii)
                    UnpackAscii(InOutFileName, InOutDir);
            }
            else if (ProcessMode == ProcessModes.Pack)
            {
                if (DataMode == DataModes.Unicode)
                    PackUnicdoe(InOutFileName, InOutDir);
                else if (DataMode == DataModes.Ascii)
                    PackAscii(InOutFileName, InOutDir);
            }
        }
    }
}
