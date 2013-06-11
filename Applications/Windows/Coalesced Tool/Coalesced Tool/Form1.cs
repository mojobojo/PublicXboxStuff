using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Security.Cryptography;

namespace Coalesced_Tool
{
    public partial class Form1 : Form
    {
        string FolderPath;
        string HashSecTemp = Application.StartupPath + "\\HashSec";
        List<string> HashSecFiles = new List<string>();
        List<byte[]> HashSecHashes = new List<byte[]>();
        StreamWriter logwriter;

        public Form1()
        {
            InitializeComponent();
        }

        public void AddLog(string log)
        {
            logwriter.WriteLine(log);
            logwriter.Flush();
            LogBox.Items.Add(log);
            LogBox.SelectedIndex = LogBox.Items.Count - 1;
        }

        private string[] FileToStringArray(string FileName)
        {
            List<string> ret = new List<string>();
            StreamReader reader = new StreamReader(FileName);

            while (!reader.EndOfStream)
            {
                string line = reader.ReadLine();
                if (line != "")
                    ret.Add(line);
            }
            reader.Dispose();
            return ret.ToArray();
        }

        private MojosIO GetHashSec(string XEXFileName)
        {
            MojosIO mIO = new MojosIO(XEXFileName, Endian.Big);

            if (!mIO.Accessed)
            {
                AddLog("Error accessing 'default.xex'");
                return null;
            }

            if (mIO.ReadString(4, Encoding.ASCII) == "XEX2")
            {
                AddLog("XEX2 Header valid");

                mIO.Position = 8;
                int BaseFileOffset = mIO.ReadInt32();
                mIO.Position = 0x10;
                int SomePointer = mIO.ReadInt32();
                mIO.Position = SomePointer + 0x110;
                uint LoadingAddress = mIO.ReadUInt32();
                mIO.Position = SomePointer;
                int TablePointer = mIO.ReadInt32() + SomePointer;
                int pos = TablePointer + 4;
                mIO.Position = pos;
                uint TableSize = mIO.ReadUInt32();
                uint FileAddress;
                uint FileSize;
                mIO.Position -= 4;
                string tem = "";

                while (pos < (TableSize + TablePointer))
                {
                    tem = mIO.ReadString(8, Encoding.ASCII);
                    FileAddress = mIO.ReadUInt32();
                    FileSize = mIO.ReadUInt32();
                    if (tem == "HashSec")
                    {
                        AddLog(string.Format("HashSec Located at Address 0x{0:X}", (uint)((FileAddress - LoadingAddress) + BaseFileOffset)));
                        mIO.Position = ((FileAddress - LoadingAddress) + BaseFileOffset);
                        File.WriteAllBytes(HashSecTemp, mIO.ReadBytes((int)FileSize));
                        mIO.Close();
                        return new MojosIO(HashSecTemp, Endian.Big);
                    }
                }
            }
            else
            {
                mIO.Close();
                AddLog("Invalid XEX Header");
                return null;
            }

            mIO.Close();
            return null;
        }

        private void ReadHashSec(string XEXPath)
        {
            MojosIO mIO = GetHashSec(XEXPath);

            int counter = 0;
            string tem = "";
            mIO.Position = 0;

            while (mIO.Position < mIO.StreamLength)
            {
                tem = mIO.ReadCString();
                HashSecFiles.Add(tem);
                HashSecHashes.Add(mIO.ReadBytes(20));
                string s = Path.GetDirectoryName(XEXPath) + "\\" + Path.GetFileName(tem);
                if (!File.Exists(s))
                    AddLog(string.Format("File '{0}' not found", Path.GetFileName(tem)));
                counter++;
            }

            AddLog(string.Format("{0} File Hashes found", counter));
            mIO.Close();
        }

        private byte[] CalcSHA1(string FileName)
        {
            return new SHA1CryptoServiceProvider().ComputeHash(File.ReadAllBytes(FileName));
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            logwriter = new StreamWriter(Application.StartupPath + "\\default.log");
            AddLog(string.Format("Welcome to Coalesced Tool V{0}", Application.ProductVersion));
        }

        private void FolderPathBrowser_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            if (fbd.ShowDialog() == DialogResult.OK)
            {
                FolderPath = fbd.SelectedPath;
                if (File.Exists(FolderPath + "\\default.xex"))
                    ReadHashSec(FolderPath + "\\default.xex");
                else
                    AddLog("No XEX Found in directory \"" + FolderPath + "\"");
                textBox1.Text = FolderPath;
            }
        }

        private void ApplyXEXPatchButton_Click(object sender, EventArgs e)
        {
            try
            {
                if (BackupXEXCheckbox.Checked)
                    if (!File.Exists(FolderPath + "\\default.xex.bak"))
                    {
                        AddLog("Backing up XEX...");
                        File.Copy(FolderPath + "\\default.xex", FolderPath + "\\default.xex.bak");
                    }
                    else
                        AddLog("Your XEX is already backed up.");
                if (BackupX360TOCCheckbox.Checked)
                    if (!File.Exists(FolderPath + "\\Xbox360TOC.txt.bak"))
                    {
                        AddLog("Backing up 'Xbox360TOC.txt'...");
                        File.Copy(FolderPath + "\\Xbox360TOC.txt", FolderPath + "\\Xbox360TOC.txt.bak");
                    }
                    else
                        AddLog("'Xbox360TOC.txt' is already backed up.");

                AddLog("Loading 'Xbox360TOC.txt' to memory.");
                string[] data = FileToStringArray(FolderPath + "\\Xbox360TOC.txt");
                StreamWriter tocw = new StreamWriter(FolderPath + "\\Xbox360TOC.txt");

                for (int i = 0; i < data.Length; i++)
                {
                    AddLog(string.Format("Parsing line {0}...", i));
                    int s = 0;
                    string tem = string.Empty;
                    int p = 0;

                    for (int x = 0; x < data[i].Length; x++)
                    {
                        if (data[i][x] == ' ') break;
                        tem += data[i][x];
                        p++;
                    }

                    s = Convert.ToInt32(tem);
                    tem = string.Empty;

                    if (s == 0)
                    {
                        tocw.WriteLine(data[i]);
                        break;
                    }

                    for (int x = (p + 5); x < data[i].Length; x++)
                    {
                        if (data[i][x] == ' ') break;
                        tem += data[i][x];
                    }

                    if (File.Exists(FolderPath + "\\" + Path.GetFileName(tem)))
                    {
                        int filesize = File.ReadAllBytes(FolderPath + "\\" + Path.GetFileName(tem)).Length;
                        AddLog(string.Format("Writing file size {0} bytes of file '{1}' to line {2}...", filesize, Path.GetFileName(tem), i));
                        tocw.WriteLine(filesize.ToString() + data[i].Substring(s.ToString().Length));
                    }
                    else
                        tocw.WriteLine(data[i]);
                }
                AddLog("Flushing stream...");
                tocw.Flush();
                tocw.Dispose();
                AddLog("Done Repairing 'Xbox360TOC.txt'.");

                MojosIO mIO = GetHashSec(FolderPath + "\\default.xex");

                for (int i = 0; i < HashSecFiles.Count; i++)
                {
                    mIO.ReadCString();
                    if (File.Exists(FolderPath + "\\" + Path.GetFileName(HashSecFiles[i])))
                    {
                        AddLog(string.Format("Fixing '{0}' SHA1 Hash", Path.GetFileName(HashSecFiles[i])));
                        mIO.Write(CalcSHA1(FolderPath + "\\" + Path.GetFileName(HashSecFiles[i])));
                    }
                    else
                    {
                        AddLog(string.Format("'{0}' not found", Path.GetFileName(HashSecFiles[i])));
                        mIO.Position += 20;
                    }
                }

                AddLog("Flushing stream...");
                mIO.Flush();
                mIO.Close();
                AddLog("Success, XEX patched!");
            }
            catch (Exception x)
            { AddLog("ERROR: " + x.Message); }
        }

        private void PackCoalescedButton_Click(object sender, EventArgs e)
        {
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.Filter = "Mirrors Enge INI Files|*.ini|Deutsch Localization File|*.deu|Español Localization File|*.esn|Français Localization File|*.fra|English Localization File|*.int|Italiano Localization File|*.ita|Russian Localization File|*.rus|All Files | *.*";
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                FolderBrowserDialog fbd2 = new FolderBrowserDialog();
                if (fbd2.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        if (!File.Exists(fbd2.SelectedPath + "\\Files.txt"))
                            throw new Exception("The file 'Files.txt' dose not exist.\nThis is needed to rebuild the package.");

                        string[] Entrys = FileToStringArray(fbd2.SelectedPath + "\\Files.txt");
                        MojosIO mIO = new MojosIO(new FileStream(sfd.FileName, FileMode.Create), Endian.Big);

                        if (!mIO.Accessed)
                            throw new Exception("There was a problem while acessing the stream.");

                        AddLog(string.Format("Writing Entry Count of {0}...", (Entrys.Length * 2)));
                        mIO.Write((int)(Entrys.Length * 2));

                        for (int i = 0; i < Entrys.Length; i++)
                        {
                            mIO.Write((int)(Entrys[i].Length + 1));
                            mIO.WriteString(Entrys[i], Encoding.ASCII);
                            mIO.Write((byte)0);
                            AddLog(string.Format("Writing {0}...", Path.GetFileName(Entrys[i])));
                            byte[] Buffer = File.ReadAllBytes(fbd2.SelectedPath + "\\" + Path.GetFileName(Entrys[i]));
                            mIO.Write((int)(Buffer.Length + 1));
                            mIO.Write(Buffer);
                            mIO.Write((byte)0);
                        }
                        AddLog("Flushing Stream...");
                        mIO.Flush();
                        mIO.Close();
                        AddLog("Done packing files.");
                    }
                    catch (Exception x)
                    { AddLog("ERROR: " + x.Message); }
                }
            }
        }

        private void UnpackCoalescedButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "Mirrors Enge INI Files|*.ini|Deutsch Localization File|*.deu|Español Localization File|*.esn|Français Localization File|*.fra|English Localization File|*.int|Italiano Localization File|*.ita|Russian Localization File|*.rus|All Files | *.*";
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                FolderBrowserDialog fbd2 = new FolderBrowserDialog();
                if (fbd2.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        StreamWriter fw = new StreamWriter(fbd2.SelectedPath + "\\Files.txt");
                        MojosIO mIO = new MojosIO(ofd.FileName, Endian.Big);

                        if (!mIO.Accessed)
                        {
                            fw.Close();
                            throw new Exception("There was a problem while acessing the stream.");
                        }

                        int EntryCount = mIO.ReadInt32();

                        AddLog(string.Format("Total Entrys: {0}", (EntryCount / 2)));

                        for (int i = 0; i < (EntryCount / 2); i++)
                        {
                            int EntryNameLength = mIO.ReadInt32();
                            string EntryName = mIO.ReadString(EntryNameLength, Encoding.ASCII);
                            int EntrySize = mIO.ReadInt32();
                            byte[] Entry = mIO.ReadBytes(EntrySize - 1);
                            mIO.Position++;
                            AddLog(string.Format("Writing file {0}", Path.GetFileName(EntryName)));
                            File.WriteAllBytes(fbd2.SelectedPath + "\\" + Path.GetFileName(EntryName), Entry);
                            fw.WriteLine(EntryName);
                            fw.Flush();
                        }
                        fw.Close();
                        mIO.Close();
                        AddLog("Done extracting files!");
                    }
                    catch (Exception x)
                    { AddLog("ERROR: " + x.Message); }
                }
            }
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("App coded by Mojobojo, Coalesced research by Mojobojo.\n", "About");
        }
    }
}
