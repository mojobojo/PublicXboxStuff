namespace SimpleDump360
{
    partial class ValueFinder
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
            this.NextScanButton = new System.Windows.Forms.Button();
            this.NewScanButton = new System.Windows.Forms.Button();
            this.HexCheckBox = new System.Windows.Forms.CheckBox();
            this.label10 = new System.Windows.Forms.Label();
            this.ValueToSearchTextBox = new System.Windows.Forms.TextBox();
            this.StopScanTextBox = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.ScanTypeCBox = new System.Windows.Forms.ComboBox();
            this.StartScanCBox = new System.Windows.Forms.ComboBox();
            this.Scanning = new System.Windows.Forms.GroupBox();
            this.ValueTypeCBox = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.hexViewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.freezeXboxToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.unfreezeXboxToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.screenshotToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.FoundDataPanel = new System.Windows.Forms.FlowLayoutPanel();
            this.Scanning.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // NextScanButton
            // 
            this.NextScanButton.Location = new System.Drawing.Point(364, 17);
            this.NextScanButton.Name = "NextScanButton";
            this.NextScanButton.Size = new System.Drawing.Size(80, 127);
            this.NextScanButton.TabIndex = 18;
            this.NextScanButton.Text = "Next Scan";
            this.NextScanButton.UseVisualStyleBackColor = true;
            // 
            // NewScanButton
            // 
            this.NewScanButton.Location = new System.Drawing.Point(279, 17);
            this.NewScanButton.Name = "NewScanButton";
            this.NewScanButton.Size = new System.Drawing.Size(80, 127);
            this.NewScanButton.TabIndex = 17;
            this.NewScanButton.Text = "Begin Scan";
            this.NewScanButton.UseVisualStyleBackColor = true;
            this.NewScanButton.Click += new System.EventHandler(this.NewScanButton_Click);
            // 
            // HexCheckBox
            // 
            this.HexCheckBox.AutoSize = true;
            this.HexCheckBox.Location = new System.Drawing.Point(21, 19);
            this.HexCheckBox.Name = "HexCheckBox";
            this.HexCheckBox.Size = new System.Drawing.Size(45, 17);
            this.HexCheckBox.TabIndex = 6;
            this.HexCheckBox.Text = "Hex";
            this.HexCheckBox.UseVisualStyleBackColor = true;
            this.HexCheckBox.CheckedChanged += new System.EventHandler(this.HexCheckBox_CheckedChanged);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(18, 127);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(27, 13);
            this.label10.TabIndex = 15;
            this.label10.Text = "Size";
            // 
            // ValueToSearchTextBox
            // 
            this.ValueToSearchTextBox.Location = new System.Drawing.Point(87, 17);
            this.ValueToSearchTextBox.Name = "ValueToSearchTextBox";
            this.ValueToSearchTextBox.Size = new System.Drawing.Size(186, 20);
            this.ValueToSearchTextBox.TabIndex = 7;
            // 
            // StopScanTextBox
            // 
            this.StopScanTextBox.Location = new System.Drawing.Point(87, 124);
            this.StopScanTextBox.Name = "StopScanTextBox";
            this.StopScanTextBox.Size = new System.Drawing.Size(186, 20);
            this.StopScanTextBox.TabIndex = 14;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(18, 46);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(59, 13);
            this.label7.TabIndex = 8;
            this.label7.Text = "Scan Type";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(18, 100);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(29, 13);
            this.label9.TabIndex = 13;
            this.label9.Text = "Start";
            // 
            // ScanTypeCBox
            // 
            this.ScanTypeCBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ScanTypeCBox.FormattingEnabled = true;
            this.ScanTypeCBox.Items.AddRange(new object[] {
            "Exact Value",
            "Bigger Than",
            "Less Than",
            "Value Between",
            "Unknown Inital Value"});
            this.ScanTypeCBox.Location = new System.Drawing.Point(87, 43);
            this.ScanTypeCBox.Name = "ScanTypeCBox";
            this.ScanTypeCBox.Size = new System.Drawing.Size(186, 21);
            this.ScanTypeCBox.TabIndex = 9;
            // 
            // StartScanCBox
            // 
            this.StartScanCBox.FormattingEnabled = true;
            this.StartScanCBox.Items.AddRange(new object[] {
            "30000000",
            "40000000",
            "70000000",
            "80000000",
            "82000000",
            "C0000000"});
            this.StartScanCBox.Location = new System.Drawing.Point(87, 97);
            this.StartScanCBox.Name = "StartScanCBox";
            this.StartScanCBox.Size = new System.Drawing.Size(186, 21);
            this.StartScanCBox.TabIndex = 12;
            this.StartScanCBox.Text = "30000000";
            // 
            // Scanning
            // 
            this.Scanning.Controls.Add(this.FoundDataPanel);
            this.Scanning.Controls.Add(this.NextScanButton);
            this.Scanning.Controls.Add(this.NewScanButton);
            this.Scanning.Controls.Add(this.HexCheckBox);
            this.Scanning.Controls.Add(this.label10);
            this.Scanning.Controls.Add(this.ValueToSearchTextBox);
            this.Scanning.Controls.Add(this.StopScanTextBox);
            this.Scanning.Controls.Add(this.label7);
            this.Scanning.Controls.Add(this.label9);
            this.Scanning.Controls.Add(this.ScanTypeCBox);
            this.Scanning.Controls.Add(this.StartScanCBox);
            this.Scanning.Controls.Add(this.ValueTypeCBox);
            this.Scanning.Controls.Add(this.label8);
            this.Scanning.Location = new System.Drawing.Point(12, 31);
            this.Scanning.Name = "Scanning";
            this.Scanning.Size = new System.Drawing.Size(450, 434);
            this.Scanning.TabIndex = 21;
            this.Scanning.TabStop = false;
            this.Scanning.Text = "Scanning";
            // 
            // ValueTypeCBox
            // 
            this.ValueTypeCBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ValueTypeCBox.FormattingEnabled = true;
            this.ValueTypeCBox.Items.AddRange(new object[] {
            "Binary",
            "Byte",
            "2 Bytes",
            "4 Bytes",
            "8 Bytes",
            "Float",
            "Double",
            "Text",
            "Byte Array"});
            this.ValueTypeCBox.Location = new System.Drawing.Point(87, 70);
            this.ValueTypeCBox.Name = "ValueTypeCBox";
            this.ValueTypeCBox.Size = new System.Drawing.Size(186, 21);
            this.ValueTypeCBox.TabIndex = 10;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(18, 73);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(61, 13);
            this.label8.TabIndex = 11;
            this.label8.Text = "Value Type";
            // 
            // hexViewToolStripMenuItem
            // 
            this.hexViewToolStripMenuItem.Name = "hexViewToolStripMenuItem";
            this.hexViewToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.hexViewToolStripMenuItem.Text = "Hex View";
            this.hexViewToolStripMenuItem.Click += new System.EventHandler(this.hexViewToolStripMenuItem_Click);
            // 
            // freezeXboxToolStripMenuItem
            // 
            this.freezeXboxToolStripMenuItem.Name = "freezeXboxToolStripMenuItem";
            this.freezeXboxToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.freezeXboxToolStripMenuItem.Text = "Freeze Xbox";
            this.freezeXboxToolStripMenuItem.Click += new System.EventHandler(this.freezeXboxToolStripMenuItem_Click);
            // 
            // toolsToolStripMenuItem
            // 
            this.toolsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.hexViewToolStripMenuItem,
            this.freezeXboxToolStripMenuItem,
            this.unfreezeXboxToolStripMenuItem,
            this.screenshotToolStripMenuItem});
            this.toolsToolStripMenuItem.Name = "toolsToolStripMenuItem";
            this.toolsToolStripMenuItem.Size = new System.Drawing.Size(48, 20);
            this.toolsToolStripMenuItem.Text = "Tools";
            // 
            // unfreezeXboxToolStripMenuItem
            // 
            this.unfreezeXboxToolStripMenuItem.Name = "unfreezeXboxToolStripMenuItem";
            this.unfreezeXboxToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.unfreezeXboxToolStripMenuItem.Text = "Unfreeze Xbox";
            this.unfreezeXboxToolStripMenuItem.Click += new System.EventHandler(this.unfreezeXboxToolStripMenuItem_Click);
            // 
            // screenshotToolStripMenuItem
            // 
            this.screenshotToolStripMenuItem.Name = "screenshotToolStripMenuItem";
            this.screenshotToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.screenshotToolStripMenuItem.Text = "Screenshot";
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolsToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(468, 24);
            this.menuStrip1.TabIndex = 17;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // FoundDataPanel
            // 
            this.FoundDataPanel.AutoScroll = true;
            this.FoundDataPanel.BackColor = System.Drawing.SystemColors.ControlDark;
            this.FoundDataPanel.Location = new System.Drawing.Point(6, 150);
            this.FoundDataPanel.Name = "FoundDataPanel";
            this.FoundDataPanel.Size = new System.Drawing.Size(438, 276);
            this.FoundDataPanel.TabIndex = 19;
            // 
            // ValueFinder
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(468, 469);
            this.Controls.Add(this.Scanning);
            this.Controls.Add(this.menuStrip1);
            this.Name = "ValueFinder";
            this.Text = "SimpleDump360 - Value Finder";
            this.Load += new System.EventHandler(this.ValueFinder_Load);
            this.Scanning.ResumeLayout(false);
            this.Scanning.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button NextScanButton;
        private System.Windows.Forms.Button NewScanButton;
        private System.Windows.Forms.CheckBox HexCheckBox;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox ValueToSearchTextBox;
        private System.Windows.Forms.TextBox StopScanTextBox;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.ComboBox ScanTypeCBox;
        private System.Windows.Forms.ComboBox StartScanCBox;
        private System.Windows.Forms.GroupBox Scanning;
        private System.Windows.Forms.ComboBox ValueTypeCBox;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ToolStripMenuItem hexViewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem freezeXboxToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem unfreezeXboxToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem screenshotToolStripMenuItem;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.FlowLayoutPanel FoundDataPanel;

    }
}