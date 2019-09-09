using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace MoonPDF_DLL_Test
{
    class MoonPDF_DLL
    {
        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "InitMoonPDFEnvironment", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern int InitMoonPDFEnvironment();

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "DestoryMoonPDFEnvironment", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern int DestoryMoonPDFEnvironment();

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "MoonToolsExtractPageToSave", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern int MoonToolsExtractPageToSave(StringBuilder srcPath, StringBuilder tagPath,int pageIndex);

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "MoonToolsGetPDFPageCount", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern int MoonToolsGetPDFPageCount(StringBuilder srcPath);

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "WindowCompentInit", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern int WindowCompentInit(IntPtr hWnd);

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "MoonPDFLoad", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern int MoonPDFLoad(StringBuilder pdfPath);

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "MoonPaintPDF", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern void MoonPaintPDF();

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "MoonResizePDF", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern void MoonResizePDF(int width, int height);

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "MoonZoomIn", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern void MoonZoomIn();

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "MoonZoomOut", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern void MoonZoomOut();

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "MoonClockwiseRotation", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern void MoonClockwiseRotation();

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "MoonContrarotate", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern void MoonContrarotate();

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "MoonGetPDFPageCount", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern void MoonGetPDFPageCount();

        [DllImport(@"D:\vswork\cppproject\MoonPDF_DLL\Debug\MoonPDF_DLL.dll", EntryPoint = "MoonGotoPage", SetLastError = true,
                CharSet = CharSet.Ansi, ExactSpelling = false,
                CallingConvention = CallingConvention.Cdecl)]
        public static extern void MoonGotoPage(int pageIndex);
    }
}
