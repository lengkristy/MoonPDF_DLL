using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MoonPDF_DLL_Test
{
    public partial class MainWindow : Form
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            MoonPDF_DLL.InitMoonPDFEnvironment();
            int ret = MoonPDF_DLL.WindowCompentInit(pdfPanel.Handle);
            if (ret == -1)
            {
                MessageBox.Show("初始化PDF失败");
                return;
            }
        }

        //pdf显示窗口大小被重置
        private void pdfPanel_Resize(object sender, EventArgs e)
        {
            MoonPDF_DLL.MoonResizePDF(((Control)sender).Width, ((Control)sender).Height);
        }

        private void pdfPanel_Paint(object sender, PaintEventArgs e)
        {
            MoonPDF_DLL.MoonPaintPDF();
        }

        ~MainWindow()
        {
            MoonPDF_DLL.DestoryMoonPDFEnvironment();
        }

        private void btnOpen_Click(object sender, EventArgs e)
        {
            OpenFileDialog file = new OpenFileDialog();
            file.Filter = "pdf files(*.pdf)|*.pdf|All files(*.*)|*.*";
            file.ShowDialog();
            string text = file.FileName;
            MoonPDF_DLL.MoonPDFLoad(new StringBuilder(text));
            //重绘界面
            MoonPDF_DLL.MoonResizePDF(pdfPanel.Width, pdfPanel.Height);
        }

        private void btnZoonIn_Click(object sender, EventArgs e)
        {
            MoonPDF_DLL.MoonZoomIn();
        }

        private void btnZoomOut_Click(object sender, EventArgs e)
        {
            MoonPDF_DLL.MoonZoomOut();
        }

        private void btnSSZXX_Click(object sender, EventArgs e)
        {
            MoonPDF_DLL.MoonClockwiseRotation();
        }

        private void btnNSZXZ_Click(object sender, EventArgs e)
        {
            MoonPDF_DLL.MoonContrarotate();
        }

        private void btnGoto_Click(object sender, EventArgs e)
        {
            if(string.IsNullOrEmpty(tbPage.Text))
            {
                return;
            }
            int pageIndex = Int32.Parse(tbPage.Text);
            MoonPDF_DLL.MoonGotoPage(pageIndex);
        }

        private void btnSplitePage_Click(object sender, EventArgs e)
        {
            OpenFileDialog file = new OpenFileDialog();
            file.Filter = "pdf files(*.pdf)|*.pdf|All files(*.*)|*.*";
            file.ShowDialog();
            string text = file.FileName;
            int count = MoonPDF_DLL.MoonToolsGetPDFPageCount(new StringBuilder(text));
            //计算性能
            DateTime startTime = DateTime.Now;
            for (int i = 0; i < count; i++)
            {
                //获取路径
                StringBuilder sbPath = new StringBuilder();
                sbPath.Append(text.Substring(0, text.LastIndexOf('\\')));
                sbPath.Append("\\");
                sbPath.Append(i+1);
                sbPath.Append(".pdf");
                MoonPDF_DLL.MoonToolsExtractPageToSave(new StringBuilder(text), sbPath, i + 1);
            }
            DateTime endTime = DateTime.Now;

            var tim = endTime - startTime;
            MessageBox.Show("总共花费：" + tim.TotalSeconds + "秒");
        }
    }
}
