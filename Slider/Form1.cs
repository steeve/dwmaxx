using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using dwmaxxLib;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace Slider
{
    public partial class Form1 : Form
    {
        private enum Pouet
        {
            MilCmdInvalid,
            MilCmdTransportSyncFlush,
            MilCmdTransportDestroyResourcesOnChannel,
            MilCmdTransportRoundTripRequest,
            MilCmdTransportAsyncFlush,
            MilCmdPartitionRegisterForNotifications,
            MilCmdPartitionSetCurrentMmTask,
            MilCmdPartitionSetMemoryPriority,
            MilCmdPartitionSetTuningScheme,
            MilCmdChannelRequestTier,
            MilCmdPartitionSetVBlankSyncMode,
            MilCmdPartitionNotifyPresent,
            MilCmdChannelCreateResource,
            MilCmdChannelDeleteResource,
            MilCmdChannelDuplicateHandle,
            MilCmdBitmapSource,
            MilCmdBitmapPixels,
            MilCmdBitmapSection,
            MilCmdDoubleResource,
            MilCmdColorResource,
            MilCmdPointResource,
            MilCmdRectResource,
            MilCmdSizeResource,
            MilCmdMatrixResource,
            MilCmdPoint3DResource,
            MilCmdVector3DResource,
            MilCmdQuaternionResource,
            MilCmdColorTransformResource,
            MilCmdMediaPlayer,
            MilCmdRenderData,
            MilCmdDrawingGroupSetContent,
            MilCmdEtwEventResource,
            MilCmdTileBrushSetSourceModifications,
            MilCmdVisualCreate,
            MilCmdVisualSetOffset,
            MilCmdVisualSetTransform,
            MilCmdVisualSetClip,
            MilCmdVisualSetAlpha,
            MilCmdVisualSetRenderOptions,
            MilCmdVisualSetContent,
            MilCmdVisualSetAlphaMask,
            MilCmdVisualRemoveAllChildren,
            MilCmdVisualRemoveChild,
            MilCmdVisualInsertChildAt,
            MilCmdVisualSetGuidelineCollection,
            MilCmdVisualSetColorTransform,
            MilCmdViewport3DVisualSetCamera,
            MilCmdViewport3DVisualSetViewport,
            MilCmdViewport3DVisualSet3DChild,
            MilCmdVisual3DSetContent,
            MilCmdVisual3DSetTransform,
            MilCmdVisual3DRemoveAllChildren,
            MilCmdVisual3DRemoveChild,
            MilCmdVisual3DInsertChildAt,
            MilCmdWindowNodeCreate,
            MilCmdWindowNodeDetach,
            MilCmdWindowNodeFlushDxUpdates,
            MilCmdWindowNodeNotifyDirty,
            MilCmdWindowNodeSetBounds,
            MilCmdWindowNodeAddDirtyRegion,
            MilCmdWindowNodeUpdateSpriteHandle,
            MilCmdWindowNodeNotifyDxUpdate,
            MilCmdWindowNodeSetSpriteImage,
            MilCmdWindowNodeSetDxImage,
            MilCmdWindowNodeSetSpriteClip,
            MilCmdWindowNodeSetDxClip,
            MilCmdWindowNodeSetSourceModifications,
            MilCmdWindowNodeSetAlphaMargins,
            MilCmdWindowNodeSetComposeOnce,
            MilCmdWindowNodeCopyCompositorOwnedResources,
            MilCmdWindowNodeSetMaximizedClipMargins,
            MilCmdWindowNodeNotifyVisRgnUpdate,
            MilCmdWindowNodeSetDxAlpha,
            MilCmdHwndTargetCreate,
            MilCmdHwndTargetSuppressLayered,
            MilCmdTargetUpdateWindowSettings,
            MilCmdGenericTargetCreate,
            MilCmdTargetSetRoot,
            MilCmdTargetSetClearColor,
            MilCmdTargetInvalidate,
            MilCmdTargetSetFlags,
            MilCmdTargetCaptureBits,
            MilCmdGlyphCacheCreate,
            MilCmdGlyphCacheAddBitmaps,
            MilCmdGlyphBitmap,
            MilCmdGlyphCacheRemoveBitmaps,
            MilCmdGlyphRunCreate,
            MilCmdGlyphRunAddRealization,
            MilCmdGlyphRunRemoveRealization,
            MilCmdGlyphRunGeometry,
            MilCmdGdiSpriteBitmap,
            MilCmdGdiSpriteBitmapUpdateMargins,
            MilCmdGdiSpriteBitmapTSUpdateSection,
            MilCmdGdiSpriteBitmapUnmapSection,
            MilCmdFlipChainCreate,
            MilCmdFlipChainInitializeSharedDataObjects,
            MilCmdFlipChainRequestSharedHandle,
            MilCmdFlipChainUpdateMargins,
            MilCmdFlipChainSetPresentParameters,
            MilCmdFlipChainGetCompositionTimingInfo,
            MilCmdFlipChainModifyFrameDuration,
            MilCmdFlipChainResetSourceFrameCounters,
            MilCmdSpriteNotifyDirty,
            MilCmdMeshGeometry2DSetConstantOpacity,
            MilDrawBitmap,
            MilDrawGlass,
            MilDrawMesh2D,
            MilDrawOcclusionRectangle,
            MilDrawVisual,
            MilDrawLine,
            MilDrawLineAnimate,
            MilDrawRectangle,
            MilDrawRectangleAnimate,
            MilDrawRoundedRectangle,
            MilDrawRoundedRectangleAnimate,
            MilDrawEllipse,
            MilDrawEllipseAnimate,
            MilDrawGeometry,
            MilDrawImage,
            MilDrawImageAnimate,
            MilDrawGlyphRun,
            MilDrawDrawing,
            MilDrawVideo,
            MilDrawVideoAnimate,
            MilDrawScene3D,
            MilPushClip,
            MilPushOpacityMask,
            MilPushOpacity,
            MilPushOpacityAnimate,
            MilPushTransform,
            MilPushGuidelineSet,
            MilPushGuidelineY1,
            MilPushGuidelineY2,
            MilPushEffect,
            MilPop,
            MilCmdAxisAngleRotation3D,
            MilCmdQuaternionRotation3D,
            MilCmdScene3D,
            MilCmdPerspectiveCamera,
            MilCmdOrthographicCamera,
            MilCmdMatrixCamera,
            MilCmdModel3DGroup,
            MilCmdAmbientLight,
            MilCmdDirectionalLight,
            MilCmdPointLight,
            MilCmdSpotLight,
            MilCmdGeometryModel3D,
            MilCmdMeshGeometry3D,
            MilCmdMeshGeometry2D,
            MilCmdGeometry2DGroup,
            MilCmdMaterialGroup,
            MilCmdDiffuseMaterial,
            MilCmdSpecularMaterial,
            MilCmdEmissiveMaterial,
            MilCmdTransform3DGroup,
            MilCmdTranslateTransform3D,
            MilCmdScaleTransform3D,
            MilCmdRotateTransform3D,
            MilCmdMatrixTransform3D,
            MilCmdBitmapEffectDrawing,
            MilCmdDrawingImage,
            MilCmdCachedVisualImage,
            MilCmdTransformGroup,
            MilCmdTranslateTransform,
            MilCmdScaleTransform,
            MilCmdSkewTransform,
            MilCmdRotateTransform,
            MilCmdMatrixTransform,
            MilCmdLineGeometry,
            MilCmdRectangleGeometry,
            MilCmdEllipseGeometry,
            MilCmdGeometryGroup,
            MilCmdCombinedGeometry,
            MilCmdPathGeometry,
            MilCmdSolidColorBrush,
            MilCmdLinearGradientBrush,
            MilCmdRadialGradientBrush,
            MilCmdImageBrush,
            MilCmdDrawingBrush,
            MilCmdVisualBrush,
            MilCmdDashStyle,
            MilCmdPen,
            MilCmdGeometryDrawing,
            MilCmdGlyphRunDrawing,
            MilCmdImageDrawing,
            MilCmdVideoDrawing,
            MilCmdDrawingGroup,
            MilCmdGuidelineSet
        }

        [DllImport("user32.dll", SetLastError = true)]
        static extern IntPtr FindWindow(string lpClassName, string lpWindowName);

        [DllImport("user32.dll")]
        static extern IntPtr    GetDesktopWindow();

        // Siwu addition, for GetAncestor()
        public const int GA_PARENT = 1;
        public const int GA_ROOT = 2;
        public const int GA_ROOTOWNER = 3;
        
        [DllImport("user32")]
        public static extern int GetAncestor(IntPtr hwnd, uint gaFlags);

        [DllImport("user32")]
        public static extern int WindowFromPoint(int xPoint, int yPoint);

        [DllImport("user32")]
        public static extern int GetWindowRect(IntPtr hwnd, ref Rectangle lpRect);


        DWMInjector    _injector = null;
        DWMEx          _dwm = null;
        IntPtr          _hCurrentWindow = IntPtr.Zero;
        Rectangle _currentWindowRectangle = new Rectangle();

        public Form1()
        {
            InitializeComponent();

            //string[] names = Enum.GetNames(typeof(Pouet));
            //for (int i = 0; i < names.Length; i++)
            //    Debug.WriteLine(string.Format("AddConstEx(enumIdx, \"{0}\", {1}, -1);", names[i], i));
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (_injector.IsInjected == false)
                _injector.Inject();
            else
                _injector.Unload();

            Config();

            //if (_injector.IsInjected == true)
            //    _dwm.StartConsole();
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            PictureBox box = (PictureBox)sender;
            box.Capture = true;
            Cursor.Current = Cursors.Cross;
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            PictureBox box = (PictureBox)sender;
            box.Capture = false;
            Cursor.Current = Cursors.Default;
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            PictureBox box = (PictureBox)sender;
            if (box.Capture == true)
            {
                IntPtr hWnd = (IntPtr)GetAncestor((IntPtr)WindowFromPoint(Cursor.Position.X, Cursor.Position.Y), GA_ROOTOWNER);
                if (hWnd == this.Handle)
                    return;
                _hCurrentWindow = hWnd;
                GetWindowRect(_hCurrentWindow, ref _currentWindowRectangle);
                textBox1.Text = User32Sharp.GetWindowText(hWnd);
            }
        }

        private void Config()
        {
            if (_injector.IsInjected == true)
            {
                _injector.GetDWMExObject(out _dwm);
                button1.Text = "Unload";
                checkBox1.Checked = true;
            }
            else
            {
                button1.Text = "Inject";
                checkBox1.Checked = false;
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            _injector = new DWMInjector();

            Config();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            trackBar1.Value = 0;
            trackBar1_ValueChanged(button2, null);
        }

        private void trackBar1_ValueChanged(object sender, EventArgs e)
        {
            //float scale = 1.0f + ((float)trackBar1.Value / 1000.0f);


            if (_hCurrentWindow != IntPtr.Zero)
                _dwm.SetWindowMatrix(_hCurrentWindow.ToInt32(), (float)_currentWindowRectangle.X, (float)_currentWindowRectangle.Y, 1.0f, 1.0f, (((float)trackBar1.Value / 10.0f) * (float)Math.PI) / 180.0f);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            _dwm.SetRenderOptions(_hCurrentWindow.ToInt32(), 0);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            _dwm.OpenConsole();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            _dwm.CloseConsole();
        }
    }
}