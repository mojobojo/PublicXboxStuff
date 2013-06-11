using System;
using System.Drawing;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace EZIO.IO
{
    //EndianIO C# Class
    //Version 1.7
    //Compiled by Eaton
    //Xbox360-Content.com
    //Do not remove this!

    public enum EndianType
    {
        BigEndian,
        LittleEndian
    }

    public class EndianIO
    {
        public EndianReader Reader { get; set; }
        public EndianWriter Writer { get; set; }
        private string FileName { get; set; }
        private EndianType EndianType { get; set; }
        private Stream Stream { get; set; }
        private MemoryStream MemoryStream { get; set; }

        public EndianIO(string fileName, EndianType endiantype)
        {
            EndianType = endiantype;
            FileName = fileName;
        }

        public EndianIO(string fileName, EndianType endiantype, bool Open, bool IsNewFile)
        {
            EndianType = endiantype;
            FileName = fileName;
            var mode = IsNewFile ? FileMode.Create : FileMode.Open;
            try
            {
                Stream = new FileStream(FileName, mode);
                Reader = new EndianReader(Stream, EndianType);
                Writer = new EndianWriter(Stream, EndianType);
                if (!Open)
                {
                    Close();
                }
            }
            catch
            {
            }
        }

        public EndianIO(MemoryStream memoryStream, EndianType endiantype)
        {
            EndianType = endiantype;
            MemoryStream = memoryStream;
        }

        public EndianIO(Stream stream, EndianType endiantype)
        {
            EndianType = endiantype;
            Stream = stream;
        }

        public EndianIO(byte[] Buffer, EndianType endiantype)
        {
            EndianType = endiantype;
            MemoryStream = new MemoryStream(Buffer);
        }

        public void Close()
        {
            try
            {
                Stream.Close();
                Stream = null;
            }
            catch
            {
            }
        }

        public void Open()
        {
            try
            {
                Stream = new FileStream(FileName, FileMode.Open);
                Reader = new EndianReader(Stream, EndianType);
                Writer = new EndianWriter(Stream, EndianType);
            }
            catch
            {
            }
        }
    }

    public class EndianReader : BinaryReader
    {
        public EndianType EndianType;

        public EndianReader(Stream input)
            : base(input)
        {
            EndianType = EndianType.LittleEndian;
        }

        public EndianReader(Stream input, EndianType endiantype)
            : base(input)
        {
            EndianType = endiantype;
        }

        public EndianReader(Stream input, EndianType endiantype, Encoding encoding)
            : base(input, encoding)
        {
            EndianType = endiantype;
        }

        public byte[] GenerateSHA1Hash(long Address, int Length)
        {
            BaseStream.Position = Address;
            var buffer = ReadBytes(Length);
            return SHA1.Create().ComputeHash(buffer);
        }

        public override byte[] ReadBytes(int count)
        {
            return ReadBytes(count, EndianType.LittleEndian);
        }

        public byte[] ReadBytes(int count, EndianType endiantype)
        {
            var array = base.ReadBytes(count);
            if (endiantype == EndianType.BigEndian)
            {
                Array.Reverse(array);
            }
            return array;
        }

        public override char ReadChar()
        {
            return Encoding.ASCII.GetChars(ReadBytes(1))[0];
        }

        public override char[] ReadChars(int count)
        {
            return ReadChars(count, EndianType.LittleEndian);
        }

        public char[] ReadChars(int count, EndianType endiantype)
        {
            var chars = Encoding.ASCII.GetChars(XReadBytes(count));
            if (endiantype == EndianType.BigEndian)
            {
                Array.Reverse(chars);
            }
            return chars;
        }

        public override double ReadDouble()
        {
            return ReadDouble(EndianType);
        }

        public double ReadDouble(EndianType endiantype)
        {
            var num = base.ReadDouble();
            if (endiantype == EndianType.BigEndian)
            {
                var bytes = BitConverter.GetBytes(num);
                Array.Reverse(bytes);
                num = BitConverter.ToDouble(bytes, 0);
            }
            return num;
        }

        public string ReadHexString(int Length)
        {
            var str = string.Empty;
            for (var i = 0; i < Length; i++)
            {
                str = str + ReadByte().ToString("X2");
            }
            return str;
        }

        public override short ReadInt16()
        {
            return ReadInt16(EndianType);
        }

        public short ReadInt16(EndianType endiantype)
        {
            var num = base.ReadInt16();
            if (endiantype == EndianType.BigEndian)
            {
                var bytes = BitConverter.GetBytes(num);
                Array.Reverse(bytes);
                num = BitConverter.ToInt16(bytes, 0);
            }
            return num;
        }

        public int ReadInt24()
        {
            return ReadInt24(EndianType);
        }

        public int ReadInt24(EndianType endiantype)
        {
            var buffer = new byte[4];
            if (endiantype == EndianType.BigEndian)
            {
                Read(buffer, 1, 3);
            }
            else
            {
                Read(buffer, 0, 3);
            }
            if (endiantype == EndianType.BigEndian)
            {
                Array.Reverse(buffer);
            }
            return BitConverter.ToInt32(buffer, 0);
        }

        public override int ReadInt32()
        {
            return ReadInt32(EndianType);
        }

        public int ReadInt32(EndianType endiantype)
        {
            var num = base.ReadInt32();
            if (endiantype == EndianType.BigEndian)
            {
                var bytes = BitConverter.GetBytes(num);
                Array.Reverse(bytes);
                num = BitConverter.ToInt32(bytes, 0);
            }
            return num;
        }

        public override long ReadInt64()
        {
            return ReadInt64(EndianType);
        }

        public long ReadInt64(EndianType endiantype)
        {
            var num = base.ReadInt64();
            if (endiantype == EndianType.BigEndian)
            {
                var bytes = BitConverter.GetBytes(num);
                Array.Reverse(bytes);
                num = BitConverter.ToInt64(bytes, 0);
            }
            return num;
        }

        public override float ReadSingle()
        {
            return ReadSingle(EndianType);
        }

        public float ReadSingle(EndianType endiantype)
        {
            var num = base.ReadSingle();
            if (endiantype == EndianType.BigEndian)
            {
                var bytes = BitConverter.GetBytes(num);
                Array.Reverse(bytes);
                num = BitConverter.ToSingle(bytes, 0);
            }
            return num;
        }

        public string ReadString(uint nbchar)
        {
            var str = "";
            for (uint i = 0; i < nbchar; i++)
            {
                var ch = ReadChar();
                if (ch != '\0')
                {
                    str = str + Convert.ToString(ch);
                }
            }
            return str;
        }

        public override ushort ReadUInt16()
        {
            return ReadUInt16(EndianType);
        }

        public ushort ReadUInt16(EndianType endiantype)
        {
            var num = base.ReadUInt16();
            if (endiantype == EndianType.BigEndian)
            {
                var bytes = BitConverter.GetBytes(num);
                Array.Reverse(bytes);
                num = BitConverter.ToUInt16(bytes, 0);
            }
            return num;
        }

        public override uint ReadUInt32()
        {
            return ReadUInt32(EndianType);
        }

        public uint ReadUInt32(EndianType endiantype)
        {
            var num = base.ReadUInt32();
            if (endiantype == EndianType.BigEndian)
            {
                var bytes = BitConverter.GetBytes(num);
                Array.Reverse(bytes);
                num = BitConverter.ToUInt32(bytes, 0);
            }
            return num;
        }

        public override ulong ReadUInt64()
        {
            return ReadUInt64(EndianType);
        }

        public ulong ReadUInt64(EndianType endiantype)
        {
            var num = base.ReadUInt64();
            if (endiantype == EndianType.BigEndian)
            {
                var bytes = BitConverter.GetBytes(num);
                Array.Reverse(bytes);
                num = BitConverter.ToUInt64(bytes, 0);
            }
            return num;
        }

        public string ReadNullTerminatedString()
        {
            var newString = string.Empty;
            char temp;
            while ((temp = ReadChar()) != '\0')
            {
                if (temp != '\0') newString += temp;
                else break;
            }
            return newString;
        }

        public string ReadASCIIString(int Length)
        {
            return ReadASCIIString(Length, EndianType);
        }

        public string ReadASCIIString(int Length, EndianType endiantype)
        {
            var newString = string.Empty;
            var howMuch = 0;
            for (var x = 0; x < Length; x++)
            {
                var tempChar = (char)ReadByte();
                howMuch++;
                if (tempChar != '\0')
                    newString += tempChar;
                else
                    break;
            }

            var size = (Length - howMuch) * sizeof(byte);
            BaseStream.Seek(size, SeekOrigin.Current);

            return newString;
        }

        public string ReadUnicodeString()
        {
            var str = string.Empty;
            var ch = (char)ReadUInt16(EndianType);
            do
            {
                if (ch == '\n')
                {
                    ch = (char)ReadUInt16(EndianType);
                    if (ch == '\0')
                    {
                        ch = (char)ReadUInt16(EndianType);
                    }
                }
                if (((ch == '\0') || (ch == '\n')) || (ch == '\r')) continue;
                str = str + ch;
                ch = (char)ReadUInt16(EndianType);
            }
            while (((ch != '\0') && (ch != '\n')) && (ch != '\r'));
            return str;
        }

        public long Seek(long offset)
        {
            BaseStream.Position = offset;
            return 0L;
        }

        public long SeekForward(int offset)
        {
            return BaseStream.Seek(offset, SeekOrigin.Current);
        }

        public Image ParseImage(int Size)
        {
            return ParseImage(Size, BaseStream.Position);
        }

        public Image ParseImage(int Size, long Address)
        {
            Seek(Address);
            var stream = new MemoryStream(ReadBytes(Size, EndianType.LittleEndian));
            try
            {
                return Image.FromStream(stream);
            }
            catch
            {
            }
            return null;
        }

        public virtual byte[] XReadBytes(int count)
        {
            if (BaseStream == null)
            {
                throw new Exception("File not open");
            }
            var buffer = new byte[count];
            var offset = 0;
            do
            {
                var num2 = BaseStream.Read(buffer, offset, count);
                if (num2 == 0)
                {
                    break;
                }
                offset += num2;
                count -= num2;
            }
            while (count > 0);
            if (offset != buffer.Length)
            {
                var dst = new byte[offset];
                Buffer.BlockCopy(buffer, 0, dst, 0, offset);
                buffer = dst;
            }
            return buffer;
        }

        public virtual uint XReadUInt32()
        {
            uint num = 0;
            for (var i = 0; i < 4; i++)
            {
                num *= 0x100;
                num += ReadByte();
            }
            return num;
        }

        public string XReadUnicodeString(int Length)
        {
            return XReadUnicodeString(Length, EndianType);
        }

        public string XReadUnicodeString(int Length, EndianType EndianType)
        {
            var str = string.Empty;
            var num = 0;
            for (var i = 0; i < Length; i++)
            {
                var ch = (char)ReadUInt16(EndianType);
                num++;
                if (ch == '\0')
                {
                    break;
                }
                str = str + ch;
            }
            var num3 = (Length - num) - 1;
            BaseStream.Seek(num3, SeekOrigin.Current);
            return str;
        }
    }

    public class EndianWriter : BinaryWriter
    {
        public EndianType EndianType { get; set; }

        public EndianWriter(Stream output)
            : base(output)
        {
            EndianType = EndianType.LittleEndian;
        }

        public EndianWriter(Stream output, EndianType endianType)
            : base(output)
        {
            EndianType = endianType;
        }

        public EndianWriter(Stream output, EndianType endianType, Encoding encoding)
            : base(output, encoding)
        {
            EndianType = endianType;
        }

        private bool EndianSwap()
        {
            return (EndianType == EndianType.BigEndian);
        }

        public long Seek(int offset)
        {
            return base.Seek(offset, SeekOrigin.Begin);
        }

        public long SeekUp(int offset)
        {
            return base.Seek(offset, SeekOrigin.Current);
        }

        public void Write(short value, EndianType EndianType)
        {
            var buffer = BitConverter.GetBytes(value);
            if (EndianType == EndianType.BigEndian)
                Array.Reverse(buffer);

            base.Write(buffer);
        }

        public override void Write(ushort value)
        {
            Write(value, EndianType);
        }
        public void Write(ushort value, EndianType EndianType)
        {
            var buffer = BitConverter.GetBytes(value);
            if (EndianType == EndianType.BigEndian)
                Array.Reverse(buffer);

            base.Write(buffer);
        }

        public override void Write(int value)
        {
            Write(value, EndianType);
        }
        public void Write(int value, EndianType EndianType)
        {
            var buffer = BitConverter.GetBytes(value);
            if (EndianType == EndianType.BigEndian)
                Array.Reverse(buffer);

            base.Write(buffer);
        }

        public override void Write(uint value)
        {
            Write(value, EndianType);
        }
        public void Write(uint value, EndianType EndianType)
        {
            var buffer = BitConverter.GetBytes(value);
            if (EndianType == EndianType.BigEndian)
                Array.Reverse(buffer);

            base.Write(buffer);
        }

        public override void Write(long value)
        {
            Write(value, EndianType);
        }
        public void Write(long value, EndianType EndianType)
        {
            var buffer = BitConverter.GetBytes(value);
            if (EndianType == EndianType.BigEndian)
                Array.Reverse(buffer);

            base.Write(buffer);
        }

        public override void Write(ulong value)
        {
            Write(value, EndianType);
        }
        public void Write(ulong value, EndianType EndianType)
        {
            var buffer = BitConverter.GetBytes(value);
            if (EndianType == EndianType.BigEndian)
                Array.Reverse(buffer);

            base.Write(buffer);
        }

        public override void Write(float value)
        {
            Write(value, EndianType);
        }
        public void Write(float value, EndianType EndianType)
        {
            var buffer = BitConverter.GetBytes(value);
            if (EndianType == EndianType.BigEndian)
                Array.Reverse(buffer);

            base.Write(buffer);
        }

        public void Write(string value, int length, EndianType type)
        {
            var array = value.ToCharArray();
            if (type == EndianType.BigEndian)
            {
                Array.Reverse(array);
            }
            base.Write(array);
            for (var i = 0; i < (length - value.Length); i++)
            {
                Write((byte)0);
            }
        }

        public override void Write(double value)
        {
            Write(value, EndianType);
        }
        public void Write(double value, EndianType EndianType)
        {
            var buffer = BitConverter.GetBytes(value);
            if (EndianType == EndianType.BigEndian)
                Array.Reverse(buffer);

            base.Write(buffer);
        }

        public void WriteFloat(float value)
        {
            var bytes = BitConverter.GetBytes(value);
            Array.Reverse(bytes);
            var num = BitConverter.ToSingle(bytes, 0);
            base.Write(num);
        }

        public void WriteIdent(int value)
        {
            var bytes = BitConverter.GetBytes(value);
            Array.Reverse(bytes);
            var num = BitConverter.ToInt32(bytes, 0);
            base.Write(num);
        }

        public void WriteInt24(int Value)
        {
            var bytes = BitConverter.GetBytes(Value);
            var num = bytes[0];
            var num2 = bytes[1];
            var num3 = bytes[2];
            var array = new[] { num, num2, num3 };
            if (EndianSwap())
            {
                Array.Reverse(array);
            }
            Write(array);
        }

        public void WriteTagType(string tagType)
        {
            EndianType = EndianType.BigEndian;
            Write(tagType);
            EndianType = EndianType.LittleEndian;
        }

        public void WriteAsciiString(string String, int Length)
        {
            WriteAsciiString(String, Length, EndianType);
        }

        public void WriteAsciiString(string String, int Length, EndianType EndianType)
        {
            var strLen = String.Length;
            for (var x = 0; x < strLen; x++)
            {
                if (x > Length)
                    break;//just incase they pass a huge string

                var val = (byte)String[x];
                Write(val);
            }

            var nullSize = (Length - strLen) * sizeof(byte);
            if (nullSize > 0)
                Write(new byte[nullSize]);
        }

        public void WriteUnicodeString(string String, int Length)
        {
            WriteUnicodeString(String, Length, EndianType);
        }

        public void WriteUnicodeString(string String, int Length, EndianType EndianType)
        {
            var strLen = String.Length;
            for (var x = 0; x < strLen; x++)
            {
                if (x > Length)
                    break;//just incase they pass a huge string

                ushort val = String[x];
                Write(val, EndianType);
            }

            var nullSize = (Length - strLen) * sizeof(ushort);
            if (nullSize > 0)
                Write(new byte[nullSize]);
        }

        public void WriteUnicodeNoIndent(string str, int length)
        {
            for (var i = 0; i < str.Length; i++)
            {
                Write(str[i]);
                Write((byte)0);
            }
            for (var j = 0; j < (length - str.Length); j++)
            {
                Write((byte)0);
            }
        }
    }
}