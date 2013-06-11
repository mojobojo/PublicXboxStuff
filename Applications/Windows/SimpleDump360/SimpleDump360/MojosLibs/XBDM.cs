using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Net;
using System.Net.Sockets;

namespace MojosLibs.XBDMExtender
{
    // Written with what I understand about the Xbox Debug Manager
    public class XBDM
    {
        // Our TCP connection
        private TcpClient client;

        // Our progress callback
        public delegate void DumpProgressCallback(int Percentage);

        // Are we connected?
        public bool Connected;

        public XBDM(string IPAddress)
        {
            // Init and connect
            client = new TcpClient();
            client.Connect(IPAddress, 730);

            // First thing that XBDM does is send a packet to us when we connect

            // Max packet size is 1026
            byte[] Packet = new byte[1026];
            client.Client.Receive(Packet);

            if (Encoding.ASCII.GetString(Packet).Replace("\0", "").Substring(0, 3) != "201")
                throw new Exception("XBDM did not send connect message");

            Connected = true;
        }

        public void Close()
        {
            SendCommand("bye");
            client.Close();

            Connected = false;
        }

        public void SendCommand(string Command)
        {
            // Send a text command. Always have \r\n at the end of commands
            client.Client.Send(Encoding.ASCII.GetBytes(Command + "\r\n"));
        }

        public void WriteMemory(uint Address, byte[] Data)
        {
            // Send the setmem command
            client.Client.Send(Encoding.ASCII.GetBytes(string.Format("SETMEM ADDR=0x{0} DATA={1}\r\n", Address.ToString("X2"), BitConverter.ToString(Data).Replace("-", ""))));

            // Check to see our response
            byte[] Packet = new byte[1026];
            client.Client.Receive(Packet);

            if (Encoding.ASCII.GetString(Packet).Replace("\0", "").Substring(0, 11) == "0 bytes set")
                throw new Exception("A problem occurred while writing bytes. 0 bytes set");
        }

        public byte[] ReadMemory(uint Address, uint Length, DumpProgressCallback ProgressCallback)
        {
            List<byte> ReturnData = new List<byte>();
            byte[] Packet = new byte[1026];
            byte[] PacketData = new byte[1024];
            int ProgressPercentage = 0;
            
            // Send getmemex command.
            client.Client.Send(Encoding.ASCII.GetBytes(string.Format("GETMEMEX ADDR=0x{0} LENGTH=0x{1}\r\n", Address.ToString("X2"), Length.ToString("X2"))));

            // Receieve the 203 response to verify we are going to recieve raw data in packets
            client.Client.Receive(Packet);

            if (Encoding.ASCII.GetString(Packet).Replace("\0", "").Substring(0, 3) != "203")
                throw new Exception("GETMEMEX 203 response not recieved. Cannot read memory.");

            // It will return with data in 1026 byte size packets, first two bytes I think are flags and the rest is the data
            // Length / 1024 will get how many packets there are to recieve
            for (uint i = 0; i < Length / 1024; i++)
            {
                client.Client.Receive(Packet);

                // Store the data minus the first two bytes
                // This was a cheap way of removing the 2 byte header
                Array.Copy(Packet, 2, PacketData, 0, 1024);
                ReturnData.AddRange(PacketData);

                // Update the progress if we have a callback
                if (ProgressCallback != null)
                {
                    ProgressCallback((int)Math.Round((((double)i * 1024.0) / (double)Length) * 100));
                }
            }

            // Get the remainder of Length / 1024 to see if we are recieving extra.
            uint Remainder = (Length % 1024);

            // If there is a remainder, read it
            if (Remainder > 0)
            {
                client.Client.Receive(Packet);

                // Store the data minus the first two bytes
                // This was a cheap way of removing the 2 byte header
                Array.Copy(Packet, 2, PacketData, 0, 1024);
                ReturnData.AddRange(PacketData);
            }

            // Update to finished
            if (ProgressCallback != null)
            {
                ProgressCallback(100);
            }

            return ReturnData.ToArray();
        }

        public void DumpMemory(uint Address, uint Length, string FileName, DumpProgressCallback ProgressCallback)
        {
            byte[] Packet = new byte[1026];
            int ProgressPercentage = 0;

            // Send getmemex command.
            client.Client.Send(Encoding.ASCII.GetBytes(string.Format("GETMEMEX ADDR=0x{0} LENGTH=0x{1}\r\n", Address.ToString("X2"), Length.ToString("X2"))));

            // Receieve the 203 response to verify we are going to recieve raw data in packets
            client.Client.Receive(Packet);

            if (Encoding.ASCII.GetString(Packet).Replace("\0", "").Substring(0, 3) != "203")
                throw new Exception("GETMEMEX 203 response not recieved. Cannot read memory.");

            FileStream outfile = new FileStream(FileName, FileMode.Create, FileAccess.ReadWrite, FileShare.ReadWrite);

            // It will return with data in 1026 byte size packets, first two bytes I think are flags and the rest is the data
            // Length / 1024 will get how many packets there are to recieve
            for (uint i = 0; i < Length / 1024; i++)
            {
                client.Client.Receive(Packet);

                // Write the data minus the first two bytes
                outfile.Write(Packet, 2, 1024);

                // Update the progress if we have a callback
                if (ProgressCallback != null)
                {
                    ProgressCallback((int)Math.Round((((double)i * 1024.0) / (double)Length) * 100));
                }
            }

            // Get the remainder of Length / 1024 to see if we are recieving extra.
            uint Remainder = (Length % 1024);

            // If there is a remainder, read it
            if (Remainder > 0)
            {
                client.Client.Receive(Packet);

                // Write the data minus the first two bytes
                outfile.Write(Packet, 2, 1024);
            }

            // Update to finished
            if (ProgressCallback != null)
            {
                ProgressCallback(100);
            }

            // Flush and close the file
            outfile.Flush();
            outfile.Close();
        }
    }
}
