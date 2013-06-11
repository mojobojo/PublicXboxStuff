using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using MojosLibs.XBDMExtender;
using MojosLibs.Binary;
using System.IO;

namespace SimpleDump360
{
    public partial class ValueFinder : Form
    {
        public XBDM XboxDebugCommunicator;
        private List<uint> LastScan;

        public ValueFinder()
        {
            InitializeComponent();
        }

        

        byte[] ConvertValueFromDataBox()
        {
            // Right now only supporting hex
            return BinaryConversions.HexStringToByteArray(ValueToSearchTextBox.Text);
        }

        private void hexViewToolStripMenuItem_Click(object sender, EventArgs e)
        {
            HexView hv = new HexView();

            hv.XboxDebugCommunicator = this.XboxDebugCommunicator;
            hv.StartAddress = 0x82000000;

            hv.ShowDialog();
        }

        private void ValueFinder_Load(object sender, EventArgs e)
        {
            ScanTypeCBox.SelectedIndex = 0;
            ValueTypeCBox.SelectedIndex = 0;

            HexCheckBox.Checked = true;
            HexCheckBox.Enabled = false;
        }

        private void HexCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (HexCheckBox.Checked)
            {
                ScanTypeCBox.Enabled = false;
                ValueTypeCBox.Enabled = false;
            }
            else
            {
                ScanTypeCBox.Enabled = true;
                ValueTypeCBox.Enabled = true;
            }
        }

        private void freezeXboxToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Send the freeze command
            XboxDebugCommunicator.SendCommand("stop");
        }

        private void unfreezeXboxToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Send the unfreeze command
            XboxDebugCommunicator.SendCommand("go");
        }

        private void NewScanButton_Click(object sender, EventArgs e)
        {
            // Clear all the controls from the panel
            FoundDataPanel.Controls.Clear();

            // Format the dump base file name
            string OutFileName = Application.StartupPath + "\\Dumps\\dmp_";

            // Check to see if we have a dumps directory, if not, make one
            if (!Directory.Exists(Application.StartupPath + "\\Dumps"))
                Directory.CreateDirectory(Application.StartupPath + "\\Dumps");

            // Remove all of the files in the directory
            foreach (string fi in Directory.GetFiles(Application.StartupPath + "\\Dumps"))
            {
                File.Delete(fi);
            }

            
            // Check for the very last dump made
            int i;
            for (i = 0; ; i++)
            {
                if (!File.Exists(OutFileName + i.ToString()))
                    break;
            }

            // Create a new progress bar window
            ProgressWindow dmpw = new ProgressWindow();

            // Dump to a file
            dmpw.XboxDebugCommunicator = this.XboxDebugCommunicator;
            dmpw.Address = Convert.ToUInt32(StartScanCBox.Text, 16);
            dmpw.Length = Convert.ToUInt32(StopScanTextBox.Text, 16);

            dmpw.ProgressType = ProgressWindowType.Dumping;

            dmpw.Text = "Dumping, Please Wait";

            dmpw.OutDumpFileName = OutFileName + i.ToString();

            dmpw.ShowDialog();
            
            // Search for the data in the file
            dmpw.SearchingBuffer = File.ReadAllBytes(OutFileName + i.ToString());
            dmpw.ToSearch = ConvertValueFromDataBox();

            dmpw.ProgressType = ProgressWindowType.Scanning;

            dmpw.Text = "Searching, Please Wait";

            dmpw.ShowDialog();

            LastScan = dmpw.DataFound;

            if (LastScan.Count > 1000)
            {
                MessageBox.Show("Too many values, do another scan to narrow it down", "Warning");
                return;
            }

            // Put all the found values in the panel provided there is less than 1000
            foreach (uint FoundValues in dmpw.DataFound)
            {
                MemoryAddress m = new MemoryAddress();
                m.Address = Convert.ToUInt32(StartScanCBox.Text, 16) + FoundValues;

                FoundDataPanel.Controls.Add(m);
            }

            // Dispose it or we freeze next time we make a dump
            dmpw.Dispose();
        }
    }
}
