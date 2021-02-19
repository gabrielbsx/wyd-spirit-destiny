using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CalcAddress
{
    public partial class Calc : Form
    {
        public Calc()
        {
            InitializeComponent();
        }

        private void OriginalOffset_KeyUp(object sender, KeyEventArgs e)
        {
            var OriginalValue = Convert.ToUInt32(OriginalOffset.Text, 16);

            OriginalValue -= Convert.ToUInt32(DecreaseVal.Text, 16);
            ResultOffset.Text = OriginalValue.ToString("X");
        }

        private void CopyBtn_Click(object sender, EventArgs e)
        {
            string tmpString = "0x" + ResultOffset.Text;
            Clipboard.SetText(tmpString);
        }
    }
}
