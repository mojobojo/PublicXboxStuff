using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;
using System.Runtime.InteropServices;
using MojosLibs.XBDMExtender;
using System.IO;
using System.Net;
using System.Net.Sockets;

namespace SimpleDump360
{
    public partial class ConnectDialog : Form
    {
        public string OutIPAddress;

        IniFile ini;

        public ConnectDialog()
        {
            InitializeComponent();
        }

        private void ConnectBtn_Click(object sender, EventArgs e)
        {
            IPAddress ipaddr;

            if (!System.Net.IPAddress.TryParse(IPAddressBox.Text, out ipaddr))
            {
                MessageBox.Show("Invalid IP Address");
                return;
            }

            int i = 0;

            while (true)
            {
                string str = ini.IniReadValue("Recent", i.ToString());

                if (str == "")
                    break;

                i++;
            }

            ini.IniWriteValue("Recent", i.ToString(), ipaddr.ToString());

            OutIPAddress = ipaddr.ToString();
            this.Close();
        }

        private void ConnectDialog_Load(object sender, EventArgs e)
        {
            if (!File.Exists(Application.StartupPath + "\\Recent.ini"))
            {
                FileStream fs = File.Create(Application.StartupPath + "\\Recent.ini");
                fs.Close();
            }

            ini = new IniFile(Application.StartupPath + "\\Recent.ini");

            int i = 0;

            while (true)
            {
                string str = ini.IniReadValue("Recent", i.ToString());

                if (str == "")
                    break;

                RecentListBox.Items.Add(str);

                i++;
            }
        }

        private void RecentListBox_DoubleClick(object sender, EventArgs e)
        {
            if (RecentListBox.SelectedItem != null)
            {
                OutIPAddress = RecentListBox.SelectedItem.ToString();
                this.Close();
            }
        }
    }

    public class IniFile
    {
        public string path;

        [DllImport("kernel32")]
        private static extern long WritePrivateProfileString(string section,
            string key, string val, string filePath);
        [DllImport("kernel32")]
        private static extern int GetPrivateProfileString(string section,
                 string key, string def, StringBuilder retVal,
            int size, string filePath);

        /// <summary>

        /// INIFile Constructor.

        /// </summary>

        /// <PARAM name="INIPath"></PARAM>

        public IniFile(string INIPath)
        {
            path = INIPath;
        }
        /// <summary>

        /// Write Data to the INI File

        /// </summary>

        /// <PARAM name="Section"></PARAM>

        /// Section name

        /// <PARAM name="Key"></PARAM>

        /// Key Name

        /// <PARAM name="Value"></PARAM>

        /// Value Name

        public void IniWriteValue(string Section, string Key, string Value)
        {
            WritePrivateProfileString(Section, Key, Value, this.path);
        }

        /// <summary>

        /// Read Data Value From the Ini File

        /// </summary>

        /// <PARAM name="Section"></PARAM>

        /// <PARAM name="Key"></PARAM>

        /// <PARAM name="Path"></PARAM>

        /// <returns></returns>

        public string IniReadValue(string Section, string Key)
        {
            StringBuilder temp = new StringBuilder(255);
            int i = GetPrivateProfileString(Section, Key, "", temp,
                                            255, this.path);
            return temp.ToString();

        }
    }
}
