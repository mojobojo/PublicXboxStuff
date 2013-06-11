namespace SimpleDump360
{
    partial class HexView
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
            this.RefreshButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SeekButton = new System.Windows.Forms.Button();
            this.PositionBox = new System.Windows.Forms.TextBox();
            this.HexDataBox = new System.Windows.Forms.RichTextBox();
            this.LastButton = new System.Windows.Forms.Button();
            this.NextButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // RefreshButton
            // 
            this.RefreshButton.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.RefreshButton.Location = new System.Drawing.Point(479, 530);
            this.RefreshButton.Name = "RefreshButton";
            this.RefreshButton.Size = new System.Drawing.Size(75, 23);
            this.RefreshButton.TabIndex = 13;
            this.RefreshButton.Text = "Refresh";
            this.RefreshButton.UseVisualStyleBackColor = true;
            this.RefreshButton.Click += new System.EventHandler(this.RefreshButton_Click);
            // 
            // label1
            // 
            this.label1.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(235, 535);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 13);
            this.label1.TabIndex = 12;
            this.label1.Text = "Position";
            // 
            // SeekButton
            // 
            this.SeekButton.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.SeekButton.Location = new System.Drawing.Point(398, 530);
            this.SeekButton.Name = "SeekButton";
            this.SeekButton.Size = new System.Drawing.Size(75, 23);
            this.SeekButton.TabIndex = 11;
            this.SeekButton.Text = "Seek";
            this.SeekButton.UseVisualStyleBackColor = true;
            this.SeekButton.Click += new System.EventHandler(this.SeekButton_Click);
            // 
            // PositionBox
            // 
            this.PositionBox.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.PositionBox.Location = new System.Drawing.Point(285, 532);
            this.PositionBox.Name = "PositionBox";
            this.PositionBox.Size = new System.Drawing.Size(107, 20);
            this.PositionBox.TabIndex = 10;
            this.PositionBox.Text = "82000000";
            // 
            // HexDataBox
            // 
            this.HexDataBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.HexDataBox.Font = new System.Drawing.Font("Courier New", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.HexDataBox.Location = new System.Drawing.Point(10, 9);
            this.HexDataBox.Name = "HexDataBox";
            this.HexDataBox.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.ForcedVertical;
            this.HexDataBox.Size = new System.Drawing.Size(780, 514);
            this.HexDataBox.TabIndex = 9;
            this.HexDataBox.Text = "";
            // 
            // LastButton
            // 
            this.LastButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.LastButton.Location = new System.Drawing.Point(10, 529);
            this.LastButton.Name = "LastButton";
            this.LastButton.Size = new System.Drawing.Size(75, 23);
            this.LastButton.TabIndex = 8;
            this.LastButton.Text = "<-";
            this.LastButton.UseVisualStyleBackColor = true;
            this.LastButton.Click += new System.EventHandler(this.LastButton_Click);
            // 
            // NextButton
            // 
            this.NextButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.NextButton.Location = new System.Drawing.Point(719, 529);
            this.NextButton.Name = "NextButton";
            this.NextButton.Size = new System.Drawing.Size(75, 23);
            this.NextButton.TabIndex = 7;
            this.NextButton.Text = "->";
            this.NextButton.UseVisualStyleBackColor = true;
            this.NextButton.Click += new System.EventHandler(this.NextButton_Click);
            // 
            // HexView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(804, 562);
            this.Controls.Add(this.RefreshButton);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.SeekButton);
            this.Controls.Add(this.PositionBox);
            this.Controls.Add(this.HexDataBox);
            this.Controls.Add(this.LastButton);
            this.Controls.Add(this.NextButton);
            this.Name = "HexView";
            this.Text = "SimpleDump360 - Hex Viewer";
            this.Load += new System.EventHandler(this.HexView_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button RefreshButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button SeekButton;
        private System.Windows.Forms.TextBox PositionBox;
        private System.Windows.Forms.RichTextBox HexDataBox;
        private System.Windows.Forms.Button LastButton;
        private System.Windows.Forms.Button NextButton;
    }
}