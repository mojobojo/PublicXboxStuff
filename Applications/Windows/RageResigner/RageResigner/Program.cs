using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Security.Cryptography;

namespace RageResigner
{
    class Program
    {
        static uint RageChecksum(byte[] Buffer)
        {
            byte[] md5 = new MD5CryptoServiceProvider().ComputeHash(Buffer);

            uint A = (uint)(md5[15] << 24) | (uint)(md5[14] << 16) | (uint)(md5[13] << 8) | md5[12];
            uint B = (uint)(md5[11] << 24) | (uint)(md5[10] << 16) | (uint)(md5[9] << 8)  | md5[8];
            uint C = (uint)(md5[7] << 24)  | (uint)(md5[6] << 16)  | (uint)(md5[5] << 8)  | md5[4];
            uint D = (uint)(md5[3] << 24)  | (uint)(md5[2] << 16)  | (uint)(md5[1] << 8)  | md5[0];

            return A ^ B ^ C ^ D;
        }

        static uint BSwapUint(uint num)
        {
            return
                (uint)((num & 0x000000FF) << 24) |
                (uint)((num & 0x0000FF00) << 8) |
                (uint)((num & 0x00FF0000) >> 8) |
                (uint)((num & 0xFF000000) >> 24)
                ;
        }

        static void Main(string[] args)
        {
            FileStream stream = new FileStream(args[0],FileMode.Open, FileAccess.ReadWrite, FileShare.ReadWrite );
            BinaryReader reader = new BinaryReader(stream);
            BinaryWriter writer = new BinaryWriter(stream);

            stream.Position = 4;
            byte[] Data = reader.ReadBytes((int)stream.Length - 4);

            uint Checksum = RageChecksum(Data);
            stream.Position = 0;
            writer.Write(BSwapUint(Checksum));

            writer.Flush();

            stream.Close();
        }
    }
}
