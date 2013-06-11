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
using System.Threading;

namespace SimpleDump360
{
    public enum ProgressWindowType
    {
        Dumping, 
        Scanning
    }

    public partial class ProgressWindow : Form
    {
        public XBDM XboxDebugCommunicator;
        public string IPAddress;
        public uint Address;
        public uint Length;
        public ProgressWindowType ProgressType;
        public byte[] SearchingBuffer;
        public byte[] ToSearch;
        public List<uint> DataFound;
        public string OutDumpFileName;

        public ProgressWindow()
        {
            InitializeComponent();
        }

        private delegate void UpdatePBDel(int value);
        private delegate void CloseDel();

        private void UpdateProgressBar(int value)
        {
            if (progressBar1.InvokeRequired)
            {
                progressBar1.Invoke(new UpdatePBDel(UpdateProgressBar), new object[] { value });
            }

            progressBar1.Value = value;
        }

        private void DumpThreadFunc(object o)
        {
            XboxDebugCommunicator.DumpMemory(Address, Length, (string)o, UpdateProgressBar);

            this.Invoke(new CloseDel(this.Close), null);
        }

        private void SearchThreadFunc()
        {
            DataFound = BinaryScanner.ByteArrayFindAll(SearchingBuffer, ToSearch, UpdateProgressBar);

            this.Invoke(new CloseDel(this.Close), null);
        }

        private void ProgressWindow_Load(object sender, EventArgs e)
        {
            if (ProgressType == ProgressWindowType.Dumping)
            {
                if (OutDumpFileName == null || OutDumpFileName == "")
                {
                    SaveFileDialog sfd = new SaveFileDialog();

                    if (sfd.ShowDialog() == DialogResult.OK)
                    {
                        Thread t = new Thread(new ParameterizedThreadStart(DumpThreadFunc));

                        t.Start(sfd.FileName);
                    }
                }
                else
                {
                    Thread t = new Thread(new ParameterizedThreadStart(DumpThreadFunc));

                    t.Start(OutDumpFileName);
                }
            }
            else if (ProgressType == ProgressWindowType.Scanning)
            {
                Thread t = new Thread(SearchThreadFunc);
                t.Start();
            }
        }
            
    }
}
