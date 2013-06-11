namespace Coalesced_Tool
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.BackupXEXCheckbox = new System.Windows.Forms.CheckBox();
            this.BackupX360TOCCheckbox = new System.Windows.Forms.CheckBox();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.FolderPathBrowser = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.ApplyXEXPatchButton = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.PackCoalescedButton = new System.Windows.Forms.Button();
            this.UnpackCoalescedButton = new System.Windows.Forms.Button();
            this.LogBox = new System.Windows.Forms.ListBox();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.clearLogToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.menuStrip1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.SuspendLayout();
            // 
            // BackupXEXCheckbox
            // 
            this.BackupXEXCheckbox.AutoSize = true;
            this.BackupXEXCheckbox.Location = new System.Drawing.Point(6, 19);
            this.BackupXEXCheckbox.Name = "BackupXEXCheckbox";
            this.BackupXEXCheckbox.Size = new System.Drawing.Size(47, 17);
            this.BackupXEXCheckbox.TabIndex = 5;
            this.BackupXEXCheckbox.Text = "XEX";
            this.BackupXEXCheckbox.UseVisualStyleBackColor = true;
            // 
            // BackupX360TOCCheckbox
            // 
            this.BackupX360TOCCheckbox.AutoSize = true;
            this.BackupX360TOCCheckbox.Location = new System.Drawing.Point(6, 42);
            this.BackupX360TOCCheckbox.Name = "BackupX360TOCCheckbox";
            this.BackupX360TOCCheckbox.Size = new System.Drawing.Size(104, 17);
            this.BackupX360TOCCheckbox.TabIndex = 7;
            this.BackupX360TOCCheckbox.Text = "Xbox360TOC.txt";
            this.BackupX360TOCCheckbox.UseVisualStyleBackColor = true;
            // 
            // statusStrip1
            // 
            this.statusStrip1.Location = new System.Drawing.Point(0, 244);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(403, 22);
            this.statusStrip1.TabIndex = 10;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(403, 24);
            this.menuStrip1.TabIndex = 11;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(52, 20);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Controls.Add(this.FolderPathBrowser);
            this.groupBox1.Location = new System.Drawing.Point(5, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(388, 42);
            this.groupBox1.TabIndex = 12;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Folder Path";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(4, 15);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(296, 20);
            this.textBox1.TabIndex = 1;
            // 
            // FolderPathBrowser
            // 
            this.FolderPathBrowser.Location = new System.Drawing.Point(306, 12);
            this.FolderPathBrowser.Name = "FolderPathBrowser";
            this.FolderPathBrowser.Size = new System.Drawing.Size(75, 23);
            this.FolderPathBrowser.TabIndex = 0;
            this.FolderPathBrowser.Text = "Browse";
            this.FolderPathBrowser.UseVisualStyleBackColor = true;
            this.FolderPathBrowser.Click += new System.EventHandler(this.FolderPathBrowser_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.BackupXEXCheckbox);
            this.groupBox2.Controls.Add(this.BackupX360TOCCheckbox);
            this.groupBox2.Location = new System.Drawing.Point(5, 51);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(116, 67);
            this.groupBox2.TabIndex = 13;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Backup Options";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.ApplyXEXPatchButton);
            this.groupBox3.Location = new System.Drawing.Point(161, 51);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(95, 47);
            this.groupBox3.TabIndex = 14;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "XEX Patching";
            // 
            // ApplyXEXPatchButton
            // 
            this.ApplyXEXPatchButton.Location = new System.Drawing.Point(14, 15);
            this.ApplyXEXPatchButton.Name = "ApplyXEXPatchButton";
            this.ApplyXEXPatchButton.Size = new System.Drawing.Size(68, 23);
            this.ApplyXEXPatchButton.TabIndex = 1;
            this.ApplyXEXPatchButton.Text = "Apply";
            this.ApplyXEXPatchButton.UseVisualStyleBackColor = true;
            this.ApplyXEXPatchButton.Click += new System.EventHandler(this.ApplyXEXPatchButton_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.PackCoalescedButton);
            this.groupBox4.Controls.Add(this.UnpackCoalescedButton);
            this.groupBox4.Location = new System.Drawing.Point(312, 51);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(81, 73);
            this.groupBox4.TabIndex = 15;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Coalesced";
            // 
            // PackCoalescedButton
            // 
            this.PackCoalescedButton.Location = new System.Drawing.Point(6, 15);
            this.PackCoalescedButton.Name = "PackCoalescedButton";
            this.PackCoalescedButton.Size = new System.Drawing.Size(68, 23);
            this.PackCoalescedButton.TabIndex = 2;
            this.PackCoalescedButton.Text = "Pack";
            this.PackCoalescedButton.UseVisualStyleBackColor = true;
            this.PackCoalescedButton.Click += new System.EventHandler(this.PackCoalescedButton_Click);
            // 
            // UnpackCoalescedButton
            // 
            this.UnpackCoalescedButton.Location = new System.Drawing.Point(6, 44);
            this.UnpackCoalescedButton.Name = "UnpackCoalescedButton";
            this.UnpackCoalescedButton.Size = new System.Drawing.Size(68, 23);
            this.UnpackCoalescedButton.TabIndex = 1;
            this.UnpackCoalescedButton.Text = "Unpack";
            this.UnpackCoalescedButton.UseVisualStyleBackColor = true;
            this.UnpackCoalescedButton.Click += new System.EventHandler(this.UnpackCoalescedButton_Click);
            // 
            // LogBox
            // 
            this.LogBox.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.LogBox.ContextMenuStrip = this.contextMenuStrip1;
            this.LogBox.Dock = System.Windows.Forms.DockStyle.Top;
            this.LogBox.FormattingEnabled = true;
            this.LogBox.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.LogBox.Location = new System.Drawing.Point(0, 0);
            this.LogBox.Name = "LogBox";
            this.LogBox.Size = new System.Drawing.Size(401, 78);
            this.LogBox.TabIndex = 17;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.clearLogToolStripMenuItem,
            this.saveToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(125, 48);
            // 
            // clearLogToolStripMenuItem
            // 
            this.clearLogToolStripMenuItem.Name = "clearLogToolStripMenuItem";
            this.clearLogToolStripMenuItem.Size = new System.Drawing.Size(124, 22);
            this.clearLogToolStripMenuItem.Text = "Clear Log";
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(124, 22);
            this.saveToolStripMenuItem.Text = "Save Log";
            // 
            // splitContainer1
            // 
            this.splitContainer1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 24);
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.groupBox1);
            this.splitContainer1.Panel1.Controls.Add(this.groupBox2);
            this.splitContainer1.Panel1.Controls.Add(this.groupBox4);
            this.splitContainer1.Panel1.Controls.Add(this.groupBox3);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.LogBox);
            this.splitContainer1.Size = new System.Drawing.Size(403, 220);
            this.splitContainer1.SplitterDistance = 137;
            this.splitContainer1.TabIndex = 18;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(403, 266);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Mirrors Edge Coalesced Tool BETA";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.contextMenuStrip1.ResumeLayout(false);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox BackupXEXCheckbox;
        private System.Windows.Forms.CheckBox BackupX360TOCCheckbox;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button FolderPathBrowser;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button ApplyXEXPatchButton;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button PackCoalescedButton;
        private System.Windows.Forms.Button UnpackCoalescedButton;
        private System.Windows.Forms.ListBox LogBox;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem clearLogToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
    }
}

