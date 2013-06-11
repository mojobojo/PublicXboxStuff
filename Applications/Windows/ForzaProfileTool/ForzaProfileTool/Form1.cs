using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Security.Cryptography;

namespace ForzaProfileTool
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        byte[] HexStringToByteArray(string str)
        {
            try
            {
                if (str.Length != 16)
                    throw new Exception("Invalid length");

                List<byte> ret = new List<byte>();
                for (int i = 0; i < str.Length; i += 2)
                    ret.Add(Convert.ToByte(str.Substring(i, 2), 16));
                return ret.ToArray();
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        uint BSwapUint(uint num)
        {
            return
                (uint)((num & 0x000000FF) << 24) |
                (uint)((num & 0x0000FF00) << 8) |
                (uint)((num & 0x00FF0000) >> 8) |
                (uint)((num & 0xFF000000) >> 24)
                ;
        }

        int BSwapInt(int num)
        {
            return
                (int)((num & 0x000000FF) << 24) |
                (int)((num & 0x0000FF00) << 8) |
                (int)((num & 0x00FF0000) >> 8) |
                (int)((num & 0xFF000000) >> 24)
                ;
        }

        void XorAes(ref byte[] Buf, byte[] Key, int Start)
        {
            for (int i = 0; i < Buf.Length; i++)
                Buf[i & 15] ^= Key[(i + Start) & 7];
        }

        void XorHmac(ref byte[] Buf, byte[] Key, int Start)
        {
            for (int i = 0; i < Buf.Length; i++)
                Buf[i & 31] ^= Key[(i + Start) & 7];
        }

        uint DecryptDataSize(byte[] IV, uint DataSize)
        {
            return
                (uint)((
                DataSize ^
                BSwapUint(BitConverter.ToUInt32(IV, 0)) ^
                BSwapUint(BitConverter.ToUInt32(IV, 4)) ^
                BSwapUint(BitConverter.ToUInt32(IV, 8)) ^
                BSwapUint(BitConverter.ToUInt32(IV, 12))) + 15) & 0xFFFFFFF0;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                SaveFileDialog sfd = new SaveFileDialog();

                if (sfd.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        byte[] AES_KEY = { 
                            0xB4, 0xEB, 0x7F, 0xB9, 
                            0xA9, 0xAC, 0x05, 0x92, 
                            0xAB, 0x8E, 0x42, 0xAB,
	                        0xCC, 0x61, 0xD0, 0xC0
                        };

                        BinaryReader reader = new BinaryReader(new FileStream(ofd.FileName, FileMode.Open, FileAccess.ReadWrite, FileShare.ReadWrite));
                        BinaryWriter writer = new BinaryWriter(new FileStream(sfd.FileName, FileMode.Create, FileAccess.ReadWrite, FileShare.ReadWrite));

                        byte[] ProfileID = HexStringToByteArray(textBox1.Text);

                        if (reader.ReadUInt32() != 0x73736D63)
                            throw new Exception("Invalid File");

                        uint ReadSize = BSwapUint(reader.ReadUInt32());

                        byte[] Hash = reader.ReadBytes(0x20);
                        uint DataSizeEnc = BSwapUint(reader.ReadUInt32());
                        byte[] AES_IV = reader.ReadBytes(0x10);

                        uint DataSizeDec = DecryptDataSize(AES_IV, DataSizeEnc);
                        byte[] DataBuffer = reader.ReadBytes((int)(DataSizeDec));

                        XorAes(ref AES_KEY, ProfileID, 1);

                        AesCryptoServiceProvider aes = new AesCryptoServiceProvider();
                        aes.Mode = CipherMode.CBC;
                        aes.Padding = PaddingMode.None;

                        byte[] Decrypted = aes.CreateDecryptor(AES_KEY, AES_IV).TransformFinalBlock(DataBuffer, 0, DataBuffer.Length);

                        writer.Write(0x73736D63);
                        writer.Write(BSwapUint(ReadSize));
                        writer.Write(Hash);
                        writer.Write(BSwapUint(DataSizeEnc));
                        writer.Write(AES_IV);
                        writer.Write(Decrypted);

                        writer.Flush();
                        writer.Close();
                        reader.Close();
                    }
                    catch (Exception x)
                    {
                        MessageBox.Show(x.Message);
                    }
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                SaveFileDialog sfd = new SaveFileDialog();

                if (sfd.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        byte[] AES_KEY = { 
                            0xB4, 0xEB, 0x7F, 0xB9, 
                            0xA9, 0xAC, 0x05, 0x92, 
                            0xAB, 0x8E, 0x42, 0xAB,
	                        0xCC, 0x61, 0xD0, 0xC0
                        };

                        byte[] HMAC_KEY = {
	                        0x82, 0xF4, 0x1A, 0x4F, 
                            0x03, 0x45, 0x65, 0x01, 
                            0x2F, 0x73, 0x9C, 0x4D,
	                        0x8E, 0x63, 0xA9, 0x1F, 
                            0xB9, 0x2B, 0x9D, 0x4E, 
                            0xE1, 0x11, 0x91, 0x47,
	                        0xD4, 0x3C, 0xC6, 0x88, 
                            0x3F, 0xC7, 0xFC, 0x70
                        };

                        BinaryReader reader = new BinaryReader(new FileStream(ofd.FileName, FileMode.Open, FileAccess.ReadWrite, FileShare.ReadWrite));
                        BinaryWriter writer = new BinaryWriter(new FileStream(sfd.FileName, FileMode.Create, FileAccess.ReadWrite, FileShare.ReadWrite));

                        byte[] ProfileID = HexStringToByteArray(textBox1.Text);

                        if (reader.ReadUInt32() != 0x73736D63)
                            throw new Exception("Invalid File");

                        uint ReadSize = BSwapUint(reader.ReadUInt32());

                        byte[] Hash = reader.ReadBytes(0x20);
                        uint DataSizeEnc = BSwapUint(reader.ReadUInt32());
                        byte[] AES_IV = reader.ReadBytes(0x10);

                        uint DataSizeDec = DecryptDataSize(AES_IV, DataSizeEnc);
                        byte[] DataBuffer = reader.ReadBytes((int)(DataSizeDec));

                        XorAes(ref AES_KEY, ProfileID, 1);

                        AesCryptoServiceProvider aes = new AesCryptoServiceProvider();
                        aes.Mode = CipherMode.CBC;
                        aes.Padding = PaddingMode.None;

                        byte[] Encrypted = aes.CreateEncryptor(AES_KEY, AES_IV).TransformFinalBlock(DataBuffer, 0, DataBuffer.Length);

                        XorHmac(ref HMAC_KEY, ProfileID, 0);
                        HMACSHA256 hmac = new HMACSHA256(HMAC_KEY);

                        byte[] Tmp = new byte[0x14];
                        Buffer.BlockCopy(BitConverter.GetBytes(BSwapUint(DataSizeEnc)), 0, Tmp,  0, 4);
                        Buffer.BlockCopy(AES_IV, 0, Tmp, 4, 0x10);

                        hmac.TransformBlock(Tmp, 0, 0x14, null, 0);
                        hmac.TransformFinalBlock(Encrypted, 0, Encrypted.Length);

                        writer.Write(0x73736D63);
                        writer.Write(BSwapUint(ReadSize));
                        writer.Write(hmac.Hash);
                        writer.Write(BSwapUint(DataSizeEnc));
                        writer.Write(AES_IV);
                        writer.Write(Encrypted);

                        writer.Flush();
                        writer.Close();
                        reader.Close();
                    }
                    catch (Exception x)
                    {
                        MessageBox.Show(x.Message);
                    }
                }
            }
        }
    }
}
