using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Diagnostics;
using MojosLibs.XBDMExtender;

namespace SimpleDump360
{
    public partial class Form1 : Form
    {
        private XBDM XboxDebugCommunicator;

        public Form1()
        {
            InitializeComponent();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            MemoryAddressBox.Text = "0xC0000000";
            LengthBox.Text = "0x1FFF0FFF";
        }

        private void button5_Click(object sender, EventArgs e)
        {
            MemoryAddressBox.Text = "0x82000000";
            LengthBox.Text = "0x5000000";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            MemoryAddressBox.Text = "0x40000000";
            LengthBox.Text = "0x5000000";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            MemoryAddressBox.Text = "0x30000000";
            LengthBox.Text = "0x5000000";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MemoryAddressBox.Text = "0x70000000";
            LengthBox.Text = "0x5000000";
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Process.Start("www.360haven.com");
        }

        private void DumpMemoryButton_Click(object sender, EventArgs e)
        {
            try
            {
                ProgressWindow dmpw = new ProgressWindow();

                dmpw.XboxDebugCommunicator = this.XboxDebugCommunicator;
                dmpw.Address = Convert.ToUInt32(MemoryAddressBox.Text, 16);
                dmpw.Length = Convert.ToUInt32(LengthBox.Text, 16);

                dmpw.ProgressType = ProgressWindowType.Dumping;

                dmpw.Text = "Dumping, Please Wait";

                dmpw.ShowDialog();

                dmpw.Dispose();
            }
            catch (Exception x)
            {
                MessageBox.Show(x.Message, "Error");
            }
        }

        private void connectToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                ConnectDialog cdlg = new ConnectDialog();

                cdlg.ShowDialog();

                if (cdlg.OutIPAddress == "" || cdlg.OutIPAddress == null)
                    return;

                XboxDebugCommunicator = new XBDM(cdlg.OutIPAddress);

                MessageBox.Show("Connected! Your 360 is ready to expose itself for a little poking action.", "Success!", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
            }
            catch (Exception x)
            {
                MessageBox.Show(x.Message, "Error");
            }
        }

        private void disconnectToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                XboxDebugCommunicator.Close();
            }
            catch (Exception x)
            {
                MessageBox.Show(x.Message, "Error");
            }
        }

        private void quitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                XboxDebugCommunicator.Close();
            }
            catch
            {
            }
            Application.Exit();
        }

        private void clearRecentConnectionsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (File.Exists(Application.StartupPath + "\\Recent.ini"))
                {
                    File.Delete(Application.StartupPath + "\\Recent.ini");

                    FileStream fs = File.Create(Application.StartupPath + "\\Recent.ini");
                    fs.Close();
                }
            }
            catch (Exception x)
            {
                MessageBox.Show(x.Message, "Error");
            }
        }

        private void valueFinderToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                ValueFinder vf = new ValueFinder();

                vf.XboxDebugCommunicator = this.XboxDebugCommunicator;

                vf.ShowDialog();
            }
            catch (Exception x)
            {
                MessageBox.Show(x.Message, "Error");
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            FuckingUnicorns fuck = new FuckingUnicorns();
            fuck.ShowDialog();
        }

        private void freezeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            XboxDebugCommunicator.SendCommand("stop");
        }

        private void unfreezeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            XboxDebugCommunicator.SendCommand("go");
        }
    }
}
