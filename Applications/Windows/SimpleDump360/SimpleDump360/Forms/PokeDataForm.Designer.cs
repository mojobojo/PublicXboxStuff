namespace SimpleDump360
{
    partial class PokeDataForm
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
            this.ValueTypeCBox = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
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
            this.ValueTypeCBox.Location = new System.Drawing.Point(27, 81);
            this.ValueTypeCBox.Name = "ValueTypeCBox";
            this.ValueTypeCBox.Size = new System.Drawing.Size(186, 21);
            this.ValueTypeCBox.TabIndex = 11;
            // 
            // PokeDataForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.ValueTypeCBox);
            this.Name = "PokeDataForm";
            this.Text = "Poke Data";
            this.Load += new System.EventHandler(this.PokeDataForm_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ComboBox ValueTypeCBox;
    }
}