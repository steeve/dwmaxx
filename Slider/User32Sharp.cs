#region Using directives

using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using System.Runtime.InteropServices;

#endregion

namespace Slider
{
	public class User32Sharp
	{
        [DllImport("user32")]
        public static extern int GetWindowText(IntPtr hwnd, StringBuilder lpString, int cch);
        [DllImport("user32")]
        public static extern int GetWindowTextLength(IntPtr hwnd);

		public static string GetWindowText(IntPtr hWin)
		{
			StringBuilder str = new StringBuilder(GetWindowTextLength(hWin));
			GetWindowText(hWin, str, str.MaxCapacity);
			return (str.ToString());
		}
	}
}
