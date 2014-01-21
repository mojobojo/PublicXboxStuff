using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CaffChecksumTest
{
    class Program
    {
        static uint CaffChecksum(byte[] data, int length)
        {
            uint r11 = 0;

            for (int i = 0; i < length; i++)
            {
                uint r8 = data[i];
                uint r10 = r11 << 4;

                if ((r8 & 0x80) > 0)
                {
                    r11 = 0xFFFFFF80 | r8;
                }
                else
                {
                    r11 = r8;
                }

                r11 = r11 + r10;
                r10 = r11 & 0xF0000000;

                if (r10 != 0)
                {
                    r8 = r10 >> 24;
                    r10 = r8 | r10;
                    r11 = r10 ^ r11;
                }
            }

            return r11;
        }

        static void Main(string[] args)
        {
            FileStream stream = new FileStream("C:\\Users\\mojobojo\\Desktop\\685374\\7A41120.bin", FileMode.Open);
 
            byte[] data = new byte[0x78];
            stream.Read(data, 0, 0x78);

            data[0x18] = 0;
            data[0x19] = 0;
            data[0x1A] = 0;
            data[0x1B] = 0;

            uint checksum = CaffChecksum(data, 0x78);
            Console.WriteLine(checksum.ToString("X8"));
            Console.WriteLine();
        }
    }
}
