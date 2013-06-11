namespace SimpleDump360
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.DumpMemoryButton = new System.Windows.Forms.Button();
            this.MemoryAddressBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.LengthBox = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.connectionToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.connectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.disconnectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.quitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.valueFinderToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.peekPokeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.clearRecentConnectionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.freezeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.unfreezeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // DumpMemoryButton
            // 
            this.DumpMemoryButton.Location = new System.Drawing.Point(9, 117);
            this.DumpMemoryButton.Name = "DumpMemoryButton";
            this.DumpMemoryButton.Size = new System.Drawing.Size(231, 104);
            this.DumpMemoryButton.TabIndex = 0;
            this.DumpMemoryButton.Text = "Dump 360 Memory";
            this.DumpMemoryButton.UseVisualStyleBackColor = true;
            this.DumpMemoryButton.Click += new System.EventHandler(this.DumpMemoryButton_Click);
            // 
            // MemoryAddressBox
            // 
            this.MemoryAddressBox.Location = new System.Drawing.Point(9, 49);
            this.MemoryAddressBox.Name = "MemoryAddressBox";
            this.MemoryAddressBox.Size = new System.Drawing.Size(231, 20);
            this.MemoryAddressBox.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(85, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Memory Address";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 75);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(40, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Length";
            // 
            // LengthBox
            // 
            this.LengthBox.Location = new System.Drawing.Point(9, 88);
            this.LengthBox.Name = "LengthBox";
            this.LengthBox.Size = new System.Drawing.Size(231, 20);
            this.LengthBox.TabIndex = 4;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(284, 227);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(165, 24);
            this.button2.TabIndex = 7;
            this.button2.Text = "Dump Stack";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(284, 197);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(165, 24);
            this.button3.TabIndex = 8;
            this.button3.Text = "Dump Heap";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(284, 166);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(165, 24);
            this.button4.TabIndex = 9;
            this.button4.Text = "Dump Allocated Data";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(284, 136);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(165, 24);
            this.button5.TabIndex = 10;
            this.button5.Text = "Dump 360 Basefile";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(284, 106);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(165, 24);
            this.button6.TabIndex = 11;
            this.button6.Text = "Dump Xbox 360 RAM (512mb)";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.ForeColor = System.Drawing.Color.Red;
            this.label4.Location = new System.Drawing.Point(1, 238);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(166, 13);
            this.label4.TabIndex = 13;
            this.label4.Text = "Created by Mojobojo + Renegade";
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Location = new System.Drawing.Point(173, 236);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(105, 13);
            this.linkLabel1.TabIndex = 14;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "www.360haven.com";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(321, 33);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(87, 67);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 15;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.connectionToolStripMenuItem,
            this.toolsToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(458, 24);
            this.menuStrip1.TabIndex = 17;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // connectionToolStripMenuItem
            // 
            this.connectionToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.connectToolStripMenuItem,
            this.disconnectToolStripMenuItem,
            this.quitToolStripMenuItem});
            this.connectionToolStripMenuItem.Name = "connectionToolStripMenuItem";
            this.connectionToolStripMenuItem.Size = new System.Drawing.Size(81, 20);
            this.connectionToolStripMenuItem.Text = "Connection";
            // 
            // connectToolStripMenuItem
            // 
            this.connectToolStripMenuItem.Name = "connectToolStripMenuItem";
            this.connectToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.connectToolStripMenuItem.Text = "Connect";
            this.connectToolStripMenuItem.Click += new System.EventHandler(this.connectToolStripMenuItem_Click);
            // 
            // disconnectToolStripMenuItem
            // 
            this.disconnectToolStripMenuItem.Name = "disconnectToolStripMenuItem";
            this.disconnectToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.disconnectToolStripMenuItem.Text = "Disconnect";
            this.disconnectToolStripMenuItem.Click += new System.EventHandler(this.disconnectToolStripMenuItem_Click);
            // 
            // quitToolStripMenuItem
            // 
            this.quitToolStripMenuItem.Name = "quitToolStripMenuItem";
            this.quitToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.quitToolStripMenuItem.Text = "Quit";
            this.quitToolStripMenuItem.Click += new System.EventHandler(this.quitToolStripMenuItem_Click);
            // 
            // toolsToolStripMenuItem
            // 
            this.toolsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.valueFinderToolStripMenuItem,
            this.peekPokeToolStripMenuItem,
            this.freezeToolStripMenuItem,
            this.unfreezeToolStripMenuItem,
            this.clearRecentConnectionsToolStripMenuItem});
            this.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem";
            this.toolsToolStripMenuItem.Size = new System.Drawing.Size(48, 20);
            this.toolsToolStripMenuItem.Text = "Tools";
            // 
            // valueFinderToolStripMenuItem
            // 
            this.valueFinderToolStripMenuItem.Name = "valueFinderToolStripMenuItem";
            this.valueFinderToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
            this.valueFinderToolStripMenuItem.Text = "Value Finder";
            this.valueFinderToolStripMenuItem.Click += new System.EventHandler(this.valueFinderToolStripMenuItem_Click);
            // 
            // peekPokeToolStripMenuItem
            // 
            this.peekPokeToolStripMenuItem.Name = "peekPokeToolStripMenuItem";
            this.peekPokeToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
            this.peekPokeToolStripMenuItem.Text = "Poke";
            // 
            // clearRecentConnectionsToolStripMenuItem
            // 
            this.clearRecentConnectionsToolStripMenuItem.Name = "clearRecentConnectionsToolStripMenuItem";
            this.clearRecentConnectionsToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
            this.clearRecentConnectionsToolStripMenuItem.Text = "Clear Recent Connections";
            this.clearRecentConnectionsToolStripMenuItem.Click += new System.EventHandler(this.clearRecentConnectionsToolStripMenuItem_Click);
            // 
            // freezeToolStripMenuItem
            // 
            this.freezeToolStripMenuItem.Name = "freezeToolStripMenuItem";
            this.freezeToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
            this.freezeToolStripMenuItem.Text = "Freeze";
            this.freezeToolStripMenuItem.Click += new System.EventHandler(this.freezeToolStripMenuItem_Click);
            // 
            // unfreezeToolStripMenuItem
            // 
            this.unfreezeToolStripMenuItem.Name = "unfreezeToolStripMenuItem";
            this.unfreezeToolStripMenuItem.Size = new System.Drawing.Size(210, 22);
            this.unfreezeToolStripMenuItem.Text = "Unfreeze";
            this.unfreezeToolStripMenuItem.Click += new System.EventHandler(this.unfreezeToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(458, 257);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.LengthBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.MemoryAddressBox);
            this.Controls.Add(this.DumpMemoryButton);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "SimpleDump360 - 360Haven";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button DumpMemoryButton;
        private System.Windows.Forms.TextBox MemoryAddressBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox LengthBox;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem connectionToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem connectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem disconnectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem quitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem valueFinderToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem peekPokeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem clearRecentConnectionsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem freezeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem unfreezeToolStripMenuItem;
    }
}

