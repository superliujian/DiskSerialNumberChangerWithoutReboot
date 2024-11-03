using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

namespace SharpChangeDiskId
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            LoadProcesses();
        }

        private void btnLoadProcesses_Click(object sender, EventArgs e)
        {
            LoadProcesses();
        }

        private void txtDiskId_Validating(object sender, CancelEventArgs e)
        {

        }

        private void txtDiskId_Validated(object sender, EventArgs e)
        {

        }

        private void btnOK_Click(object sender, EventArgs e)
        {

        }


        private void LoadProcesses()
        {
            this.cbProcesses.Items.Clear();
            foreach (Process p in Process.GetProcesses())
            {
                this.cbProcesses.Items.Add(p.ProcessName);
            }
        }
    }
}