using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Drawing;
using System.Drawing.Imaging;
using System.Globalization;
using System.Runtime.CompilerServices;
using System.Linq;
using System.Windows.Forms;

/// <summary>
/// The endian mode the data is processed in.
/// </summary>
public enum Endian { Big = 1, Little = 2 }

public enum RLEMode { Encode = 1, Decode = 2 }

public class MojosIO
{
    [CompilerGenerated]
    private BinaryReader reader { get; set; }
    [CompilerGenerated]
    private BinaryWriter writer { get; set; }
    [CompilerGenerated]
    private Stream stream { get; set; }
    [CompilerGenerated]
    private Endian endian = Endian.Little;
    [CompilerGenerated]
    private long PrevPos = 0;
    /// <summary>
    /// Gets or sets the position of the current stream.
    /// </summary>
    [CompilerGenerated]
    public long Position
    {
        get { return stream.Position; }
        set{ stream.Position = value; }
    }
    /// <summary>
    /// Gets or sets the current endian for reading and writing.
    /// </summary>
    [CompilerGenerated]
    public Endian CurrentEndian
    {
        get { return endian; }
        set { endian = value; }
    }
    /// <summary>
    /// Returns a boolean of wether or not the stream is properly accessed.
    /// </summary>
    [CompilerGenerated]
    public bool Accessed
    {
        get
        {
            if (stream == null) return false;
            return (stream.CanRead && stream.CanWrite && stream.CanSeek);
        }
    }
    /// <summary>
    /// Gets the length of the current stream.
    /// </summary>
    [CompilerGenerated]
    public long StreamLength
    {
        get { return stream.Length; }
        set
        {
            try
            {
                if (value == stream.Length) return;
                if (Accessed) stream.SetLength(value);
                else throw MojoIOExceptions.SetStreamFailedException;
            }
            catch { throw MojoIOExceptions.SetStreamFailedException; }
        }
    }

    /// <summary>
    /// Declares a new instance of MojosIO.
    /// </summary>
    /// <param name="xIn"></param>
    /// <param name="EndianMode"></param>
    public MojosIO(object xIn, Endian EndianMode)
    {
        switch (xIn.GetType().ToString().ToLower())
        {
            case "system.string":
                stream = new FileStream((string)xIn, FileMode.Open, FileAccess.ReadWrite, FileShare.ReadWrite);
                break;
            case "system.io.filestream":
                stream = (FileStream)xIn;
                break;
            case "system.io.memorystream":
                stream = (MemoryStream)xIn;
                break;
            case "system.byte[]":
                stream = new MemoryStream((byte[])xIn);
                break;
            case "system.char[]":
                stream = new MemoryStream((byte[])xIn);
                break;
            case "system.long":
                if ((long)xIn < 1) 
                    throw MojoIOExceptions.InvalidLengthException;
                stream = new MemoryStream(new byte[(long)xIn]);
                break;
            case "system.int":
                if ((int)xIn < 1)
                    throw MojoIOExceptions.InvalidLengthException;
                stream = new MemoryStream(new byte[(int)xIn]);
                break;
            case "system.short":
                if ((short)xIn < 1)
                    throw MojoIOExceptions.InvalidLengthException;
                stream = new MemoryStream(new byte[(short)xIn]);
                break;
            case "system.byte":
                if ((byte)xIn < 1)
                    throw MojoIOExceptions.InvalidLengthException;
                stream = new MemoryStream(new byte[(byte)xIn]);
                break;
            default:
                throw MojoIOExceptions.InvalidInputException;
        }

        if (Accessed)
        {
            if (!SetStream())
                throw MojoIOExceptions.SetStreamFailedException;
            endian = EndianMode;
        }
        else throw MojoIOExceptions.StreamClosedException;
    }

    /// <summary>
    /// Reads an 8 bit unsigned integer.
    /// </summary>
    /// <returns>Byte</returns>
    public byte ReadByte()
    {
        try
        {
            PrevPos = stream.Position;
            return reader.ReadByte();
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads an 8 bit signed integer.
    /// </summary>
    /// <returns>SByte</returns>
    public sbyte ReadSByte()
    {
        try
        {
            PrevPos = stream.Position;
            return reader.ReadSByte();
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a given amount of bytes from the current stream.
    /// </summary>
    /// <param name="count"></param>
    /// <returns>Byte[]</returns>
    public byte[] ReadBytes(int count)
    {
        try
        {
            PrevPos = stream.Position;
            return reader.ReadBytes(count);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a 16 bit signed integer from the current stream.
    /// </summary>
    /// <returns>Short</returns>
    public short ReadInt16()
    {
        try
        {
            PrevPos = stream.Position;
            byte[] xData = ReadBytes(2);
            if (endian == Endian.Big)
                xData.Reverse();
            return (short)((short)xData[1] << 8 | (short)xData[0]);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a 16 bit unsigned integer from the current stream.
    /// </summary>
    /// <returns>UShort</returns>
    public ushort ReadUInt16()
    {
        try
        {
            PrevPos = stream.Position;
            byte[] xData = ReadBytes(2);
            if (endian == Endian.Big)
                xData.Reverse();
            return (ushort)((ushort)xData[1] << 8 | (ushort)xData[0]);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a 24 bit signed integer from the current stream.
    /// </summary>
    /// <returns>Int</returns>
    public int ReadInt24()
    {
        try
        {
            PrevPos = stream.Position;
            byte[] xData = ReadBytes(3);
            if (endian == Endian.Big)
                xData.Reverse();
            return ((int)xData[2] << 16 | (int)xData[1] << 8 | (int)xData[0]);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a 24 bit unsigned integer from the current stream.
    /// </summary>
    /// <returns>UInt</returns>
    public uint ReadUInt24()
    {
        try
        {
            PrevPos = stream.Position;
            byte[] xData = ReadBytes(3);
            if (endian == Endian.Big)
                xData.Reverse();
            return ((uint)xData[2] << 16 | (uint)xData[1] << 8 | (uint)xData[0]);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a 32 bit signed integer from the current stream.
    /// </summary>
    /// <returns>Int</returns>
    public int ReadInt32()
    {
        try
        {
            PrevPos = stream.Position;
            byte[] xData = reader.ReadBytes(4);
            if (endian == Endian.Big)
                xData.Reverse();
            return ((int)xData[3] << 24  | (int)xData[2] << 16 | (int)xData[1] << 8 | (int)xData[0]);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a 32 bit unsigned integer from the current stream.
    /// </summary>
    /// <returns>UInt</returns>
    public uint ReadUInt32()
    {
        try
        {
            PrevPos = stream.Position;
            byte[] xData = reader.ReadBytes(4);
            if (endian == Endian.Big)
                xData.Reverse();
            return ((uint)xData[3] << 24 | (uint)xData[2] << 16 | (uint)xData[1] << 8 | (uint)xData[0]);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a 64 bit signed integer from the current stream.
    /// </summary>
    /// <returns>Long</returns>
    public long ReadInt64()
    {
        try
        {
            PrevPos = stream.Position;
            byte[] xData = reader.ReadBytes(8);
            if (endian == Endian.Big)
                xData.Reverse();
            return ((long)xData[7] << 56 | (long)xData[6] << 48 | (long)xData[5] << 40 | (long)xData[4] << 32 |
                (long)xData[3] << 24 | (long)xData[2] << 16 | (long)xData[1] << 8 | (long)xData[0]);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a 64 bit unsigned integer from the current stream.
    /// </summary>
    /// <returns>ULong</returns>
    public ulong ReadUInt64()
    {
        try
        {
            PrevPos = stream.Position;
            byte[] xData = reader.ReadBytes(8);
            if (endian == Endian.Big)
                xData.Reverse();
            return ((ulong)xData[7] << 56 | (ulong)xData[6] << 48 | (ulong)xData[5] << 40 | (ulong)xData[4] << 32 |
                (ulong)xData[3] << 24 | (ulong)xData[2] << 16 | (ulong)xData[1] << 8 | (ulong)xData[0]);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a single precision floating point integer from the current stream.
    /// </summary>
    /// <returns>Float</returns>
    public float ReadSingle()
    {
        try
        {
            PrevPos = stream.Position;
            byte[] xData = reader.ReadBytes(4);
            if (endian == Endian.Big)
                xData.Reverse();
            return BitConverter.ToSingle(xData, 0);

        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a double precision floating point integer from the current stream.
    /// </summary>
    /// <returns>Double</returns>
    public double ReadDouble()
    {
        try
        {
            PrevPos = stream.Position;
            byte[] xData = reader.ReadBytes(8);
            if (endian == Endian.Big)
                xData.Reverse();
            return BitConverter.ToDouble(xData, 0);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a Hexadecimal string from the current stream.
    /// </summary>
    /// <param name="count"></param>
    /// <returns>String</returns>
    public string ReadHexString(int count)
    {
        try
        {
            PrevPos = stream.Position;
            return reader.ReadBytes(count).ToHexString();
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a string with a given encoding type from the current stream.
    /// </summary>
    /// <param name="count"></param>
    /// <param name="EncodingMode"></param>
    /// <returns>String</returns>
    public string ReadString(int count, Encoding EncodingMode)
    {
        try
        {
            PrevPos = stream.Position;
            string temp = "";
            if (EncodingMode == Encoding.ASCII)
                temp = Encoding.ASCII.GetString(reader.ReadBytes(count));
            else if (EncodingMode == Encoding.Unicode)
                temp = Encoding.Unicode.GetString(reader.ReadBytes(count));
            else if (EncodingMode == Encoding.BigEndianUnicode)
                temp = Encoding.BigEndianUnicode.GetString(reader.ReadBytes(count));
            else if (EncodingMode == Encoding.UTF7)
                temp = Encoding.UTF7.GetString(reader.ReadBytes(count));
            else if (EncodingMode == Encoding.UTF8)
                temp = Encoding.UTF8.GetString(reader.ReadBytes(count));
            else if (EncodingMode == Encoding.UTF32)
                temp = Encoding.UTF32.GetString(reader.ReadBytes(count));
            else
                temp = Encoding.Default.GetString(reader.ReadBytes(count));
            return temp.Replace("\0", "");
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a null char terminated string from the current stream.
    /// </summary>
    /// <returns>String</returns>
    public string ReadCString()
    {
        try
        {
            PrevPos = stream.Position;
            char cTemp;
            string sTemp = "";
            while ((cTemp = reader.ReadChar()) != '\0')
                sTemp += cTemp;
            return sTemp;
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a unicode encoded string from the current stream.
    /// </summary>
    /// <returns>String</returns>
    public string ReadUnicodeString()
    {
        try
        {
            PrevPos = stream.Position;
            if (reader.PeekChar() == '\0')
                reader.BaseStream.Position++;
            char cTemp;
            string sTemp = "";
            while ((cTemp = reader.ReadChar()) != '\0')
            {
                sTemp += cTemp;
                reader.BaseStream.Position++;
            }
            return sTemp;
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads an image from the current stream.
    /// </summary>
    /// <param name="count"></param>
    /// <returns>Image</returns>
    public Image ReadImage(int count)
    {
        try
        {
            PrevPos = stream.Position;
            return Functions.ByteArrayToImage(reader.ReadBytes(count));
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads an 8 bit integer to a binary string.
    /// </summary>
    /// <returns></returns>
    public string Read8BitBinary()
    {
        PrevPos = stream.Position;
        return Functions.NumberToBinary(reader.ReadByte());
    }

    /// <summary>
    /// Reads an 16 bit integer to a binary string.
    /// </summary>
    /// <returns></returns>
    public string Read16BitBinary()
    {
        try
        {
            PrevPos = stream.Position;
            return Functions.NumberToBinary(ReadInt16());
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads an 24 bit integer to a binary string.
    /// </summary>
    /// <returns></returns>
    public string Read24BitBinary()
    {
        try
        {
            PrevPos = stream.Position;
            return Functions.NumberToBinary(ReadInt24());
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads an 32 bit integer to a binary string.
    /// </summary>
    /// <returns></returns>
    public string Read32BitBinary()
    {
        try
        {
            PrevPos = stream.Position;
            return Functions.NumberToBinary(ReadInt32());
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads an 64 bit integer to a binary string.
    /// </summary>
    /// <returns></returns>
    public string Read64BitBinary()
    {
        try
        {
            PrevPos = stream.Position;
            return Functions.NumberToBinary(ReadInt64());
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Reads a boolean from the current stream.
    /// </summary>
    /// <returns></returns>
    public bool ReadBoolean() { return (ReadByte() != 0); }

    /// <summary>
    /// Writes an 8 bit signed integer to the current stream.
    /// </summary>
    /// <param name="value"></param>
    public void Write(sbyte value)
    {
        try
        {
            PrevPos = stream.Position;
            writer.Write(value);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes an 8 bit unsigned integer to the current stream.
    /// </summary>
    /// <param name="value"></param>
    public void Write(byte value)
    {
        try
        {
            PrevPos = stream.Position;
            writer.Write(value);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes a 32 bit signed integer to the current stream.
    /// </summary>
    /// <param name="value"></param>
    public void Write(int value)
    {
        try
        {
            PrevPos = stream.Position;
            if (endian == Endian.Big)
                writer.Write(value.Reverse());
            else
                writer.Write(value);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes a 32 bit unsigned integer to the current stream.
    /// </summary>
    /// <param name="value"></param>
    public void Write(uint value)
    {
        try
        {
            PrevPos = stream.Position;
            if (endian == Endian.Big)
                writer.Write(value.Reverse());
            else
                writer.Write(value);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes a 64 bit signed integer to the current stream.
    /// </summary>
    /// <param name="value"></param>
    public void Write(long value)
    {
        try
        {
            PrevPos = stream.Position;
            if (endian == Endian.Big)
                writer.Write(value.Reverse());
            else
                writer.Write(value);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes a 64 bit unsigned integer to the current stream.
    /// </summary>
    /// <param name="value"></param>
    public void Write(ulong value)
    {
        try
        {
            PrevPos = stream.Position;
            if (endian == Endian.Big)
                writer.Write(value.Reverse());
            else
                writer.Write(value);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes a 16 bit signed integer to the current stream. 
    /// </summary>
    /// <param name="value"></param>
    public void Write(short value)
    {
        try
        {
            PrevPos = stream.Position;
            if (endian == Endian.Big)
                writer.Write(value.Reverse());
            else
                writer.Write(value);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes an unsigned 16 bit integer to the current stream.
    /// </summary>
    /// <param name="value"></param>
    public void Write(ushort value)
    {
        try
        {
            PrevPos = stream.Position;
            if (endian == Endian.Big)
                writer.Write(value.Reverse());
            else
                writer.Write(value);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes a single precision floating point integer to the current stream.
    /// </summary>
    /// <param name="value"></param>
    public void Write(float value)
    {
        try
        {
            PrevPos = stream.Position;
            if (endian == Endian.Big)
                writer.Write(value.Reverse());
            else
                writer.Write(value);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes a double precision floating point integer to the current stream.
    /// </summary>
    /// <param name="value"></param>
    public void Write(double value)
    {
        try
        {
            PrevPos = stream.Position;
            if (endian == Endian.Big)
                writer.Write(value.Reverse());
            else
                writer.Write(value);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes a 24 bit unsigned integer to the current stream.
    /// Origially from DJ's IO.
    /// </summary>
    /// <param name="value"></param>
    public void WriteUInt24(uint value)
    {
        try
        {
            PrevPos = stream.Position;
            List<byte> tem = BitConverter.GetBytes(value).ToList<byte>();
            tem.RemoveAt(3);
            if (endian == Endian.Big)
                writer.Write(Functions.RevBytes(tem.ToArray()));
            else writer.Write(tem.ToArray());
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes a string to the current stream as ASCII encoding.
    /// </summary>
    /// <param name="str"></param>
    public void WriteString(string str)
    {
        try
        {
            PrevPos = stream.Position;
            writer.Write(Encoding.ASCII.GetBytes(str));
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes a string to the current stream with a given encoding type.
    /// </summary>
    /// <param name="str"></param>
    /// <param name="EncodingMode"></param>
    public void WriteString(string str, Encoding EncodingMode)
    {
        try
        {
            PrevPos = stream.Position;
            byte[] buffer;
            if (EncodingMode == Encoding.ASCII)
                buffer = Encoding.ASCII.GetBytes(str);
            else if (EncodingMode == Encoding.Unicode)
                buffer = Encoding.Unicode.GetBytes(str);
            else if (EncodingMode == Encoding.BigEndianUnicode)
                buffer = Encoding.BigEndianUnicode.GetBytes(str);
            else if (EncodingMode == Encoding.UTF7)
                buffer = Encoding.UTF7.GetBytes(str);
            else if (EncodingMode == Encoding.UTF8)
                buffer = Encoding.UTF8.GetBytes(str);
            else if (EncodingMode == Encoding.UTF32)
                buffer = Encoding.UTF32.GetBytes(str);
            else
                buffer = Encoding.Default.GetBytes(str);
            writer.Write(buffer);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes a byte[] to the current stream.
    /// </summary>
    /// <param name="buffer"></param>
    public void Write(byte[] buffer)
    {
        try
        {
            PrevPos = stream.Position;
            writer.Write(buffer);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes a Hexadecimal string to the current stream.
    /// </summary>
    /// <param name="HexString"></param>
    public void WriteHexString(string HexString)
    {
        try
        {
            PrevPos = stream.Position;
            writer.Write(Functions.HexStringToByteArray(HexString));
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Writes an image to the current stream with a given format.
    /// </summary>
    /// <param name="image"></param>
    /// <param name="format"></param>
    public void WriteImage(Image image, ImageFormat format)
    {
        try
        {
            PrevPos = stream.Position;
            writer.Write(Functions.ImageToByteArray(image, format));
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Nulls out a given number of bytes in the current stream.
    /// </summary>
    /// <param name="count"></param>
    public void WriteNullPadding(int count)
    {
        try
        {
            PrevPos = stream.Position;
            writer.Write(Functions.ByteBuffer(count, 0));
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Clears all buffers for current writer and causes any buffered data to be written.
    /// </summary>
    public void Flush() { if (Accessed) writer.Flush(); }

    /// <summary>
    /// Closes the current stream.
    /// </summary>
    public void Close()
    {
        if (Accessed)
        {
            endian = Endian.Little;
            PrevPos = 0;
            stream.Dispose();
            reader = null;
            writer = null;
        }
        else throw MojoIOExceptions.StreamClosedException;
    }

    /// <summary>
    /// Disposes the current stream.
    /// </summary>
    public void Dispose()
    {
        if (Accessed)
        {
            endian = Endian.Little;
            PrevPos = 0;
            stream.Dispose();
            reader = null;
            writer = null;
        }
        else throw MojoIOExceptions.StreamClosedException;
    }

    /// <summary>
    /// Resets the streams position to zero.
    /// </summary>
    /// <returns>A boolean if the stream position sucessfully moved to 0L.</returns>
    public bool ResetPosition()
    {
        try
        {
            if (Accessed)
            {
                stream.Position = 0;
                return true;
            }
            else return false;
        }
        catch
        { return false; }
    }

    /// <summary>
    /// Returns to the previous position from last read data.
    /// </summary>
    /// <returns>A boolean if the stream position sucessfull moved back.</returns>
    public bool RollBack()
    {
        try
        {
            if (Accessed)
            {
                stream.Position = PrevPos;
                return true;
            }
            else return false;
        }
        catch
        { return false; }
    }

    private bool SetStream()
    {
        try
        {
            if (Accessed)
            {
                reader = new BinaryReader(stream);
                writer = new BinaryWriter(stream);
                PrevPos = 0;
                return true;
            }
            else return false;
        }
        catch
        { return false; }
    }
}

public class Functions
{
    /// <summary>
    /// Reverses a given byte array.
    /// </summary>
    /// <param name="bytes"></param>
    /// <returns>Byte[]</returns>
    public static byte[] RevBytes(byte[] bytes)
    {
        Array.Reverse(bytes);
        return bytes;
    }

    /// <summary>
    /// Converts a byte array to a string.
    /// </summary>
    /// <param name="bytes"></param>
    /// <returns>String</returns>
    public static string ByteArrayToString(byte[] bytes) 
    { return BitConverter.ToString(bytes).Replace("-", ""); }

    /// <summary>
    /// Converts a Hexadecimal string to a byte[].
    /// </summary>
    /// <param name="str"></param>
    /// <returns>Byte[]</returns>
    public static byte[] HexStringToByteArray(string str)
    {
        try
        {
            if (!str.IsHexString()) throw MojoIOExceptions.InvalidHexadecimalStringException;
            if (str.Length % 2 == 1) str = "0" + str;
            List<byte> ret = new List<byte>();
            for (int i = 0; i < str.Length; i += 2)
                ret.Add(Convert.ToByte(str.Substring(i, 2), 16));
            return ret.ToArray();
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Converts a byte[] to an Image.
    /// </summary>
    /// <param name="data"></param>
    /// <returns>Image</returns>
    public static Image ByteArrayToImage(byte[] data)
    {
        try
        {
            using (MemoryStream ms = new MemoryStream(data))
            {
                return Image.FromStream(ms);
            }
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Converts an Image to a byte[].
    /// </summary>
    /// <param name="image"></param>
    /// <param name="format"></param>
    /// <returns>Byte[]</returns>
    public static byte[] ImageToByteArray(Image image, ImageFormat format)
    {
        try
        {
            using (MemoryStream ms = new MemoryStream())
            {
                image.Save(ms, format);
                return ms.ToArray();
            }
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Converts a Hexadecimal string to an 8 bit signed integer.
    /// </summary>
    /// <param name="HexString"></param>
    /// <returns>SByte</returns>
    public static sbyte HexStringToSByte(string HexString)
    {
        try
        {
            if (!HexString.IsHexString() || HexString.Length > 2 || HexString.Length < 2) 
                throw MojoIOExceptions.InvalidLengthException;
            return sbyte.Parse(HexString, NumberStyles.HexNumber);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Converts a Hexadecimal string to an 8 bit unsigned integer.
    /// </summary>
    /// <param name="HexString"></param>
    /// <returns>Byte</returns>
    public static byte HexStringToByte(string HexString)
    {
        try
        {
            if (!HexString.IsHexString() || HexString.Length > 2 || HexString.Length < 2) 
                throw MojoIOExceptions.InvalidLengthException;
            return byte.Parse(HexString, NumberStyles.HexNumber);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Converts a Hexadecimal string to a 16 bit signed integer.
    /// </summary>
    /// <param name="HexString"></param>
    /// <param name="EndianMode"></param>
    /// <returns>Short</returns>
    public static short HexStringToShort(string HexString, Endian EndianMode)
    {
        try
        {
            if (!HexString.IsHexString() || HexString.Length > 4 || HexString.Length < 4) 
                throw MojoIOExceptions.InvalidLengthException;
            if (EndianMode == Endian.Big)
                return (short.Parse(HexString, NumberStyles.HexNumber)).Reverse();
            else
                return short.Parse(HexString, NumberStyles.HexNumber);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Converts a Hexadecimal string to a 16 bit unsigned integer.
    /// </summary>
    /// <param name="HexString"></param>
    /// <param name="EndianMode"></param>
    /// <returns>UShort</returns>
    public static ushort HexStringToUShort(string HexString, Endian EndianMode)
    {
        try
        {
            if (!HexString.IsHexString() || HexString.Length > 4 || HexString.Length < 4) 
                throw MojoIOExceptions.InvalidLengthException;
            if (EndianMode == Endian.Big)
                return (ushort.Parse(HexString, NumberStyles.HexNumber)).Reverse();
            else
                return ushort.Parse(HexString, NumberStyles.HexNumber);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Converts a Hexadecimal string to a 32 bit signed integer.
    /// </summary>
    /// <param name="HexString"></param>
    /// <param name="EndianMode"></param>
    /// <returns>Int</returns>
    public static int HexStringToInt(string HexString, Endian EndianMode)
    {
        try
        {
            if (!HexString.IsHexString() || HexString.Length > 8 || HexString.Length < 8) 
                throw MojoIOExceptions.InvalidLengthException;
            if (EndianMode == Endian.Big)
                return (int.Parse(HexString, NumberStyles.HexNumber)).Reverse();
            else
                return int.Parse(HexString, NumberStyles.HexNumber);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Converts a Hexadecimal string to a 32 bit unsigned integer.
    /// </summary>
    /// <param name="HexString"></param>
    /// <param name="EndianMode"></param>
    /// <returns>UInt</returns>
    public static uint HexStringToUInt(string HexString, Endian EndianMode)
    {
        try
        {
            if (!HexString.IsHexString() || HexString.Length > 8 || HexString.Length < 8) 
                throw MojoIOExceptions.InvalidLengthException;
            if (EndianMode == Endian.Big)
                return (uint.Parse(HexString, NumberStyles.HexNumber)).Reverse();
            else
                return uint.Parse(HexString, NumberStyles.HexNumber);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Converts a Hexadecimal string to a 64 bit signed integer.
    /// </summary>
    /// <param name="HexString"></param>
    /// <param name="EndianMode"></param>
    /// <returns>Long</returns>
    public static long HexStringToLong(string HexString, Endian EndianMode)
    {
        try
        {
            if (!HexString.IsHexString() || HexString.Length > 16 || HexString.Length < 16) 
                throw MojoIOExceptions.InvalidLengthException;
            if (EndianMode == Endian.Big)
                return (long.Parse(HexString, NumberStyles.HexNumber)).Reverse();
            else
                return long.Parse(HexString, NumberStyles.HexNumber);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Converts a Hexadecimal string to a 64 bit unsigned integer.
    /// </summary>
    /// <param name="HexString"></param>
    /// <param name="EndianMode"></param>
    /// <returns>ULong</returns>
    public static ulong HexStringToULong(string HexString, Endian EndianMode)
    {
        try
        {
            if (!HexString.IsHexString() || HexString.Length > 16 || HexString.Length < 16) 
                throw MojoIOExceptions.InvalidLengthException;
            if (EndianMode == Endian.Big)
                return (ulong.Parse(HexString, NumberStyles.HexNumber)).Reverse();
            else
                return ulong.Parse(HexString, NumberStyles.HexNumber);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Converts a Hexadecimal string to a single precision floating point integer.
    /// </summary>
    /// <param name="HexString"></param>
    /// <param name="EndianMode"></param>
    /// <returns>Float</returns>
    public static float HexStringToSingle(string HexString, Endian EndianMode)
    {
        try
        {
            if (!HexString.IsHexString() || HexString.Length > 4 || HexString.Length < 4) 
                throw MojoIOExceptions.InvalidLengthException;
            if (EndianMode == Endian.Big)
                return (float.Parse(HexString, NumberStyles.HexNumber)).Reverse();
            else
                return float.Parse(HexString, NumberStyles.HexNumber);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Converts a Hexadecimal string to a double precision floating point integer.
    /// </summary>
    /// <param name="HexString"></param>
    /// <param name="EndianMode"></param>
    /// <returns>Double</returns>
    public static double HexStringToDouble(string HexString, Endian EndianMode)
    {
        try
        {
            if (!HexString.IsHexString() || HexString.Length > 8 || HexString.Length < 8) 
                throw MojoIOExceptions.InvalidLengthException;
            if (EndianMode == Endian.Big)
                return (double.Parse(HexString, NumberStyles.HexNumber)).Reverse();
            else
                return double.Parse(HexString, NumberStyles.HexNumber);
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Creates a byte[] of a given value of bytes and length.
    /// </summary>
    /// <param name="count"></param>
    /// <returns>Byte[]</returns>
    public static byte[] ByteBuffer(int count, byte value)
    {
        try
        {
            byte[] NewBuffer = new byte[count];
            for (int i = 0; i < count; i++)
                NewBuffer[i] = value;
            return NewBuffer;
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Searches a byte array in the current IO stream.
    /// </summary>
    /// <param name="ToSearch"></param>
    /// <param name="Start"></param>
    /// <param name="StopWhenFound"></param>
    /// <param name="mIO"></param>
    /// <returns>Long[]</returns>
    public static long[] SearchByteArray(byte[] ToSearch, long Start, bool StopWhenFound, MojosIO mIO)
    {
        try
        {
            List<long> ret = new List<long>();
            for (long i = Start; i < mIO.StreamLength - ToSearch.Length; i++)
            {
                byte[] tem = mIO.ReadBytes(ToSearch.Length);
                if (BitConverter.ToString(tem) == BitConverter.ToString(ToSearch))
                {
                    ret.Add(i);
                    if (StopWhenFound) break;
                }
            }
            return ret.ToArray();
        }
        catch (Exception ex)
        { throw ex; }
    }

    /// <summary>
    /// Searches ASCII characters in the current IO stream.
    /// </summary>
    /// <param name="ToSearch"></param>
    /// <param name="Start"></param>
    /// <param name="StopWhenFound"></param>
    /// <param name="mIO"></param>
    /// <returns>Long[]</returns>
    public static long[] SearchASCII(string ToSearch, long Start, bool StopWhenFound, MojosIO mIO)
    {
        return SearchByteArray(Encoding.ASCII.GetBytes(ToSearch), Start, StopWhenFound, mIO);
    }

    /// <summary>
    /// Searches a unicode string from the current IO stream.
    /// </summary>
    /// <param name="ToSearch"></param>
    /// <param name="Start"></param>
    /// <param name="StopWhenFound"></param>
    /// <param name="mIO"></param>
    /// <returns></returns>
    public static long[] SearchUnicodeString(string ToSearch, long Start, bool StopWhenFound, MojosIO mIO)
    {
        return SearchByteArray(Encoding.Unicode.GetBytes(ToSearch), Start, StopWhenFound, mIO);
    }

    /// <summary>
    /// Searches a Hexagdecimal string from the current IO stream.
    /// </summary>
    /// <param name="HexString"></param>
    /// <param name="Start"></param>
    /// <param name="StopWhenFound"></param>
    /// <param name="mIO"></param>
    /// <returns>Long[]</returns>
    public static long[] SearchHexString(string HexString, long Start, bool StopWhenFound, MojosIO mIO)
    {
        return SearchByteArray(HexStringToByteArray(HexString), Start, StopWhenFound, mIO);
    }

    /// <summary>
    /// Runs and XOR Aglorthim on the selected data.
    /// </summary>
    /// <param name="xData"></param>
    /// <param name="xKey"></param>
    /// <returns></returns>
    public static byte[] RunXORAlgorithm(byte[] xData, byte[] xKey)
    {
        int keybytes = 0;
        byte[] buffer = new byte[xData.Length];

        for (int i = 0; i < xData.Length; i++)
        {
            if (keybytes >= xKey.Length)
                keybytes = 0;

            buffer[i] = (byte)(xData[i] ^ xKey[keybytes++]);
        }

        return buffer;
    }

    /// <summary>
    /// Runs a Run Length Encoding Algorithim on the selceted data.
    /// </summary>
    /// <param name="xData"></param>
    /// <param name="Mode"></param>
    /// <returns></returns>
    public static byte[] RunRLEAlgorithim(byte[] xData, RLEMode Mode)
    {
        if (Mode == RLEMode.Encode)
        {
            List<byte> tem = new List<byte>();
            for (int i = 0; i < xData.Length; i++)
            {
                int rl = 1;
                while ((i + 1) < xData.Length && xData[i] == xData[i + 1])
                {
                    if (rl >= 255) break;
                    rl++; i++;
                }
                tem.Add((byte)rl);
                tem.Add(xData[i]);
            }
            return tem.ToArray();
        }
        else if (Mode == RLEMode.Decode)
        {
            List<byte> tem = new List<byte>();
            for (int i = 0; i < xData.Length; i += 2)
                for (int j = 0; j < xData[i]; j++)
                    tem.Add(xData[i + 1]);
            return tem.ToArray();
        }
        else throw MojoIOExceptions.InvalidInputException;
    }

    /// <summary>
    /// Turns a number to a binary string.
    /// </summary>
    /// <param name="x"></param>
    /// <returns></returns>
    public static string NumberToBinary(long x)
    {
        string ret = string.Empty;
        do
        {
            ret = ((x % 2 == 0) ? "0" : "1") + ret;
            x /= 2;
        }
        while (x != 0);
        for (int i = 0; i < (ret.Length % 8); i++)
            ret = "0" + ret;
        return ret;
    }

    public static int BinaryToInt32(string xIn, Endian xEndian)
    {
        if (!xIn.IsBinaryString()) 
            throw MojoIOExceptions.InvalidInputException;
        int factor = 1, dec = 0;

        foreach (char c in xIn)
        {
            dec += Convert.ToInt32(c.ToString()) * factor;
            factor *= 2;
        }

        if (xEndian == Endian.Big)
            return dec.Reverse();
        else
            return dec;
    }
}

internal static class DataTypeExtentions
{
    /// <summary>
    /// Converts a byte[] to a Hexadecimal string.
    /// </summary>
    /// <param name="x"></param>
    /// <returns>String</returns>
    public static string ToHexString(this byte[] x)
    {
        return BitConverter.ToString(x).Replace("-", "");
    }

    /// <summary>
    /// Reverses the endian of a 16 bit signed integer.
    /// </summary>
    /// <param name="x"></param>
    /// <returns>Short</returns>
    public static short Reverse(this short x)
    {
        byte[] buffer = BitConverter.GetBytes(x);
        return BitConverter.ToInt16(Functions.RevBytes(buffer), 0);
    }

    /// <summary>
    /// Reverses the endian of a 16 bit unsigned integer.
    /// </summary>
    /// <param name="x"></param>
    /// <returns>UShort</returns>
    public static ushort Reverse(this ushort x)
    {
        byte[] buffer = BitConverter.GetBytes(x);
        return BitConverter.ToUInt16(Functions.RevBytes(buffer), 0);
    }

    /// <summary>
    /// Reverses the endian of a 32 bit signed integer.
    /// </summary>
    /// <param name="x"></param>
    /// <returns>Int</returns>
    public static int Reverse(this int x)
    {
        byte[] buffer = BitConverter.GetBytes(x);
        return BitConverter.ToInt32(Functions.RevBytes(buffer), 0);
    }

    /// <summary>
    /// Reverses the endian of a 32 bit unsigned integer.
    /// </summary>
    /// <param name="x"></param>
    /// <returns>UInt</returns>
    public static uint Reverse(this uint x)
    {
        byte[] buffer = BitConverter.GetBytes(x);
        return BitConverter.ToUInt32(Functions.RevBytes(buffer), 0);
    }

    /// <summary>
    /// Reverses the endian of a 64 bit signed integer.
    /// </summary>
    /// <param name="x"></param>
    /// <returns>Long</returns>
    public static long Reverse(this long x)
    {
        byte[] buffer = BitConverter.GetBytes(x);
        return BitConverter.ToInt64(Functions.RevBytes(buffer), 0);
    }

    /// <summary>
    /// Reverses the endian of a 64 bit unsigned integer.
    /// </summary>
    /// <param name="x"></param>
    /// <returns>ULong</returns>
    public static ulong Reverse(this ulong x)
    {
        byte[] buffer = BitConverter.GetBytes(x);
        return BitConverter.ToUInt64(Functions.RevBytes(buffer), 0);
    }

    /// <summary>
    /// Reverses the endian of a single precision floating point integer.
    /// </summary>
    /// <param name="x"></param>
    /// <returns>ULong</returns>
    public static float Reverse(this float x)
    {
        byte[] buffer = BitConverter.GetBytes(x);
        return BitConverter.ToSingle(Functions.RevBytes(buffer), 0);
    }

    /// <summary>
    /// Reverses the endian of a double precision floating point integer.
    /// </summary>
    /// <param name="x"></param>
    /// <returns>Double</returns>
    public static double Reverse(this double x)
    {
        byte[] buffer = BitConverter.GetBytes(x);
        return BitConverter.ToDouble(Functions.RevBytes(buffer), 0);
    }

    /// <summary>
    /// Reverses the current byte array.
    /// </summary>
    /// <param name="x"></param>
    /// <returns>Byte[]</returns>
    public static byte[] Reverse(this byte[] x) { Array.Reverse(x); return x; }

    /// <summary>
    /// Returns whether or not a string is all hexadecimal characters.
    /// </summary>
    /// <param name="hex"></param>
    /// <returns>Bool</returns>
    public static bool IsHexString(this string x)
    {
        char[] HexTable = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
        bool validstring = false;

        foreach (char c in x.ToUpper())
        {
            foreach (char t in HexTable)
            {
                validstring = (c == t);
                if (validstring) break;
            }
            if (!validstring) return false;
        }
        return true;
    }

    /// <summary>
    /// Returns whether or not a string is all binary characters (1s and 0s).
    /// </summary>
    /// <param name="x"></param>
    /// <returns></returns>
    public static bool IsBinaryString(this string x)
    {
        for (int i = 0; i < x.Length; i++)
            if (x[i] != '1' && x[i] != '0') return false;
        return true;
    }
}

public class TempFile
{
    [CompilerGenerated]
    internal string xFilePath;
    [CompilerGenerated]
    public string FilePath { get { return xFilePath; } }

    public TempFile()
    {
        xFilePath = Path.GetTempFileName();
        File.Create(xFilePath);
    }

    public void Copy(string Destination) { File.Copy(xFilePath, Destination); }

    public void Move(string Destination) 
    { 
        File.Move(xFilePath, Destination);
        xFilePath = Destination;
    }

    public void Delete()
    {
        if (File.Exists(xFilePath))
            File.Delete(xFilePath);
    }
}

internal class MojoIOExceptions
{
    [CompilerGenerated]
    static Exception streamclosedex = new Exception("Current stream is closed. Reopen or declare a new instance of MojoIO.");
    [CompilerGenerated]
    static Exception setstreamfailex = new Exception("Failed to set stream.");
    [CompilerGenerated]
    static Exception invalidhexstringex = new Exception("Invalid hexadecimal string.");
    [CompilerGenerated]
    static Exception reopenstreamfailex = new Exception("Failed to re-open stream.");
    [CompilerGenerated]
    static Exception invalidstreampositionex = new Exception("Invalid stream position.\nNumber was out of range of stream length.");
    [CompilerGenerated]
    static Exception setstreamsizeex = new Exception("Failed to set stream size.");
    [CompilerGenerated]
    static Exception invalidsizespecifiedex = new Exception("Invalid size.");
    [CompilerGenerated]
    static Exception invalidinputex = new Exception("Invalid input.");

    public static Exception StreamClosedException
    {
        get { return streamclosedex; }
    }
    public static Exception SetStreamFailedException
    {
        get { return setstreamfailex; }
    }
    public static Exception InvalidHexadecimalStringException
    {
        get { return invalidhexstringex; }
    }
    public static Exception ReopenStreamFailException
    {
        get { return reopenstreamfailex; }
    }
    public static Exception InvalidStreamPosition
    {
        get { return invalidstreampositionex; }
    }
    public static Exception SetStreamSizeException
    {
        get { return setstreamsizeex; }
    }
    public static Exception InvalidLengthException { get { return invalidsizespecifiedex; } }
    public static Exception InvalidInputException { get { return invalidinputex; } }
}
