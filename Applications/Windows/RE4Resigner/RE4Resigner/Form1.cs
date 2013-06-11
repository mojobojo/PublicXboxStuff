using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace RE4Resigner
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private uint BSwapUint(uint num)
        {
            return
                (uint)((num & 0x000000FF) << 24) |
                (uint)((num & 0x0000FF00) << 8) |
                (uint)((num & 0x00FF0000) >> 8) |
                (uint)((num & 0xFF000000) >> 24)
                ;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                FileStream stream = new FileStream(ofd.FileName, FileMode.Open, FileAccess.ReadWrite, FileShare.ReadWrite);
                BinaryReader reader = new BinaryReader(stream);
                BinaryWriter writer = new BinaryWriter(stream);
                RE4Checksum.RE4Checksum re4c = new RE4Checksum.RE4Checksum();

                // Data checked is at 0x1EE4 for length of 0x1FC. This MUST be computed first!
                reader.BaseStream.Position = 0x1EE4;
                uint CRC = re4c.Compute(reader.ReadBytes(0x1FC), 0x1FC);

                // First checsum location is at 0x1EE0
                writer.BaseStream.Position = 0x1EE0;

                // Write as big endian
                writer.Write(BitConverter.GetBytes(BSwapUint(CRC)));
                writer.Flush();

                // Second part of the data checked is at 0x1EE0 for length of 0xCAF8
                reader.BaseStream.Position = 0x1EE0;
                CRC = re4c.Compute(reader.ReadBytes(0xCAF8), 0xCAF8);

                // Second checksum location is at 0xE9D8
                writer.BaseStream.Position = 0xE9D8;


                // Write as big endian
                writer.Write(BitConverter.GetBytes(BSwapUint(CRC)));
                writer.Flush();

                // Third checksum location is at 0xFFA90 (unchecked by the game but doing this for keeping save integrity)
                writer.BaseStream.Position = 0xFFA90;

                // Write as big endian
                writer.Write(BitConverter.GetBytes(BSwapUint(CRC)));
                writer.Flush();

                stream.Close();

                MessageBox.Show("Resign Completed!");
            }
        }
    }
}
