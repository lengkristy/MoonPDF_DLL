namespace MoonPDF_DLL_Test
{
    partial class MainWindow
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.btnNSZXZ = new System.Windows.Forms.Button();
            this.btnSSZXX = new System.Windows.Forms.Button();
            this.btnZoomOut = new System.Windows.Forms.Button();
            this.btnZoonIn = new System.Windows.Forms.Button();
            this.btnOpen = new System.Windows.Forms.Button();
            this.tbPdfPath = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.pdfPanel = new System.Windows.Forms.Panel();
            this.tbPage = new System.Windows.Forms.TextBox();
            this.btnGoto = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.tbSplitPdfPath = new System.Windows.Forms.TextBox();
            this.btnSplitePage = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.btnSplitePage);
            this.splitContainer1.Panel1.Controls.Add(this.btnGoto);
            this.splitContainer1.Panel1.Controls.Add(this.tbPage);
            this.splitContainer1.Panel1.Controls.Add(this.btnNSZXZ);
            this.splitContainer1.Panel1.Controls.Add(this.btnSSZXX);
            this.splitContainer1.Panel1.Controls.Add(this.btnZoomOut);
            this.splitContainer1.Panel1.Controls.Add(this.btnZoonIn);
            this.splitContainer1.Panel1.Controls.Add(this.btnOpen);
            this.splitContainer1.Panel1.Controls.Add(this.tbSplitPdfPath);
            this.splitContainer1.Panel1.Controls.Add(this.tbPdfPath);
            this.splitContainer1.Panel1.Controls.Add(this.label2);
            this.splitContainer1.Panel1.Controls.Add(this.label1);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.pdfPanel);
            this.splitContainer1.Size = new System.Drawing.Size(958, 667);
            this.splitContainer1.SplitterDistance = 62;
            this.splitContainer1.TabIndex = 0;
            // 
            // btnNSZXZ
            // 
            this.btnNSZXZ.Location = new System.Drawing.Point(630, 8);
            this.btnNSZXZ.Name = "btnNSZXZ";
            this.btnNSZXZ.Size = new System.Drawing.Size(75, 23);
            this.btnNSZXZ.TabIndex = 3;
            this.btnNSZXZ.Text = "逆时针旋转";
            this.btnNSZXZ.UseVisualStyleBackColor = true;
            this.btnNSZXZ.Click += new System.EventHandler(this.btnNSZXZ_Click);
            // 
            // btnSSZXX
            // 
            this.btnSSZXX.Location = new System.Drawing.Point(549, 8);
            this.btnSSZXX.Name = "btnSSZXX";
            this.btnSSZXX.Size = new System.Drawing.Size(75, 23);
            this.btnSSZXX.TabIndex = 3;
            this.btnSSZXX.Text = "顺时针旋转";
            this.btnSSZXX.UseVisualStyleBackColor = true;
            this.btnSSZXX.Click += new System.EventHandler(this.btnSSZXX_Click);
            // 
            // btnZoomOut
            // 
            this.btnZoomOut.Location = new System.Drawing.Point(468, 8);
            this.btnZoomOut.Name = "btnZoomOut";
            this.btnZoomOut.Size = new System.Drawing.Size(75, 23);
            this.btnZoomOut.TabIndex = 3;
            this.btnZoomOut.Text = "缩小";
            this.btnZoomOut.UseVisualStyleBackColor = true;
            this.btnZoomOut.Click += new System.EventHandler(this.btnZoomOut_Click);
            // 
            // btnZoonIn
            // 
            this.btnZoonIn.Location = new System.Drawing.Point(387, 8);
            this.btnZoonIn.Name = "btnZoonIn";
            this.btnZoonIn.Size = new System.Drawing.Size(75, 23);
            this.btnZoonIn.TabIndex = 3;
            this.btnZoonIn.Text = "放大";
            this.btnZoonIn.UseVisualStyleBackColor = true;
            this.btnZoonIn.Click += new System.EventHandler(this.btnZoonIn_Click);
            // 
            // btnOpen
            // 
            this.btnOpen.Location = new System.Drawing.Point(306, 8);
            this.btnOpen.Name = "btnOpen";
            this.btnOpen.Size = new System.Drawing.Size(75, 23);
            this.btnOpen.TabIndex = 2;
            this.btnOpen.Text = "选择";
            this.btnOpen.UseVisualStyleBackColor = true;
            this.btnOpen.Click += new System.EventHandler(this.btnOpen_Click);
            // 
            // tbPdfPath
            // 
            this.tbPdfPath.Location = new System.Drawing.Point(66, 10);
            this.tbPdfPath.Name = "tbPdfPath";
            this.tbPdfPath.Size = new System.Drawing.Size(234, 21);
            this.tbPdfPath.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(47, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "PDF路径";
            // 
            // pdfPanel
            // 
            this.pdfPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pdfPanel.Location = new System.Drawing.Point(0, 0);
            this.pdfPanel.Name = "pdfPanel";
            this.pdfPanel.Size = new System.Drawing.Size(958, 601);
            this.pdfPanel.TabIndex = 0;
            this.pdfPanel.Paint += new System.Windows.Forms.PaintEventHandler(this.pdfPanel_Paint);
            this.pdfPanel.Resize += new System.EventHandler(this.pdfPanel_Resize);
            // 
            // tbPage
            // 
            this.tbPage.Location = new System.Drawing.Point(721, 10);
            this.tbPage.Name = "tbPage";
            this.tbPage.Size = new System.Drawing.Size(48, 21);
            this.tbPage.TabIndex = 4;
            // 
            // btnGoto
            // 
            this.btnGoto.Location = new System.Drawing.Point(775, 8);
            this.btnGoto.Name = "btnGoto";
            this.btnGoto.Size = new System.Drawing.Size(75, 23);
            this.btnGoto.TabIndex = 5;
            this.btnGoto.Text = "跳转到页";
            this.btnGoto.UseVisualStyleBackColor = true;
            this.btnGoto.Click += new System.EventHandler(this.btnGoto_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 41);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 12);
            this.label2.TabIndex = 0;
            this.label2.Text = "PDF路径";
            // 
            // tbSplitPdfPath
            // 
            this.tbSplitPdfPath.Location = new System.Drawing.Point(66, 38);
            this.tbSplitPdfPath.Name = "tbSplitPdfPath";
            this.tbSplitPdfPath.Size = new System.Drawing.Size(234, 21);
            this.tbSplitPdfPath.TabIndex = 1;
            // 
            // btnSplitePage
            // 
            this.btnSplitePage.Location = new System.Drawing.Point(306, 37);
            this.btnSplitePage.Name = "btnSplitePage";
            this.btnSplitePage.Size = new System.Drawing.Size(75, 23);
            this.btnSplitePage.TabIndex = 6;
            this.btnSplitePage.Text = "拆页页面";
            this.btnSplitePage.UseVisualStyleBackColor = true;
            this.btnSplitePage.Click += new System.EventHandler(this.btnSplitePage_Click);
            // 
            // MainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(958, 667);
            this.Controls.Add(this.splitContainer1);
            this.Name = "MainWindow";
            this.Text = "MoonPDF测试界面";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.Panel pdfPanel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tbPdfPath;
        private System.Windows.Forms.Button btnOpen;
        private System.Windows.Forms.Button btnZoonIn;
        private System.Windows.Forms.Button btnZoomOut;
        private System.Windows.Forms.Button btnSSZXX;
        private System.Windows.Forms.Button btnNSZXZ;
        private System.Windows.Forms.Button btnGoto;
        private System.Windows.Forms.TextBox tbPage;
        private System.Windows.Forms.TextBox tbSplitPdfPath;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnSplitePage;
    }
}

