using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using EZIO.IO;
using System.IO;

namespace NG2Resigner
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                FileStream stream = new FileStream(ofd.FileName, FileMode.Open);
                EndianReader reader = new EndianReader(stream, EndianType.BigEndian);
                EndianWriter writer = new EndianWriter(stream, EndianType.BigEndian);

                int CSum = 0;
                reader.BaseStream.Position = 0xD000;
                for (int i = 0; i < 0x768; i += 4)
                    CSum += reader.ReadInt32();

                writer.Write(CSum);
                writer.Flush();
                writer.Close();
                reader.Close();
                MessageBox.Show("New Checksum: " + CSum.ToString("X2"), "Done!");
            }
        }
    }
}
