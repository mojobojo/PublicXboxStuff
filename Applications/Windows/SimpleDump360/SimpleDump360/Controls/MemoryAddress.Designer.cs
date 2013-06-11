namespace SimpleDump360
{
    partial class MemoryAddress
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.MemoryAddressLabel = new System.Windows.Forms.Label();
            this.HexViewButton = new System.Windows.Forms.Button();
            this.ChangeValueButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // MemoryAddressLabel
            // 
            this.MemoryAddressLabel.AutoSize = true;
            this.MemoryAddressLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MemoryAddressLabel.Location = new System.Drawing.Point(3, 9);
            this.MemoryAddressLabel.Name = "MemoryAddressLabel";
            this.MemoryAddressLabel.Size = new System.Drawing.Size(97, 20);
            this.MemoryAddressLabel.TabIndex = 0;
            this.MemoryAddressLabel.Text = "0x00000000";
            // 
            // HexViewButton
            // 
            this.HexViewButton.Location = new System.Drawing.Point(306, 6);
            this.HexViewButton.Name = "HexViewButton";
            this.HexViewButton.Size = new System.Drawing.Size(100, 23);
            this.HexViewButton.TabIndex = 1;
            this.HexViewButton.Text = "View Memory";
            this.HexViewButton.UseVisualStyleBackColor = true;
            this.HexViewButton.Click += new System.EventHandler(this.HexViewButton_Click);
            // 
            // ChangeValueButton
            // 
            this.ChangeValueButton.Location = new System.Drawing.Point(191, 6);
            this.ChangeValueButton.Name = "ChangeValueButton";
            this.ChangeValueButton.Size = new System.Drawing.Size(100, 23);
            this.ChangeValueButton.TabIndex = 2;
            this.ChangeValueButton.Text = "Poke Value";
            this.ChangeValueButton.UseVisualStyleBackColor = true;
            this.ChangeValueButton.Click += new System.EventHandler(this.ChangeValueButton_Click);
            // 
            // MemoryAddress
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.Controls.Add(this.ChangeValueButton);
            this.Controls.Add(this.HexViewButton);
            this.Controls.Add(this.MemoryAddressLabel);
            this.Name = "MemoryAddress";
            this.Size = new System.Drawing.Size(413, 36);
            this.Load += new System.EventHandler(this.MemoryAddress_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label MemoryAddressLabel;
        private System.Windows.Forms.Button HexViewButton;
        private System.Windows.Forms.Button ChangeValueButton;
    }
}
