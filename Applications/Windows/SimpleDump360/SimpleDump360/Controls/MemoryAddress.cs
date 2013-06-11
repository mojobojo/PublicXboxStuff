using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using MojosLibs.XBDMExtender;

namespace SimpleDump360
{
    public partial class MemoryAddress : UserControl
    {
        public XBDM XboxDebugCommunicator;
        public uint Address;

        public MemoryAddress()
        {
            InitializeComponent();
        }

        private void MemoryAddress_Load(object sender, EventArgs e)
        {
            this.MemoryAddressLabel.Text = "0x" + Address.ToString("X8");
        }

        private void ChangeValueButton_Click(object sender, EventArgs e)
        {

        }

        private void HexViewButton_Click(object sender, EventArgs e)
        {

        }
    }
}
