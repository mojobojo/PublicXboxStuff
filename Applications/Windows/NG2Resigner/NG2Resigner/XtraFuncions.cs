using System;
using System.Collections.Generic;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Runtime.CompilerServices;
using System.Text;
using System.Windows.Forms;
using Microsoft.VisualBasic;
using EZIO.IO;

namespace EZIO.Misc
{
    //XtraFunctions C# Class
    //Version 1.2
    //Compiled by Eaton
    //Xbox360-Content.com
    //Do not remove this!

    public abstract class XtraFunctions
    {
        public static void ReverseBlocks(byte[] Key, int BlockSize)
        {
            var num = Key.GetLength(0) / 2;
            for (var i = 1; i <= num; i++)
            {
                var index = i - 1;
                var num4 = ((Key.GetLength(0) - ((index / BlockSize) * BlockSize)) - BlockSize) + (index % BlockSize);
                var num5 = Convert.ToByte(Key.GetValue(num4));
                Key.SetValue(RuntimeHelpers.GetObjectValue(Key.GetValue(index)), num4);
                Key.SetValue(num5, index);
            }
        }

        public static byte[] StringToByteArray(string str)
        {
            var encoding = new ASCIIEncoding();
            return encoding.GetBytes(str);
        }

        public static string BytesToString(byte[] Buffer)
        {
            var str = string.Empty;
            for (var i = 0; i < Buffer.Length; i++)
            {
                str = str + Buffer[i].ToString("X2");
            }
            return str;
        }

        public static int ArrayToInt(byte[] input, bool bigEndian)
        {
            if (!bigEndian)
            {
                Array.Reverse(input);
            }
            var num3 = 0;
            if (input.Length > 4)
            {
                throw new ArgumentException("Byte array too large to convert to int.");
            }
            var num4 = input.Length - 1;
            for (var i = 0; i <= num4; i++)
            {
                num3 = num3 << 8;
                num3 |= input[i];
            }
            return num3;
        }

        public static long ArrayToLong(byte[] input, bool bigEndian)
        {
            var num3 = 0L;
            if (input.Length > 8)
            {
                throw new ArgumentException("Byte array too large to convert to long.");
            }
            if (!bigEndian)
            {
                Array.Reverse(input);
            }
            var num4 = input.Length - 1;
            for (var i = 0; i <= num4; i++)
            {
                num3 = num3 << 8;
                num3 |= input[i];
            }
            return num3;
        }

        public static byte[] ASCIIToHex(string ascii)
        {
            var buffer = new byte[ascii.Length / 2];
            for (var i = 0; i < (ascii.Length / 2); i++)
            {
                buffer[i] = byte.Parse(ascii.Substring(i * 2, 2), NumberStyles.HexNumber);
            }
            return buffer;
        }

        public static string HexToASCII(byte[] hex)
        {
            var str = string.Empty;
            for (var i = 0; i < hex.Length; i++)
            {
                var str2 = hex[i].ToString("X");
                if (str2.Length == 1)
                {
                    str2 = String.Format("0{0}", str2);
                }
                str = str + str2;
            }
            return str;
        }

        public static byte[] StringToBytes(string data)
        {
            return Encoding.ASCII.GetBytes(data);
        }

        public static string BytesToHexString(byte[] data)
        {
            var hexString = string.Empty;
            for (var i = 0; i < data.Length; i++)
            {
                var dataStr = data[i].ToString("X");
                while (dataStr.Length != 2)
                {
                    dataStr = String.Format("0{0}", dataStr);
                }
                hexString += dataStr;
            }
            return hexString;
        }

        public static byte[] HexStringToBytes(string hexString)
        {
            var data = new List<byte>();
            for (var i = 0; i < hexString.Length; i += 2)
            {
                if (hexString.Length > i + 1)
                {
                    data.Add(byte.Parse(hexString[i] + hexString[i + 1].ToString(), NumberStyles.HexNumber));
                }
            }
            return data.ToArray();
        }

        public static string RemoveWhiteSpacingFromString(string str)
        {
            return str.Replace("\0", string.Empty);
        }

        public static byte[] GetBytesFromStream(EndianReader er)
        {
            return GetBytesFromStream(er, 0, (int)er.BaseStream.Length);
        }

        public static byte[] GetBytesFromStream(EndianReader er, int offset, int size)
        {
            er.BaseStream.Position = offset;
            var data = er.ReadBytes(size);
            return data;
        }

        public static byte[] StringToUnicodeBytes(string text)
        {
            var origData = StringToBytes(text);
            var newData = new byte[origData.Length * 2];
            for (var i = 0; i < origData.Length; i++)
            {
                newData[i * 2] = origData[i];
            }
            return newData;
        }

        public static byte[] StringToUnicodeBytes(string text, int length)
        {
            var origData = StringToBytes(text);
            var newData = new byte[length];
            for (var i = 0; i < origData.Length; i++)
                newData[i * 2] = origData[i];
            return newData;
        }

        public static void ReverseBytes(ref byte[] data)
        {
            Array.Reverse(data);
        }

        public static byte[] ValueToBytes(string data, bool unicode)
        {
            return unicode ? StringToUnicodeBytes(data) : StringToBytes(data);
        }

        public static byte[] ValueToBytes(byte data)
        {
            return new[] { data };
        }

        public static byte[] ValueToBytes(short data, EndianType et)
        {
            var ms = new MemoryStream();
            var io = new EndianIO(ms, et);
            io.Open();
            io.Writer.Write(data);
            io.Reader.BaseStream.Position = 0;
            var array = io.Reader.ReadBytes((int)io.Reader.BaseStream.Length);
            io.Close();
            ms.Close();
            return array;
        }

        public static byte[] ValueToBytes(ushort data, EndianType et)
        {
            var ms = new MemoryStream();
            var io = new EndianIO(ms, et);
            io.Open();
            io.Writer.Write(data);
            io.Reader.BaseStream.Position = 0;
            var array = io.Reader.ReadBytes((int)io.Reader.BaseStream.Length);
            io.Close();
            ms.Close();
            return array;
        }

        public static byte[] ValueToBytes(int data, EndianType et)
        {
            var ms = new MemoryStream();
            var io = new EndianIO(ms, et);
            io.Open();
            io.Writer.Write(data);
            io.Reader.BaseStream.Position = 0;
            var array = io.Reader.ReadBytes((int)io.Reader.BaseStream.Length);
            io.Close();
            ms.Close();
            return array;
        }

        public static byte[] ValueToBytes(uint data, EndianType et)
        {
            var ms = new MemoryStream();
            var io = new EndianIO(ms, et);
            io.Open();
            io.Writer.Write(data);
            io.Reader.BaseStream.Position = 0;
            var array = io.Reader.ReadBytes((int)io.Reader.BaseStream.Length);
            io.Close();
            ms.Close();
            return array;
        }

        public static byte[] ValueToBytes(float data, EndianType et)
        {
            var ms = new MemoryStream();
            var io = new EndianIO(ms, et);
            io.Open();
            io.Writer.Write(data);
            io.Reader.BaseStream.Position = 0;
            var array = io.Reader.ReadBytes((int)io.Reader.BaseStream.Length);
            io.Close();
            ms.Close();
            return array;
        }

        public static string ReverseString(string str)
        {
            //Load our array of characters
            var array = str.ToCharArray();

            //Reverse our array of characters
            Array.Reverse(array);

            //Return our string.
            return CharsToStr(array);
        }

        static byte[] TextStringToBytes(string str)
        {
            var parts = str.Split(new[] { '-' });
            if (parts.Length >= 1)
            {
                var bytes = new byte[parts.Length];
                for (var x = 0; x < parts.Length; x++)
                    if (!byte.TryParse(parts[x], out bytes[x])) return new byte[0];

                return bytes;
            }

            return new byte[0];
        }

        public static string CharsToStr(char[] chars)
        {
            //Create our resultant string
            var result = string.Empty;

            //Loop for each character
            for (var i = 0; i < chars.Length; i++)
            {
                //Add to our string
                result += chars[i].ToString();
            }
            //Return the result
            return result;
        }

        public static void InsertBytes(string filePath, int startOffset, int size)
        {
            var input = new FileStream(filePath, FileMode.Open);
            var er = new EndianReader(input)
            {
                BaseStream = { Position = startOffset }
            };
            var buffer = er.ReadBytes(((int)er.BaseStream.Length) - ((int)er.BaseStream.Position));
            er.Close();
            input.Close();
            input = new FileStream(filePath, FileMode.Open);
            var ew = new EndianWriter(input)
            {
                BaseStream = { Position = startOffset }
            };
            ew.Write(new byte[size]);
            ew.Write(buffer);
            input.Close();
            ew.Close();
        }

        public static void DeleteBytes(string filePath, int startOffset, int size)
        {
            var input = new FileStream(filePath, FileMode.Open);
            var er = new EndianReader(input);
            var buffer = er.ReadBytes(startOffset);
            var baseStream = er.BaseStream;
            baseStream.Position += size;
            var buffer2 = er.ReadBytes(((int)er.BaseStream.Length) - ((int)er.BaseStream.Position));
            er.Close();
            input.Close();
            input = new FileStream(filePath, FileMode.Create);
            var ew = new EndianWriter(input);
            ew.Write(buffer);
            ew.Write(buffer2);
            input.Close();
            ew.Close();
        }

        public static float GetFloatFromBytes(byte[] bytes)
        {
            // Stores the bytes into a byte collection called "ReversedBytes"
            var reversedBytes = bytes;
            // Then Reverses the bytes order (123 - 321)
            Array.Reverse(reversedBytes);
            // Finally returns the bytes as a Single(float)
            return BitConverter.ToSingle(reversedBytes, 0);
        }

        public static int GetIntFromBytes(byte[] bytes)
        {
            // Stores the bytes into a byte collection called "ReversedBytes"
            var reversedBytes = bytes;
            // Then Reverses the bytes order (123 - 321)
            Array.Reverse(reversedBytes);
            // Finally returns the bytes as an Int32(int)
            return BitConverter.ToInt32(reversedBytes, 0);
        }

        public static Int16 GetInt16FromBytes(byte[] bytes)
        {
            // Stores the bytes into a byte collection called "ReversedBytes"
            var reversedBytes = bytes;
            // Then Reverses the bytes order (123 - 321)
            Array.Reverse(reversedBytes);
            // Finally returns the bytes as an Int16
            return BitConverter.ToInt16(reversedBytes, 0);
        }

        /*private static double HexToDec(string HexStr)
        {
            return Conversion.Val(string.Format("&H{0}", HexStr));
        }*/

        public static object ConvertTextToInteger(string text)
        {
            var down = new NumericUpDown
            {
                Maximum = 999999999999999999M,
                Minimum = -999999999999999999M,
                Text = text
            };
            var down2 = down;
            down2.Value = decimal.Add(down2.Value, decimal.One);
            down2 = down;
            down2.Value = decimal.Subtract(down2.Value, decimal.One);
            var num = Convert.ToInt64(down.Value);
            down.Dispose();
            return num;
        }

        public static int CalculatePadding(int integer, int interval)
        {
            return (interval - (integer % interval));
        }

        /*private byte ReverseByte(byte ByteT)
        {
            return (byte)Math.Round(HexToDec(Strings.StrReverse(Strings.Right("00" + Conversion.Hex(ByteT), 2))));
        }*/

        public static byte[] ImageToByteArray(System.Drawing.Image imageIn)
        {
            var ms = new MemoryStream();
            imageIn.Save(ms, System.Drawing.Imaging.ImageFormat.Gif);
            return ms.ToArray();
        }

        public static Image ByteArrayToImage(byte[] byteArrayIn)
        {
            var ms = new MemoryStream(byteArrayIn);
            var returnImage = Image.FromStream(ms);
            return returnImage;
        }
    }
}