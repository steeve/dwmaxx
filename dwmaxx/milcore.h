#pragma once

#include <windows.h>

#pragma pack(push, 1)

typedef enum
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
} MIL_COMMAND;

typedef enum
{
    TYPE_NULL,
    TYPE_MEDIAPLAYER,
    TYPE_ROTATION3D,
    TYPE_AXISANGLEROTATION3D,
    TYPE_QUATERNIONROTATION3D,
    TYPE_SCENE3D,
    TYPE_CAMERA,
    TYPE_PROJECTIONCAMERA,
    TYPE_PERSPECTIVECAMERA,
    TYPE_ORTHOGRAPHICCAMERA,
    TYPE_MATRIXCAMERA,
    TYPE_MODEL3D,
    TYPE_MODEL3DGROUP,
    TYPE_LIGHT,
    TYPE_AMBIENTLIGHT,
    TYPE_DIRECTIONALLIGHT,
    TYPE_POINTLIGHTBASE,
    TYPE_POINTLIGHT,
    TYPE_SPOTLIGHT,
    TYPE_GEOMETRYMODEL3D,
    TYPE_GEOMETRY3D,
    TYPE_MESHGEOMETRY3D,
    TYPE_GEOMETRY2D,
    TYPE_MESHGEOMETRY2D,
    TYPE_GEOMETRY2DGROUP,
    TYPE_MATERIAL,
    TYPE_MATERIALGROUP,
    TYPE_DIFFUSEMATERIAL,
    TYPE_SPECULARMATERIAL,
    TYPE_EMISSIVEMATERIAL,
    TYPE_TRANSFORM3D,
    TYPE_TRANSFORM3DGROUP,
    TYPE_AFFINETRANSFORM3D,
    TYPE_TRANSLATETRANSFORM3D,
    TYPE_SCALETRANSFORM3D,
    TYPE_ROTATETRANSFORM3D,
    TYPE_MATRIXTRANSFORM3D,
    TYPE_BITMAPEFFECTDRAWING,
    TYPE_GLYPHCACHE,
    TYPE_VISUAL,
    TYPE_VIEWPORT3DVISUAL,
    TYPE_VISUAL3D,
    TYPE_WINDOWNODE,
    TYPE_GLYPHRUN,
    TYPE_RENDERDATA,
    TYPE_DRAWINGCONTEXT,
    TYPE_RENDERTARGET,
    TYPE_HWNDRENDERTARGET,
    TYPE_DESKTOPRENDERTARGET,
    TYPE_GENERICRENDERTARGET,
    TYPE_WINDOWRENDERTARGET,
    TYPE_WINDOWRENDERTARGETOVERRIDE,
    TYPE_ETWEVENTRESOURCE,
    TYPE_DOUBLERESOURCE,
    TYPE_COLORRESOURCE,
    TYPE_POINTRESOURCE,
    TYPE_RECTRESOURCE,
    TYPE_SIZERESOURCE,
    TYPE_MATRIXRESOURCE,
    TYPE_POINT3DRESOURCE,
    TYPE_VECTOR3DRESOURCE,
    TYPE_QUATERNIONRESOURCE,
    TYPE_COLORTRANSFORMRESOURCE,
    TYPE_IMAGESOURCE,
    TYPE_DRAWINGIMAGE,
    TYPE_CACHEDVISUALIMAGE,
    TYPE_TRANSFORM,
    TYPE_TRANSFORMGROUP,
    TYPE_TRANSLATETRANSFORM,
    TYPE_SCALETRANSFORM,
    TYPE_SKEWTRANSFORM,
    TYPE_ROTATETRANSFORM,
    TYPE_MATRIXTRANSFORM,
    TYPE_GEOMETRY,
    TYPE_LINEGEOMETRY,
    TYPE_RECTANGLEGEOMETRY,
    TYPE_ELLIPSEGEOMETRY,
    TYPE_GEOMETRYGROUP,
    TYPE_COMBINEDGEOMETRY,
    TYPE_PATHGEOMETRY,
    TYPE_BRUSH,
    TYPE_SOLIDCOLORBRUSH,
    TYPE_GRADIENTBRUSH,
    TYPE_LINEARGRADIENTBRUSH,
    TYPE_RADIALGRADIENTBRUSH,
    TYPE_TILEBRUSH,
    TYPE_IMAGEBRUSH,
    TYPE_DRAWINGBRUSH,
    TYPE_VISUALBRUSH,
    TYPE_DASHSTYLE,
    TYPE_PEN,
    TYPE_DRAWING,
    TYPE_GEOMETRYDRAWING,
    TYPE_GLYPHRUNDRAWING,
    TYPE_IMAGEDRAWING,
    TYPE_VIDEODRAWING,
    TYPE_DRAWINGGROUP,
    TYPE_GUIDELINESET,
    TYPE_BITMAPSOURCE,
    TYPE_FLIPCHAIN,
    TYPE_GDISPRITEBITMAP
} MIL_RESOURCE_TYPE;

typedef void*			MIL_CHANNEL;
typedef unsigned int	MIL_RESOURCE_HANDLE;

typedef struct
{
    double S_11;
    double S_12;
    double S_21;
    double S_22;
    double DX;
    double DY;
} MIL_MATRIX3X2D;

typedef struct
{
	MIL_COMMAND			Type;
	MIL_RESOURCE_HANDLE	Handle;
	MIL_MATRIX3X2D		Matrix;
    unsigned int		hMatrixAnimations;
} MILCMD_MATRIXTRANSFORM;

typedef struct
{
	MIL_COMMAND			Type;
	MIL_RESOURCE_HANDLE	Handle;
    MIL_RESOURCE_HANDLE	hTransform;
}  MILCMD_VISUAL_SETTRANSFORM;

typedef struct
{
	MIL_COMMAND			Type;
	MIL_RESOURCE_HANDLE	Handle;
    double				Alpha;
} MILCMD_VISUAL_SETALPHA;

typedef struct
{
	MIL_COMMAND			Type;
	MIL_RESOURCE_HANDLE	Handle;
	double				offsetX;
	double				offsetY;
} MILCMD_VISUAL_SETOFFSET;

typedef struct
{
	MIL_COMMAND			Type;
	MIL_RESOURCE_HANDLE	Handle;
    double				ScaleX;
    double				ScaleY;
	double				CenterX;
	double				CenterY;
	MIL_RESOURCE_HANDLE	hScaleXAnimations;
	MIL_RESOURCE_HANDLE	hScaleYAnimations;
	MIL_RESOURCE_HANDLE	hCenterXAnimations;
	MIL_RESOURCE_HANDLE	hCenterYAnimations;
} MILCMD_SCALETRANSFORM;

typedef struct
{
	MIL_COMMAND			Type;
	unsigned int		Handle;
	double				Angle;
	double				CenterX;
	double				CenterY;
	MIL_RESOURCE_HANDLE	hAngleAnimations;
	MIL_RESOURCE_HANDLE	hCenterXAnimations;
	MIL_RESOURCE_HANDLE	hCenterYAnimations;
} MILCMD_ROTATETRANSFORM;

typedef struct
{
	MIL_COMMAND			Type;
	MIL_RESOURCE_HANDLE	Handle;
	MIL_RESOURCE_HANDLE	Flags;
} MILCMD_TARGET_SETFLAGS;

typedef struct
{
	double	X;
	double	Y;
	double	Width;
	double	Height;
} MIL_RECT; // sizeof(MIL_RECT) == 0x20

typedef struct
{
	MIL_COMMAND			Type;					// 0x00
	MIL_RESOURCE_HANDLE	Handle;					// 0x04
    MIL_RECT			ViewportRectangle;		// 0x08
    MIL_RESOURCE_HANDLE	hModels;				// 0x28
    MIL_RESOURCE_HANDLE	hCamera;				// 0x2C
    MIL_RESOURCE_HANDLE	hViewportAnimations;	// 0x30
} MILCMD_SCENE3D;

typedef enum
{
    EM_Unspecified,
    Aliased
} EdgeModes;

typedef enum
{
    BitmapScalingMode = 1,
    CompositingMode = 0x20,
    DisableAnisotropicFiltering = 0x40,
    DisableTrilinearFiltering = 2,
    DisableZBuffer = 4,
    EdgeMode = 8,
    FORCE_DWORD = -1,
    InterpolationMode = 0x10
} MILRenderOptionFlags;

typedef enum
{
    BSM_Unspecified,
    LowQuality,
    HighQuality
} BitmapScalingModes;

typedef struct
{
    MILRenderOptionFlags	Flags;
    EdgeModes				EdgeMode;
	unsigned int			InterpolationMode;
    unsigned int			MILCompositingMode;
    BitmapScalingModes		BitmapScalingMode;
    unsigned int			ForcePacking;
} MILRenderOptions;

typedef struct
{
	MIL_COMMAND			Type;
	MIL_RESOURCE_HANDLE	Handle;
    MILRenderOptions	RenderOptions;
} MILCMD_VISUAL_SETRENDEROPTIONS;

typedef enum
{
    IsBitmapEffectDirty = 0x80,
    IsBitmapScalingModeDirty = 0x8000,
    IsClipDirty = 4,
    IsConnectedToParent = 0x1000,
    IsContentConnected = 0x400,
    IsContentDirty = 8,
    IsContentNodeConnected = 0x800,
    IsDeleteResourceInProgress = 0x10000,
    IsEdgeModeDirty = 0x200,
    IsGuidelineCollectionDirty = 0x100,
    IsOffsetDirty = 0x40,
    IsOpacityDirty = 0x10,
    IsOpacityMaskDirty = 0x20,
    IsSubtreeDirtyForRender = 1,
    IsTransformDirty = 2,
    None = 0,
    Viewport3DVisual_IsCameraDirty = 0x2000,
    Viewport3DVisual_IsViewportDirty = 0x4000
} VisualProxyFlags;


#pragma pack(pop)


extern "C" __declspec(dllimport) int __stdcall MilChannel_AppendCommandData(MIL_CHANNEL pChannel, void* pbData, unsigned int cbSize);
extern "C" __declspec(dllimport) int __stdcall MilChannel_BeginCommand(MIL_CHANNEL pChannel, void* pbData, unsigned int cbSize, unsigned int cbExtra);
extern "C" __declspec(dllimport) int __stdcall MilChannel_EndCommand(MIL_CHANNEL pChannel);
//int MilChannel_GetMarshalType(MIL_CHANNEL channelHandle, out ChannelMarshalType marshalType);
extern "C" __declspec(dllimport) int __stdcall MilChannel_SetNotificationWindow(MIL_CHANNEL pChannel, HWND hwnd, int message);
//int MilComposition_PeekNextMessage(MIL_CHANNEL pChannel, out DUCE.MilMessage.Message message, IntPtr messageSize, out int messageRetrieved);
//int MilComposition_WaitForNextMessage(IntPtr pChannel, int nCount, IntPtr[] handles, int bWaitAll, uint waitTimeout, out int waitReturn);

//int MilConnection_CommitChannel(IntPtr channelHandle);
extern "C" __declspec(dllimport) int __stdcall MilChannel_CommitChannel(MIL_CHANNEL channelHandle);

extern "C" __declspec(dllimport) int __stdcall MilConnection_CreateChannel(MIL_CHANNEL pTransport, MIL_CHANNEL hChannel, MIL_CHANNEL* channelHandle);
extern "C" __declspec(dllimport) int __stdcall MilConnection_DestroyChannel(MIL_CHANNEL channelHandle);
extern "C" __declspec(dllimport) int __stdcall MilResource_CreateOrAddRefOnChannel(MIL_CHANNEL pChannel, MIL_RESOURCE_HANDLE resourceType, MIL_RESOURCE_HANDLE* hResource);
extern "C" __declspec(dllimport) int __stdcall MilResource_DuplicateHandle(MIL_CHANNEL pSourceChannel, MIL_RESOURCE_HANDLE original, MIL_CHANNEL pTargetChannel, MIL_RESOURCE_HANDLE* duplicate);
extern "C" __declspec(dllimport) int __stdcall MilResource_ReleaseOnChannel(MIL_CHANNEL pChannel, MIL_RESOURCE_HANDLE hResource, BOOL* deleted);
extern "C" __declspec(dllimport) int __stdcall MilResource_SendCommand(void* pbData, unsigned int cbSize, MIL_CHANNEL pChannel);
//int MilResource_SendCommandBitmapSource(RESOURCE_HANDLE handle, BitmapSourceSafeMILHandle pBitmapSource, bool shareBitmap, bool systemMemoryBitmap, IntPtr pChannel);
//int MilResource_SendCommandMedia(DUCE.ResourceHandle handle, SafeMediaHandle pMedia, DUCE.ResourceHandle hImageSource, IntPtr pChannel, bool notifyUceDirect, bool isRemote);
//int MilSyncPacketTransport_Present(IntPtr pPacketTransport);
