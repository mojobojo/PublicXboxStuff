using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using MojosLibs.XBDMExtender;

namespace SimpleDump360
{
    public partial class HexView : Form
    {
        public XBDM XboxDebugCommunicator;
        public uint StartAddress = 0x82000000;
        public uint CurrentPosition;

        public HexView()
        {
            InitializeComponent();
        }

        void LoadDataToBox()
        {
            byte[] Buf = XboxDebugCommunicator.ReadMemory(CurrentPosition, 1024, null);

            HexDataBox.Clear();
            for (int i = 0; i < 1024; i += 16)
            {
                string LineData = (CurrentPosition + i).ToString("X2") + ": ";
                for (int x = 0; x < 16; x++)
                {
                    LineData += Buf[i + x].ToString("X2") + " ";
                }

                LineData += "|";

                for (int x = 0; x < 16; x++)
                {
                    byte b = Buf[i + x];

                    if (b >= 0x20 && b <= 0x7E && b != 0x5E)
                    {
                        LineData += (char)b + " ";
                    }
                    else
                    {
                        LineData += ". ";
                    }
                }

                HexDataBox.Text += LineData + Environment.NewLine;
            }
        }

        private void HexView_Load(object sender, EventArgs e)
        {
            CurrentPosition = StartAddress;

            PositionBox.Text = CurrentPosition.ToString("X2");

            LoadDataToBox();
        }

        private void NextButton_Click(object sender, EventArgs e)
        {
            CurrentPosition += 1024;
            LoadDataToBox();

            PositionBox.Text = CurrentPosition.ToString("X2");
        }

        private void LastButton_Click(object sender, EventArgs e)
        {
            CurrentPosition -= 1024;
            LoadDataToBox();

            PositionBox.Text = CurrentPosition.ToString("X2");
        }

        private void SeekButton_Click(object sender, EventArgs e)
        {
            PositionBox.Text.Replace("0x", "");
            CurrentPosition = uint.Parse(PositionBox.Text, System.Globalization.NumberStyles.HexNumber);
            LoadDataToBox();
        }

        private void RefreshButton_Click(object sender, EventArgs e)
        {
            LoadDataToBox();
        }
    }
}
