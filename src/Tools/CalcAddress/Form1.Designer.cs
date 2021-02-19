
namespace CalcAddress
{
    partial class Calc
    {
        /// <summary>
        /// Variável de designer necessária.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpar os recursos que estão sendo usados.
        /// </summary>
        /// <param name="disposing">true se for necessário descartar os recursos gerenciados; caso contrário, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código gerado pelo Windows Form Designer

        /// <summary>
        /// Método necessário para suporte ao Designer - não modifique 
        /// o conteúdo deste método com o editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.OriginalOffset = new System.Windows.Forms.TextBox();
            this.ResultOffset = new System.Windows.Forms.TextBox();
            this.DecreaseVal = new System.Windows.Forms.TextBox();
            this.CopyBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 121);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(63, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "MinusOffset";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Offset";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 44);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Result";
            // 
            // OriginalOffset
            // 
            this.OriginalOffset.Location = new System.Drawing.Point(53, 6);
            this.OriginalOffset.Name = "OriginalOffset";
            this.OriginalOffset.Size = new System.Drawing.Size(116, 20);
            this.OriginalOffset.TabIndex = 3;
            this.OriginalOffset.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.OriginalOffset.KeyUp += new System.Windows.Forms.KeyEventHandler(this.OriginalOffset_KeyUp);
            // 
            // ResultOffset
            // 
            this.ResultOffset.Location = new System.Drawing.Point(53, 41);
            this.ResultOffset.Name = "ResultOffset";
            this.ResultOffset.Size = new System.Drawing.Size(116, 20);
            this.ResultOffset.TabIndex = 4;
            this.ResultOffset.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // DecreaseVal
            // 
            this.DecreaseVal.Enabled = false;
            this.DecreaseVal.Location = new System.Drawing.Point(81, 118);
            this.DecreaseVal.Name = "DecreaseVal";
            this.DecreaseVal.ReadOnly = true;
            this.DecreaseVal.Size = new System.Drawing.Size(88, 20);
            this.DecreaseVal.TabIndex = 5;
            this.DecreaseVal.Text = "4B1000";
            this.DecreaseVal.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // CopyBtn
            // 
            this.CopyBtn.Location = new System.Drawing.Point(12, 67);
            this.CopyBtn.Name = "CopyBtn";
            this.CopyBtn.Size = new System.Drawing.Size(157, 45);
            this.CopyBtn.TabIndex = 6;
            this.CopyBtn.Text = "Copy!";
            this.CopyBtn.UseVisualStyleBackColor = true;
            this.CopyBtn.Click += new System.EventHandler(this.CopyBtn_Click);
            // 
            // Calc
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(181, 143);
            this.Controls.Add(this.CopyBtn);
            this.Controls.Add(this.DecreaseVal);
            this.Controls.Add(this.ResultOffset);
            this.Controls.Add(this.OriginalOffset);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Calc";
            this.Text = "CalcAddr";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox OriginalOffset;
        private System.Windows.Forms.TextBox ResultOffset;
        private System.Windows.Forms.TextBox DecreaseVal;
        private System.Windows.Forms.Button CopyBtn;
    }
}

