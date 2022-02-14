#inclue "hip_runtime.h"
#include <vector>
#include <string>


std::vector<std::string> clang_rewrite_literal_names = {
"CUDA_IPC_HANDLE_SIZE",
"CUevent_st",
"CUgraphExec_st",
"CUgraphNode_st",
"CUgraph_st",
"CUstream_st",
"cudaAddressModeBorder",
"cudaAddressModeClamp",
"cudaAddressModeMirror",
"cudaAddressModeWrap",
"cudaArray",
"cudaArrayCubemap",
"cudaArrayDefault",
"cudaArrayLayered",
"cudaArraySurfaceLoadStore",
"cudaArrayTextureGather",
"cudaArray_const_t",
"cudaArray_t",
"cudaBoundaryModeClamp",
"cudaBoundaryModeTrap",
"cudaBoundaryModeZero",
"cudaChannelFormatDesc",
"cudaChannelFormatKind",
"cudaChannelFormatKindFloat",
"cudaChannelFormatKindNone",
"cudaChannelFormatKindSigned",
"cudaChannelFormatKindUnsigned",
"cudaComputeMode",
"cudaComputeModeDefault",
"cudaComputeModeExclusive",
"cudaComputeModeExclusiveProcess",
"cudaComputeModeProhibited",
"cudaCooperativeLaunchMultiDeviceNoPostSync",
"cudaCooperativeLaunchMultiDeviceNoPreSync",
"cudaCpuDeviceId",
"cudaDevAttrAsyncEngineCount",
"cudaDevAttrCanMapHostMemory",
"cudaDevAttrCanUseHostPointerForRegisteredMem",
"cudaDevAttrClockRate",
"cudaDevAttrComputeCapabilityMajor",
"cudaDevAttrComputeCapabilityMinor",
"cudaDevAttrComputeMode",
"cudaDevAttrComputePreemptionSupported",
"cudaDevAttrConcurrentKernels",
"cudaDevAttrConcurrentManagedAccess",
"cudaDevAttrCooperativeLaunch",
"cudaDevAttrCooperativeMultiDeviceLaunch",
"cudaDevAttrDirectManagedMemAccessFromHost",
"cudaDevAttrEccEnabled",
"cudaDevAttrGlobalL1CacheSupported",
"cudaDevAttrGlobalMemoryBusWidth",
"cudaDevAttrGpuOverlap",
"cudaDevAttrHostNativeAtomicSupported",
"cudaDevAttrIntegrated",
"cudaDevAttrIsMultiGpuBoard",
"cudaDevAttrKernelExecTimeout",
"cudaDevAttrL2CacheSize",
"cudaDevAttrLocalL1CacheSupported",
"cudaDevAttrManagedMemory",
"cudaDevAttrMaxBlockDimX",
"cudaDevAttrMaxBlockDimY",
"cudaDevAttrMaxBlockDimZ",
"cudaDevAttrMaxBlocksPerMultiprocessor",
"cudaDevAttrMaxGridDimX",
"cudaDevAttrMaxGridDimY",
"cudaDevAttrMaxGridDimZ",
"cudaDevAttrMaxPitch",
"cudaDevAttrMaxRegistersPerBlock",
"cudaDevAttrMaxRegistersPerMultiprocessor",
"cudaDevAttrMaxSharedMemoryPerBlock",
"cudaDevAttrMaxSharedMemoryPerBlockOptin",
"cudaDevAttrMaxSharedMemoryPerMultiprocessor",
"cudaDevAttrMaxSurface1DLayeredWidth",
"cudaDevAttrMaxSurface1DWidth",
"cudaDevAttrMaxSurface2DHeight",
"cudaDevAttrMaxSurface2DLayeredHeight",
"cudaDevAttrMaxSurface2DLayeredWidth",
"cudaDevAttrMaxSurface2DWidth",
"cudaDevAttrMaxSurface3DDepth",
"cudaDevAttrMaxSurface3DHeight",
"cudaDevAttrMaxSurface3DWidth",
"cudaDevAttrMaxSurfaceCubemapLayeredWidth",
"cudaDevAttrMaxSurfaceCubemapWidth",
"cudaDevAttrMaxTexture1DLayeredWidth",
"cudaDevAttrMaxTexture1DLinearWidth",
"cudaDevAttrMaxTexture1DMipmappedWidth",
"cudaDevAttrMaxTexture1DWidth",
"cudaDevAttrMaxTexture2DGatherHeight",
"cudaDevAttrMaxTexture2DGatherWidth",
"cudaDevAttrMaxTexture2DHeight",
"cudaDevAttrMaxTexture2DLayeredHeight",
"cudaDevAttrMaxTexture2DLayeredWidth",
"cudaDevAttrMaxTexture2DLinearHeight",
"cudaDevAttrMaxTexture2DLinearPitch",
"cudaDevAttrMaxTexture2DLinearWidth",
"cudaDevAttrMaxTexture2DMipmappedHeight",
"cudaDevAttrMaxTexture2DMipmappedWidth",
"cudaDevAttrMaxTexture2DWidth",
"cudaDevAttrMaxTexture3DDepth",
"cudaDevAttrMaxTexture3DDepthAlt",
"cudaDevAttrMaxTexture3DHeight",
"cudaDevAttrMaxTexture3DHeightAlt",
"cudaDevAttrMaxTexture3DWidth",
"cudaDevAttrMaxTexture3DWidthAlt",
"cudaDevAttrMaxTextureCubemapLayeredWidth",
"cudaDevAttrMaxTextureCubemapWidth",
"cudaDevAttrMaxThreadsPerBlock",
"cudaDevAttrMaxThreadsPerMultiProcessor",
"cudaDevAttrMemoryClockRate",
"cudaDevAttrMultiGpuBoardGroupID",
"cudaDevAttrMultiProcessorCount",
"cudaDevAttrPageableMemoryAccess",
"cudaDevAttrPageableMemoryAccessUsesHostPageTables",
"cudaDevAttrPciBusId",
"cudaDevAttrPciDeviceId",
"cudaDevAttrPciDomainId",
"cudaDevAttrReserved94",
"cudaDevAttrSingleToDoublePrecisionPerfRatio",
"cudaDevAttrStreamPrioritiesSupported",
"cudaDevAttrSurfaceAlignment",
"cudaDevAttrTccDriver",
"cudaDevAttrTextureAlignment",
"cudaDevAttrTexturePitchAlignment",
"cudaDevAttrTotalConstantMemory",
"cudaDevAttrUnifiedAddressing",
"cudaDevAttrWarpSize",
"cudaDevP2PAttrAccessSupported",
"cudaDevP2PAttrCudaArrayAccessSupported",
"cudaDevP2PAttrNativeAtomicSupported",
"cudaDevP2PAttrPerformanceRank",
"cudaDeviceAttr",
"cudaDeviceLmemResizeToMax",
"cudaDeviceMapHost",
"cudaDeviceP2PAttr",
"cudaDeviceProp",
"cudaDeviceScheduleAuto",
"cudaDeviceScheduleBlockingSync",
"cudaDeviceScheduleMask",
"cudaDeviceScheduleSpin",
"cudaDeviceScheduleYield",
"cudaError",
"cudaErrorAlreadyAcquired",
"cudaErrorAlreadyMapped",
"cudaErrorArrayIsMapped",
"cudaErrorAssert",
"cudaErrorCapturedEvent",
"cudaErrorContextIsDestroyed",
"cudaErrorCooperativeLaunchTooLarge",
"cudaErrorCudartUnloading",
"cudaErrorDeviceAlreadyInUse",
"cudaErrorDeviceUninitialized",
"cudaErrorECCUncorrectable",
"cudaErrorFileNotFound",
"cudaErrorHostMemoryAlreadyRegistered",
"cudaErrorHostMemoryNotRegistered",
"cudaErrorIllegalAddress",
"cudaErrorInitializationError",
"cudaErrorInsufficientDriver",
"cudaErrorInvalidConfiguration",
"cudaErrorInvalidDevice",
"cudaErrorInvalidDeviceFunction",
"cudaErrorInvalidGraphicsContext",
"cudaErrorInvalidKernelImage",
"cudaErrorInvalidMemcpyDirection",
"cudaErrorInvalidPitchValue",
"cudaErrorInvalidPtx",
"cudaErrorInvalidResourceHandle",
"cudaErrorInvalidSource",
"cudaErrorInvalidSymbol",
"cudaErrorInvalidValue",
"cudaErrorLaunchFailure",
"cudaErrorLaunchOutOfResources",
"cudaErrorLaunchTimeout",
"cudaErrorMapBufferObjectFailed",
"cudaErrorMemoryAllocation",
"cudaErrorMissingConfiguration",
"cudaErrorNoDevice",
"cudaErrorNoKernelImageForDevice",
"cudaErrorNotMapped",
"cudaErrorNotMappedAsArray",
"cudaErrorNotMappedAsPointer",
"cudaErrorNotReady",
"cudaErrorNotSupported",
"cudaErrorOperatingSystem",
"cudaErrorPeerAccessAlreadyEnabled",
"cudaErrorPeerAccessNotEnabled",
"cudaErrorPeerAccessUnsupported",
"cudaErrorProfilerDisabled",
"cudaErrorSetOnActiveProcess",
"cudaErrorSharedObjectInitFailed",
"cudaErrorSharedObjectSymbolNotFound",
"cudaErrorStreamCaptureImplicit",
"cudaErrorStreamCaptureInvalidated",
"cudaErrorStreamCaptureIsolation",
"cudaErrorStreamCaptureMerge",
"cudaErrorStreamCaptureUnjoined",
"cudaErrorStreamCaptureUnmatched",
"cudaErrorStreamCaptureUnsupported",
"cudaErrorStreamCaptureWrongThread",
"cudaErrorSymbolNotFound",
"cudaErrorUnknown",
"cudaErrorUnmapBufferObjectFailed",
"cudaErrorUnsupportedLimit",
"cudaError_t",
"cudaEventBlockingSync",
"cudaEventDefault",
"cudaEventDisableTiming",
"cudaEventInterprocess",
"cudaEvent_t",
"cudaExtent",
"cudaExternalMemoryBufferDesc",
"cudaExternalMemoryHandleDesc",
"cudaExternalMemoryHandleType",
"cudaExternalMemoryHandleTypeD3D11Resource",
"cudaExternalMemoryHandleTypeD3D11ResourceKmt",
"cudaExternalMemoryHandleTypeD3D12Heap",
"cudaExternalMemoryHandleTypeD3D12Resource",
"cudaExternalMemoryHandleTypeOpaqueFd",
"cudaExternalMemoryHandleTypeOpaqueWin32",
"cudaExternalMemoryHandleTypeOpaqueWin32Kmt",
"cudaExternalMemory_t",
"cudaExternalSemaphoreHandleDesc",
"cudaExternalSemaphoreHandleType",
"cudaExternalSemaphoreHandleTypeD3D12Fence",
"cudaExternalSemaphoreHandleTypeOpaqueFd",
"cudaExternalSemaphoreHandleTypeOpaqueWin32",
"cudaExternalSemaphoreHandleTypeOpaqueWin32Kmt",
"cudaExternalSemaphoreSignalParams",
"cudaExternalSemaphoreSignalParams_v1",
"cudaExternalSemaphoreWaitParams",
"cudaExternalSemaphoreWaitParams_v1",
"cudaExternalSemaphore_t",
"cudaFilterModeLinear",
"cudaFilterModePoint",
"cudaFuncAttribute",
"cudaFuncAttributeMax",
"cudaFuncAttributeMaxDynamicSharedMemorySize",
"cudaFuncAttributePreferredSharedMemoryCarveout",
"cudaFuncAttributes",
"cudaFuncCache",
"cudaFuncCachePreferEqual",
"cudaFuncCachePreferL1",
"cudaFuncCachePreferNone",
"cudaFuncCachePreferShared",
"cudaFunction_t",
"cudaGLDeviceList",
"cudaGLDeviceListAll",
"cudaGLDeviceListCurrentFrame",
"cudaGLDeviceListNextFrame",
"cudaGraphExecUpdateError",
"cudaGraphExecUpdateErrorFunctionChanged",
"cudaGraphExecUpdateErrorNodeTypeChanged",
"cudaGraphExecUpdateErrorNotSupported",
"cudaGraphExecUpdateErrorParametersChanged",
"cudaGraphExecUpdateErrorTopologyChanged",
"cudaGraphExecUpdateErrorUnsupportedFunctionChange",
"cudaGraphExecUpdateResult",
"cudaGraphExecUpdateSuccess",
"cudaGraphExec_t",
"cudaGraphNodeType",
"cudaGraphNodeTypeCount",
"cudaGraphNodeTypeEmpty",
"cudaGraphNodeTypeEventRecord",
"cudaGraphNodeTypeGraph",
"cudaGraphNodeTypeHost",
"cudaGraphNodeTypeKernel",
"cudaGraphNodeTypeMemcpy",
"cudaGraphNodeTypeMemset",
"cudaGraphNodeTypeWaitEvent",
"cudaGraphNode_t",
"cudaGraph_t",
"cudaGraphicsRegisterFlags",
"cudaGraphicsRegisterFlagsNone",
"cudaGraphicsRegisterFlagsReadOnly",
"cudaGraphicsRegisterFlagsSurfaceLoadStore",
"cudaGraphicsRegisterFlagsTextureGather",
"cudaGraphicsRegisterFlagsWriteDiscard",
"cudaGraphicsResource",
"cudaGraphicsResource_t",
"cudaHostAllocDefault",
"cudaHostAllocMapped",
"cudaHostAllocPortable",
"cudaHostAllocWriteCombined",
"cudaHostFn_t",
"cudaHostNodeParams",
"cudaHostRegisterDefault",
"cudaHostRegisterIoMemory",
"cudaHostRegisterMapped",
"cudaHostRegisterPortable",
"cudaInvalidDeviceId",
"cudaIpcEventHandle_st",
"cudaIpcEventHandle_t",
"cudaIpcMemHandle_st",
"cudaIpcMemHandle_t",
"cudaIpcMemLazyEnablePeerAccess",
"cudaKernelNodeParams",
"cudaLaunchParams",
"cudaLimit",
"cudaLimitMallocHeapSize",
"cudaLimitPrintfFifoSize",
"cudaMemAdviseSetAccessedBy",
"cudaMemAdviseSetPreferredLocation",
"cudaMemAdviseSetReadMostly",
"cudaMemAdviseUnsetAccessedBy",
"cudaMemAdviseUnsetPreferredLocation",
"cudaMemAdviseUnsetReadMostly",
"cudaMemAttachGlobal",
"cudaMemAttachHost",
"cudaMemAttachSingle",
"cudaMemRangeAttribute",
"cudaMemRangeAttributeAccessedBy",
"cudaMemRangeAttributeLastPrefetchLocation",
"cudaMemRangeAttributePreferredLocation",
"cudaMemRangeAttributeReadMostly",
"cudaMemcpy3DParms",
"cudaMemcpyDefault",
"cudaMemcpyDeviceToDevice",
"cudaMemcpyDeviceToHost",
"cudaMemcpyHostToDevice",
"cudaMemcpyHostToHost",
"cudaMemcpyKind",
"cudaMemoryAdvise",
"cudaMemoryType",
"cudaMemoryTypeDevice",
"cudaMemoryTypeHost",
"cudaMemsetParams",
"cudaMipmappedArray",
"cudaMipmappedArray_const_t",
"cudaMipmappedArray_t",
"cudaOccupancyDefault",
"cudaPitchedPtr",
"cudaPointerAttributes",
"cudaPos",
"cudaReadModeElementType",
"cudaReadModeNormalizedFloat",
"cudaResViewFormatFloat1",
"cudaResViewFormatFloat2",
"cudaResViewFormatFloat4",
"cudaResViewFormatHalf1",
"cudaResViewFormatHalf2",
"cudaResViewFormatHalf4",
"cudaResViewFormatNone",
"cudaResViewFormatSignedBlockCompressed4",
"cudaResViewFormatSignedBlockCompressed5",
"cudaResViewFormatSignedBlockCompressed6H",
"cudaResViewFormatSignedChar1",
"cudaResViewFormatSignedChar2",
"cudaResViewFormatSignedChar4",
"cudaResViewFormatSignedInt1",
"cudaResViewFormatSignedInt2",
"cudaResViewFormatSignedInt4",
"cudaResViewFormatSignedShort1",
"cudaResViewFormatSignedShort2",
"cudaResViewFormatSignedShort4",
"cudaResViewFormatUnsignedBlockCompressed1",
"cudaResViewFormatUnsignedBlockCompressed2",
"cudaResViewFormatUnsignedBlockCompressed3",
"cudaResViewFormatUnsignedBlockCompressed4",
"cudaResViewFormatUnsignedBlockCompressed5",
"cudaResViewFormatUnsignedBlockCompressed6H",
"cudaResViewFormatUnsignedBlockCompressed7",
"cudaResViewFormatUnsignedChar1",
"cudaResViewFormatUnsignedChar2",
"cudaResViewFormatUnsignedChar4",
"cudaResViewFormatUnsignedInt1",
"cudaResViewFormatUnsignedInt2",
"cudaResViewFormatUnsignedInt4",
"cudaResViewFormatUnsignedShort1",
"cudaResViewFormatUnsignedShort2",
"cudaResViewFormatUnsignedShort4",
"cudaResourceDesc",
"cudaResourceType",
"cudaResourceTypeArray",
"cudaResourceTypeLinear",
"cudaResourceTypeMipmappedArray",
"cudaResourceTypePitch2D",
"cudaResourceViewDesc",
"cudaResourceViewFormat",
"cudaSharedMemBankSizeDefault",
"cudaSharedMemBankSizeEightByte",
"cudaSharedMemBankSizeFourByte",
"cudaSharedMemConfig",
"cudaStreamCallback_t",
"cudaStreamCaptureMode",
"cudaStreamCaptureModeGlobal",
"cudaStreamCaptureModeRelaxed",
"cudaStreamCaptureModeThreadLocal",
"cudaStreamCaptureStatus",
"cudaStreamCaptureStatusActive",
"cudaStreamCaptureStatusInvalidated",
"cudaStreamCaptureStatusNone",
"cudaStreamDefault",
"cudaStreamNonBlocking",
"cudaStreamPerThread",
"cudaStream_t",
"cudaSuccess",
"cudaSurfaceBoundaryMode",
"cudaSurfaceObject_t",
"cudaTextureAddressMode",
"cudaTextureDesc",
"cudaTextureFilterMode",
"cudaTextureObject_t",
"cudaTextureReadMode",
"cudaTextureType1D",
"cudaTextureType1DLayered",
"cudaTextureType2D",
"cudaTextureType2DLayered",
"cudaTextureType3D",
"cudaTextureTypeCubemap",
"cudaTextureTypeCubemapLayered",
"surfaceReference",
"cuTexObjectGetTextureDesc",
"cudaChooseDevice",
"cudaCreateChannelDesc",
"cudaCreateSurfaceObject",
"cudaCreateTextureObject",
"cudaDestroyExternalMemory",
"cudaDestroyExternalSemaphore",
"cudaDestroySurfaceObject",
"cudaDestroyTextureObject",
"cudaDeviceCanAccessPeer",
"cudaDeviceDisablePeerAccess",
"cudaDeviceEnablePeerAccess",
"cudaDeviceGetAttribute",
"cudaDeviceGetByPCIBusId",
"cudaDeviceGetCacheConfig",
"cudaDeviceGetLimit",
"cudaDeviceGetP2PAttribute",
"cudaDeviceGetPCIBusId",
"cudaDeviceGetSharedMemConfig",
"cudaDeviceGetStreamPriorityRange",
"cudaDeviceReset",
"cudaDeviceSetCacheConfig",
"cudaDeviceSetSharedMemConfig",
"cudaDeviceSynchronize",
"cudaDriverGetVersion",
"cudaEventCreate",
"cudaEventCreateWithFlags",
"cudaEventDestroy",
"cudaEventElapsedTime",
"cudaEventQuery",
"cudaEventRecord",
"cudaEventSynchronize",
"cudaExternalMemoryGetMappedBuffer",
"cudaFree",
"cudaFreeArray",
"cudaFreeHost",
"cudaFreeMipmappedArray",
"cudaFuncGetAttributes",
"cudaFuncSetAttribute",
"cudaFuncSetCacheConfig",
"cudaFuncSetSharedMemConfig",
"cudaGLGetDevices",
"cudaGetChannelDesc",
"cudaGetDevice",
"cudaGetDeviceCount",
"cudaGetDeviceFlags",
"cudaGetDeviceProperties",
"cudaGetErrorName",
"cudaGetErrorString",
"cudaGetLastError",
"cudaGetMipmappedArrayLevel",
"cudaGetSymbolAddress",
"cudaGetSymbolSize",
"cudaGetTextureObjectResourceDesc",
"cudaGetTextureObjectResourceViewDesc",
"cudaGraphAddDependencies",
"cudaGraphAddEmptyNode",
"cudaGraphAddKernelNode",
"cudaGraphAddMemcpyNode",
"cudaGraphAddMemcpyNode1D",
"cudaGraphAddMemsetNode",
"cudaGraphCreate",
"cudaGraphDestroy",
"cudaGraphExecDestroy",
"cudaGraphExecKernelNodeSetParams",
"cudaGraphGetNodes",
"cudaGraphGetRootNodes",
"cudaGraphInstantiate",
"cudaGraphKernelNodeGetParams",
"cudaGraphKernelNodeSetParams",
"cudaGraphLaunch",
"cudaGraphMemcpyNodeGetParams",
"cudaGraphMemcpyNodeSetParams",
"cudaGraphMemsetNodeGetParams",
"cudaGraphMemsetNodeSetParams",
"cudaGraphicsGLRegisterBuffer",
"cudaGraphicsMapResources",
"cudaGraphicsResourceGetMappedPointer",
"cudaGraphicsUnmapResources",
"cudaGraphicsUnregisterResource",
"cudaHostAlloc",
"cudaHostGetDevicePointer",
"cudaHostGetFlags",
"cudaHostRegister",
"cudaHostUnregister",
"cudaImportExternalMemory",
"cudaImportExternalSemaphore",
"cudaIpcCloseMemHandle",
"cudaIpcGetEventHandle",
"cudaIpcGetMemHandle",
"cudaIpcOpenEventHandle",
"cudaIpcOpenMemHandle",
"cudaLaunchCooperativeKernel",
"cudaLaunchKernel",
"cudaMalloc",
"cudaMalloc3D",
"cudaMalloc3DArray",
"cudaMallocArray",
"cudaMallocHost",
"cudaMallocManaged",
"cudaMallocMipmappedArray",
"cudaMallocPitch",
"cudaMemAdvise",
"cudaMemGetInfo",
"cudaMemPrefetchAsync",
"cudaMemRangeGetAttribute",
"cudaMemRangeGetAttributes",
"cudaMemcpy",
"cudaMemcpy2D",
"cudaMemcpy2DAsync",
"cudaMemcpy2DFromArray",
"cudaMemcpy2DFromArrayAsync",
"cudaMemcpy2DToArray",
"cudaMemcpy2DToArrayAsync",
"cudaMemcpy3D",
"cudaMemcpy3DAsync",
"cudaMemcpyAsync",
"cudaMemcpyFromSymbol",
"cudaMemcpyFromSymbolAsync",
"cudaMemcpyPeer",
"cudaMemcpyPeerAsync",
"cudaMemcpyToSymbol",
"cudaMemcpyToSymbolAsync",
"cudaMemset",
"cudaMemset2D",
"cudaMemset2DAsync",
"cudaMemset3D",
"cudaMemset3DAsync",
"cudaMemsetAsync",
"cudaOccupancyMaxActiveBlocksPerMultiprocessor",
"cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags",
"cudaOccupancyMaxPotentialBlockSize",
"cudaOccupancyMaxPotentialBlockSizeWithFlags",
"cudaPeekAtLastError",
"cudaPointerGetAttributes",
"cudaRuntimeGetVersion",
"cudaSetDevice",
"cudaSetDeviceFlags",
"cudaSignalExternalSemaphoresAsync",
"cudaStreamAddCallback",
"cudaStreamAttachMemAsync",
"cudaStreamBeginCapture",
"cudaStreamCreate",
"cudaStreamCreateWithFlags",
"cudaStreamCreateWithPriority",
"cudaStreamDestroy",
"cudaStreamEndCapture",
"cudaStreamGetFlags",
"cudaStreamGetPriority",
"cudaStreamQuery",
"cudaStreamSynchronize",
"cudaStreamWaitEvent",
"cudaWaitExternalSemaphoresAsync",
"make_cudaExtent",
"make_cudaPitchedPtr",
"make_cudaPos",
};


__global__ void kern(int arg0 = 0, int arg1 = 0, int arg2 = 0, int arg3 = 0, int arg4 = 0, int arg5 = 0, int arg6 = 0, int arg7 = 0, int arg8 = 0, int arg9 = 0, int arg10 = 0, int arg11 = 0, int arg12 = 0, int arg13 = 0, int arg14 = 0, int arg15 = 0, int arg16 = 0, int arg17 = 0, int arg18 = 0, int arg19 = 0, int arg20 = 0, int arg21 = 0, int arg22 = 0, int arg23 = 0, int arg24 = 0, int arg25 = 0, int arg26 = 0, int arg27 = 0, int arg28 = 0, int arg29 = 0, int arg30 = 0, int arg31 = 0, int arg32 = 0) {}

template <int numblocks, int numthreads>
[[clang::matcher("kernel_launch 0 args 2 params")]]
auto cuda_kernel_launch_0_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>();
  }
}

template <int numblocks, int numthreads>
[[clang::replace("kernel_launch 0 args 2 params")]]
auto cuda_kernel_launch_0_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0);
  }
}

template <int numblocks, int numthreads, int shmem>
[[clang::matcher("kernel_launch 0 args 3 params")]]
auto cuda_kernel_launch_0_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>();
  }
}

template <int numblocks, int numthreads, int shmem>
[[clang::replace("kernel_launch 0 args 3 params")]]
auto cuda_kernel_launch_0_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0);
  }
}

template <int numblocks, int numthreads, int shmem, int stream>
[[clang::matcher("kernel_launch 0 args 4 params")]]
auto cuda_kernel_launch_0_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>();
  }
}

template <int numblocks, int numthreads, int shmem, int stream>
[[clang::replace("kernel_launch 0 args 4 params")]]
auto cuda_kernel_launch_0_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream);
  }
}

template <int numblocks, int numthreads, int arg1>
[[clang::matcher("kernel_launch 1 args 2 params")]]
auto cuda_kernel_launch_1_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1);
  }
}

template <int numblocks, int numthreads, int arg1>
[[clang::replace("kernel_launch 1 args 2 params")]]
auto cuda_kernel_launch_1_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1>
[[clang::matcher("kernel_launch 1 args 3 params")]]
auto cuda_kernel_launch_1_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1>
[[clang::replace("kernel_launch 1 args 3 params")]]
auto cuda_kernel_launch_1_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1>
[[clang::matcher("kernel_launch 1 args 4 params")]]
auto cuda_kernel_launch_1_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1>
[[clang::replace("kernel_launch 1 args 4 params")]]
auto cuda_kernel_launch_1_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2>
[[clang::matcher("kernel_launch 2 args 2 params")]]
auto cuda_kernel_launch_2_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2>
[[clang::replace("kernel_launch 2 args 2 params")]]
auto cuda_kernel_launch_2_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2>
[[clang::matcher("kernel_launch 2 args 3 params")]]
auto cuda_kernel_launch_2_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2>
[[clang::replace("kernel_launch 2 args 3 params")]]
auto cuda_kernel_launch_2_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2>
[[clang::matcher("kernel_launch 2 args 4 params")]]
auto cuda_kernel_launch_2_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2>
[[clang::replace("kernel_launch 2 args 4 params")]]
auto cuda_kernel_launch_2_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3>
[[clang::matcher("kernel_launch 3 args 2 params")]]
auto cuda_kernel_launch_3_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3>
[[clang::replace("kernel_launch 3 args 2 params")]]
auto cuda_kernel_launch_3_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3>
[[clang::matcher("kernel_launch 3 args 3 params")]]
auto cuda_kernel_launch_3_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3>
[[clang::replace("kernel_launch 3 args 3 params")]]
auto cuda_kernel_launch_3_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3>
[[clang::matcher("kernel_launch 3 args 4 params")]]
auto cuda_kernel_launch_3_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3>
[[clang::replace("kernel_launch 3 args 4 params")]]
auto cuda_kernel_launch_3_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4>
[[clang::matcher("kernel_launch 4 args 2 params")]]
auto cuda_kernel_launch_4_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4>
[[clang::replace("kernel_launch 4 args 2 params")]]
auto cuda_kernel_launch_4_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4>
[[clang::matcher("kernel_launch 4 args 3 params")]]
auto cuda_kernel_launch_4_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4>
[[clang::replace("kernel_launch 4 args 3 params")]]
auto cuda_kernel_launch_4_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4>
[[clang::matcher("kernel_launch 4 args 4 params")]]
auto cuda_kernel_launch_4_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4>
[[clang::replace("kernel_launch 4 args 4 params")]]
auto cuda_kernel_launch_4_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5>
[[clang::matcher("kernel_launch 5 args 2 params")]]
auto cuda_kernel_launch_5_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5>
[[clang::replace("kernel_launch 5 args 2 params")]]
auto cuda_kernel_launch_5_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5>
[[clang::matcher("kernel_launch 5 args 3 params")]]
auto cuda_kernel_launch_5_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5>
[[clang::replace("kernel_launch 5 args 3 params")]]
auto cuda_kernel_launch_5_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5>
[[clang::matcher("kernel_launch 5 args 4 params")]]
auto cuda_kernel_launch_5_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5>
[[clang::replace("kernel_launch 5 args 4 params")]]
auto cuda_kernel_launch_5_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6>
[[clang::matcher("kernel_launch 6 args 2 params")]]
auto cuda_kernel_launch_6_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6>
[[clang::replace("kernel_launch 6 args 2 params")]]
auto cuda_kernel_launch_6_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6>
[[clang::matcher("kernel_launch 6 args 3 params")]]
auto cuda_kernel_launch_6_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6>
[[clang::replace("kernel_launch 6 args 3 params")]]
auto cuda_kernel_launch_6_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6>
[[clang::matcher("kernel_launch 6 args 4 params")]]
auto cuda_kernel_launch_6_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6>
[[clang::replace("kernel_launch 6 args 4 params")]]
auto cuda_kernel_launch_6_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7>
[[clang::matcher("kernel_launch 7 args 2 params")]]
auto cuda_kernel_launch_7_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7>
[[clang::replace("kernel_launch 7 args 2 params")]]
auto cuda_kernel_launch_7_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7>
[[clang::matcher("kernel_launch 7 args 3 params")]]
auto cuda_kernel_launch_7_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7>
[[clang::replace("kernel_launch 7 args 3 params")]]
auto cuda_kernel_launch_7_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7>
[[clang::matcher("kernel_launch 7 args 4 params")]]
auto cuda_kernel_launch_7_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7>
[[clang::replace("kernel_launch 7 args 4 params")]]
auto cuda_kernel_launch_7_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8>
[[clang::matcher("kernel_launch 8 args 2 params")]]
auto cuda_kernel_launch_8_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8>
[[clang::replace("kernel_launch 8 args 2 params")]]
auto cuda_kernel_launch_8_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8>
[[clang::matcher("kernel_launch 8 args 3 params")]]
auto cuda_kernel_launch_8_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8>
[[clang::replace("kernel_launch 8 args 3 params")]]
auto cuda_kernel_launch_8_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8>
[[clang::matcher("kernel_launch 8 args 4 params")]]
auto cuda_kernel_launch_8_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8>
[[clang::replace("kernel_launch 8 args 4 params")]]
auto cuda_kernel_launch_8_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9>
[[clang::matcher("kernel_launch 9 args 2 params")]]
auto cuda_kernel_launch_9_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9>
[[clang::replace("kernel_launch 9 args 2 params")]]
auto cuda_kernel_launch_9_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9>
[[clang::matcher("kernel_launch 9 args 3 params")]]
auto cuda_kernel_launch_9_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9>
[[clang::replace("kernel_launch 9 args 3 params")]]
auto cuda_kernel_launch_9_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9>
[[clang::matcher("kernel_launch 9 args 4 params")]]
auto cuda_kernel_launch_9_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9>
[[clang::replace("kernel_launch 9 args 4 params")]]
auto cuda_kernel_launch_9_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10>
[[clang::matcher("kernel_launch 10 args 2 params")]]
auto cuda_kernel_launch_10_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10>
[[clang::replace("kernel_launch 10 args 2 params")]]
auto cuda_kernel_launch_10_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10>
[[clang::matcher("kernel_launch 10 args 3 params")]]
auto cuda_kernel_launch_10_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10>
[[clang::replace("kernel_launch 10 args 3 params")]]
auto cuda_kernel_launch_10_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10>
[[clang::matcher("kernel_launch 10 args 4 params")]]
auto cuda_kernel_launch_10_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10>
[[clang::replace("kernel_launch 10 args 4 params")]]
auto cuda_kernel_launch_10_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11>
[[clang::matcher("kernel_launch 11 args 2 params")]]
auto cuda_kernel_launch_11_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11>
[[clang::replace("kernel_launch 11 args 2 params")]]
auto cuda_kernel_launch_11_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11>
[[clang::matcher("kernel_launch 11 args 3 params")]]
auto cuda_kernel_launch_11_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11>
[[clang::replace("kernel_launch 11 args 3 params")]]
auto cuda_kernel_launch_11_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11>
[[clang::matcher("kernel_launch 11 args 4 params")]]
auto cuda_kernel_launch_11_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11>
[[clang::replace("kernel_launch 11 args 4 params")]]
auto cuda_kernel_launch_11_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12>
[[clang::matcher("kernel_launch 12 args 2 params")]]
auto cuda_kernel_launch_12_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12>
[[clang::replace("kernel_launch 12 args 2 params")]]
auto cuda_kernel_launch_12_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12>
[[clang::matcher("kernel_launch 12 args 3 params")]]
auto cuda_kernel_launch_12_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12>
[[clang::replace("kernel_launch 12 args 3 params")]]
auto cuda_kernel_launch_12_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12>
[[clang::matcher("kernel_launch 12 args 4 params")]]
auto cuda_kernel_launch_12_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12>
[[clang::replace("kernel_launch 12 args 4 params")]]
auto cuda_kernel_launch_12_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13>
[[clang::matcher("kernel_launch 13 args 2 params")]]
auto cuda_kernel_launch_13_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13>
[[clang::replace("kernel_launch 13 args 2 params")]]
auto cuda_kernel_launch_13_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13>
[[clang::matcher("kernel_launch 13 args 3 params")]]
auto cuda_kernel_launch_13_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13>
[[clang::replace("kernel_launch 13 args 3 params")]]
auto cuda_kernel_launch_13_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13>
[[clang::matcher("kernel_launch 13 args 4 params")]]
auto cuda_kernel_launch_13_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13>
[[clang::replace("kernel_launch 13 args 4 params")]]
auto cuda_kernel_launch_13_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14>
[[clang::matcher("kernel_launch 14 args 2 params")]]
auto cuda_kernel_launch_14_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14>
[[clang::replace("kernel_launch 14 args 2 params")]]
auto cuda_kernel_launch_14_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14>
[[clang::matcher("kernel_launch 14 args 3 params")]]
auto cuda_kernel_launch_14_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14>
[[clang::replace("kernel_launch 14 args 3 params")]]
auto cuda_kernel_launch_14_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14>
[[clang::matcher("kernel_launch 14 args 4 params")]]
auto cuda_kernel_launch_14_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14>
[[clang::replace("kernel_launch 14 args 4 params")]]
auto cuda_kernel_launch_14_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15>
[[clang::matcher("kernel_launch 15 args 2 params")]]
auto cuda_kernel_launch_15_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15>
[[clang::replace("kernel_launch 15 args 2 params")]]
auto cuda_kernel_launch_15_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15>
[[clang::matcher("kernel_launch 15 args 3 params")]]
auto cuda_kernel_launch_15_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15>
[[clang::replace("kernel_launch 15 args 3 params")]]
auto cuda_kernel_launch_15_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15>
[[clang::matcher("kernel_launch 15 args 4 params")]]
auto cuda_kernel_launch_15_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15>
[[clang::replace("kernel_launch 15 args 4 params")]]
auto cuda_kernel_launch_15_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16>
[[clang::matcher("kernel_launch 16 args 2 params")]]
auto cuda_kernel_launch_16_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16>
[[clang::replace("kernel_launch 16 args 2 params")]]
auto cuda_kernel_launch_16_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16>
[[clang::matcher("kernel_launch 16 args 3 params")]]
auto cuda_kernel_launch_16_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16>
[[clang::replace("kernel_launch 16 args 3 params")]]
auto cuda_kernel_launch_16_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16>
[[clang::matcher("kernel_launch 16 args 4 params")]]
auto cuda_kernel_launch_16_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16>
[[clang::replace("kernel_launch 16 args 4 params")]]
auto cuda_kernel_launch_16_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17>
[[clang::matcher("kernel_launch 17 args 2 params")]]
auto cuda_kernel_launch_17_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17>
[[clang::replace("kernel_launch 17 args 2 params")]]
auto cuda_kernel_launch_17_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17>
[[clang::matcher("kernel_launch 17 args 3 params")]]
auto cuda_kernel_launch_17_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17>
[[clang::replace("kernel_launch 17 args 3 params")]]
auto cuda_kernel_launch_17_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17>
[[clang::matcher("kernel_launch 17 args 4 params")]]
auto cuda_kernel_launch_17_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17>
[[clang::replace("kernel_launch 17 args 4 params")]]
auto cuda_kernel_launch_17_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18>
[[clang::matcher("kernel_launch 18 args 2 params")]]
auto cuda_kernel_launch_18_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18>
[[clang::replace("kernel_launch 18 args 2 params")]]
auto cuda_kernel_launch_18_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18>
[[clang::matcher("kernel_launch 18 args 3 params")]]
auto cuda_kernel_launch_18_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18>
[[clang::replace("kernel_launch 18 args 3 params")]]
auto cuda_kernel_launch_18_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18>
[[clang::matcher("kernel_launch 18 args 4 params")]]
auto cuda_kernel_launch_18_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18>
[[clang::replace("kernel_launch 18 args 4 params")]]
auto cuda_kernel_launch_18_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19>
[[clang::matcher("kernel_launch 19 args 2 params")]]
auto cuda_kernel_launch_19_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19>
[[clang::replace("kernel_launch 19 args 2 params")]]
auto cuda_kernel_launch_19_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19>
[[clang::matcher("kernel_launch 19 args 3 params")]]
auto cuda_kernel_launch_19_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19>
[[clang::replace("kernel_launch 19 args 3 params")]]
auto cuda_kernel_launch_19_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19>
[[clang::matcher("kernel_launch 19 args 4 params")]]
auto cuda_kernel_launch_19_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19>
[[clang::replace("kernel_launch 19 args 4 params")]]
auto cuda_kernel_launch_19_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20>
[[clang::matcher("kernel_launch 20 args 2 params")]]
auto cuda_kernel_launch_20_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20>
[[clang::replace("kernel_launch 20 args 2 params")]]
auto cuda_kernel_launch_20_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20>
[[clang::matcher("kernel_launch 20 args 3 params")]]
auto cuda_kernel_launch_20_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20>
[[clang::replace("kernel_launch 20 args 3 params")]]
auto cuda_kernel_launch_20_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20>
[[clang::matcher("kernel_launch 20 args 4 params")]]
auto cuda_kernel_launch_20_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20>
[[clang::replace("kernel_launch 20 args 4 params")]]
auto cuda_kernel_launch_20_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21>
[[clang::matcher("kernel_launch 21 args 2 params")]]
auto cuda_kernel_launch_21_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21>
[[clang::replace("kernel_launch 21 args 2 params")]]
auto cuda_kernel_launch_21_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21>
[[clang::matcher("kernel_launch 21 args 3 params")]]
auto cuda_kernel_launch_21_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21>
[[clang::replace("kernel_launch 21 args 3 params")]]
auto cuda_kernel_launch_21_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21>
[[clang::matcher("kernel_launch 21 args 4 params")]]
auto cuda_kernel_launch_21_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21>
[[clang::replace("kernel_launch 21 args 4 params")]]
auto cuda_kernel_launch_21_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22>
[[clang::matcher("kernel_launch 22 args 2 params")]]
auto cuda_kernel_launch_22_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22>
[[clang::replace("kernel_launch 22 args 2 params")]]
auto cuda_kernel_launch_22_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22>
[[clang::matcher("kernel_launch 22 args 3 params")]]
auto cuda_kernel_launch_22_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22>
[[clang::replace("kernel_launch 22 args 3 params")]]
auto cuda_kernel_launch_22_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22>
[[clang::matcher("kernel_launch 22 args 4 params")]]
auto cuda_kernel_launch_22_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22>
[[clang::replace("kernel_launch 22 args 4 params")]]
auto cuda_kernel_launch_22_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23>
[[clang::matcher("kernel_launch 23 args 2 params")]]
auto cuda_kernel_launch_23_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23>
[[clang::replace("kernel_launch 23 args 2 params")]]
auto cuda_kernel_launch_23_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23>
[[clang::matcher("kernel_launch 23 args 3 params")]]
auto cuda_kernel_launch_23_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23>
[[clang::replace("kernel_launch 23 args 3 params")]]
auto cuda_kernel_launch_23_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23>
[[clang::matcher("kernel_launch 23 args 4 params")]]
auto cuda_kernel_launch_23_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23>
[[clang::replace("kernel_launch 23 args 4 params")]]
auto cuda_kernel_launch_23_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24>
[[clang::matcher("kernel_launch 24 args 2 params")]]
auto cuda_kernel_launch_24_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24>
[[clang::replace("kernel_launch 24 args 2 params")]]
auto cuda_kernel_launch_24_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24>
[[clang::matcher("kernel_launch 24 args 3 params")]]
auto cuda_kernel_launch_24_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24>
[[clang::replace("kernel_launch 24 args 3 params")]]
auto cuda_kernel_launch_24_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24>
[[clang::matcher("kernel_launch 24 args 4 params")]]
auto cuda_kernel_launch_24_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24>
[[clang::replace("kernel_launch 24 args 4 params")]]
auto cuda_kernel_launch_24_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25>
[[clang::matcher("kernel_launch 25 args 2 params")]]
auto cuda_kernel_launch_25_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25>
[[clang::replace("kernel_launch 25 args 2 params")]]
auto cuda_kernel_launch_25_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25>
[[clang::matcher("kernel_launch 25 args 3 params")]]
auto cuda_kernel_launch_25_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25>
[[clang::replace("kernel_launch 25 args 3 params")]]
auto cuda_kernel_launch_25_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25>
[[clang::matcher("kernel_launch 25 args 4 params")]]
auto cuda_kernel_launch_25_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25>
[[clang::replace("kernel_launch 25 args 4 params")]]
auto cuda_kernel_launch_25_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26>
[[clang::matcher("kernel_launch 26 args 2 params")]]
auto cuda_kernel_launch_26_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26>
[[clang::replace("kernel_launch 26 args 2 params")]]
auto cuda_kernel_launch_26_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26>
[[clang::matcher("kernel_launch 26 args 3 params")]]
auto cuda_kernel_launch_26_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26>
[[clang::replace("kernel_launch 26 args 3 params")]]
auto cuda_kernel_launch_26_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26>
[[clang::matcher("kernel_launch 26 args 4 params")]]
auto cuda_kernel_launch_26_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26>
[[clang::replace("kernel_launch 26 args 4 params")]]
auto cuda_kernel_launch_26_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27>
[[clang::matcher("kernel_launch 27 args 2 params")]]
auto cuda_kernel_launch_27_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27>
[[clang::replace("kernel_launch 27 args 2 params")]]
auto cuda_kernel_launch_27_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27>
[[clang::matcher("kernel_launch 27 args 3 params")]]
auto cuda_kernel_launch_27_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27>
[[clang::replace("kernel_launch 27 args 3 params")]]
auto cuda_kernel_launch_27_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27>
[[clang::matcher("kernel_launch 27 args 4 params")]]
auto cuda_kernel_launch_27_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27>
[[clang::replace("kernel_launch 27 args 4 params")]]
auto cuda_kernel_launch_27_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28>
[[clang::matcher("kernel_launch 28 args 2 params")]]
auto cuda_kernel_launch_28_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28>
[[clang::replace("kernel_launch 28 args 2 params")]]
auto cuda_kernel_launch_28_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28>
[[clang::matcher("kernel_launch 28 args 3 params")]]
auto cuda_kernel_launch_28_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28>
[[clang::replace("kernel_launch 28 args 3 params")]]
auto cuda_kernel_launch_28_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28>
[[clang::matcher("kernel_launch 28 args 4 params")]]
auto cuda_kernel_launch_28_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28>
[[clang::replace("kernel_launch 28 args 4 params")]]
auto cuda_kernel_launch_28_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29>
[[clang::matcher("kernel_launch 29 args 2 params")]]
auto cuda_kernel_launch_29_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29>
[[clang::replace("kernel_launch 29 args 2 params")]]
auto cuda_kernel_launch_29_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29>
[[clang::matcher("kernel_launch 29 args 3 params")]]
auto cuda_kernel_launch_29_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29>
[[clang::replace("kernel_launch 29 args 3 params")]]
auto cuda_kernel_launch_29_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29>
[[clang::matcher("kernel_launch 29 args 4 params")]]
auto cuda_kernel_launch_29_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29>
[[clang::replace("kernel_launch 29 args 4 params")]]
auto cuda_kernel_launch_29_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30>
[[clang::matcher("kernel_launch 30 args 2 params")]]
auto cuda_kernel_launch_30_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30>
[[clang::replace("kernel_launch 30 args 2 params")]]
auto cuda_kernel_launch_30_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30>
[[clang::matcher("kernel_launch 30 args 3 params")]]
auto cuda_kernel_launch_30_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30>
[[clang::replace("kernel_launch 30 args 3 params")]]
auto cuda_kernel_launch_30_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30>
[[clang::matcher("kernel_launch 30 args 4 params")]]
auto cuda_kernel_launch_30_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30>
[[clang::replace("kernel_launch 30 args 4 params")]]
auto cuda_kernel_launch_30_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31>
[[clang::matcher("kernel_launch 31 args 2 params")]]
auto cuda_kernel_launch_31_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31>
[[clang::replace("kernel_launch 31 args 2 params")]]
auto cuda_kernel_launch_31_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31>
[[clang::matcher("kernel_launch 31 args 3 params")]]
auto cuda_kernel_launch_31_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31>
[[clang::replace("kernel_launch 31 args 3 params")]]
auto cuda_kernel_launch_31_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31>
[[clang::matcher("kernel_launch 31 args 4 params")]]
auto cuda_kernel_launch_31_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31>
[[clang::replace("kernel_launch 31 args 4 params")]]
auto cuda_kernel_launch_31_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31, int arg32>
[[clang::matcher("kernel_launch 32 args 2 params")]]
auto cuda_kernel_launch_32_2() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32);
  }
}

template <int numblocks, int numthreads, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31, int arg32>
[[clang::replace("kernel_launch 32 args 2 params")]]
auto cuda_kernel_launch_32_2_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, 0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31, int arg32>
[[clang::matcher("kernel_launch 32 args 3 params")]]
auto cuda_kernel_launch_32_3() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32);
  }
}

template <int numblocks, int numthreads, int shmem, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31, int arg32>
[[clang::replace("kernel_launch 32 args 3 params")]]
auto cuda_kernel_launch_32_3_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31, int arg32>
[[clang::matcher("kernel_launch 32 args 4 params")]]
auto cuda_kernel_launch_32_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32);
  }
}

template <int numblocks, int numthreads, int shmem, int stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31, int arg32>
[[clang::replace("kernel_launch 32 args 4 params")]]
auto cuda_kernel_launch_32_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32);
  }
}



[[clang::matcher("CUDA_IPC_HANDLE_SIZE type")]]
auto CUDA_IPC_HANDLE_SIZE_type() {
  [[clang::matcher_block]]
  {
    CUDA_IPC_HANDLE_SIZE varname;
  }
}

[[clang::replace("CUDA_IPC_HANDLE_SIZE type")]]
auto CUDA_IPC_HANDLE_SIZE_replace() {
  [[clang::matcher_block]]
  {
    HIP_IPC_HANDLE_SIZE varname;
  }
}

[[clang::matcher("CUevent_st type")]]
auto CUevent_st_type() {
  [[clang::matcher_block]]
  {
    CUevent_st varname;
  }
}

[[clang::replace("CUevent_st type")]]
auto CUevent_st_replace() {
  [[clang::matcher_block]]
  {
    ihipEvent_t varname;
  }
}

[[clang::matcher("CUgraphExec_st type")]]
auto CUgraphExec_st_type() {
  [[clang::matcher_block]]
  {
    CUgraphExec_st varname;
  }
}

[[clang::replace("CUgraphExec_st type")]]
auto CUgraphExec_st_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExec varname;
  }
}

[[clang::matcher("CUgraphNode_st type")]]
auto CUgraphNode_st_type() {
  [[clang::matcher_block]]
  {
    CUgraphNode_st varname;
  }
}

[[clang::replace("CUgraphNode_st type")]]
auto CUgraphNode_st_replace() {
  [[clang::matcher_block]]
  {
    hipGraphNode varname;
  }
}

[[clang::matcher("CUgraph_st type")]]
auto CUgraph_st_type() {
  [[clang::matcher_block]]
  {
    CUgraph_st varname;
  }
}

[[clang::replace("CUgraph_st type")]]
auto CUgraph_st_replace() {
  [[clang::matcher_block]]
  {
    ihipGraph varname;
  }
}

[[clang::matcher("CUstream_st type")]]
auto CUstream_st_type() {
  [[clang::matcher_block]]
  {
    CUstream_st varname;
  }
}

[[clang::replace("CUstream_st type")]]
auto CUstream_st_replace() {
  [[clang::matcher_block]]
  {
    ihipStream_t varname;
  }
}

[[clang::matcher("cudaAddressModeBorder type")]]
auto cudaAddressModeBorder_type() {
  [[clang::matcher_block]]
  {
    cudaAddressModeBorder varname;
  }
}

[[clang::replace("cudaAddressModeBorder type")]]
auto cudaAddressModeBorder_replace() {
  [[clang::matcher_block]]
  {
    hipAddressModeBorder varname;
  }
}

[[clang::matcher("cudaAddressModeClamp type")]]
auto cudaAddressModeClamp_type() {
  [[clang::matcher_block]]
  {
    cudaAddressModeClamp varname;
  }
}

[[clang::replace("cudaAddressModeClamp type")]]
auto cudaAddressModeClamp_replace() {
  [[clang::matcher_block]]
  {
    hipAddressModeClamp varname;
  }
}

[[clang::matcher("cudaAddressModeMirror type")]]
auto cudaAddressModeMirror_type() {
  [[clang::matcher_block]]
  {
    cudaAddressModeMirror varname;
  }
}

[[clang::replace("cudaAddressModeMirror type")]]
auto cudaAddressModeMirror_replace() {
  [[clang::matcher_block]]
  {
    hipAddressModeMirror varname;
  }
}

[[clang::matcher("cudaAddressModeWrap type")]]
auto cudaAddressModeWrap_type() {
  [[clang::matcher_block]]
  {
    cudaAddressModeWrap varname;
  }
}

[[clang::replace("cudaAddressModeWrap type")]]
auto cudaAddressModeWrap_replace() {
  [[clang::matcher_block]]
  {
    hipAddressModeWrap varname;
  }
}

[[clang::matcher("cudaArray type")]]
auto cudaArray_type() {
  [[clang::matcher_block]]
  {
    cudaArray varname;
  }
}

[[clang::replace("cudaArray type")]]
auto cudaArray_replace() {
  [[clang::matcher_block]]
  {
    hipArray varname;
  }
}

[[clang::matcher("cudaArrayCubemap type")]]
auto cudaArrayCubemap_type() {
  [[clang::matcher_block]]
  {
    cudaArrayCubemap varname;
  }
}

[[clang::replace("cudaArrayCubemap type")]]
auto cudaArrayCubemap_replace() {
  [[clang::matcher_block]]
  {
    hipArrayCubemap varname;
  }
}

[[clang::matcher("cudaArrayDefault type")]]
auto cudaArrayDefault_type() {
  [[clang::matcher_block]]
  {
    cudaArrayDefault varname;
  }
}

[[clang::replace("cudaArrayDefault type")]]
auto cudaArrayDefault_replace() {
  [[clang::matcher_block]]
  {
    hipArrayDefault varname;
  }
}

[[clang::matcher("cudaArrayLayered type")]]
auto cudaArrayLayered_type() {
  [[clang::matcher_block]]
  {
    cudaArrayLayered varname;
  }
}

[[clang::replace("cudaArrayLayered type")]]
auto cudaArrayLayered_replace() {
  [[clang::matcher_block]]
  {
    hipArrayLayered varname;
  }
}

[[clang::matcher("cudaArraySurfaceLoadStore type")]]
auto cudaArraySurfaceLoadStore_type() {
  [[clang::matcher_block]]
  {
    cudaArraySurfaceLoadStore varname;
  }
}

[[clang::replace("cudaArraySurfaceLoadStore type")]]
auto cudaArraySurfaceLoadStore_replace() {
  [[clang::matcher_block]]
  {
    hipArraySurfaceLoadStore varname;
  }
}

[[clang::matcher("cudaArrayTextureGather type")]]
auto cudaArrayTextureGather_type() {
  [[clang::matcher_block]]
  {
    cudaArrayTextureGather varname;
  }
}

[[clang::replace("cudaArrayTextureGather type")]]
auto cudaArrayTextureGather_replace() {
  [[clang::matcher_block]]
  {
    hipArrayTextureGather varname;
  }
}

[[clang::matcher("cudaArray_const_t type")]]
auto cudaArray_const_t_type() {
  [[clang::matcher_block]]
  {
    cudaArray_const_t varname;
  }
}

[[clang::replace("cudaArray_const_t type")]]
auto cudaArray_const_t_replace() {
  [[clang::matcher_block]]
  {
    hipArray_const_t varname;
  }
}

[[clang::matcher("cudaArray_t type")]]
auto cudaArray_t_type() {
  [[clang::matcher_block]]
  {
    cudaArray_t varname;
  }
}

[[clang::replace("cudaArray_t type")]]
auto cudaArray_t_replace() {
  [[clang::matcher_block]]
  {
    hipArray_t varname;
  }
}

[[clang::matcher("cudaBoundaryModeClamp type")]]
auto cudaBoundaryModeClamp_type() {
  [[clang::matcher_block]]
  {
    cudaBoundaryModeClamp varname;
  }
}

[[clang::replace("cudaBoundaryModeClamp type")]]
auto cudaBoundaryModeClamp_replace() {
  [[clang::matcher_block]]
  {
    hipBoundaryModeClamp varname;
  }
}

[[clang::matcher("cudaBoundaryModeTrap type")]]
auto cudaBoundaryModeTrap_type() {
  [[clang::matcher_block]]
  {
    cudaBoundaryModeTrap varname;
  }
}

[[clang::replace("cudaBoundaryModeTrap type")]]
auto cudaBoundaryModeTrap_replace() {
  [[clang::matcher_block]]
  {
    hipBoundaryModeTrap varname;
  }
}

[[clang::matcher("cudaBoundaryModeZero type")]]
auto cudaBoundaryModeZero_type() {
  [[clang::matcher_block]]
  {
    cudaBoundaryModeZero varname;
  }
}

[[clang::replace("cudaBoundaryModeZero type")]]
auto cudaBoundaryModeZero_replace() {
  [[clang::matcher_block]]
  {
    hipBoundaryModeZero varname;
  }
}

[[clang::matcher("cudaChannelFormatDesc type")]]
auto cudaChannelFormatDesc_type() {
  [[clang::matcher_block]]
  {
    cudaChannelFormatDesc varname;
  }
}

[[clang::replace("cudaChannelFormatDesc type")]]
auto cudaChannelFormatDesc_replace() {
  [[clang::matcher_block]]
  {
    hipChannelFormatDesc varname;
  }
}

[[clang::matcher("cudaChannelFormatKind type")]]
auto cudaChannelFormatKind_type() {
  [[clang::matcher_block]]
  {
    cudaChannelFormatKind varname;
  }
}

[[clang::replace("cudaChannelFormatKind type")]]
auto cudaChannelFormatKind_replace() {
  [[clang::matcher_block]]
  {
    hipChannelFormatKind varname;
  }
}

[[clang::matcher("cudaChannelFormatKindFloat type")]]
auto cudaChannelFormatKindFloat_type() {
  [[clang::matcher_block]]
  {
    cudaChannelFormatKindFloat varname;
  }
}

[[clang::replace("cudaChannelFormatKindFloat type")]]
auto cudaChannelFormatKindFloat_replace() {
  [[clang::matcher_block]]
  {
    hipChannelFormatKindFloat varname;
  }
}

[[clang::matcher("cudaChannelFormatKindNone type")]]
auto cudaChannelFormatKindNone_type() {
  [[clang::matcher_block]]
  {
    cudaChannelFormatKindNone varname;
  }
}

[[clang::replace("cudaChannelFormatKindNone type")]]
auto cudaChannelFormatKindNone_replace() {
  [[clang::matcher_block]]
  {
    hipChannelFormatKindNone varname;
  }
}

[[clang::matcher("cudaChannelFormatKindSigned type")]]
auto cudaChannelFormatKindSigned_type() {
  [[clang::matcher_block]]
  {
    cudaChannelFormatKindSigned varname;
  }
}

[[clang::replace("cudaChannelFormatKindSigned type")]]
auto cudaChannelFormatKindSigned_replace() {
  [[clang::matcher_block]]
  {
    hipChannelFormatKindSigned varname;
  }
}

[[clang::matcher("cudaChannelFormatKindUnsigned type")]]
auto cudaChannelFormatKindUnsigned_type() {
  [[clang::matcher_block]]
  {
    cudaChannelFormatKindUnsigned varname;
  }
}

[[clang::replace("cudaChannelFormatKindUnsigned type")]]
auto cudaChannelFormatKindUnsigned_replace() {
  [[clang::matcher_block]]
  {
    hipChannelFormatKindUnsigned varname;
  }
}

[[clang::matcher("cudaComputeMode type")]]
auto cudaComputeMode_type() {
  [[clang::matcher_block]]
  {
    cudaComputeMode varname;
  }
}

[[clang::replace("cudaComputeMode type")]]
auto cudaComputeMode_replace() {
  [[clang::matcher_block]]
  {
    hipComputeMode varname;
  }
}

[[clang::matcher("cudaComputeModeDefault type")]]
auto cudaComputeModeDefault_type() {
  [[clang::matcher_block]]
  {
    cudaComputeModeDefault varname;
  }
}

[[clang::replace("cudaComputeModeDefault type")]]
auto cudaComputeModeDefault_replace() {
  [[clang::matcher_block]]
  {
    hipComputeModeDefault varname;
  }
}

[[clang::matcher("cudaComputeModeExclusive type")]]
auto cudaComputeModeExclusive_type() {
  [[clang::matcher_block]]
  {
    cudaComputeModeExclusive varname;
  }
}

[[clang::replace("cudaComputeModeExclusive type")]]
auto cudaComputeModeExclusive_replace() {
  [[clang::matcher_block]]
  {
    hipComputeModeExclusive varname;
  }
}

[[clang::matcher("cudaComputeModeExclusiveProcess type")]]
auto cudaComputeModeExclusiveProcess_type() {
  [[clang::matcher_block]]
  {
    cudaComputeModeExclusiveProcess varname;
  }
}

[[clang::replace("cudaComputeModeExclusiveProcess type")]]
auto cudaComputeModeExclusiveProcess_replace() {
  [[clang::matcher_block]]
  {
    hipComputeModeExclusiveProcess varname;
  }
}

[[clang::matcher("cudaComputeModeProhibited type")]]
auto cudaComputeModeProhibited_type() {
  [[clang::matcher_block]]
  {
    cudaComputeModeProhibited varname;
  }
}

[[clang::replace("cudaComputeModeProhibited type")]]
auto cudaComputeModeProhibited_replace() {
  [[clang::matcher_block]]
  {
    hipComputeModeProhibited varname;
  }
}

[[clang::matcher("cudaCooperativeLaunchMultiDeviceNoPostSync type")]]
auto cudaCooperativeLaunchMultiDeviceNoPostSync_type() {
  [[clang::matcher_block]]
  {
    cudaCooperativeLaunchMultiDeviceNoPostSync varname;
  }
}

[[clang::replace("cudaCooperativeLaunchMultiDeviceNoPostSync type")]]
auto cudaCooperativeLaunchMultiDeviceNoPostSync_replace() {
  [[clang::matcher_block]]
  {
    hipCooperativeLaunchMultiDeviceNoPostSync varname;
  }
}

[[clang::matcher("cudaCooperativeLaunchMultiDeviceNoPreSync type")]]
auto cudaCooperativeLaunchMultiDeviceNoPreSync_type() {
  [[clang::matcher_block]]
  {
    cudaCooperativeLaunchMultiDeviceNoPreSync varname;
  }
}

[[clang::replace("cudaCooperativeLaunchMultiDeviceNoPreSync type")]]
auto cudaCooperativeLaunchMultiDeviceNoPreSync_replace() {
  [[clang::matcher_block]]
  {
    hipCooperativeLaunchMultiDeviceNoPreSync varname;
  }
}

[[clang::matcher("cudaCpuDeviceId type")]]
auto cudaCpuDeviceId_type() {
  [[clang::matcher_block]]
  {
    cudaCpuDeviceId varname;
  }
}

[[clang::replace("cudaCpuDeviceId type")]]
auto cudaCpuDeviceId_replace() {
  [[clang::matcher_block]]
  {
    hipCpuDeviceId varname;
  }
}

[[clang::matcher("cudaDevAttrAsyncEngineCount type")]]
auto cudaDevAttrAsyncEngineCount_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrAsyncEngineCount varname;
  }
}

[[clang::replace("cudaDevAttrAsyncEngineCount type")]]
auto cudaDevAttrAsyncEngineCount_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeAsyncEngineCount varname;
  }
}

[[clang::matcher("cudaDevAttrCanMapHostMemory type")]]
auto cudaDevAttrCanMapHostMemory_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrCanMapHostMemory varname;
  }
}

[[clang::replace("cudaDevAttrCanMapHostMemory type")]]
auto cudaDevAttrCanMapHostMemory_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeCanMapHostMemory varname;
  }
}

[[clang::matcher("cudaDevAttrCanUseHostPointerForRegisteredMem type")]]
auto cudaDevAttrCanUseHostPointerForRegisteredMem_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrCanUseHostPointerForRegisteredMem varname;
  }
}

[[clang::replace("cudaDevAttrCanUseHostPointerForRegisteredMem type")]]
auto cudaDevAttrCanUseHostPointerForRegisteredMem_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeCanUseHostPointerForRegisteredMem varname;
  }
}

[[clang::matcher("cudaDevAttrClockRate type")]]
auto cudaDevAttrClockRate_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrClockRate varname;
  }
}

[[clang::replace("cudaDevAttrClockRate type")]]
auto cudaDevAttrClockRate_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeClockRate varname;
  }
}

[[clang::matcher("cudaDevAttrComputeCapabilityMajor type")]]
auto cudaDevAttrComputeCapabilityMajor_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrComputeCapabilityMajor varname;
  }
}

[[clang::replace("cudaDevAttrComputeCapabilityMajor type")]]
auto cudaDevAttrComputeCapabilityMajor_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeComputeCapabilityMajor varname;
  }
}

[[clang::matcher("cudaDevAttrComputeCapabilityMinor type")]]
auto cudaDevAttrComputeCapabilityMinor_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrComputeCapabilityMinor varname;
  }
}

[[clang::replace("cudaDevAttrComputeCapabilityMinor type")]]
auto cudaDevAttrComputeCapabilityMinor_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeComputeCapabilityMinor varname;
  }
}

[[clang::matcher("cudaDevAttrComputeMode type")]]
auto cudaDevAttrComputeMode_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrComputeMode varname;
  }
}

[[clang::replace("cudaDevAttrComputeMode type")]]
auto cudaDevAttrComputeMode_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeComputeMode varname;
  }
}

[[clang::matcher("cudaDevAttrComputePreemptionSupported type")]]
auto cudaDevAttrComputePreemptionSupported_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrComputePreemptionSupported varname;
  }
}

[[clang::replace("cudaDevAttrComputePreemptionSupported type")]]
auto cudaDevAttrComputePreemptionSupported_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeComputePreemptionSupported varname;
  }
}

[[clang::matcher("cudaDevAttrConcurrentKernels type")]]
auto cudaDevAttrConcurrentKernels_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrConcurrentKernels varname;
  }
}

[[clang::replace("cudaDevAttrConcurrentKernels type")]]
auto cudaDevAttrConcurrentKernels_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeConcurrentKernels varname;
  }
}

[[clang::matcher("cudaDevAttrConcurrentManagedAccess type")]]
auto cudaDevAttrConcurrentManagedAccess_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrConcurrentManagedAccess varname;
  }
}

[[clang::replace("cudaDevAttrConcurrentManagedAccess type")]]
auto cudaDevAttrConcurrentManagedAccess_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeConcurrentManagedAccess varname;
  }
}

[[clang::matcher("cudaDevAttrCooperativeLaunch type")]]
auto cudaDevAttrCooperativeLaunch_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrCooperativeLaunch varname;
  }
}

[[clang::replace("cudaDevAttrCooperativeLaunch type")]]
auto cudaDevAttrCooperativeLaunch_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeCooperativeLaunch varname;
  }
}

[[clang::matcher("cudaDevAttrCooperativeMultiDeviceLaunch type")]]
auto cudaDevAttrCooperativeMultiDeviceLaunch_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrCooperativeMultiDeviceLaunch varname;
  }
}

[[clang::replace("cudaDevAttrCooperativeMultiDeviceLaunch type")]]
auto cudaDevAttrCooperativeMultiDeviceLaunch_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeCooperativeMultiDeviceLaunch varname;
  }
}

[[clang::matcher("cudaDevAttrDirectManagedMemAccessFromHost type")]]
auto cudaDevAttrDirectManagedMemAccessFromHost_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrDirectManagedMemAccessFromHost varname;
  }
}

[[clang::replace("cudaDevAttrDirectManagedMemAccessFromHost type")]]
auto cudaDevAttrDirectManagedMemAccessFromHost_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeDirectManagedMemAccessFromHost varname;
  }
}

[[clang::matcher("cudaDevAttrEccEnabled type")]]
auto cudaDevAttrEccEnabled_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrEccEnabled varname;
  }
}

[[clang::replace("cudaDevAttrEccEnabled type")]]
auto cudaDevAttrEccEnabled_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeEccEnabled varname;
  }
}

[[clang::matcher("cudaDevAttrGlobalL1CacheSupported type")]]
auto cudaDevAttrGlobalL1CacheSupported_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrGlobalL1CacheSupported varname;
  }
}

[[clang::replace("cudaDevAttrGlobalL1CacheSupported type")]]
auto cudaDevAttrGlobalL1CacheSupported_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeGlobalL1CacheSupported varname;
  }
}

[[clang::matcher("cudaDevAttrGlobalMemoryBusWidth type")]]
auto cudaDevAttrGlobalMemoryBusWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrGlobalMemoryBusWidth varname;
  }
}

[[clang::replace("cudaDevAttrGlobalMemoryBusWidth type")]]
auto cudaDevAttrGlobalMemoryBusWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMemoryBusWidth varname;
  }
}

[[clang::matcher("cudaDevAttrGpuOverlap type")]]
auto cudaDevAttrGpuOverlap_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrGpuOverlap varname;
  }
}

[[clang::replace("cudaDevAttrGpuOverlap type")]]
auto cudaDevAttrGpuOverlap_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeAsyncEngineCount varname;
  }
}

[[clang::matcher("cudaDevAttrHostNativeAtomicSupported type")]]
auto cudaDevAttrHostNativeAtomicSupported_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrHostNativeAtomicSupported varname;
  }
}

[[clang::replace("cudaDevAttrHostNativeAtomicSupported type")]]
auto cudaDevAttrHostNativeAtomicSupported_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeHostNativeAtomicSupported varname;
  }
}

[[clang::matcher("cudaDevAttrIntegrated type")]]
auto cudaDevAttrIntegrated_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrIntegrated varname;
  }
}

[[clang::replace("cudaDevAttrIntegrated type")]]
auto cudaDevAttrIntegrated_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeIntegrated varname;
  }
}

[[clang::matcher("cudaDevAttrIsMultiGpuBoard type")]]
auto cudaDevAttrIsMultiGpuBoard_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrIsMultiGpuBoard varname;
  }
}

[[clang::replace("cudaDevAttrIsMultiGpuBoard type")]]
auto cudaDevAttrIsMultiGpuBoard_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeIsMultiGpuBoard varname;
  }
}

[[clang::matcher("cudaDevAttrKernelExecTimeout type")]]
auto cudaDevAttrKernelExecTimeout_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrKernelExecTimeout varname;
  }
}

[[clang::replace("cudaDevAttrKernelExecTimeout type")]]
auto cudaDevAttrKernelExecTimeout_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeKernelExecTimeout varname;
  }
}

[[clang::matcher("cudaDevAttrL2CacheSize type")]]
auto cudaDevAttrL2CacheSize_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrL2CacheSize varname;
  }
}

[[clang::replace("cudaDevAttrL2CacheSize type")]]
auto cudaDevAttrL2CacheSize_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeL2CacheSize varname;
  }
}

[[clang::matcher("cudaDevAttrLocalL1CacheSupported type")]]
auto cudaDevAttrLocalL1CacheSupported_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrLocalL1CacheSupported varname;
  }
}

[[clang::replace("cudaDevAttrLocalL1CacheSupported type")]]
auto cudaDevAttrLocalL1CacheSupported_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeLocalL1CacheSupported varname;
  }
}

[[clang::matcher("cudaDevAttrManagedMemory type")]]
auto cudaDevAttrManagedMemory_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrManagedMemory varname;
  }
}

[[clang::replace("cudaDevAttrManagedMemory type")]]
auto cudaDevAttrManagedMemory_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeManagedMemory varname;
  }
}

[[clang::matcher("cudaDevAttrMaxBlockDimX type")]]
auto cudaDevAttrMaxBlockDimX_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxBlockDimX varname;
  }
}

[[clang::replace("cudaDevAttrMaxBlockDimX type")]]
auto cudaDevAttrMaxBlockDimX_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxBlockDimX varname;
  }
}

[[clang::matcher("cudaDevAttrMaxBlockDimY type")]]
auto cudaDevAttrMaxBlockDimY_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxBlockDimY varname;
  }
}

[[clang::replace("cudaDevAttrMaxBlockDimY type")]]
auto cudaDevAttrMaxBlockDimY_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxBlockDimY varname;
  }
}

[[clang::matcher("cudaDevAttrMaxBlockDimZ type")]]
auto cudaDevAttrMaxBlockDimZ_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxBlockDimZ varname;
  }
}

[[clang::replace("cudaDevAttrMaxBlockDimZ type")]]
auto cudaDevAttrMaxBlockDimZ_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxBlockDimZ varname;
  }
}

[[clang::matcher("cudaDevAttrMaxBlocksPerMultiprocessor type")]]
auto cudaDevAttrMaxBlocksPerMultiprocessor_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxBlocksPerMultiprocessor varname;
  }
}

[[clang::replace("cudaDevAttrMaxBlocksPerMultiprocessor type")]]
auto cudaDevAttrMaxBlocksPerMultiprocessor_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxBlocksPerMultiprocessor varname;
  }
}

[[clang::matcher("cudaDevAttrMaxGridDimX type")]]
auto cudaDevAttrMaxGridDimX_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxGridDimX varname;
  }
}

[[clang::replace("cudaDevAttrMaxGridDimX type")]]
auto cudaDevAttrMaxGridDimX_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxGridDimX varname;
  }
}

[[clang::matcher("cudaDevAttrMaxGridDimY type")]]
auto cudaDevAttrMaxGridDimY_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxGridDimY varname;
  }
}

[[clang::replace("cudaDevAttrMaxGridDimY type")]]
auto cudaDevAttrMaxGridDimY_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxGridDimY varname;
  }
}

[[clang::matcher("cudaDevAttrMaxGridDimZ type")]]
auto cudaDevAttrMaxGridDimZ_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxGridDimZ varname;
  }
}

[[clang::replace("cudaDevAttrMaxGridDimZ type")]]
auto cudaDevAttrMaxGridDimZ_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxGridDimZ varname;
  }
}

[[clang::matcher("cudaDevAttrMaxPitch type")]]
auto cudaDevAttrMaxPitch_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxPitch varname;
  }
}

[[clang::replace("cudaDevAttrMaxPitch type")]]
auto cudaDevAttrMaxPitch_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxPitch varname;
  }
}

[[clang::matcher("cudaDevAttrMaxRegistersPerBlock type")]]
auto cudaDevAttrMaxRegistersPerBlock_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxRegistersPerBlock varname;
  }
}

[[clang::replace("cudaDevAttrMaxRegistersPerBlock type")]]
auto cudaDevAttrMaxRegistersPerBlock_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxRegistersPerBlock varname;
  }
}

[[clang::matcher("cudaDevAttrMaxRegistersPerMultiprocessor type")]]
auto cudaDevAttrMaxRegistersPerMultiprocessor_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxRegistersPerMultiprocessor varname;
  }
}

[[clang::replace("cudaDevAttrMaxRegistersPerMultiprocessor type")]]
auto cudaDevAttrMaxRegistersPerMultiprocessor_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxRegistersPerMultiprocessor varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSharedMemoryPerBlock type")]]
auto cudaDevAttrMaxSharedMemoryPerBlock_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSharedMemoryPerBlock varname;
  }
}

[[clang::replace("cudaDevAttrMaxSharedMemoryPerBlock type")]]
auto cudaDevAttrMaxSharedMemoryPerBlock_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSharedMemoryPerBlock varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSharedMemoryPerBlockOptin type")]]
auto cudaDevAttrMaxSharedMemoryPerBlockOptin_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSharedMemoryPerBlockOptin varname;
  }
}

[[clang::replace("cudaDevAttrMaxSharedMemoryPerBlockOptin type")]]
auto cudaDevAttrMaxSharedMemoryPerBlockOptin_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeSharedMemPerBlockOptin varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSharedMemoryPerMultiprocessor type")]]
auto cudaDevAttrMaxSharedMemoryPerMultiprocessor_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSharedMemoryPerMultiprocessor varname;
  }
}

[[clang::replace("cudaDevAttrMaxSharedMemoryPerMultiprocessor type")]]
auto cudaDevAttrMaxSharedMemoryPerMultiprocessor_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSharedMemoryPerMultiprocessor varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSurface1DLayeredWidth type")]]
auto cudaDevAttrMaxSurface1DLayeredWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSurface1DLayeredWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxSurface1DLayeredWidth type")]]
auto cudaDevAttrMaxSurface1DLayeredWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSurface1DLayered varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSurface1DWidth type")]]
auto cudaDevAttrMaxSurface1DWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSurface1DWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxSurface1DWidth type")]]
auto cudaDevAttrMaxSurface1DWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSurface1D varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSurface2DHeight type")]]
auto cudaDevAttrMaxSurface2DHeight_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSurface2DHeight varname;
  }
}

[[clang::replace("cudaDevAttrMaxSurface2DHeight type")]]
auto cudaDevAttrMaxSurface2DHeight_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSurface2D varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSurface2DLayeredHeight type")]]
auto cudaDevAttrMaxSurface2DLayeredHeight_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSurface2DLayeredHeight varname;
  }
}

[[clang::replace("cudaDevAttrMaxSurface2DLayeredHeight type")]]
auto cudaDevAttrMaxSurface2DLayeredHeight_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSurface2DLayered varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSurface2DLayeredWidth type")]]
auto cudaDevAttrMaxSurface2DLayeredWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSurface2DLayeredWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxSurface2DLayeredWidth type")]]
auto cudaDevAttrMaxSurface2DLayeredWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSurface2DLayered varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSurface2DWidth type")]]
auto cudaDevAttrMaxSurface2DWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSurface2DWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxSurface2DWidth type")]]
auto cudaDevAttrMaxSurface2DWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSurface2D varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSurface3DDepth type")]]
auto cudaDevAttrMaxSurface3DDepth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSurface3DDepth varname;
  }
}

[[clang::replace("cudaDevAttrMaxSurface3DDepth type")]]
auto cudaDevAttrMaxSurface3DDepth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSurface3D varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSurface3DHeight type")]]
auto cudaDevAttrMaxSurface3DHeight_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSurface3DHeight varname;
  }
}

[[clang::replace("cudaDevAttrMaxSurface3DHeight type")]]
auto cudaDevAttrMaxSurface3DHeight_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSurface3D varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSurface3DWidth type")]]
auto cudaDevAttrMaxSurface3DWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSurface3DWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxSurface3DWidth type")]]
auto cudaDevAttrMaxSurface3DWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSurface3D varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSurfaceCubemapLayeredWidth type")]]
auto cudaDevAttrMaxSurfaceCubemapLayeredWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSurfaceCubemapLayeredWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxSurfaceCubemapLayeredWidth type")]]
auto cudaDevAttrMaxSurfaceCubemapLayeredWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSurfaceCubemapLayered varname;
  }
}

[[clang::matcher("cudaDevAttrMaxSurfaceCubemapWidth type")]]
auto cudaDevAttrMaxSurfaceCubemapWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxSurfaceCubemapWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxSurfaceCubemapWidth type")]]
auto cudaDevAttrMaxSurfaceCubemapWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxSurfaceCubemap varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture1DLayeredWidth type")]]
auto cudaDevAttrMaxTexture1DLayeredWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture1DLayeredWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture1DLayeredWidth type")]]
auto cudaDevAttrMaxTexture1DLayeredWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture1DLayered varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture1DLinearWidth type")]]
auto cudaDevAttrMaxTexture1DLinearWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture1DLinearWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture1DLinearWidth type")]]
auto cudaDevAttrMaxTexture1DLinearWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture1DLinear varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture1DMipmappedWidth type")]]
auto cudaDevAttrMaxTexture1DMipmappedWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture1DMipmappedWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture1DMipmappedWidth type")]]
auto cudaDevAttrMaxTexture1DMipmappedWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture1DMipmap varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture1DWidth type")]]
auto cudaDevAttrMaxTexture1DWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture1DWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture1DWidth type")]]
auto cudaDevAttrMaxTexture1DWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture1DWidth varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture2DGatherHeight type")]]
auto cudaDevAttrMaxTexture2DGatherHeight_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture2DGatherHeight varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture2DGatherHeight type")]]
auto cudaDevAttrMaxTexture2DGatherHeight_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture2DGather varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture2DGatherWidth type")]]
auto cudaDevAttrMaxTexture2DGatherWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture2DGatherWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture2DGatherWidth type")]]
auto cudaDevAttrMaxTexture2DGatherWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture2DGather varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture2DHeight type")]]
auto cudaDevAttrMaxTexture2DHeight_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture2DHeight varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture2DHeight type")]]
auto cudaDevAttrMaxTexture2DHeight_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture2DHeight varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture2DLayeredHeight type")]]
auto cudaDevAttrMaxTexture2DLayeredHeight_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture2DLayeredHeight varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture2DLayeredHeight type")]]
auto cudaDevAttrMaxTexture2DLayeredHeight_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture2DLayered varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture2DLayeredWidth type")]]
auto cudaDevAttrMaxTexture2DLayeredWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture2DLayeredWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture2DLayeredWidth type")]]
auto cudaDevAttrMaxTexture2DLayeredWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture2DLayered varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture2DLinearHeight type")]]
auto cudaDevAttrMaxTexture2DLinearHeight_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture2DLinearHeight varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture2DLinearHeight type")]]
auto cudaDevAttrMaxTexture2DLinearHeight_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture2DLinear varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture2DLinearPitch type")]]
auto cudaDevAttrMaxTexture2DLinearPitch_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture2DLinearPitch varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture2DLinearPitch type")]]
auto cudaDevAttrMaxTexture2DLinearPitch_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture2DLinear varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture2DLinearWidth type")]]
auto cudaDevAttrMaxTexture2DLinearWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture2DLinearWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture2DLinearWidth type")]]
auto cudaDevAttrMaxTexture2DLinearWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture2DLinear varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture2DMipmappedHeight type")]]
auto cudaDevAttrMaxTexture2DMipmappedHeight_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture2DMipmappedHeight varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture2DMipmappedHeight type")]]
auto cudaDevAttrMaxTexture2DMipmappedHeight_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture2DMipmap varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture2DMipmappedWidth type")]]
auto cudaDevAttrMaxTexture2DMipmappedWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture2DMipmappedWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture2DMipmappedWidth type")]]
auto cudaDevAttrMaxTexture2DMipmappedWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture2DMipmap varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture2DWidth type")]]
auto cudaDevAttrMaxTexture2DWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture2DWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture2DWidth type")]]
auto cudaDevAttrMaxTexture2DWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture2DWidth varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture3DDepth type")]]
auto cudaDevAttrMaxTexture3DDepth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture3DDepth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture3DDepth type")]]
auto cudaDevAttrMaxTexture3DDepth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture3DDepth varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture3DDepthAlt type")]]
auto cudaDevAttrMaxTexture3DDepthAlt_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture3DDepthAlt varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture3DDepthAlt type")]]
auto cudaDevAttrMaxTexture3DDepthAlt_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture3DAlt varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture3DHeight type")]]
auto cudaDevAttrMaxTexture3DHeight_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture3DHeight varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture3DHeight type")]]
auto cudaDevAttrMaxTexture3DHeight_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture3DHeight varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture3DHeightAlt type")]]
auto cudaDevAttrMaxTexture3DHeightAlt_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture3DHeightAlt varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture3DHeightAlt type")]]
auto cudaDevAttrMaxTexture3DHeightAlt_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture3DAlt varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture3DWidth type")]]
auto cudaDevAttrMaxTexture3DWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture3DWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture3DWidth type")]]
auto cudaDevAttrMaxTexture3DWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture3DWidth varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTexture3DWidthAlt type")]]
auto cudaDevAttrMaxTexture3DWidthAlt_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTexture3DWidthAlt varname;
  }
}

[[clang::replace("cudaDevAttrMaxTexture3DWidthAlt type")]]
auto cudaDevAttrMaxTexture3DWidthAlt_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTexture3DAlt varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTextureCubemapLayeredWidth type")]]
auto cudaDevAttrMaxTextureCubemapLayeredWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTextureCubemapLayeredWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTextureCubemapLayeredWidth type")]]
auto cudaDevAttrMaxTextureCubemapLayeredWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTextureCubemapLayered varname;
  }
}

[[clang::matcher("cudaDevAttrMaxTextureCubemapWidth type")]]
auto cudaDevAttrMaxTextureCubemapWidth_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxTextureCubemapWidth varname;
  }
}

[[clang::replace("cudaDevAttrMaxTextureCubemapWidth type")]]
auto cudaDevAttrMaxTextureCubemapWidth_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxTextureCubemap varname;
  }
}

[[clang::matcher("cudaDevAttrMaxThreadsPerBlock type")]]
auto cudaDevAttrMaxThreadsPerBlock_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxThreadsPerBlock varname;
  }
}

[[clang::replace("cudaDevAttrMaxThreadsPerBlock type")]]
auto cudaDevAttrMaxThreadsPerBlock_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxThreadsPerBlock varname;
  }
}

[[clang::matcher("cudaDevAttrMaxThreadsPerMultiProcessor type")]]
auto cudaDevAttrMaxThreadsPerMultiProcessor_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMaxThreadsPerMultiProcessor varname;
  }
}

[[clang::replace("cudaDevAttrMaxThreadsPerMultiProcessor type")]]
auto cudaDevAttrMaxThreadsPerMultiProcessor_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMaxThreadsPerMultiProcessor varname;
  }
}

[[clang::matcher("cudaDevAttrMemoryClockRate type")]]
auto cudaDevAttrMemoryClockRate_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMemoryClockRate varname;
  }
}

[[clang::replace("cudaDevAttrMemoryClockRate type")]]
auto cudaDevAttrMemoryClockRate_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMemoryClockRate varname;
  }
}

[[clang::matcher("cudaDevAttrMultiGpuBoardGroupID type")]]
auto cudaDevAttrMultiGpuBoardGroupID_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMultiGpuBoardGroupID varname;
  }
}

[[clang::replace("cudaDevAttrMultiGpuBoardGroupID type")]]
auto cudaDevAttrMultiGpuBoardGroupID_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMultiGpuBoardGroupID varname;
  }
}

[[clang::matcher("cudaDevAttrMultiProcessorCount type")]]
auto cudaDevAttrMultiProcessorCount_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrMultiProcessorCount varname;
  }
}

[[clang::replace("cudaDevAttrMultiProcessorCount type")]]
auto cudaDevAttrMultiProcessorCount_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeMultiprocessorCount varname;
  }
}

[[clang::matcher("cudaDevAttrPageableMemoryAccess type")]]
auto cudaDevAttrPageableMemoryAccess_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrPageableMemoryAccess varname;
  }
}

[[clang::replace("cudaDevAttrPageableMemoryAccess type")]]
auto cudaDevAttrPageableMemoryAccess_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributePageableMemoryAccess varname;
  }
}

[[clang::matcher("cudaDevAttrPageableMemoryAccessUsesHostPageTables type")]]
auto cudaDevAttrPageableMemoryAccessUsesHostPageTables_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrPageableMemoryAccessUsesHostPageTables varname;
  }
}

[[clang::replace("cudaDevAttrPageableMemoryAccessUsesHostPageTables type")]]
auto cudaDevAttrPageableMemoryAccessUsesHostPageTables_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributePageableMemoryAccessUsesHostPageTables varname;
  }
}

[[clang::matcher("cudaDevAttrPciBusId type")]]
auto cudaDevAttrPciBusId_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrPciBusId varname;
  }
}

[[clang::replace("cudaDevAttrPciBusId type")]]
auto cudaDevAttrPciBusId_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributePciBusId varname;
  }
}

[[clang::matcher("cudaDevAttrPciDeviceId type")]]
auto cudaDevAttrPciDeviceId_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrPciDeviceId varname;
  }
}

[[clang::replace("cudaDevAttrPciDeviceId type")]]
auto cudaDevAttrPciDeviceId_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributePciDeviceId varname;
  }
}

[[clang::matcher("cudaDevAttrPciDomainId type")]]
auto cudaDevAttrPciDomainId_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrPciDomainId varname;
  }
}

[[clang::replace("cudaDevAttrPciDomainId type")]]
auto cudaDevAttrPciDomainId_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributePciDomainID varname;
  }
}

[[clang::matcher("cudaDevAttrReserved94 type")]]
auto cudaDevAttrReserved94_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrReserved94 varname;
  }
}

[[clang::replace("cudaDevAttrReserved94 type")]]
auto cudaDevAttrReserved94_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeCanUseStreamWaitValue varname;
  }
}

[[clang::matcher("cudaDevAttrSingleToDoublePrecisionPerfRatio type")]]
auto cudaDevAttrSingleToDoublePrecisionPerfRatio_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrSingleToDoublePrecisionPerfRatio varname;
  }
}

[[clang::replace("cudaDevAttrSingleToDoublePrecisionPerfRatio type")]]
auto cudaDevAttrSingleToDoublePrecisionPerfRatio_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeSingleToDoublePrecisionPerfRatio varname;
  }
}

[[clang::matcher("cudaDevAttrStreamPrioritiesSupported type")]]
auto cudaDevAttrStreamPrioritiesSupported_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrStreamPrioritiesSupported varname;
  }
}

[[clang::replace("cudaDevAttrStreamPrioritiesSupported type")]]
auto cudaDevAttrStreamPrioritiesSupported_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeStreamPrioritiesSupported varname;
  }
}

[[clang::matcher("cudaDevAttrSurfaceAlignment type")]]
auto cudaDevAttrSurfaceAlignment_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrSurfaceAlignment varname;
  }
}

[[clang::replace("cudaDevAttrSurfaceAlignment type")]]
auto cudaDevAttrSurfaceAlignment_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeSurfaceAlignment varname;
  }
}

[[clang::matcher("cudaDevAttrTccDriver type")]]
auto cudaDevAttrTccDriver_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrTccDriver varname;
  }
}

[[clang::replace("cudaDevAttrTccDriver type")]]
auto cudaDevAttrTccDriver_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeTccDriver varname;
  }
}

[[clang::matcher("cudaDevAttrTextureAlignment type")]]
auto cudaDevAttrTextureAlignment_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrTextureAlignment varname;
  }
}

[[clang::replace("cudaDevAttrTextureAlignment type")]]
auto cudaDevAttrTextureAlignment_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeTextureAlignment varname;
  }
}

[[clang::matcher("cudaDevAttrTexturePitchAlignment type")]]
auto cudaDevAttrTexturePitchAlignment_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrTexturePitchAlignment varname;
  }
}

[[clang::replace("cudaDevAttrTexturePitchAlignment type")]]
auto cudaDevAttrTexturePitchAlignment_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeTexturePitchAlignment varname;
  }
}

[[clang::matcher("cudaDevAttrTotalConstantMemory type")]]
auto cudaDevAttrTotalConstantMemory_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrTotalConstantMemory varname;
  }
}

[[clang::replace("cudaDevAttrTotalConstantMemory type")]]
auto cudaDevAttrTotalConstantMemory_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeTotalConstantMemory varname;
  }
}

[[clang::matcher("cudaDevAttrUnifiedAddressing type")]]
auto cudaDevAttrUnifiedAddressing_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrUnifiedAddressing varname;
  }
}

[[clang::replace("cudaDevAttrUnifiedAddressing type")]]
auto cudaDevAttrUnifiedAddressing_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeUnifiedAddressing varname;
  }
}

[[clang::matcher("cudaDevAttrWarpSize type")]]
auto cudaDevAttrWarpSize_type() {
  [[clang::matcher_block]]
  {
    cudaDevAttrWarpSize varname;
  }
}

[[clang::replace("cudaDevAttrWarpSize type")]]
auto cudaDevAttrWarpSize_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttributeWarpSize varname;
  }
}

[[clang::matcher("cudaDevP2PAttrAccessSupported type")]]
auto cudaDevP2PAttrAccessSupported_type() {
  [[clang::matcher_block]]
  {
    cudaDevP2PAttrAccessSupported varname;
  }
}

[[clang::replace("cudaDevP2PAttrAccessSupported type")]]
auto cudaDevP2PAttrAccessSupported_replace() {
  [[clang::matcher_block]]
  {
    hipDevP2PAttrAccessSupported varname;
  }
}

[[clang::matcher("cudaDevP2PAttrCudaArrayAccessSupported type")]]
auto cudaDevP2PAttrCudaArrayAccessSupported_type() {
  [[clang::matcher_block]]
  {
    cudaDevP2PAttrCudaArrayAccessSupported varname;
  }
}

[[clang::replace("cudaDevP2PAttrCudaArrayAccessSupported type")]]
auto cudaDevP2PAttrCudaArrayAccessSupported_replace() {
  [[clang::matcher_block]]
  {
    hipDevP2PAttrHipArrayAccessSupported varname;
  }
}

[[clang::matcher("cudaDevP2PAttrNativeAtomicSupported type")]]
auto cudaDevP2PAttrNativeAtomicSupported_type() {
  [[clang::matcher_block]]
  {
    cudaDevP2PAttrNativeAtomicSupported varname;
  }
}

[[clang::replace("cudaDevP2PAttrNativeAtomicSupported type")]]
auto cudaDevP2PAttrNativeAtomicSupported_replace() {
  [[clang::matcher_block]]
  {
    hipDevP2PAttrNativeAtomicSupported varname;
  }
}

[[clang::matcher("cudaDevP2PAttrPerformanceRank type")]]
auto cudaDevP2PAttrPerformanceRank_type() {
  [[clang::matcher_block]]
  {
    cudaDevP2PAttrPerformanceRank varname;
  }
}

[[clang::replace("cudaDevP2PAttrPerformanceRank type")]]
auto cudaDevP2PAttrPerformanceRank_replace() {
  [[clang::matcher_block]]
  {
    hipDevP2PAttrPerformanceRank varname;
  }
}

[[clang::matcher("cudaDeviceAttr type")]]
auto cudaDeviceAttr_type() {
  [[clang::matcher_block]]
  {
    cudaDeviceAttr varname;
  }
}

[[clang::replace("cudaDeviceAttr type")]]
auto cudaDeviceAttr_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceAttribute_t varname;
  }
}

[[clang::matcher("cudaDeviceLmemResizeToMax type")]]
auto cudaDeviceLmemResizeToMax_type() {
  [[clang::matcher_block]]
  {
    cudaDeviceLmemResizeToMax varname;
  }
}

[[clang::replace("cudaDeviceLmemResizeToMax type")]]
auto cudaDeviceLmemResizeToMax_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceLmemResizeToMax varname;
  }
}

[[clang::matcher("cudaDeviceMapHost type")]]
auto cudaDeviceMapHost_type() {
  [[clang::matcher_block]]
  {
    cudaDeviceMapHost varname;
  }
}

[[clang::replace("cudaDeviceMapHost type")]]
auto cudaDeviceMapHost_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceMapHost varname;
  }
}

[[clang::matcher("cudaDeviceP2PAttr type")]]
auto cudaDeviceP2PAttr_type() {
  [[clang::matcher_block]]
  {
    cudaDeviceP2PAttr varname;
  }
}

[[clang::replace("cudaDeviceP2PAttr type")]]
auto cudaDeviceP2PAttr_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceP2PAttr varname;
  }
}

[[clang::matcher("cudaDeviceProp type")]]
auto cudaDeviceProp_type() {
  [[clang::matcher_block]]
  {
    cudaDeviceProp varname;
  }
}

[[clang::replace("cudaDeviceProp type")]]
auto cudaDeviceProp_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceProp_t varname;
  }
}

[[clang::matcher("cudaDeviceScheduleAuto type")]]
auto cudaDeviceScheduleAuto_type() {
  [[clang::matcher_block]]
  {
    cudaDeviceScheduleAuto varname;
  }
}

[[clang::replace("cudaDeviceScheduleAuto type")]]
auto cudaDeviceScheduleAuto_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceScheduleAuto varname;
  }
}

[[clang::matcher("cudaDeviceScheduleBlockingSync type")]]
auto cudaDeviceScheduleBlockingSync_type() {
  [[clang::matcher_block]]
  {
    cudaDeviceScheduleBlockingSync varname;
  }
}

[[clang::replace("cudaDeviceScheduleBlockingSync type")]]
auto cudaDeviceScheduleBlockingSync_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceScheduleBlockingSync varname;
  }
}

[[clang::matcher("cudaDeviceScheduleMask type")]]
auto cudaDeviceScheduleMask_type() {
  [[clang::matcher_block]]
  {
    cudaDeviceScheduleMask varname;
  }
}

[[clang::replace("cudaDeviceScheduleMask type")]]
auto cudaDeviceScheduleMask_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceScheduleMask varname;
  }
}

[[clang::matcher("cudaDeviceScheduleSpin type")]]
auto cudaDeviceScheduleSpin_type() {
  [[clang::matcher_block]]
  {
    cudaDeviceScheduleSpin varname;
  }
}

[[clang::replace("cudaDeviceScheduleSpin type")]]
auto cudaDeviceScheduleSpin_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceScheduleSpin varname;
  }
}

[[clang::matcher("cudaDeviceScheduleYield type")]]
auto cudaDeviceScheduleYield_type() {
  [[clang::matcher_block]]
  {
    cudaDeviceScheduleYield varname;
  }
}

[[clang::replace("cudaDeviceScheduleYield type")]]
auto cudaDeviceScheduleYield_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceScheduleYield varname;
  }
}

[[clang::matcher("cudaError type")]]
auto cudaError_type() {
  [[clang::matcher_block]]
  {
    cudaError varname;
  }
}

[[clang::replace("cudaError type")]]
auto cudaError_replace() {
  [[clang::matcher_block]]
  {
    hipError_t varname;
  }
}

[[clang::matcher("cudaErrorAlreadyAcquired type")]]
auto cudaErrorAlreadyAcquired_type() {
  [[clang::matcher_block]]
  {
    cudaErrorAlreadyAcquired varname;
  }
}

[[clang::replace("cudaErrorAlreadyAcquired type")]]
auto cudaErrorAlreadyAcquired_replace() {
  [[clang::matcher_block]]
  {
    hipErrorAlreadyAcquired varname;
  }
}

[[clang::matcher("cudaErrorAlreadyMapped type")]]
auto cudaErrorAlreadyMapped_type() {
  [[clang::matcher_block]]
  {
    cudaErrorAlreadyMapped varname;
  }
}

[[clang::replace("cudaErrorAlreadyMapped type")]]
auto cudaErrorAlreadyMapped_replace() {
  [[clang::matcher_block]]
  {
    hipErrorAlreadyMapped varname;
  }
}

[[clang::matcher("cudaErrorArrayIsMapped type")]]
auto cudaErrorArrayIsMapped_type() {
  [[clang::matcher_block]]
  {
    cudaErrorArrayIsMapped varname;
  }
}

[[clang::replace("cudaErrorArrayIsMapped type")]]
auto cudaErrorArrayIsMapped_replace() {
  [[clang::matcher_block]]
  {
    hipErrorArrayIsMapped varname;
  }
}

[[clang::matcher("cudaErrorAssert type")]]
auto cudaErrorAssert_type() {
  [[clang::matcher_block]]
  {
    cudaErrorAssert varname;
  }
}

[[clang::replace("cudaErrorAssert type")]]
auto cudaErrorAssert_replace() {
  [[clang::matcher_block]]
  {
    hipErrorAssert varname;
  }
}

[[clang::matcher("cudaErrorCapturedEvent type")]]
auto cudaErrorCapturedEvent_type() {
  [[clang::matcher_block]]
  {
    cudaErrorCapturedEvent varname;
  }
}

[[clang::replace("cudaErrorCapturedEvent type")]]
auto cudaErrorCapturedEvent_replace() {
  [[clang::matcher_block]]
  {
    hipErrorCapturedEvent varname;
  }
}

[[clang::matcher("cudaErrorContextIsDestroyed type")]]
auto cudaErrorContextIsDestroyed_type() {
  [[clang::matcher_block]]
  {
    cudaErrorContextIsDestroyed varname;
  }
}

[[clang::replace("cudaErrorContextIsDestroyed type")]]
auto cudaErrorContextIsDestroyed_replace() {
  [[clang::matcher_block]]
  {
    hipErrorContextIsDestroyed varname;
  }
}

[[clang::matcher("cudaErrorCooperativeLaunchTooLarge type")]]
auto cudaErrorCooperativeLaunchTooLarge_type() {
  [[clang::matcher_block]]
  {
    cudaErrorCooperativeLaunchTooLarge varname;
  }
}

[[clang::replace("cudaErrorCooperativeLaunchTooLarge type")]]
auto cudaErrorCooperativeLaunchTooLarge_replace() {
  [[clang::matcher_block]]
  {
    hipErrorCooperativeLaunchTooLarge varname;
  }
}

[[clang::matcher("cudaErrorCudartUnloading type")]]
auto cudaErrorCudartUnloading_type() {
  [[clang::matcher_block]]
  {
    cudaErrorCudartUnloading varname;
  }
}

[[clang::replace("cudaErrorCudartUnloading type")]]
auto cudaErrorCudartUnloading_replace() {
  [[clang::matcher_block]]
  {
    hipErrorDeinitialized varname;
  }
}

[[clang::matcher("cudaErrorDeviceAlreadyInUse type")]]
auto cudaErrorDeviceAlreadyInUse_type() {
  [[clang::matcher_block]]
  {
    cudaErrorDeviceAlreadyInUse varname;
  }
}

[[clang::replace("cudaErrorDeviceAlreadyInUse type")]]
auto cudaErrorDeviceAlreadyInUse_replace() {
  [[clang::matcher_block]]
  {
    hipErrorContextAlreadyInUse varname;
  }
}

[[clang::matcher("cudaErrorDeviceUninitialized type")]]
auto cudaErrorDeviceUninitialized_type() {
  [[clang::matcher_block]]
  {
    cudaErrorDeviceUninitialized varname;
  }
}

[[clang::replace("cudaErrorDeviceUninitialized type")]]
auto cudaErrorDeviceUninitialized_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidContext varname;
  }
}

[[clang::matcher("cudaErrorECCUncorrectable type")]]
auto cudaErrorECCUncorrectable_type() {
  [[clang::matcher_block]]
  {
    cudaErrorECCUncorrectable varname;
  }
}

[[clang::replace("cudaErrorECCUncorrectable type")]]
auto cudaErrorECCUncorrectable_replace() {
  [[clang::matcher_block]]
  {
    hipErrorECCNotCorrectable varname;
  }
}

[[clang::matcher("cudaErrorFileNotFound type")]]
auto cudaErrorFileNotFound_type() {
  [[clang::matcher_block]]
  {
    cudaErrorFileNotFound varname;
  }
}

[[clang::replace("cudaErrorFileNotFound type")]]
auto cudaErrorFileNotFound_replace() {
  [[clang::matcher_block]]
  {
    hipErrorFileNotFound varname;
  }
}

[[clang::matcher("cudaErrorHostMemoryAlreadyRegistered type")]]
auto cudaErrorHostMemoryAlreadyRegistered_type() {
  [[clang::matcher_block]]
  {
    cudaErrorHostMemoryAlreadyRegistered varname;
  }
}

[[clang::replace("cudaErrorHostMemoryAlreadyRegistered type")]]
auto cudaErrorHostMemoryAlreadyRegistered_replace() {
  [[clang::matcher_block]]
  {
    hipErrorHostMemoryAlreadyRegistered varname;
  }
}

[[clang::matcher("cudaErrorHostMemoryNotRegistered type")]]
auto cudaErrorHostMemoryNotRegistered_type() {
  [[clang::matcher_block]]
  {
    cudaErrorHostMemoryNotRegistered varname;
  }
}

[[clang::replace("cudaErrorHostMemoryNotRegistered type")]]
auto cudaErrorHostMemoryNotRegistered_replace() {
  [[clang::matcher_block]]
  {
    hipErrorHostMemoryNotRegistered varname;
  }
}

[[clang::matcher("cudaErrorIllegalAddress type")]]
auto cudaErrorIllegalAddress_type() {
  [[clang::matcher_block]]
  {
    cudaErrorIllegalAddress varname;
  }
}

[[clang::replace("cudaErrorIllegalAddress type")]]
auto cudaErrorIllegalAddress_replace() {
  [[clang::matcher_block]]
  {
    hipErrorIllegalAddress varname;
  }
}

[[clang::matcher("cudaErrorInitializationError type")]]
auto cudaErrorInitializationError_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInitializationError varname;
  }
}

[[clang::replace("cudaErrorInitializationError type")]]
auto cudaErrorInitializationError_replace() {
  [[clang::matcher_block]]
  {
    hipErrorNotInitialized varname;
  }
}

[[clang::matcher("cudaErrorInsufficientDriver type")]]
auto cudaErrorInsufficientDriver_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInsufficientDriver varname;
  }
}

[[clang::replace("cudaErrorInsufficientDriver type")]]
auto cudaErrorInsufficientDriver_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInsufficientDriver varname;
  }
}

[[clang::matcher("cudaErrorInvalidConfiguration type")]]
auto cudaErrorInvalidConfiguration_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInvalidConfiguration varname;
  }
}

[[clang::replace("cudaErrorInvalidConfiguration type")]]
auto cudaErrorInvalidConfiguration_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidConfiguration varname;
  }
}

[[clang::matcher("cudaErrorInvalidDevice type")]]
auto cudaErrorInvalidDevice_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInvalidDevice varname;
  }
}

[[clang::replace("cudaErrorInvalidDevice type")]]
auto cudaErrorInvalidDevice_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidDevice varname;
  }
}

[[clang::matcher("cudaErrorInvalidDeviceFunction type")]]
auto cudaErrorInvalidDeviceFunction_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInvalidDeviceFunction varname;
  }
}

[[clang::replace("cudaErrorInvalidDeviceFunction type")]]
auto cudaErrorInvalidDeviceFunction_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidDeviceFunction varname;
  }
}

[[clang::matcher("cudaErrorInvalidGraphicsContext type")]]
auto cudaErrorInvalidGraphicsContext_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInvalidGraphicsContext varname;
  }
}

[[clang::replace("cudaErrorInvalidGraphicsContext type")]]
auto cudaErrorInvalidGraphicsContext_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidGraphicsContext varname;
  }
}

[[clang::matcher("cudaErrorInvalidKernelImage type")]]
auto cudaErrorInvalidKernelImage_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInvalidKernelImage varname;
  }
}

[[clang::replace("cudaErrorInvalidKernelImage type")]]
auto cudaErrorInvalidKernelImage_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidImage varname;
  }
}

[[clang::matcher("cudaErrorInvalidMemcpyDirection type")]]
auto cudaErrorInvalidMemcpyDirection_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInvalidMemcpyDirection varname;
  }
}

[[clang::replace("cudaErrorInvalidMemcpyDirection type")]]
auto cudaErrorInvalidMemcpyDirection_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidMemcpyDirection varname;
  }
}

[[clang::matcher("cudaErrorInvalidPitchValue type")]]
auto cudaErrorInvalidPitchValue_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInvalidPitchValue varname;
  }
}

[[clang::replace("cudaErrorInvalidPitchValue type")]]
auto cudaErrorInvalidPitchValue_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidPitchValue varname;
  }
}

[[clang::matcher("cudaErrorInvalidPtx type")]]
auto cudaErrorInvalidPtx_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInvalidPtx varname;
  }
}

[[clang::replace("cudaErrorInvalidPtx type")]]
auto cudaErrorInvalidPtx_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidKernelFile varname;
  }
}

[[clang::matcher("cudaErrorInvalidResourceHandle type")]]
auto cudaErrorInvalidResourceHandle_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInvalidResourceHandle varname;
  }
}

[[clang::replace("cudaErrorInvalidResourceHandle type")]]
auto cudaErrorInvalidResourceHandle_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidHandle varname;
  }
}

[[clang::matcher("cudaErrorInvalidSource type")]]
auto cudaErrorInvalidSource_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInvalidSource varname;
  }
}

[[clang::replace("cudaErrorInvalidSource type")]]
auto cudaErrorInvalidSource_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidSource varname;
  }
}

[[clang::matcher("cudaErrorInvalidSymbol type")]]
auto cudaErrorInvalidSymbol_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInvalidSymbol varname;
  }
}

[[clang::replace("cudaErrorInvalidSymbol type")]]
auto cudaErrorInvalidSymbol_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidSymbol varname;
  }
}

[[clang::matcher("cudaErrorInvalidValue type")]]
auto cudaErrorInvalidValue_type() {
  [[clang::matcher_block]]
  {
    cudaErrorInvalidValue varname;
  }
}

[[clang::replace("cudaErrorInvalidValue type")]]
auto cudaErrorInvalidValue_replace() {
  [[clang::matcher_block]]
  {
    hipErrorInvalidValue varname;
  }
}

[[clang::matcher("cudaErrorLaunchFailure type")]]
auto cudaErrorLaunchFailure_type() {
  [[clang::matcher_block]]
  {
    cudaErrorLaunchFailure varname;
  }
}

[[clang::replace("cudaErrorLaunchFailure type")]]
auto cudaErrorLaunchFailure_replace() {
  [[clang::matcher_block]]
  {
    hipErrorLaunchFailure varname;
  }
}

[[clang::matcher("cudaErrorLaunchOutOfResources type")]]
auto cudaErrorLaunchOutOfResources_type() {
  [[clang::matcher_block]]
  {
    cudaErrorLaunchOutOfResources varname;
  }
}

[[clang::replace("cudaErrorLaunchOutOfResources type")]]
auto cudaErrorLaunchOutOfResources_replace() {
  [[clang::matcher_block]]
  {
    hipErrorLaunchOutOfResources varname;
  }
}

[[clang::matcher("cudaErrorLaunchTimeout type")]]
auto cudaErrorLaunchTimeout_type() {
  [[clang::matcher_block]]
  {
    cudaErrorLaunchTimeout varname;
  }
}

[[clang::replace("cudaErrorLaunchTimeout type")]]
auto cudaErrorLaunchTimeout_replace() {
  [[clang::matcher_block]]
  {
    hipErrorLaunchTimeOut varname;
  }
}

[[clang::matcher("cudaErrorMapBufferObjectFailed type")]]
auto cudaErrorMapBufferObjectFailed_type() {
  [[clang::matcher_block]]
  {
    cudaErrorMapBufferObjectFailed varname;
  }
}

[[clang::replace("cudaErrorMapBufferObjectFailed type")]]
auto cudaErrorMapBufferObjectFailed_replace() {
  [[clang::matcher_block]]
  {
    hipErrorMapFailed varname;
  }
}

[[clang::matcher("cudaErrorMemoryAllocation type")]]
auto cudaErrorMemoryAllocation_type() {
  [[clang::matcher_block]]
  {
    cudaErrorMemoryAllocation varname;
  }
}

[[clang::replace("cudaErrorMemoryAllocation type")]]
auto cudaErrorMemoryAllocation_replace() {
  [[clang::matcher_block]]
  {
    hipErrorOutOfMemory varname;
  }
}

[[clang::matcher("cudaErrorMissingConfiguration type")]]
auto cudaErrorMissingConfiguration_type() {
  [[clang::matcher_block]]
  {
    cudaErrorMissingConfiguration varname;
  }
}

[[clang::replace("cudaErrorMissingConfiguration type")]]
auto cudaErrorMissingConfiguration_replace() {
  [[clang::matcher_block]]
  {
    hipErrorMissingConfiguration varname;
  }
}

[[clang::matcher("cudaErrorNoDevice type")]]
auto cudaErrorNoDevice_type() {
  [[clang::matcher_block]]
  {
    cudaErrorNoDevice varname;
  }
}

[[clang::replace("cudaErrorNoDevice type")]]
auto cudaErrorNoDevice_replace() {
  [[clang::matcher_block]]
  {
    hipErrorNoDevice varname;
  }
}

[[clang::matcher("cudaErrorNoKernelImageForDevice type")]]
auto cudaErrorNoKernelImageForDevice_type() {
  [[clang::matcher_block]]
  {
    cudaErrorNoKernelImageForDevice varname;
  }
}

[[clang::replace("cudaErrorNoKernelImageForDevice type")]]
auto cudaErrorNoKernelImageForDevice_replace() {
  [[clang::matcher_block]]
  {
    hipErrorNoBinaryForGpu varname;
  }
}

[[clang::matcher("cudaErrorNotMapped type")]]
auto cudaErrorNotMapped_type() {
  [[clang::matcher_block]]
  {
    cudaErrorNotMapped varname;
  }
}

[[clang::replace("cudaErrorNotMapped type")]]
auto cudaErrorNotMapped_replace() {
  [[clang::matcher_block]]
  {
    hipErrorNotMapped varname;
  }
}

[[clang::matcher("cudaErrorNotMappedAsArray type")]]
auto cudaErrorNotMappedAsArray_type() {
  [[clang::matcher_block]]
  {
    cudaErrorNotMappedAsArray varname;
  }
}

[[clang::replace("cudaErrorNotMappedAsArray type")]]
auto cudaErrorNotMappedAsArray_replace() {
  [[clang::matcher_block]]
  {
    hipErrorNotMappedAsArray varname;
  }
}

[[clang::matcher("cudaErrorNotMappedAsPointer type")]]
auto cudaErrorNotMappedAsPointer_type() {
  [[clang::matcher_block]]
  {
    cudaErrorNotMappedAsPointer varname;
  }
}

[[clang::replace("cudaErrorNotMappedAsPointer type")]]
auto cudaErrorNotMappedAsPointer_replace() {
  [[clang::matcher_block]]
  {
    hipErrorNotMappedAsPointer varname;
  }
}

[[clang::matcher("cudaErrorNotReady type")]]
auto cudaErrorNotReady_type() {
  [[clang::matcher_block]]
  {
    cudaErrorNotReady varname;
  }
}

[[clang::replace("cudaErrorNotReady type")]]
auto cudaErrorNotReady_replace() {
  [[clang::matcher_block]]
  {
    hipErrorNotReady varname;
  }
}

[[clang::matcher("cudaErrorNotSupported type")]]
auto cudaErrorNotSupported_type() {
  [[clang::matcher_block]]
  {
    cudaErrorNotSupported varname;
  }
}

[[clang::replace("cudaErrorNotSupported type")]]
auto cudaErrorNotSupported_replace() {
  [[clang::matcher_block]]
  {
    hipErrorNotSupported varname;
  }
}

[[clang::matcher("cudaErrorOperatingSystem type")]]
auto cudaErrorOperatingSystem_type() {
  [[clang::matcher_block]]
  {
    cudaErrorOperatingSystem varname;
  }
}

[[clang::replace("cudaErrorOperatingSystem type")]]
auto cudaErrorOperatingSystem_replace() {
  [[clang::matcher_block]]
  {
    hipErrorOperatingSystem varname;
  }
}

[[clang::matcher("cudaErrorPeerAccessAlreadyEnabled type")]]
auto cudaErrorPeerAccessAlreadyEnabled_type() {
  [[clang::matcher_block]]
  {
    cudaErrorPeerAccessAlreadyEnabled varname;
  }
}

[[clang::replace("cudaErrorPeerAccessAlreadyEnabled type")]]
auto cudaErrorPeerAccessAlreadyEnabled_replace() {
  [[clang::matcher_block]]
  {
    hipErrorPeerAccessAlreadyEnabled varname;
  }
}

[[clang::matcher("cudaErrorPeerAccessNotEnabled type")]]
auto cudaErrorPeerAccessNotEnabled_type() {
  [[clang::matcher_block]]
  {
    cudaErrorPeerAccessNotEnabled varname;
  }
}

[[clang::replace("cudaErrorPeerAccessNotEnabled type")]]
auto cudaErrorPeerAccessNotEnabled_replace() {
  [[clang::matcher_block]]
  {
    hipErrorPeerAccessNotEnabled varname;
  }
}

[[clang::matcher("cudaErrorPeerAccessUnsupported type")]]
auto cudaErrorPeerAccessUnsupported_type() {
  [[clang::matcher_block]]
  {
    cudaErrorPeerAccessUnsupported varname;
  }
}

[[clang::replace("cudaErrorPeerAccessUnsupported type")]]
auto cudaErrorPeerAccessUnsupported_replace() {
  [[clang::matcher_block]]
  {
    hipErrorPeerAccessUnsupported varname;
  }
}

[[clang::matcher("cudaErrorProfilerDisabled type")]]
auto cudaErrorProfilerDisabled_type() {
  [[clang::matcher_block]]
  {
    cudaErrorProfilerDisabled varname;
  }
}

[[clang::replace("cudaErrorProfilerDisabled type")]]
auto cudaErrorProfilerDisabled_replace() {
  [[clang::matcher_block]]
  {
    hipErrorProfilerDisabled varname;
  }
}

[[clang::matcher("cudaErrorSetOnActiveProcess type")]]
auto cudaErrorSetOnActiveProcess_type() {
  [[clang::matcher_block]]
  {
    cudaErrorSetOnActiveProcess varname;
  }
}

[[clang::replace("cudaErrorSetOnActiveProcess type")]]
auto cudaErrorSetOnActiveProcess_replace() {
  [[clang::matcher_block]]
  {
    hipErrorSetOnActiveProcess varname;
  }
}

[[clang::matcher("cudaErrorSharedObjectInitFailed type")]]
auto cudaErrorSharedObjectInitFailed_type() {
  [[clang::matcher_block]]
  {
    cudaErrorSharedObjectInitFailed varname;
  }
}

[[clang::replace("cudaErrorSharedObjectInitFailed type")]]
auto cudaErrorSharedObjectInitFailed_replace() {
  [[clang::matcher_block]]
  {
    hipErrorSharedObjectInitFailed varname;
  }
}

[[clang::matcher("cudaErrorSharedObjectSymbolNotFound type")]]
auto cudaErrorSharedObjectSymbolNotFound_type() {
  [[clang::matcher_block]]
  {
    cudaErrorSharedObjectSymbolNotFound varname;
  }
}

[[clang::replace("cudaErrorSharedObjectSymbolNotFound type")]]
auto cudaErrorSharedObjectSymbolNotFound_replace() {
  [[clang::matcher_block]]
  {
    hipErrorSharedObjectSymbolNotFound varname;
  }
}

[[clang::matcher("cudaErrorStreamCaptureImplicit type")]]
auto cudaErrorStreamCaptureImplicit_type() {
  [[clang::matcher_block]]
  {
    cudaErrorStreamCaptureImplicit varname;
  }
}

[[clang::replace("cudaErrorStreamCaptureImplicit type")]]
auto cudaErrorStreamCaptureImplicit_replace() {
  [[clang::matcher_block]]
  {
    hipErrorStreamCaptureImplicit varname;
  }
}

[[clang::matcher("cudaErrorStreamCaptureInvalidated type")]]
auto cudaErrorStreamCaptureInvalidated_type() {
  [[clang::matcher_block]]
  {
    cudaErrorStreamCaptureInvalidated varname;
  }
}

[[clang::replace("cudaErrorStreamCaptureInvalidated type")]]
auto cudaErrorStreamCaptureInvalidated_replace() {
  [[clang::matcher_block]]
  {
    hipErrorStreamCaptureInvalidated varname;
  }
}

[[clang::matcher("cudaErrorStreamCaptureIsolation type")]]
auto cudaErrorStreamCaptureIsolation_type() {
  [[clang::matcher_block]]
  {
    cudaErrorStreamCaptureIsolation varname;
  }
}

[[clang::replace("cudaErrorStreamCaptureIsolation type")]]
auto cudaErrorStreamCaptureIsolation_replace() {
  [[clang::matcher_block]]
  {
    hipErrorStreamCaptureIsolation varname;
  }
}

[[clang::matcher("cudaErrorStreamCaptureMerge type")]]
auto cudaErrorStreamCaptureMerge_type() {
  [[clang::matcher_block]]
  {
    cudaErrorStreamCaptureMerge varname;
  }
}

[[clang::replace("cudaErrorStreamCaptureMerge type")]]
auto cudaErrorStreamCaptureMerge_replace() {
  [[clang::matcher_block]]
  {
    hipErrorStreamCaptureMerge varname;
  }
}

[[clang::matcher("cudaErrorStreamCaptureUnjoined type")]]
auto cudaErrorStreamCaptureUnjoined_type() {
  [[clang::matcher_block]]
  {
    cudaErrorStreamCaptureUnjoined varname;
  }
}

[[clang::replace("cudaErrorStreamCaptureUnjoined type")]]
auto cudaErrorStreamCaptureUnjoined_replace() {
  [[clang::matcher_block]]
  {
    hipErrorStreamCaptureUnjoined varname;
  }
}

[[clang::matcher("cudaErrorStreamCaptureUnmatched type")]]
auto cudaErrorStreamCaptureUnmatched_type() {
  [[clang::matcher_block]]
  {
    cudaErrorStreamCaptureUnmatched varname;
  }
}

[[clang::replace("cudaErrorStreamCaptureUnmatched type")]]
auto cudaErrorStreamCaptureUnmatched_replace() {
  [[clang::matcher_block]]
  {
    hipErrorStreamCaptureUnmatched varname;
  }
}

[[clang::matcher("cudaErrorStreamCaptureUnsupported type")]]
auto cudaErrorStreamCaptureUnsupported_type() {
  [[clang::matcher_block]]
  {
    cudaErrorStreamCaptureUnsupported varname;
  }
}

[[clang::replace("cudaErrorStreamCaptureUnsupported type")]]
auto cudaErrorStreamCaptureUnsupported_replace() {
  [[clang::matcher_block]]
  {
    hipErrorStreamCaptureUnsupported varname;
  }
}

[[clang::matcher("cudaErrorStreamCaptureWrongThread type")]]
auto cudaErrorStreamCaptureWrongThread_type() {
  [[clang::matcher_block]]
  {
    cudaErrorStreamCaptureWrongThread varname;
  }
}

[[clang::replace("cudaErrorStreamCaptureWrongThread type")]]
auto cudaErrorStreamCaptureWrongThread_replace() {
  [[clang::matcher_block]]
  {
    hipErrorStreamCaptureWrongThread varname;
  }
}

[[clang::matcher("cudaErrorSymbolNotFound type")]]
auto cudaErrorSymbolNotFound_type() {
  [[clang::matcher_block]]
  {
    cudaErrorSymbolNotFound varname;
  }
}

[[clang::replace("cudaErrorSymbolNotFound type")]]
auto cudaErrorSymbolNotFound_replace() {
  [[clang::matcher_block]]
  {
    hipErrorNotFound varname;
  }
}

[[clang::matcher("cudaErrorUnknown type")]]
auto cudaErrorUnknown_type() {
  [[clang::matcher_block]]
  {
    cudaErrorUnknown varname;
  }
}

[[clang::replace("cudaErrorUnknown type")]]
auto cudaErrorUnknown_replace() {
  [[clang::matcher_block]]
  {
    hipErrorUnknown varname;
  }
}

[[clang::matcher("cudaErrorUnmapBufferObjectFailed type")]]
auto cudaErrorUnmapBufferObjectFailed_type() {
  [[clang::matcher_block]]
  {
    cudaErrorUnmapBufferObjectFailed varname;
  }
}

[[clang::replace("cudaErrorUnmapBufferObjectFailed type")]]
auto cudaErrorUnmapBufferObjectFailed_replace() {
  [[clang::matcher_block]]
  {
    hipErrorUnmapFailed varname;
  }
}

[[clang::matcher("cudaErrorUnsupportedLimit type")]]
auto cudaErrorUnsupportedLimit_type() {
  [[clang::matcher_block]]
  {
    cudaErrorUnsupportedLimit varname;
  }
}

[[clang::replace("cudaErrorUnsupportedLimit type")]]
auto cudaErrorUnsupportedLimit_replace() {
  [[clang::matcher_block]]
  {
    hipErrorUnsupportedLimit varname;
  }
}

[[clang::matcher("cudaError_t type")]]
auto cudaError_t_type() {
  [[clang::matcher_block]]
  {
    cudaError_t varname;
  }
}

[[clang::replace("cudaError_t type")]]
auto cudaError_t_replace() {
  [[clang::matcher_block]]
  {
    hipError_t varname;
  }
}

[[clang::matcher("cudaEventBlockingSync type")]]
auto cudaEventBlockingSync_type() {
  [[clang::matcher_block]]
  {
    cudaEventBlockingSync varname;
  }
}

[[clang::replace("cudaEventBlockingSync type")]]
auto cudaEventBlockingSync_replace() {
  [[clang::matcher_block]]
  {
    hipEventBlockingSync varname;
  }
}

[[clang::matcher("cudaEventDefault type")]]
auto cudaEventDefault_type() {
  [[clang::matcher_block]]
  {
    cudaEventDefault varname;
  }
}

[[clang::replace("cudaEventDefault type")]]
auto cudaEventDefault_replace() {
  [[clang::matcher_block]]
  {
    hipEventDefault varname;
  }
}

[[clang::matcher("cudaEventDisableTiming type")]]
auto cudaEventDisableTiming_type() {
  [[clang::matcher_block]]
  {
    cudaEventDisableTiming varname;
  }
}

[[clang::replace("cudaEventDisableTiming type")]]
auto cudaEventDisableTiming_replace() {
  [[clang::matcher_block]]
  {
    hipEventDisableTiming varname;
  }
}

[[clang::matcher("cudaEventInterprocess type")]]
auto cudaEventInterprocess_type() {
  [[clang::matcher_block]]
  {
    cudaEventInterprocess varname;
  }
}

[[clang::replace("cudaEventInterprocess type")]]
auto cudaEventInterprocess_replace() {
  [[clang::matcher_block]]
  {
    hipEventInterprocess varname;
  }
}

[[clang::matcher("cudaEvent_t type")]]
auto cudaEvent_t_type() {
  [[clang::matcher_block]]
  {
    cudaEvent_t varname;
  }
}

[[clang::replace("cudaEvent_t type")]]
auto cudaEvent_t_replace() {
  [[clang::matcher_block]]
  {
    hipEvent_t varname;
  }
}

[[clang::matcher("cudaExtent type")]]
auto cudaExtent_type() {
  [[clang::matcher_block]]
  {
    cudaExtent varname;
  }
}

[[clang::replace("cudaExtent type")]]
auto cudaExtent_replace() {
  [[clang::matcher_block]]
  {
    hipExtent varname;
  }
}

[[clang::matcher("cudaExternalMemoryBufferDesc type")]]
auto cudaExternalMemoryBufferDesc_type() {
  [[clang::matcher_block]]
  {
    cudaExternalMemoryBufferDesc varname;
  }
}

[[clang::replace("cudaExternalMemoryBufferDesc type")]]
auto cudaExternalMemoryBufferDesc_replace() {
  [[clang::matcher_block]]
  {
    hipExternalMemoryBufferDesc varname;
  }
}

[[clang::matcher("cudaExternalMemoryHandleDesc type")]]
auto cudaExternalMemoryHandleDesc_type() {
  [[clang::matcher_block]]
  {
    cudaExternalMemoryHandleDesc varname;
  }
}

[[clang::replace("cudaExternalMemoryHandleDesc type")]]
auto cudaExternalMemoryHandleDesc_replace() {
  [[clang::matcher_block]]
  {
    hipExternalMemoryHandleDesc varname;
  }
}

[[clang::matcher("cudaExternalMemoryHandleType type")]]
auto cudaExternalMemoryHandleType_type() {
  [[clang::matcher_block]]
  {
    cudaExternalMemoryHandleType varname;
  }
}

[[clang::replace("cudaExternalMemoryHandleType type")]]
auto cudaExternalMemoryHandleType_replace() {
  [[clang::matcher_block]]
  {
    hipExternalMemoryHandleType varname;
  }
}

[[clang::matcher("cudaExternalMemoryHandleTypeD3D11Resource type")]]
auto cudaExternalMemoryHandleTypeD3D11Resource_type() {
  [[clang::matcher_block]]
  {
    cudaExternalMemoryHandleTypeD3D11Resource varname;
  }
}

[[clang::replace("cudaExternalMemoryHandleTypeD3D11Resource type")]]
auto cudaExternalMemoryHandleTypeD3D11Resource_replace() {
  [[clang::matcher_block]]
  {
    hipExternalMemoryHandleTypeD3D11Resource varname;
  }
}

[[clang::matcher("cudaExternalMemoryHandleTypeD3D11ResourceKmt type")]]
auto cudaExternalMemoryHandleTypeD3D11ResourceKmt_type() {
  [[clang::matcher_block]]
  {
    cudaExternalMemoryHandleTypeD3D11ResourceKmt varname;
  }
}

[[clang::replace("cudaExternalMemoryHandleTypeD3D11ResourceKmt type")]]
auto cudaExternalMemoryHandleTypeD3D11ResourceKmt_replace() {
  [[clang::matcher_block]]
  {
    hipExternalMemoryHandleTypeD3D11ResourceKmt varname;
  }
}

[[clang::matcher("cudaExternalMemoryHandleTypeD3D12Heap type")]]
auto cudaExternalMemoryHandleTypeD3D12Heap_type() {
  [[clang::matcher_block]]
  {
    cudaExternalMemoryHandleTypeD3D12Heap varname;
  }
}

[[clang::replace("cudaExternalMemoryHandleTypeD3D12Heap type")]]
auto cudaExternalMemoryHandleTypeD3D12Heap_replace() {
  [[clang::matcher_block]]
  {
    hipExternalMemoryHandleTypeD3D12Heap varname;
  }
}

[[clang::matcher("cudaExternalMemoryHandleTypeD3D12Resource type")]]
auto cudaExternalMemoryHandleTypeD3D12Resource_type() {
  [[clang::matcher_block]]
  {
    cudaExternalMemoryHandleTypeD3D12Resource varname;
  }
}

[[clang::replace("cudaExternalMemoryHandleTypeD3D12Resource type")]]
auto cudaExternalMemoryHandleTypeD3D12Resource_replace() {
  [[clang::matcher_block]]
  {
    hipExternalMemoryHandleTypeD3D12Resource varname;
  }
}

[[clang::matcher("cudaExternalMemoryHandleTypeOpaqueFd type")]]
auto cudaExternalMemoryHandleTypeOpaqueFd_type() {
  [[clang::matcher_block]]
  {
    cudaExternalMemoryHandleTypeOpaqueFd varname;
  }
}

[[clang::replace("cudaExternalMemoryHandleTypeOpaqueFd type")]]
auto cudaExternalMemoryHandleTypeOpaqueFd_replace() {
  [[clang::matcher_block]]
  {
    hipExternalMemoryHandleTypeOpaqueFd varname;
  }
}

[[clang::matcher("cudaExternalMemoryHandleTypeOpaqueWin32 type")]]
auto cudaExternalMemoryHandleTypeOpaqueWin32_type() {
  [[clang::matcher_block]]
  {
    cudaExternalMemoryHandleTypeOpaqueWin32 varname;
  }
}

[[clang::replace("cudaExternalMemoryHandleTypeOpaqueWin32 type")]]
auto cudaExternalMemoryHandleTypeOpaqueWin32_replace() {
  [[clang::matcher_block]]
  {
    hipExternalMemoryHandleTypeOpaqueWin32 varname;
  }
}

[[clang::matcher("cudaExternalMemoryHandleTypeOpaqueWin32Kmt type")]]
auto cudaExternalMemoryHandleTypeOpaqueWin32Kmt_type() {
  [[clang::matcher_block]]
  {
    cudaExternalMemoryHandleTypeOpaqueWin32Kmt varname;
  }
}

[[clang::replace("cudaExternalMemoryHandleTypeOpaqueWin32Kmt type")]]
auto cudaExternalMemoryHandleTypeOpaqueWin32Kmt_replace() {
  [[clang::matcher_block]]
  {
    hipExternalMemoryHandleTypeOpaqueWin32Kmt varname;
  }
}

[[clang::matcher("cudaExternalMemory_t type")]]
auto cudaExternalMemory_t_type() {
  [[clang::matcher_block]]
  {
    cudaExternalMemory_t varname;
  }
}

[[clang::replace("cudaExternalMemory_t type")]]
auto cudaExternalMemory_t_replace() {
  [[clang::matcher_block]]
  {
    hipExternalMemory_t varname;
  }
}

[[clang::matcher("cudaExternalSemaphoreHandleDesc type")]]
auto cudaExternalSemaphoreHandleDesc_type() {
  [[clang::matcher_block]]
  {
    cudaExternalSemaphoreHandleDesc varname;
  }
}

[[clang::replace("cudaExternalSemaphoreHandleDesc type")]]
auto cudaExternalSemaphoreHandleDesc_replace() {
  [[clang::matcher_block]]
  {
    hipExternalSemaphoreHandleDesc varname;
  }
}

[[clang::matcher("cudaExternalSemaphoreHandleType type")]]
auto cudaExternalSemaphoreHandleType_type() {
  [[clang::matcher_block]]
  {
    cudaExternalSemaphoreHandleType varname;
  }
}

[[clang::replace("cudaExternalSemaphoreHandleType type")]]
auto cudaExternalSemaphoreHandleType_replace() {
  [[clang::matcher_block]]
  {
    hipExternalSemaphoreHandleType varname;
  }
}

[[clang::matcher("cudaExternalSemaphoreHandleTypeD3D12Fence type")]]
auto cudaExternalSemaphoreHandleTypeD3D12Fence_type() {
  [[clang::matcher_block]]
  {
    cudaExternalSemaphoreHandleTypeD3D12Fence varname;
  }
}

[[clang::replace("cudaExternalSemaphoreHandleTypeD3D12Fence type")]]
auto cudaExternalSemaphoreHandleTypeD3D12Fence_replace() {
  [[clang::matcher_block]]
  {
    hipExternalSemaphoreHandleTypeD3D12Fence varname;
  }
}

[[clang::matcher("cudaExternalSemaphoreHandleTypeOpaqueFd type")]]
auto cudaExternalSemaphoreHandleTypeOpaqueFd_type() {
  [[clang::matcher_block]]
  {
    cudaExternalSemaphoreHandleTypeOpaqueFd varname;
  }
}

[[clang::replace("cudaExternalSemaphoreHandleTypeOpaqueFd type")]]
auto cudaExternalSemaphoreHandleTypeOpaqueFd_replace() {
  [[clang::matcher_block]]
  {
    hipExternalSemaphoreHandleTypeOpaqueFd varname;
  }
}

[[clang::matcher("cudaExternalSemaphoreHandleTypeOpaqueWin32 type")]]
auto cudaExternalSemaphoreHandleTypeOpaqueWin32_type() {
  [[clang::matcher_block]]
  {
    cudaExternalSemaphoreHandleTypeOpaqueWin32 varname;
  }
}

[[clang::replace("cudaExternalSemaphoreHandleTypeOpaqueWin32 type")]]
auto cudaExternalSemaphoreHandleTypeOpaqueWin32_replace() {
  [[clang::matcher_block]]
  {
    hipExternalSemaphoreHandleTypeOpaqueWin32 varname;
  }
}

[[clang::matcher("cudaExternalSemaphoreHandleTypeOpaqueWin32Kmt type")]]
auto cudaExternalSemaphoreHandleTypeOpaqueWin32Kmt_type() {
  [[clang::matcher_block]]
  {
    cudaExternalSemaphoreHandleTypeOpaqueWin32Kmt varname;
  }
}

[[clang::replace("cudaExternalSemaphoreHandleTypeOpaqueWin32Kmt type")]]
auto cudaExternalSemaphoreHandleTypeOpaqueWin32Kmt_replace() {
  [[clang::matcher_block]]
  {
    hipExternalSemaphoreHandleTypeOpaqueWin32Kmt varname;
  }
}

[[clang::matcher("cudaExternalSemaphoreSignalParams type")]]
auto cudaExternalSemaphoreSignalParams_type() {
  [[clang::matcher_block]]
  {
    cudaExternalSemaphoreSignalParams varname;
  }
}

[[clang::replace("cudaExternalSemaphoreSignalParams type")]]
auto cudaExternalSemaphoreSignalParams_replace() {
  [[clang::matcher_block]]
  {
    hipExternalSemaphoreSignalParams varname;
  }
}

[[clang::matcher("cudaExternalSemaphoreSignalParams_v1 type")]]
auto cudaExternalSemaphoreSignalParams_v1_type() {
  [[clang::matcher_block]]
  {
    cudaExternalSemaphoreSignalParams_v1 varname;
  }
}

[[clang::replace("cudaExternalSemaphoreSignalParams_v1 type")]]
auto cudaExternalSemaphoreSignalParams_v1_replace() {
  [[clang::matcher_block]]
  {
    hipExternalSemaphoreSignalParams varname;
  }
}

[[clang::matcher("cudaExternalSemaphoreWaitParams type")]]
auto cudaExternalSemaphoreWaitParams_type() {
  [[clang::matcher_block]]
  {
    cudaExternalSemaphoreWaitParams varname;
  }
}

[[clang::replace("cudaExternalSemaphoreWaitParams type")]]
auto cudaExternalSemaphoreWaitParams_replace() {
  [[clang::matcher_block]]
  {
    hipExternalSemaphoreWaitParams varname;
  }
}

[[clang::matcher("cudaExternalSemaphoreWaitParams_v1 type")]]
auto cudaExternalSemaphoreWaitParams_v1_type() {
  [[clang::matcher_block]]
  {
    cudaExternalSemaphoreWaitParams_v1 varname;
  }
}

[[clang::replace("cudaExternalSemaphoreWaitParams_v1 type")]]
auto cudaExternalSemaphoreWaitParams_v1_replace() {
  [[clang::matcher_block]]
  {
    hipExternalSemaphoreWaitParams varname;
  }
}

[[clang::matcher("cudaExternalSemaphore_t type")]]
auto cudaExternalSemaphore_t_type() {
  [[clang::matcher_block]]
  {
    cudaExternalSemaphore_t varname;
  }
}

[[clang::replace("cudaExternalSemaphore_t type")]]
auto cudaExternalSemaphore_t_replace() {
  [[clang::matcher_block]]
  {
    hipExternalSemaphore_t varname;
  }
}

[[clang::matcher("cudaFilterModeLinear type")]]
auto cudaFilterModeLinear_type() {
  [[clang::matcher_block]]
  {
    cudaFilterModeLinear varname;
  }
}

[[clang::replace("cudaFilterModeLinear type")]]
auto cudaFilterModeLinear_replace() {
  [[clang::matcher_block]]
  {
    hipFilterModeLinear varname;
  }
}

[[clang::matcher("cudaFilterModePoint type")]]
auto cudaFilterModePoint_type() {
  [[clang::matcher_block]]
  {
    cudaFilterModePoint varname;
  }
}

[[clang::replace("cudaFilterModePoint type")]]
auto cudaFilterModePoint_replace() {
  [[clang::matcher_block]]
  {
    hipFilterModePoint varname;
  }
}

[[clang::matcher("cudaFuncAttribute type")]]
auto cudaFuncAttribute_type() {
  [[clang::matcher_block]]
  {
    cudaFuncAttribute varname;
  }
}

[[clang::replace("cudaFuncAttribute type")]]
auto cudaFuncAttribute_replace() {
  [[clang::matcher_block]]
  {
    hipFuncAttribute varname;
  }
}

[[clang::matcher("cudaFuncAttributeMax type")]]
auto cudaFuncAttributeMax_type() {
  [[clang::matcher_block]]
  {
    cudaFuncAttributeMax varname;
  }
}

[[clang::replace("cudaFuncAttributeMax type")]]
auto cudaFuncAttributeMax_replace() {
  [[clang::matcher_block]]
  {
    hipFuncAttributeMax varname;
  }
}

[[clang::matcher("cudaFuncAttributeMaxDynamicSharedMemorySize type")]]
auto cudaFuncAttributeMaxDynamicSharedMemorySize_type() {
  [[clang::matcher_block]]
  {
    cudaFuncAttributeMaxDynamicSharedMemorySize varname;
  }
}

[[clang::replace("cudaFuncAttributeMaxDynamicSharedMemorySize type")]]
auto cudaFuncAttributeMaxDynamicSharedMemorySize_replace() {
  [[clang::matcher_block]]
  {
    hipFuncAttributeMaxDynamicSharedMemorySize varname;
  }
}

[[clang::matcher("cudaFuncAttributePreferredSharedMemoryCarveout type")]]
auto cudaFuncAttributePreferredSharedMemoryCarveout_type() {
  [[clang::matcher_block]]
  {
    cudaFuncAttributePreferredSharedMemoryCarveout varname;
  }
}

[[clang::replace("cudaFuncAttributePreferredSharedMemoryCarveout type")]]
auto cudaFuncAttributePreferredSharedMemoryCarveout_replace() {
  [[clang::matcher_block]]
  {
    hipFuncAttributePreferredSharedMemoryCarveout varname;
  }
}

[[clang::matcher("cudaFuncAttributes type")]]
auto cudaFuncAttributes_type() {
  [[clang::matcher_block]]
  {
    cudaFuncAttributes varname;
  }
}

[[clang::replace("cudaFuncAttributes type")]]
auto cudaFuncAttributes_replace() {
  [[clang::matcher_block]]
  {
    hipFuncAttributes varname;
  }
}

[[clang::matcher("cudaFuncCache type")]]
auto cudaFuncCache_type() {
  [[clang::matcher_block]]
  {
    cudaFuncCache varname;
  }
}

[[clang::replace("cudaFuncCache type")]]
auto cudaFuncCache_replace() {
  [[clang::matcher_block]]
  {
    hipFuncCache_t varname;
  }
}

[[clang::matcher("cudaFuncCachePreferEqual type")]]
auto cudaFuncCachePreferEqual_type() {
  [[clang::matcher_block]]
  {
    cudaFuncCachePreferEqual varname;
  }
}

[[clang::replace("cudaFuncCachePreferEqual type")]]
auto cudaFuncCachePreferEqual_replace() {
  [[clang::matcher_block]]
  {
    hipFuncCachePreferEqual varname;
  }
}

[[clang::matcher("cudaFuncCachePreferL1 type")]]
auto cudaFuncCachePreferL1_type() {
  [[clang::matcher_block]]
  {
    cudaFuncCachePreferL1 varname;
  }
}

[[clang::replace("cudaFuncCachePreferL1 type")]]
auto cudaFuncCachePreferL1_replace() {
  [[clang::matcher_block]]
  {
    hipFuncCachePreferL1 varname;
  }
}

[[clang::matcher("cudaFuncCachePreferNone type")]]
auto cudaFuncCachePreferNone_type() {
  [[clang::matcher_block]]
  {
    cudaFuncCachePreferNone varname;
  }
}

[[clang::replace("cudaFuncCachePreferNone type")]]
auto cudaFuncCachePreferNone_replace() {
  [[clang::matcher_block]]
  {
    hipFuncCachePreferNone varname;
  }
}

[[clang::matcher("cudaFuncCachePreferShared type")]]
auto cudaFuncCachePreferShared_type() {
  [[clang::matcher_block]]
  {
    cudaFuncCachePreferShared varname;
  }
}

[[clang::replace("cudaFuncCachePreferShared type")]]
auto cudaFuncCachePreferShared_replace() {
  [[clang::matcher_block]]
  {
    hipFuncCachePreferShared varname;
  }
}

[[clang::matcher("cudaFunction_t type")]]
auto cudaFunction_t_type() {
  [[clang::matcher_block]]
  {
    cudaFunction_t varname;
  }
}

[[clang::replace("cudaFunction_t type")]]
auto cudaFunction_t_replace() {
  [[clang::matcher_block]]
  {
    hipFunction_t varname;
  }
}

[[clang::matcher("cudaGLDeviceList type")]]
auto cudaGLDeviceList_type() {
  [[clang::matcher_block]]
  {
    cudaGLDeviceList varname;
  }
}

[[clang::replace("cudaGLDeviceList type")]]
auto cudaGLDeviceList_replace() {
  [[clang::matcher_block]]
  {
    hipGLDeviceList varname;
  }
}

[[clang::matcher("cudaGLDeviceListAll type")]]
auto cudaGLDeviceListAll_type() {
  [[clang::matcher_block]]
  {
    cudaGLDeviceListAll varname;
  }
}

[[clang::replace("cudaGLDeviceListAll type")]]
auto cudaGLDeviceListAll_replace() {
  [[clang::matcher_block]]
  {
    hipGLDeviceListAll varname;
  }
}

[[clang::matcher("cudaGLDeviceListCurrentFrame type")]]
auto cudaGLDeviceListCurrentFrame_type() {
  [[clang::matcher_block]]
  {
    cudaGLDeviceListCurrentFrame varname;
  }
}

[[clang::replace("cudaGLDeviceListCurrentFrame type")]]
auto cudaGLDeviceListCurrentFrame_replace() {
  [[clang::matcher_block]]
  {
    hipGLDeviceListCurrentFrame varname;
  }
}

[[clang::matcher("cudaGLDeviceListNextFrame type")]]
auto cudaGLDeviceListNextFrame_type() {
  [[clang::matcher_block]]
  {
    cudaGLDeviceListNextFrame varname;
  }
}

[[clang::replace("cudaGLDeviceListNextFrame type")]]
auto cudaGLDeviceListNextFrame_replace() {
  [[clang::matcher_block]]
  {
    hipGLDeviceListNextFrame varname;
  }
}

[[clang::matcher("cudaGraphExecUpdateError type")]]
auto cudaGraphExecUpdateError_type() {
  [[clang::matcher_block]]
  {
    cudaGraphExecUpdateError varname;
  }
}

[[clang::replace("cudaGraphExecUpdateError type")]]
auto cudaGraphExecUpdateError_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExecUpdateError varname;
  }
}

[[clang::matcher("cudaGraphExecUpdateErrorFunctionChanged type")]]
auto cudaGraphExecUpdateErrorFunctionChanged_type() {
  [[clang::matcher_block]]
  {
    cudaGraphExecUpdateErrorFunctionChanged varname;
  }
}

[[clang::replace("cudaGraphExecUpdateErrorFunctionChanged type")]]
auto cudaGraphExecUpdateErrorFunctionChanged_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExecUpdateErrorFunctionChanged varname;
  }
}

[[clang::matcher("cudaGraphExecUpdateErrorNodeTypeChanged type")]]
auto cudaGraphExecUpdateErrorNodeTypeChanged_type() {
  [[clang::matcher_block]]
  {
    cudaGraphExecUpdateErrorNodeTypeChanged varname;
  }
}

[[clang::replace("cudaGraphExecUpdateErrorNodeTypeChanged type")]]
auto cudaGraphExecUpdateErrorNodeTypeChanged_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExecUpdateErrorNodeTypeChanged varname;
  }
}

[[clang::matcher("cudaGraphExecUpdateErrorNotSupported type")]]
auto cudaGraphExecUpdateErrorNotSupported_type() {
  [[clang::matcher_block]]
  {
    cudaGraphExecUpdateErrorNotSupported varname;
  }
}

[[clang::replace("cudaGraphExecUpdateErrorNotSupported type")]]
auto cudaGraphExecUpdateErrorNotSupported_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExecUpdateErrorNotSupported varname;
  }
}

[[clang::matcher("cudaGraphExecUpdateErrorParametersChanged type")]]
auto cudaGraphExecUpdateErrorParametersChanged_type() {
  [[clang::matcher_block]]
  {
    cudaGraphExecUpdateErrorParametersChanged varname;
  }
}

[[clang::replace("cudaGraphExecUpdateErrorParametersChanged type")]]
auto cudaGraphExecUpdateErrorParametersChanged_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExecUpdateErrorParametersChanged varname;
  }
}

[[clang::matcher("cudaGraphExecUpdateErrorTopologyChanged type")]]
auto cudaGraphExecUpdateErrorTopologyChanged_type() {
  [[clang::matcher_block]]
  {
    cudaGraphExecUpdateErrorTopologyChanged varname;
  }
}

[[clang::replace("cudaGraphExecUpdateErrorTopologyChanged type")]]
auto cudaGraphExecUpdateErrorTopologyChanged_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExecUpdateErrorTopologyChanged varname;
  }
}

[[clang::matcher("cudaGraphExecUpdateErrorUnsupportedFunctionChange type")]]
auto cudaGraphExecUpdateErrorUnsupportedFunctionChange_type() {
  [[clang::matcher_block]]
  {
    cudaGraphExecUpdateErrorUnsupportedFunctionChange varname;
  }
}

[[clang::replace("cudaGraphExecUpdateErrorUnsupportedFunctionChange type")]]
auto cudaGraphExecUpdateErrorUnsupportedFunctionChange_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExecUpdateErrorUnsupportedFunctionChange varname;
  }
}

[[clang::matcher("cudaGraphExecUpdateResult type")]]
auto cudaGraphExecUpdateResult_type() {
  [[clang::matcher_block]]
  {
    cudaGraphExecUpdateResult varname;
  }
}

[[clang::replace("cudaGraphExecUpdateResult type")]]
auto cudaGraphExecUpdateResult_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExecUpdateResult varname;
  }
}

[[clang::matcher("cudaGraphExecUpdateSuccess type")]]
auto cudaGraphExecUpdateSuccess_type() {
  [[clang::matcher_block]]
  {
    cudaGraphExecUpdateSuccess varname;
  }
}

[[clang::replace("cudaGraphExecUpdateSuccess type")]]
auto cudaGraphExecUpdateSuccess_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExecUpdateSuccess varname;
  }
}

[[clang::matcher("cudaGraphExec_t type")]]
auto cudaGraphExec_t_type() {
  [[clang::matcher_block]]
  {
    cudaGraphExec_t varname;
  }
}

[[clang::replace("cudaGraphExec_t type")]]
auto cudaGraphExec_t_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExec_t varname;
  }
}

[[clang::matcher("cudaGraphNodeType type")]]
auto cudaGraphNodeType_type() {
  [[clang::matcher_block]]
  {
    cudaGraphNodeType varname;
  }
}

[[clang::replace("cudaGraphNodeType type")]]
auto cudaGraphNodeType_replace() {
  [[clang::matcher_block]]
  {
    hipGraphNodeType varname;
  }
}

[[clang::matcher("cudaGraphNodeTypeCount type")]]
auto cudaGraphNodeTypeCount_type() {
  [[clang::matcher_block]]
  {
    cudaGraphNodeTypeCount varname;
  }
}

[[clang::replace("cudaGraphNodeTypeCount type")]]
auto cudaGraphNodeTypeCount_replace() {
  [[clang::matcher_block]]
  {
    hipGraphNodeTypeCount varname;
  }
}

[[clang::matcher("cudaGraphNodeTypeEmpty type")]]
auto cudaGraphNodeTypeEmpty_type() {
  [[clang::matcher_block]]
  {
    cudaGraphNodeTypeEmpty varname;
  }
}

[[clang::replace("cudaGraphNodeTypeEmpty type")]]
auto cudaGraphNodeTypeEmpty_replace() {
  [[clang::matcher_block]]
  {
    hipGraphNodeTypeEmpty varname;
  }
}

[[clang::matcher("cudaGraphNodeTypeEventRecord type")]]
auto cudaGraphNodeTypeEventRecord_type() {
  [[clang::matcher_block]]
  {
    cudaGraphNodeTypeEventRecord varname;
  }
}

[[clang::replace("cudaGraphNodeTypeEventRecord type")]]
auto cudaGraphNodeTypeEventRecord_replace() {
  [[clang::matcher_block]]
  {
    hipGraphNodeTypeEventRecord varname;
  }
}

[[clang::matcher("cudaGraphNodeTypeGraph type")]]
auto cudaGraphNodeTypeGraph_type() {
  [[clang::matcher_block]]
  {
    cudaGraphNodeTypeGraph varname;
  }
}

[[clang::replace("cudaGraphNodeTypeGraph type")]]
auto cudaGraphNodeTypeGraph_replace() {
  [[clang::matcher_block]]
  {
    hipGraphNodeTypeGraph varname;
  }
}

[[clang::matcher("cudaGraphNodeTypeHost type")]]
auto cudaGraphNodeTypeHost_type() {
  [[clang::matcher_block]]
  {
    cudaGraphNodeTypeHost varname;
  }
}

[[clang::replace("cudaGraphNodeTypeHost type")]]
auto cudaGraphNodeTypeHost_replace() {
  [[clang::matcher_block]]
  {
    hipGraphNodeTypeHost varname;
  }
}

[[clang::matcher("cudaGraphNodeTypeKernel type")]]
auto cudaGraphNodeTypeKernel_type() {
  [[clang::matcher_block]]
  {
    cudaGraphNodeTypeKernel varname;
  }
}

[[clang::replace("cudaGraphNodeTypeKernel type")]]
auto cudaGraphNodeTypeKernel_replace() {
  [[clang::matcher_block]]
  {
    hipGraphNodeTypeKernel varname;
  }
}

[[clang::matcher("cudaGraphNodeTypeMemcpy type")]]
auto cudaGraphNodeTypeMemcpy_type() {
  [[clang::matcher_block]]
  {
    cudaGraphNodeTypeMemcpy varname;
  }
}

[[clang::replace("cudaGraphNodeTypeMemcpy type")]]
auto cudaGraphNodeTypeMemcpy_replace() {
  [[clang::matcher_block]]
  {
    hipGraphNodeTypeMemcpy varname;
  }
}

[[clang::matcher("cudaGraphNodeTypeMemset type")]]
auto cudaGraphNodeTypeMemset_type() {
  [[clang::matcher_block]]
  {
    cudaGraphNodeTypeMemset varname;
  }
}

[[clang::replace("cudaGraphNodeTypeMemset type")]]
auto cudaGraphNodeTypeMemset_replace() {
  [[clang::matcher_block]]
  {
    hipGraphNodeTypeMemset varname;
  }
}

[[clang::matcher("cudaGraphNodeTypeWaitEvent type")]]
auto cudaGraphNodeTypeWaitEvent_type() {
  [[clang::matcher_block]]
  {
    cudaGraphNodeTypeWaitEvent varname;
  }
}

[[clang::replace("cudaGraphNodeTypeWaitEvent type")]]
auto cudaGraphNodeTypeWaitEvent_replace() {
  [[clang::matcher_block]]
  {
    hipGraphNodeTypeWaitEvent varname;
  }
}

[[clang::matcher("cudaGraphNode_t type")]]
auto cudaGraphNode_t_type() {
  [[clang::matcher_block]]
  {
    cudaGraphNode_t varname;
  }
}

[[clang::replace("cudaGraphNode_t type")]]
auto cudaGraphNode_t_replace() {
  [[clang::matcher_block]]
  {
    hipGraphNode_t varname;
  }
}

[[clang::matcher("cudaGraph_t type")]]
auto cudaGraph_t_type() {
  [[clang::matcher_block]]
  {
    cudaGraph_t varname;
  }
}

[[clang::replace("cudaGraph_t type")]]
auto cudaGraph_t_replace() {
  [[clang::matcher_block]]
  {
    hipGraph_t varname;
  }
}

[[clang::matcher("cudaGraphicsRegisterFlags type")]]
auto cudaGraphicsRegisterFlags_type() {
  [[clang::matcher_block]]
  {
    cudaGraphicsRegisterFlags varname;
  }
}

[[clang::replace("cudaGraphicsRegisterFlags type")]]
auto cudaGraphicsRegisterFlags_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsRegisterFlags varname;
  }
}

[[clang::matcher("cudaGraphicsRegisterFlagsNone type")]]
auto cudaGraphicsRegisterFlagsNone_type() {
  [[clang::matcher_block]]
  {
    cudaGraphicsRegisterFlagsNone varname;
  }
}

[[clang::replace("cudaGraphicsRegisterFlagsNone type")]]
auto cudaGraphicsRegisterFlagsNone_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsRegisterFlagsNone varname;
  }
}

[[clang::matcher("cudaGraphicsRegisterFlagsReadOnly type")]]
auto cudaGraphicsRegisterFlagsReadOnly_type() {
  [[clang::matcher_block]]
  {
    cudaGraphicsRegisterFlagsReadOnly varname;
  }
}

[[clang::replace("cudaGraphicsRegisterFlagsReadOnly type")]]
auto cudaGraphicsRegisterFlagsReadOnly_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsRegisterFlagsReadOnly varname;
  }
}

[[clang::matcher("cudaGraphicsRegisterFlagsSurfaceLoadStore type")]]
auto cudaGraphicsRegisterFlagsSurfaceLoadStore_type() {
  [[clang::matcher_block]]
  {
    cudaGraphicsRegisterFlagsSurfaceLoadStore varname;
  }
}

[[clang::replace("cudaGraphicsRegisterFlagsSurfaceLoadStore type")]]
auto cudaGraphicsRegisterFlagsSurfaceLoadStore_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsRegisterFlagsSurfaceLoadStore varname;
  }
}

[[clang::matcher("cudaGraphicsRegisterFlagsTextureGather type")]]
auto cudaGraphicsRegisterFlagsTextureGather_type() {
  [[clang::matcher_block]]
  {
    cudaGraphicsRegisterFlagsTextureGather varname;
  }
}

[[clang::replace("cudaGraphicsRegisterFlagsTextureGather type")]]
auto cudaGraphicsRegisterFlagsTextureGather_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsRegisterFlagsTextureGather varname;
  }
}

[[clang::matcher("cudaGraphicsRegisterFlagsWriteDiscard type")]]
auto cudaGraphicsRegisterFlagsWriteDiscard_type() {
  [[clang::matcher_block]]
  {
    cudaGraphicsRegisterFlagsWriteDiscard varname;
  }
}

[[clang::replace("cudaGraphicsRegisterFlagsWriteDiscard type")]]
auto cudaGraphicsRegisterFlagsWriteDiscard_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsRegisterFlagsWriteDiscard varname;
  }
}

[[clang::matcher("cudaGraphicsResource type")]]
auto cudaGraphicsResource_type() {
  [[clang::matcher_block]]
  {
    cudaGraphicsResource varname;
  }
}

[[clang::replace("cudaGraphicsResource type")]]
auto cudaGraphicsResource_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsResource varname;
  }
}

[[clang::matcher("cudaGraphicsResource_t type")]]
auto cudaGraphicsResource_t_type() {
  [[clang::matcher_block]]
  {
    cudaGraphicsResource_t varname;
  }
}

[[clang::replace("cudaGraphicsResource_t type")]]
auto cudaGraphicsResource_t_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsResource_t varname;
  }
}

[[clang::matcher("cudaHostAllocDefault type")]]
auto cudaHostAllocDefault_type() {
  [[clang::matcher_block]]
  {
    cudaHostAllocDefault varname;
  }
}

[[clang::replace("cudaHostAllocDefault type")]]
auto cudaHostAllocDefault_replace() {
  [[clang::matcher_block]]
  {
    hipHostMallocDefault varname;
  }
}

[[clang::matcher("cudaHostAllocMapped type")]]
auto cudaHostAllocMapped_type() {
  [[clang::matcher_block]]
  {
    cudaHostAllocMapped varname;
  }
}

[[clang::replace("cudaHostAllocMapped type")]]
auto cudaHostAllocMapped_replace() {
  [[clang::matcher_block]]
  {
    hipHostMallocMapped varname;
  }
}

[[clang::matcher("cudaHostAllocPortable type")]]
auto cudaHostAllocPortable_type() {
  [[clang::matcher_block]]
  {
    cudaHostAllocPortable varname;
  }
}

[[clang::replace("cudaHostAllocPortable type")]]
auto cudaHostAllocPortable_replace() {
  [[clang::matcher_block]]
  {
    hipHostMallocPortable varname;
  }
}

[[clang::matcher("cudaHostAllocWriteCombined type")]]
auto cudaHostAllocWriteCombined_type() {
  [[clang::matcher_block]]
  {
    cudaHostAllocWriteCombined varname;
  }
}

[[clang::replace("cudaHostAllocWriteCombined type")]]
auto cudaHostAllocWriteCombined_replace() {
  [[clang::matcher_block]]
  {
    hipHostMallocWriteCombined varname;
  }
}

[[clang::matcher("cudaHostFn_t type")]]
auto cudaHostFn_t_type() {
  [[clang::matcher_block]]
  {
    cudaHostFn_t varname;
  }
}

[[clang::replace("cudaHostFn_t type")]]
auto cudaHostFn_t_replace() {
  [[clang::matcher_block]]
  {
    hipHostFn_t varname;
  }
}

[[clang::matcher("cudaHostNodeParams type")]]
auto cudaHostNodeParams_type() {
  [[clang::matcher_block]]
  {
    cudaHostNodeParams varname;
  }
}

[[clang::replace("cudaHostNodeParams type")]]
auto cudaHostNodeParams_replace() {
  [[clang::matcher_block]]
  {
    hipHostNodeParams varname;
  }
}

[[clang::matcher("cudaHostRegisterDefault type")]]
auto cudaHostRegisterDefault_type() {
  [[clang::matcher_block]]
  {
    cudaHostRegisterDefault varname;
  }
}

[[clang::replace("cudaHostRegisterDefault type")]]
auto cudaHostRegisterDefault_replace() {
  [[clang::matcher_block]]
  {
    hipHostRegisterDefault varname;
  }
}

[[clang::matcher("cudaHostRegisterIoMemory type")]]
auto cudaHostRegisterIoMemory_type() {
  [[clang::matcher_block]]
  {
    cudaHostRegisterIoMemory varname;
  }
}

[[clang::replace("cudaHostRegisterIoMemory type")]]
auto cudaHostRegisterIoMemory_replace() {
  [[clang::matcher_block]]
  {
    hipHostRegisterIoMemory varname;
  }
}

[[clang::matcher("cudaHostRegisterMapped type")]]
auto cudaHostRegisterMapped_type() {
  [[clang::matcher_block]]
  {
    cudaHostRegisterMapped varname;
  }
}

[[clang::replace("cudaHostRegisterMapped type")]]
auto cudaHostRegisterMapped_replace() {
  [[clang::matcher_block]]
  {
    hipHostRegisterMapped varname;
  }
}

[[clang::matcher("cudaHostRegisterPortable type")]]
auto cudaHostRegisterPortable_type() {
  [[clang::matcher_block]]
  {
    cudaHostRegisterPortable varname;
  }
}

[[clang::replace("cudaHostRegisterPortable type")]]
auto cudaHostRegisterPortable_replace() {
  [[clang::matcher_block]]
  {
    hipHostRegisterPortable varname;
  }
}

[[clang::matcher("cudaInvalidDeviceId type")]]
auto cudaInvalidDeviceId_type() {
  [[clang::matcher_block]]
  {
    cudaInvalidDeviceId varname;
  }
}

[[clang::replace("cudaInvalidDeviceId type")]]
auto cudaInvalidDeviceId_replace() {
  [[clang::matcher_block]]
  {
    hipInvalidDeviceId varname;
  }
}

[[clang::matcher("cudaIpcEventHandle_st type")]]
auto cudaIpcEventHandle_st_type() {
  [[clang::matcher_block]]
  {
    cudaIpcEventHandle_st varname;
  }
}

[[clang::replace("cudaIpcEventHandle_st type")]]
auto cudaIpcEventHandle_st_replace() {
  [[clang::matcher_block]]
  {
    hipIpcEventHandle_st varname;
  }
}

[[clang::matcher("cudaIpcEventHandle_t type")]]
auto cudaIpcEventHandle_t_type() {
  [[clang::matcher_block]]
  {
    cudaIpcEventHandle_t varname;
  }
}

[[clang::replace("cudaIpcEventHandle_t type")]]
auto cudaIpcEventHandle_t_replace() {
  [[clang::matcher_block]]
  {
    hipIpcEventHandle_t varname;
  }
}

[[clang::matcher("cudaIpcMemHandle_st type")]]
auto cudaIpcMemHandle_st_type() {
  [[clang::matcher_block]]
  {
    cudaIpcMemHandle_st varname;
  }
}

[[clang::replace("cudaIpcMemHandle_st type")]]
auto cudaIpcMemHandle_st_replace() {
  [[clang::matcher_block]]
  {
    hipIpcMemHandle_st varname;
  }
}

[[clang::matcher("cudaIpcMemHandle_t type")]]
auto cudaIpcMemHandle_t_type() {
  [[clang::matcher_block]]
  {
    cudaIpcMemHandle_t varname;
  }
}

[[clang::replace("cudaIpcMemHandle_t type")]]
auto cudaIpcMemHandle_t_replace() {
  [[clang::matcher_block]]
  {
    hipIpcMemHandle_t varname;
  }
}

[[clang::matcher("cudaIpcMemLazyEnablePeerAccess type")]]
auto cudaIpcMemLazyEnablePeerAccess_type() {
  [[clang::matcher_block]]
  {
    cudaIpcMemLazyEnablePeerAccess varname;
  }
}

[[clang::replace("cudaIpcMemLazyEnablePeerAccess type")]]
auto cudaIpcMemLazyEnablePeerAccess_replace() {
  [[clang::matcher_block]]
  {
    hipIpcMemLazyEnablePeerAccess varname;
  }
}

[[clang::matcher("cudaKernelNodeParams type")]]
auto cudaKernelNodeParams_type() {
  [[clang::matcher_block]]
  {
    cudaKernelNodeParams varname;
  }
}

[[clang::replace("cudaKernelNodeParams type")]]
auto cudaKernelNodeParams_replace() {
  [[clang::matcher_block]]
  {
    hipKernelNodeParams varname;
  }
}

[[clang::matcher("cudaLaunchParams type")]]
auto cudaLaunchParams_type() {
  [[clang::matcher_block]]
  {
    cudaLaunchParams varname;
  }
}

[[clang::replace("cudaLaunchParams type")]]
auto cudaLaunchParams_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchParams varname;
  }
}

[[clang::matcher("cudaLimit type")]]
auto cudaLimit_type() {
  [[clang::matcher_block]]
  {
    cudaLimit varname;
  }
}

[[clang::replace("cudaLimit type")]]
auto cudaLimit_replace() {
  [[clang::matcher_block]]
  {
    hipLimit_t varname;
  }
}

[[clang::matcher("cudaLimitMallocHeapSize type")]]
auto cudaLimitMallocHeapSize_type() {
  [[clang::matcher_block]]
  {
    cudaLimitMallocHeapSize varname;
  }
}

[[clang::replace("cudaLimitMallocHeapSize type")]]
auto cudaLimitMallocHeapSize_replace() {
  [[clang::matcher_block]]
  {
    hipLimitMallocHeapSize varname;
  }
}

[[clang::matcher("cudaLimitPrintfFifoSize type")]]
auto cudaLimitPrintfFifoSize_type() {
  [[clang::matcher_block]]
  {
    cudaLimitPrintfFifoSize varname;
  }
}

[[clang::replace("cudaLimitPrintfFifoSize type")]]
auto cudaLimitPrintfFifoSize_replace() {
  [[clang::matcher_block]]
  {
    hipLimitPrintfFifoSize varname;
  }
}

[[clang::matcher("cudaMemAdviseSetAccessedBy type")]]
auto cudaMemAdviseSetAccessedBy_type() {
  [[clang::matcher_block]]
  {
    cudaMemAdviseSetAccessedBy varname;
  }
}

[[clang::replace("cudaMemAdviseSetAccessedBy type")]]
auto cudaMemAdviseSetAccessedBy_replace() {
  [[clang::matcher_block]]
  {
    hipMemAdviseSetAccessedBy varname;
  }
}

[[clang::matcher("cudaMemAdviseSetPreferredLocation type")]]
auto cudaMemAdviseSetPreferredLocation_type() {
  [[clang::matcher_block]]
  {
    cudaMemAdviseSetPreferredLocation varname;
  }
}

[[clang::replace("cudaMemAdviseSetPreferredLocation type")]]
auto cudaMemAdviseSetPreferredLocation_replace() {
  [[clang::matcher_block]]
  {
    hipMemAdviseSetPreferredLocation varname;
  }
}

[[clang::matcher("cudaMemAdviseSetReadMostly type")]]
auto cudaMemAdviseSetReadMostly_type() {
  [[clang::matcher_block]]
  {
    cudaMemAdviseSetReadMostly varname;
  }
}

[[clang::replace("cudaMemAdviseSetReadMostly type")]]
auto cudaMemAdviseSetReadMostly_replace() {
  [[clang::matcher_block]]
  {
    hipMemAdviseSetReadMostly varname;
  }
}

[[clang::matcher("cudaMemAdviseUnsetAccessedBy type")]]
auto cudaMemAdviseUnsetAccessedBy_type() {
  [[clang::matcher_block]]
  {
    cudaMemAdviseUnsetAccessedBy varname;
  }
}

[[clang::replace("cudaMemAdviseUnsetAccessedBy type")]]
auto cudaMemAdviseUnsetAccessedBy_replace() {
  [[clang::matcher_block]]
  {
    hipMemAdviseUnsetAccessedBy varname;
  }
}

[[clang::matcher("cudaMemAdviseUnsetPreferredLocation type")]]
auto cudaMemAdviseUnsetPreferredLocation_type() {
  [[clang::matcher_block]]
  {
    cudaMemAdviseUnsetPreferredLocation varname;
  }
}

[[clang::replace("cudaMemAdviseUnsetPreferredLocation type")]]
auto cudaMemAdviseUnsetPreferredLocation_replace() {
  [[clang::matcher_block]]
  {
    hipMemAdviseUnsetPreferredLocation varname;
  }
}

[[clang::matcher("cudaMemAdviseUnsetReadMostly type")]]
auto cudaMemAdviseUnsetReadMostly_type() {
  [[clang::matcher_block]]
  {
    cudaMemAdviseUnsetReadMostly varname;
  }
}

[[clang::replace("cudaMemAdviseUnsetReadMostly type")]]
auto cudaMemAdviseUnsetReadMostly_replace() {
  [[clang::matcher_block]]
  {
    hipMemAdviseUnsetReadMostly varname;
  }
}

[[clang::matcher("cudaMemAttachGlobal type")]]
auto cudaMemAttachGlobal_type() {
  [[clang::matcher_block]]
  {
    cudaMemAttachGlobal varname;
  }
}

[[clang::replace("cudaMemAttachGlobal type")]]
auto cudaMemAttachGlobal_replace() {
  [[clang::matcher_block]]
  {
    hipMemAttachGlobal varname;
  }
}

[[clang::matcher("cudaMemAttachHost type")]]
auto cudaMemAttachHost_type() {
  [[clang::matcher_block]]
  {
    cudaMemAttachHost varname;
  }
}

[[clang::replace("cudaMemAttachHost type")]]
auto cudaMemAttachHost_replace() {
  [[clang::matcher_block]]
  {
    hipMemAttachHost varname;
  }
}

[[clang::matcher("cudaMemAttachSingle type")]]
auto cudaMemAttachSingle_type() {
  [[clang::matcher_block]]
  {
    cudaMemAttachSingle varname;
  }
}

[[clang::replace("cudaMemAttachSingle type")]]
auto cudaMemAttachSingle_replace() {
  [[clang::matcher_block]]
  {
    hipMemAttachSingle varname;
  }
}

[[clang::matcher("cudaMemRangeAttribute type")]]
auto cudaMemRangeAttribute_type() {
  [[clang::matcher_block]]
  {
    cudaMemRangeAttribute varname;
  }
}

[[clang::replace("cudaMemRangeAttribute type")]]
auto cudaMemRangeAttribute_replace() {
  [[clang::matcher_block]]
  {
    hipMemRangeAttribute varname;
  }
}

[[clang::matcher("cudaMemRangeAttributeAccessedBy type")]]
auto cudaMemRangeAttributeAccessedBy_type() {
  [[clang::matcher_block]]
  {
    cudaMemRangeAttributeAccessedBy varname;
  }
}

[[clang::replace("cudaMemRangeAttributeAccessedBy type")]]
auto cudaMemRangeAttributeAccessedBy_replace() {
  [[clang::matcher_block]]
  {
    hipMemRangeAttributeAccessedBy varname;
  }
}

[[clang::matcher("cudaMemRangeAttributeLastPrefetchLocation type")]]
auto cudaMemRangeAttributeLastPrefetchLocation_type() {
  [[clang::matcher_block]]
  {
    cudaMemRangeAttributeLastPrefetchLocation varname;
  }
}

[[clang::replace("cudaMemRangeAttributeLastPrefetchLocation type")]]
auto cudaMemRangeAttributeLastPrefetchLocation_replace() {
  [[clang::matcher_block]]
  {
    hipMemRangeAttributeLastPrefetchLocation varname;
  }
}

[[clang::matcher("cudaMemRangeAttributePreferredLocation type")]]
auto cudaMemRangeAttributePreferredLocation_type() {
  [[clang::matcher_block]]
  {
    cudaMemRangeAttributePreferredLocation varname;
  }
}

[[clang::replace("cudaMemRangeAttributePreferredLocation type")]]
auto cudaMemRangeAttributePreferredLocation_replace() {
  [[clang::matcher_block]]
  {
    hipMemRangeAttributePreferredLocation varname;
  }
}

[[clang::matcher("cudaMemRangeAttributeReadMostly type")]]
auto cudaMemRangeAttributeReadMostly_type() {
  [[clang::matcher_block]]
  {
    cudaMemRangeAttributeReadMostly varname;
  }
}

[[clang::replace("cudaMemRangeAttributeReadMostly type")]]
auto cudaMemRangeAttributeReadMostly_replace() {
  [[clang::matcher_block]]
  {
    hipMemRangeAttributeReadMostly varname;
  }
}

[[clang::matcher("cudaMemcpy3DParms type")]]
auto cudaMemcpy3DParms_type() {
  [[clang::matcher_block]]
  {
    cudaMemcpy3DParms varname;
  }
}

[[clang::replace("cudaMemcpy3DParms type")]]
auto cudaMemcpy3DParms_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy3DParms varname;
  }
}

[[clang::matcher("cudaMemcpyDefault type")]]
auto cudaMemcpyDefault_type() {
  [[clang::matcher_block]]
  {
    cudaMemcpyDefault varname;
  }
}

[[clang::replace("cudaMemcpyDefault type")]]
auto cudaMemcpyDefault_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyDefault varname;
  }
}

[[clang::matcher("cudaMemcpyDeviceToDevice type")]]
auto cudaMemcpyDeviceToDevice_type() {
  [[clang::matcher_block]]
  {
    cudaMemcpyDeviceToDevice varname;
  }
}

[[clang::replace("cudaMemcpyDeviceToDevice type")]]
auto cudaMemcpyDeviceToDevice_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyDeviceToDevice varname;
  }
}

[[clang::matcher("cudaMemcpyDeviceToHost type")]]
auto cudaMemcpyDeviceToHost_type() {
  [[clang::matcher_block]]
  {
    cudaMemcpyDeviceToHost varname;
  }
}

[[clang::replace("cudaMemcpyDeviceToHost type")]]
auto cudaMemcpyDeviceToHost_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyDeviceToHost varname;
  }
}

[[clang::matcher("cudaMemcpyHostToDevice type")]]
auto cudaMemcpyHostToDevice_type() {
  [[clang::matcher_block]]
  {
    cudaMemcpyHostToDevice varname;
  }
}

[[clang::replace("cudaMemcpyHostToDevice type")]]
auto cudaMemcpyHostToDevice_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyHostToDevice varname;
  }
}

[[clang::matcher("cudaMemcpyHostToHost type")]]
auto cudaMemcpyHostToHost_type() {
  [[clang::matcher_block]]
  {
    cudaMemcpyHostToHost varname;
  }
}

[[clang::replace("cudaMemcpyHostToHost type")]]
auto cudaMemcpyHostToHost_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyHostToHost varname;
  }
}

[[clang::matcher("cudaMemcpyKind type")]]
auto cudaMemcpyKind_type() {
  [[clang::matcher_block]]
  {
    cudaMemcpyKind varname;
  }
}

[[clang::replace("cudaMemcpyKind type")]]
auto cudaMemcpyKind_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyKind varname;
  }
}

[[clang::matcher("cudaMemoryAdvise type")]]
auto cudaMemoryAdvise_type() {
  [[clang::matcher_block]]
  {
    cudaMemoryAdvise varname;
  }
}

[[clang::replace("cudaMemoryAdvise type")]]
auto cudaMemoryAdvise_replace() {
  [[clang::matcher_block]]
  {
    hipMemoryAdvise varname;
  }
}

[[clang::matcher("cudaMemoryType type")]]
auto cudaMemoryType_type() {
  [[clang::matcher_block]]
  {
    cudaMemoryType varname;
  }
}

[[clang::replace("cudaMemoryType type")]]
auto cudaMemoryType_replace() {
  [[clang::matcher_block]]
  {
    hipMemoryType varname;
  }
}

[[clang::matcher("cudaMemoryTypeDevice type")]]
auto cudaMemoryTypeDevice_type() {
  [[clang::matcher_block]]
  {
    cudaMemoryTypeDevice varname;
  }
}

[[clang::replace("cudaMemoryTypeDevice type")]]
auto cudaMemoryTypeDevice_replace() {
  [[clang::matcher_block]]
  {
    hipMemoryTypeDevice varname;
  }
}

[[clang::matcher("cudaMemoryTypeHost type")]]
auto cudaMemoryTypeHost_type() {
  [[clang::matcher_block]]
  {
    cudaMemoryTypeHost varname;
  }
}

[[clang::replace("cudaMemoryTypeHost type")]]
auto cudaMemoryTypeHost_replace() {
  [[clang::matcher_block]]
  {
    hipMemoryTypeHost varname;
  }
}

[[clang::matcher("cudaMemsetParams type")]]
auto cudaMemsetParams_type() {
  [[clang::matcher_block]]
  {
    cudaMemsetParams varname;
  }
}

[[clang::replace("cudaMemsetParams type")]]
auto cudaMemsetParams_replace() {
  [[clang::matcher_block]]
  {
    hipMemsetParams varname;
  }
}

[[clang::matcher("cudaMipmappedArray type")]]
auto cudaMipmappedArray_type() {
  [[clang::matcher_block]]
  {
    cudaMipmappedArray varname;
  }
}

[[clang::replace("cudaMipmappedArray type")]]
auto cudaMipmappedArray_replace() {
  [[clang::matcher_block]]
  {
    hipMipmappedArray varname;
  }
}

[[clang::matcher("cudaMipmappedArray_const_t type")]]
auto cudaMipmappedArray_const_t_type() {
  [[clang::matcher_block]]
  {
    cudaMipmappedArray_const_t varname;
  }
}

[[clang::replace("cudaMipmappedArray_const_t type")]]
auto cudaMipmappedArray_const_t_replace() {
  [[clang::matcher_block]]
  {
    hipMipmappedArray_const_t varname;
  }
}

[[clang::matcher("cudaMipmappedArray_t type")]]
auto cudaMipmappedArray_t_type() {
  [[clang::matcher_block]]
  {
    cudaMipmappedArray_t varname;
  }
}

[[clang::replace("cudaMipmappedArray_t type")]]
auto cudaMipmappedArray_t_replace() {
  [[clang::matcher_block]]
  {
    hipMipmappedArray_t varname;
  }
}

[[clang::matcher("cudaOccupancyDefault type")]]
auto cudaOccupancyDefault_type() {
  [[clang::matcher_block]]
  {
    cudaOccupancyDefault varname;
  }
}

[[clang::replace("cudaOccupancyDefault type")]]
auto cudaOccupancyDefault_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyDefault varname;
  }
}

[[clang::matcher("cudaPitchedPtr type")]]
auto cudaPitchedPtr_type() {
  [[clang::matcher_block]]
  {
    cudaPitchedPtr varname;
  }
}

[[clang::replace("cudaPitchedPtr type")]]
auto cudaPitchedPtr_replace() {
  [[clang::matcher_block]]
  {
    hipPitchedPtr varname;
  }
}

[[clang::matcher("cudaPointerAttributes type")]]
auto cudaPointerAttributes_type() {
  [[clang::matcher_block]]
  {
    cudaPointerAttributes varname;
  }
}

[[clang::replace("cudaPointerAttributes type")]]
auto cudaPointerAttributes_replace() {
  [[clang::matcher_block]]
  {
    hipPointerAttribute_t varname;
  }
}

[[clang::matcher("cudaPos type")]]
auto cudaPos_type() {
  [[clang::matcher_block]]
  {
    cudaPos varname;
  }
}

[[clang::replace("cudaPos type")]]
auto cudaPos_replace() {
  [[clang::matcher_block]]
  {
    hipPos varname;
  }
}

[[clang::matcher("cudaReadModeElementType type")]]
auto cudaReadModeElementType_type() {
  [[clang::matcher_block]]
  {
    cudaReadModeElementType varname;
  }
}

[[clang::replace("cudaReadModeElementType type")]]
auto cudaReadModeElementType_replace() {
  [[clang::matcher_block]]
  {
    hipReadModeElementType varname;
  }
}

[[clang::matcher("cudaReadModeNormalizedFloat type")]]
auto cudaReadModeNormalizedFloat_type() {
  [[clang::matcher_block]]
  {
    cudaReadModeNormalizedFloat varname;
  }
}

[[clang::replace("cudaReadModeNormalizedFloat type")]]
auto cudaReadModeNormalizedFloat_replace() {
  [[clang::matcher_block]]
  {
    hipReadModeNormalizedFloat varname;
  }
}

[[clang::matcher("cudaResViewFormatFloat1 type")]]
auto cudaResViewFormatFloat1_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatFloat1 varname;
  }
}

[[clang::replace("cudaResViewFormatFloat1 type")]]
auto cudaResViewFormatFloat1_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatFloat1 varname;
  }
}

[[clang::matcher("cudaResViewFormatFloat2 type")]]
auto cudaResViewFormatFloat2_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatFloat2 varname;
  }
}

[[clang::replace("cudaResViewFormatFloat2 type")]]
auto cudaResViewFormatFloat2_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatFloat2 varname;
  }
}

[[clang::matcher("cudaResViewFormatFloat4 type")]]
auto cudaResViewFormatFloat4_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatFloat4 varname;
  }
}

[[clang::replace("cudaResViewFormatFloat4 type")]]
auto cudaResViewFormatFloat4_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatFloat4 varname;
  }
}

[[clang::matcher("cudaResViewFormatHalf1 type")]]
auto cudaResViewFormatHalf1_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatHalf1 varname;
  }
}

[[clang::replace("cudaResViewFormatHalf1 type")]]
auto cudaResViewFormatHalf1_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatHalf1 varname;
  }
}

[[clang::matcher("cudaResViewFormatHalf2 type")]]
auto cudaResViewFormatHalf2_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatHalf2 varname;
  }
}

[[clang::replace("cudaResViewFormatHalf2 type")]]
auto cudaResViewFormatHalf2_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatHalf2 varname;
  }
}

[[clang::matcher("cudaResViewFormatHalf4 type")]]
auto cudaResViewFormatHalf4_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatHalf4 varname;
  }
}

[[clang::replace("cudaResViewFormatHalf4 type")]]
auto cudaResViewFormatHalf4_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatHalf4 varname;
  }
}

[[clang::matcher("cudaResViewFormatNone type")]]
auto cudaResViewFormatNone_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatNone varname;
  }
}

[[clang::replace("cudaResViewFormatNone type")]]
auto cudaResViewFormatNone_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatNone varname;
  }
}

[[clang::matcher("cudaResViewFormatSignedBlockCompressed4 type")]]
auto cudaResViewFormatSignedBlockCompressed4_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatSignedBlockCompressed4 varname;
  }
}

[[clang::replace("cudaResViewFormatSignedBlockCompressed4 type")]]
auto cudaResViewFormatSignedBlockCompressed4_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatSignedBlockCompressed4 varname;
  }
}

[[clang::matcher("cudaResViewFormatSignedBlockCompressed5 type")]]
auto cudaResViewFormatSignedBlockCompressed5_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatSignedBlockCompressed5 varname;
  }
}

[[clang::replace("cudaResViewFormatSignedBlockCompressed5 type")]]
auto cudaResViewFormatSignedBlockCompressed5_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatSignedBlockCompressed5 varname;
  }
}

[[clang::matcher("cudaResViewFormatSignedBlockCompressed6H type")]]
auto cudaResViewFormatSignedBlockCompressed6H_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatSignedBlockCompressed6H varname;
  }
}

[[clang::replace("cudaResViewFormatSignedBlockCompressed6H type")]]
auto cudaResViewFormatSignedBlockCompressed6H_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatSignedBlockCompressed6H varname;
  }
}

[[clang::matcher("cudaResViewFormatSignedChar1 type")]]
auto cudaResViewFormatSignedChar1_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatSignedChar1 varname;
  }
}

[[clang::replace("cudaResViewFormatSignedChar1 type")]]
auto cudaResViewFormatSignedChar1_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatSignedChar1 varname;
  }
}

[[clang::matcher("cudaResViewFormatSignedChar2 type")]]
auto cudaResViewFormatSignedChar2_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatSignedChar2 varname;
  }
}

[[clang::replace("cudaResViewFormatSignedChar2 type")]]
auto cudaResViewFormatSignedChar2_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatSignedChar2 varname;
  }
}

[[clang::matcher("cudaResViewFormatSignedChar4 type")]]
auto cudaResViewFormatSignedChar4_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatSignedChar4 varname;
  }
}

[[clang::replace("cudaResViewFormatSignedChar4 type")]]
auto cudaResViewFormatSignedChar4_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatSignedChar4 varname;
  }
}

[[clang::matcher("cudaResViewFormatSignedInt1 type")]]
auto cudaResViewFormatSignedInt1_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatSignedInt1 varname;
  }
}

[[clang::replace("cudaResViewFormatSignedInt1 type")]]
auto cudaResViewFormatSignedInt1_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatSignedInt1 varname;
  }
}

[[clang::matcher("cudaResViewFormatSignedInt2 type")]]
auto cudaResViewFormatSignedInt2_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatSignedInt2 varname;
  }
}

[[clang::replace("cudaResViewFormatSignedInt2 type")]]
auto cudaResViewFormatSignedInt2_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatSignedInt2 varname;
  }
}

[[clang::matcher("cudaResViewFormatSignedInt4 type")]]
auto cudaResViewFormatSignedInt4_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatSignedInt4 varname;
  }
}

[[clang::replace("cudaResViewFormatSignedInt4 type")]]
auto cudaResViewFormatSignedInt4_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatSignedInt4 varname;
  }
}

[[clang::matcher("cudaResViewFormatSignedShort1 type")]]
auto cudaResViewFormatSignedShort1_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatSignedShort1 varname;
  }
}

[[clang::replace("cudaResViewFormatSignedShort1 type")]]
auto cudaResViewFormatSignedShort1_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatSignedShort1 varname;
  }
}

[[clang::matcher("cudaResViewFormatSignedShort2 type")]]
auto cudaResViewFormatSignedShort2_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatSignedShort2 varname;
  }
}

[[clang::replace("cudaResViewFormatSignedShort2 type")]]
auto cudaResViewFormatSignedShort2_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatSignedShort2 varname;
  }
}

[[clang::matcher("cudaResViewFormatSignedShort4 type")]]
auto cudaResViewFormatSignedShort4_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatSignedShort4 varname;
  }
}

[[clang::replace("cudaResViewFormatSignedShort4 type")]]
auto cudaResViewFormatSignedShort4_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatSignedShort4 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedBlockCompressed1 type")]]
auto cudaResViewFormatUnsignedBlockCompressed1_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedBlockCompressed1 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedBlockCompressed1 type")]]
auto cudaResViewFormatUnsignedBlockCompressed1_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedBlockCompressed1 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedBlockCompressed2 type")]]
auto cudaResViewFormatUnsignedBlockCompressed2_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedBlockCompressed2 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedBlockCompressed2 type")]]
auto cudaResViewFormatUnsignedBlockCompressed2_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedBlockCompressed2 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedBlockCompressed3 type")]]
auto cudaResViewFormatUnsignedBlockCompressed3_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedBlockCompressed3 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedBlockCompressed3 type")]]
auto cudaResViewFormatUnsignedBlockCompressed3_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedBlockCompressed3 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedBlockCompressed4 type")]]
auto cudaResViewFormatUnsignedBlockCompressed4_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedBlockCompressed4 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedBlockCompressed4 type")]]
auto cudaResViewFormatUnsignedBlockCompressed4_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedBlockCompressed4 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedBlockCompressed5 type")]]
auto cudaResViewFormatUnsignedBlockCompressed5_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedBlockCompressed5 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedBlockCompressed5 type")]]
auto cudaResViewFormatUnsignedBlockCompressed5_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedBlockCompressed5 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedBlockCompressed6H type")]]
auto cudaResViewFormatUnsignedBlockCompressed6H_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedBlockCompressed6H varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedBlockCompressed6H type")]]
auto cudaResViewFormatUnsignedBlockCompressed6H_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedBlockCompressed6H varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedBlockCompressed7 type")]]
auto cudaResViewFormatUnsignedBlockCompressed7_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedBlockCompressed7 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedBlockCompressed7 type")]]
auto cudaResViewFormatUnsignedBlockCompressed7_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedBlockCompressed7 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedChar1 type")]]
auto cudaResViewFormatUnsignedChar1_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedChar1 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedChar1 type")]]
auto cudaResViewFormatUnsignedChar1_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedChar1 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedChar2 type")]]
auto cudaResViewFormatUnsignedChar2_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedChar2 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedChar2 type")]]
auto cudaResViewFormatUnsignedChar2_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedChar2 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedChar4 type")]]
auto cudaResViewFormatUnsignedChar4_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedChar4 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedChar4 type")]]
auto cudaResViewFormatUnsignedChar4_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedChar4 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedInt1 type")]]
auto cudaResViewFormatUnsignedInt1_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedInt1 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedInt1 type")]]
auto cudaResViewFormatUnsignedInt1_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedInt1 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedInt2 type")]]
auto cudaResViewFormatUnsignedInt2_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedInt2 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedInt2 type")]]
auto cudaResViewFormatUnsignedInt2_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedInt2 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedInt4 type")]]
auto cudaResViewFormatUnsignedInt4_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedInt4 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedInt4 type")]]
auto cudaResViewFormatUnsignedInt4_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedInt4 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedShort1 type")]]
auto cudaResViewFormatUnsignedShort1_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedShort1 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedShort1 type")]]
auto cudaResViewFormatUnsignedShort1_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedShort1 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedShort2 type")]]
auto cudaResViewFormatUnsignedShort2_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedShort2 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedShort2 type")]]
auto cudaResViewFormatUnsignedShort2_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedShort2 varname;
  }
}

[[clang::matcher("cudaResViewFormatUnsignedShort4 type")]]
auto cudaResViewFormatUnsignedShort4_type() {
  [[clang::matcher_block]]
  {
    cudaResViewFormatUnsignedShort4 varname;
  }
}

[[clang::replace("cudaResViewFormatUnsignedShort4 type")]]
auto cudaResViewFormatUnsignedShort4_replace() {
  [[clang::matcher_block]]
  {
    hipResViewFormatUnsignedShort4 varname;
  }
}

[[clang::matcher("cudaResourceDesc type")]]
auto cudaResourceDesc_type() {
  [[clang::matcher_block]]
  {
    cudaResourceDesc varname;
  }
}

[[clang::replace("cudaResourceDesc type")]]
auto cudaResourceDesc_replace() {
  [[clang::matcher_block]]
  {
    hipResourceDesc varname;
  }
}

[[clang::matcher("cudaResourceType type")]]
auto cudaResourceType_type() {
  [[clang::matcher_block]]
  {
    cudaResourceType varname;
  }
}

[[clang::replace("cudaResourceType type")]]
auto cudaResourceType_replace() {
  [[clang::matcher_block]]
  {
    hipResourceType varname;
  }
}

[[clang::matcher("cudaResourceTypeArray type")]]
auto cudaResourceTypeArray_type() {
  [[clang::matcher_block]]
  {
    cudaResourceTypeArray varname;
  }
}

[[clang::replace("cudaResourceTypeArray type")]]
auto cudaResourceTypeArray_replace() {
  [[clang::matcher_block]]
  {
    hipResourceTypeArray varname;
  }
}

[[clang::matcher("cudaResourceTypeLinear type")]]
auto cudaResourceTypeLinear_type() {
  [[clang::matcher_block]]
  {
    cudaResourceTypeLinear varname;
  }
}

[[clang::replace("cudaResourceTypeLinear type")]]
auto cudaResourceTypeLinear_replace() {
  [[clang::matcher_block]]
  {
    hipResourceTypeLinear varname;
  }
}

[[clang::matcher("cudaResourceTypeMipmappedArray type")]]
auto cudaResourceTypeMipmappedArray_type() {
  [[clang::matcher_block]]
  {
    cudaResourceTypeMipmappedArray varname;
  }
}

[[clang::replace("cudaResourceTypeMipmappedArray type")]]
auto cudaResourceTypeMipmappedArray_replace() {
  [[clang::matcher_block]]
  {
    hipResourceTypeMipmappedArray varname;
  }
}

[[clang::matcher("cudaResourceTypePitch2D type")]]
auto cudaResourceTypePitch2D_type() {
  [[clang::matcher_block]]
  {
    cudaResourceTypePitch2D varname;
  }
}

[[clang::replace("cudaResourceTypePitch2D type")]]
auto cudaResourceTypePitch2D_replace() {
  [[clang::matcher_block]]
  {
    hipResourceTypePitch2D varname;
  }
}

[[clang::matcher("cudaResourceViewDesc type")]]
auto cudaResourceViewDesc_type() {
  [[clang::matcher_block]]
  {
    cudaResourceViewDesc varname;
  }
}

[[clang::replace("cudaResourceViewDesc type")]]
auto cudaResourceViewDesc_replace() {
  [[clang::matcher_block]]
  {
    hipResourceViewDesc varname;
  }
}

[[clang::matcher("cudaResourceViewFormat type")]]
auto cudaResourceViewFormat_type() {
  [[clang::matcher_block]]
  {
    cudaResourceViewFormat varname;
  }
}

[[clang::replace("cudaResourceViewFormat type")]]
auto cudaResourceViewFormat_replace() {
  [[clang::matcher_block]]
  {
    hipResourceViewFormat varname;
  }
}

[[clang::matcher("cudaSharedMemBankSizeDefault type")]]
auto cudaSharedMemBankSizeDefault_type() {
  [[clang::matcher_block]]
  {
    cudaSharedMemBankSizeDefault varname;
  }
}

[[clang::replace("cudaSharedMemBankSizeDefault type")]]
auto cudaSharedMemBankSizeDefault_replace() {
  [[clang::matcher_block]]
  {
    hipSharedMemBankSizeDefault varname;
  }
}

[[clang::matcher("cudaSharedMemBankSizeEightByte type")]]
auto cudaSharedMemBankSizeEightByte_type() {
  [[clang::matcher_block]]
  {
    cudaSharedMemBankSizeEightByte varname;
  }
}

[[clang::replace("cudaSharedMemBankSizeEightByte type")]]
auto cudaSharedMemBankSizeEightByte_replace() {
  [[clang::matcher_block]]
  {
    hipSharedMemBankSizeEightByte varname;
  }
}

[[clang::matcher("cudaSharedMemBankSizeFourByte type")]]
auto cudaSharedMemBankSizeFourByte_type() {
  [[clang::matcher_block]]
  {
    cudaSharedMemBankSizeFourByte varname;
  }
}

[[clang::replace("cudaSharedMemBankSizeFourByte type")]]
auto cudaSharedMemBankSizeFourByte_replace() {
  [[clang::matcher_block]]
  {
    hipSharedMemBankSizeFourByte varname;
  }
}

[[clang::matcher("cudaSharedMemConfig type")]]
auto cudaSharedMemConfig_type() {
  [[clang::matcher_block]]
  {
    cudaSharedMemConfig varname;
  }
}

[[clang::replace("cudaSharedMemConfig type")]]
auto cudaSharedMemConfig_replace() {
  [[clang::matcher_block]]
  {
    hipSharedMemConfig varname;
  }
}

[[clang::matcher("cudaStreamCallback_t type")]]
auto cudaStreamCallback_t_type() {
  [[clang::matcher_block]]
  {
    cudaStreamCallback_t varname;
  }
}

[[clang::replace("cudaStreamCallback_t type")]]
auto cudaStreamCallback_t_replace() {
  [[clang::matcher_block]]
  {
    hipStreamCallback_t varname;
  }
}

[[clang::matcher("cudaStreamCaptureMode type")]]
auto cudaStreamCaptureMode_type() {
  [[clang::matcher_block]]
  {
    cudaStreamCaptureMode varname;
  }
}

[[clang::replace("cudaStreamCaptureMode type")]]
auto cudaStreamCaptureMode_replace() {
  [[clang::matcher_block]]
  {
    hipStreamCaptureMode varname;
  }
}

[[clang::matcher("cudaStreamCaptureModeGlobal type")]]
auto cudaStreamCaptureModeGlobal_type() {
  [[clang::matcher_block]]
  {
    cudaStreamCaptureModeGlobal varname;
  }
}

[[clang::replace("cudaStreamCaptureModeGlobal type")]]
auto cudaStreamCaptureModeGlobal_replace() {
  [[clang::matcher_block]]
  {
    hipStreamCaptureModeGlobal varname;
  }
}

[[clang::matcher("cudaStreamCaptureModeRelaxed type")]]
auto cudaStreamCaptureModeRelaxed_type() {
  [[clang::matcher_block]]
  {
    cudaStreamCaptureModeRelaxed varname;
  }
}

[[clang::replace("cudaStreamCaptureModeRelaxed type")]]
auto cudaStreamCaptureModeRelaxed_replace() {
  [[clang::matcher_block]]
  {
    hipStreamCaptureModeRelaxed varname;
  }
}

[[clang::matcher("cudaStreamCaptureModeThreadLocal type")]]
auto cudaStreamCaptureModeThreadLocal_type() {
  [[clang::matcher_block]]
  {
    cudaStreamCaptureModeThreadLocal varname;
  }
}

[[clang::replace("cudaStreamCaptureModeThreadLocal type")]]
auto cudaStreamCaptureModeThreadLocal_replace() {
  [[clang::matcher_block]]
  {
    hipStreamCaptureModeThreadLocal varname;
  }
}

[[clang::matcher("cudaStreamCaptureStatus type")]]
auto cudaStreamCaptureStatus_type() {
  [[clang::matcher_block]]
  {
    cudaStreamCaptureStatus varname;
  }
}

[[clang::replace("cudaStreamCaptureStatus type")]]
auto cudaStreamCaptureStatus_replace() {
  [[clang::matcher_block]]
  {
    hipStreamCaptureStatus varname;
  }
}

[[clang::matcher("cudaStreamCaptureStatusActive type")]]
auto cudaStreamCaptureStatusActive_type() {
  [[clang::matcher_block]]
  {
    cudaStreamCaptureStatusActive varname;
  }
}

[[clang::replace("cudaStreamCaptureStatusActive type")]]
auto cudaStreamCaptureStatusActive_replace() {
  [[clang::matcher_block]]
  {
    hipStreamCaptureStatusActive varname;
  }
}

[[clang::matcher("cudaStreamCaptureStatusInvalidated type")]]
auto cudaStreamCaptureStatusInvalidated_type() {
  [[clang::matcher_block]]
  {
    cudaStreamCaptureStatusInvalidated varname;
  }
}

[[clang::replace("cudaStreamCaptureStatusInvalidated type")]]
auto cudaStreamCaptureStatusInvalidated_replace() {
  [[clang::matcher_block]]
  {
    hipStreamCaptureStatusInvalidated varname;
  }
}

[[clang::matcher("cudaStreamCaptureStatusNone type")]]
auto cudaStreamCaptureStatusNone_type() {
  [[clang::matcher_block]]
  {
    cudaStreamCaptureStatusNone varname;
  }
}

[[clang::replace("cudaStreamCaptureStatusNone type")]]
auto cudaStreamCaptureStatusNone_replace() {
  [[clang::matcher_block]]
  {
    hipStreamCaptureStatusNone varname;
  }
}

[[clang::matcher("cudaStreamDefault type")]]
auto cudaStreamDefault_type() {
  [[clang::matcher_block]]
  {
    cudaStreamDefault varname;
  }
}

[[clang::replace("cudaStreamDefault type")]]
auto cudaStreamDefault_replace() {
  [[clang::matcher_block]]
  {
    hipStreamDefault varname;
  }
}

[[clang::matcher("cudaStreamNonBlocking type")]]
auto cudaStreamNonBlocking_type() {
  [[clang::matcher_block]]
  {
    cudaStreamNonBlocking varname;
  }
}

[[clang::replace("cudaStreamNonBlocking type")]]
auto cudaStreamNonBlocking_replace() {
  [[clang::matcher_block]]
  {
    hipStreamNonBlocking varname;
  }
}

[[clang::matcher("cudaStreamPerThread type")]]
auto cudaStreamPerThread_type() {
  [[clang::matcher_block]]
  {
    cudaStreamPerThread varname;
  }
}

[[clang::replace("cudaStreamPerThread type")]]
auto cudaStreamPerThread_replace() {
  [[clang::matcher_block]]
  {
    hipStreamPerThread varname;
  }
}

[[clang::matcher("cudaStream_t type")]]
auto cudaStream_t_type() {
  [[clang::matcher_block]]
  {
    cudaStream_t varname;
  }
}

[[clang::replace("cudaStream_t type")]]
auto cudaStream_t_replace() {
  [[clang::matcher_block]]
  {
    hipStream_t varname;
  }
}

[[clang::matcher("cudaSuccess type")]]
auto cudaSuccess_type() {
  [[clang::matcher_block]]
  {
    cudaSuccess varname;
  }
}

[[clang::replace("cudaSuccess type")]]
auto cudaSuccess_replace() {
  [[clang::matcher_block]]
  {
    hipSuccess varname;
  }
}

[[clang::matcher("cudaSurfaceBoundaryMode type")]]
auto cudaSurfaceBoundaryMode_type() {
  [[clang::matcher_block]]
  {
    cudaSurfaceBoundaryMode varname;
  }
}

[[clang::replace("cudaSurfaceBoundaryMode type")]]
auto cudaSurfaceBoundaryMode_replace() {
  [[clang::matcher_block]]
  {
    hipSurfaceBoundaryMode varname;
  }
}

[[clang::matcher("cudaSurfaceObject_t type")]]
auto cudaSurfaceObject_t_type() {
  [[clang::matcher_block]]
  {
    cudaSurfaceObject_t varname;
  }
}

[[clang::replace("cudaSurfaceObject_t type")]]
auto cudaSurfaceObject_t_replace() {
  [[clang::matcher_block]]
  {
    hipSurfaceObject_t varname;
  }
}

[[clang::matcher("cudaTextureAddressMode type")]]
auto cudaTextureAddressMode_type() {
  [[clang::matcher_block]]
  {
    cudaTextureAddressMode varname;
  }
}

[[clang::replace("cudaTextureAddressMode type")]]
auto cudaTextureAddressMode_replace() {
  [[clang::matcher_block]]
  {
    hipTextureAddressMode varname;
  }
}

[[clang::matcher("cudaTextureDesc type")]]
auto cudaTextureDesc_type() {
  [[clang::matcher_block]]
  {
    cudaTextureDesc varname;
  }
}

[[clang::replace("cudaTextureDesc type")]]
auto cudaTextureDesc_replace() {
  [[clang::matcher_block]]
  {
    hipTextureDesc varname;
  }
}

[[clang::matcher("cudaTextureFilterMode type")]]
auto cudaTextureFilterMode_type() {
  [[clang::matcher_block]]
  {
    cudaTextureFilterMode varname;
  }
}

[[clang::replace("cudaTextureFilterMode type")]]
auto cudaTextureFilterMode_replace() {
  [[clang::matcher_block]]
  {
    hipTextureFilterMode varname;
  }
}

[[clang::matcher("cudaTextureObject_t type")]]
auto cudaTextureObject_t_type() {
  [[clang::matcher_block]]
  {
    cudaTextureObject_t varname;
  }
}

[[clang::replace("cudaTextureObject_t type")]]
auto cudaTextureObject_t_replace() {
  [[clang::matcher_block]]
  {
    hipTextureObject_t varname;
  }
}

[[clang::matcher("cudaTextureReadMode type")]]
auto cudaTextureReadMode_type() {
  [[clang::matcher_block]]
  {
    cudaTextureReadMode varname;
  }
}

[[clang::replace("cudaTextureReadMode type")]]
auto cudaTextureReadMode_replace() {
  [[clang::matcher_block]]
  {
    hipTextureReadMode varname;
  }
}

[[clang::matcher("cudaTextureType1D type")]]
auto cudaTextureType1D_type() {
  [[clang::matcher_block]]
  {
    cudaTextureType1D varname;
  }
}

[[clang::replace("cudaTextureType1D type")]]
auto cudaTextureType1D_replace() {
  [[clang::matcher_block]]
  {
    hipTextureType1D varname;
  }
}

[[clang::matcher("cudaTextureType1DLayered type")]]
auto cudaTextureType1DLayered_type() {
  [[clang::matcher_block]]
  {
    cudaTextureType1DLayered varname;
  }
}

[[clang::replace("cudaTextureType1DLayered type")]]
auto cudaTextureType1DLayered_replace() {
  [[clang::matcher_block]]
  {
    hipTextureType1DLayered varname;
  }
}

[[clang::matcher("cudaTextureType2D type")]]
auto cudaTextureType2D_type() {
  [[clang::matcher_block]]
  {
    cudaTextureType2D varname;
  }
}

[[clang::replace("cudaTextureType2D type")]]
auto cudaTextureType2D_replace() {
  [[clang::matcher_block]]
  {
    hipTextureType2D varname;
  }
}

[[clang::matcher("cudaTextureType2DLayered type")]]
auto cudaTextureType2DLayered_type() {
  [[clang::matcher_block]]
  {
    cudaTextureType2DLayered varname;
  }
}

[[clang::replace("cudaTextureType2DLayered type")]]
auto cudaTextureType2DLayered_replace() {
  [[clang::matcher_block]]
  {
    hipTextureType2DLayered varname;
  }
}

[[clang::matcher("cudaTextureType3D type")]]
auto cudaTextureType3D_type() {
  [[clang::matcher_block]]
  {
    cudaTextureType3D varname;
  }
}

[[clang::replace("cudaTextureType3D type")]]
auto cudaTextureType3D_replace() {
  [[clang::matcher_block]]
  {
    hipTextureType3D varname;
  }
}

[[clang::matcher("cudaTextureTypeCubemap type")]]
auto cudaTextureTypeCubemap_type() {
  [[clang::matcher_block]]
  {
    cudaTextureTypeCubemap varname;
  }
}

[[clang::replace("cudaTextureTypeCubemap type")]]
auto cudaTextureTypeCubemap_replace() {
  [[clang::matcher_block]]
  {
    hipTextureTypeCubemap varname;
  }
}

[[clang::matcher("cudaTextureTypeCubemapLayered type")]]
auto cudaTextureTypeCubemapLayered_type() {
  [[clang::matcher_block]]
  {
    cudaTextureTypeCubemapLayered varname;
  }
}

[[clang::replace("cudaTextureTypeCubemapLayered type")]]
auto cudaTextureTypeCubemapLayered_replace() {
  [[clang::matcher_block]]
  {
    hipTextureTypeCubemapLayered varname;
  }
}

[[clang::matcher("surfaceReference type")]]
auto surfaceReference_type() {
  [[clang::matcher_block]]
  {
    surfaceReference varname;
  }
}

[[clang::replace("surfaceReference type")]]
auto surfaceReference_replace() {
  [[clang::matcher_block]]
  {
    surfaceReference varname;
  }
}



template<CUDA_TEXTURE_DESC * arg1, CUtexObject arg2>
[[clang::matcher("cuTexObjectGetTextureDesc 2 func")]]
auto cuTexObjectGetTextureDesc2_func() {
  [[clang::matcher_block]]
  {
    cuTexObjectGetTextureDesc(arg1, arg2);
  }
}

template<CUDA_TEXTURE_DESC *  arg1, CUtexObject  arg2>
[[clang::replace("cuTexObjectGetTextureDesc 2 func")]]
auto cuTexObjectGetTextureDesc2_replace() {
  [[clang::matcher_block]]
  {
    hipGetTextureObjectTextureDesc(arg1, arg2);
  }
}

template<int * arg1, const struct cudaDeviceProp * arg2>
[[clang::matcher("cudaChooseDevice 2 func")]]
auto cudaChooseDevice2_func() {
  [[clang::matcher_block]]
  {
    cudaChooseDevice(arg1, arg2);
  }
}

template<int *  arg1, const struct hipDeviceProp_t *  arg2>
[[clang::replace("cudaChooseDevice 2 func")]]
auto cudaChooseDevice2_replace() {
  [[clang::matcher_block]]
  {
    hipChooseDevice(arg1, arg2);
  }
}

template<int arg1, int arg2, int arg3, int arg4, enum cudaChannelFormatKind arg5>
[[clang::matcher("cudaCreateChannelDesc 5 func")]]
auto cudaCreateChannelDesc5_func() {
  [[clang::matcher_block]]
  {
    cudaCreateChannelDesc(arg1, arg2, arg3, arg4, arg5);
  }
}

template<int  arg1, int  arg2, int  arg3, int  arg4, enum hipChannelFormatKind  arg5>
[[clang::replace("cudaCreateChannelDesc 5 func")]]
auto cudaCreateChannelDesc5_replace() {
  [[clang::matcher_block]]
  {
    hipCreateChannelDesc(arg1, arg2, arg3, arg4, arg5);
  }
}

template<cudaSurfaceObject_t * arg1, const struct cudaResourceDesc * arg2>
[[clang::matcher("cudaCreateSurfaceObject 2 func")]]
auto cudaCreateSurfaceObject2_func() {
  [[clang::matcher_block]]
  {
    cudaCreateSurfaceObject(arg1, arg2);
  }
}

template<hipSurfaceObject_t *  arg1, const struct hipResourceDesc *  arg2>
[[clang::replace("cudaCreateSurfaceObject 2 func")]]
auto cudaCreateSurfaceObject2_replace() {
  [[clang::matcher_block]]
  {
    hipCreateSurfaceObject(arg1, arg2);
  }
}

template<cudaTextureObject_t * arg1, const struct cudaResourceDesc * arg2, const struct cudaTextureDesc * arg3, const struct cudaResourceViewDesc * arg4>
[[clang::matcher("cudaCreateTextureObject 4 func")]]
auto cudaCreateTextureObject4_func() {
  [[clang::matcher_block]]
  {
    cudaCreateTextureObject(arg1, arg2, arg3, arg4);
  }
}

template<hipTextureObject_t *  arg1, const struct hipResourceDesc *  arg2, const struct hipTextureDesc *  arg3, const struct hipResourceViewDesc *  arg4>
[[clang::replace("cudaCreateTextureObject 4 func")]]
auto cudaCreateTextureObject4_replace() {
  [[clang::matcher_block]]
  {
    hipCreateTextureObject(arg1, arg2, arg3, arg4);
  }
}

template<cudaExternalMemory_t arg1>
[[clang::matcher("cudaDestroyExternalMemory 1 func")]]
auto cudaDestroyExternalMemory1_func() {
  [[clang::matcher_block]]
  {
    cudaDestroyExternalMemory(arg1);
  }
}

template<hipExternalMemory_t  arg1>
[[clang::replace("cudaDestroyExternalMemory 1 func")]]
auto cudaDestroyExternalMemory1_replace() {
  [[clang::matcher_block]]
  {
    hipDestroyExternalMemory(arg1);
  }
}

template<cudaExternalSemaphore_t arg1>
[[clang::matcher("cudaDestroyExternalSemaphore 1 func")]]
auto cudaDestroyExternalSemaphore1_func() {
  [[clang::matcher_block]]
  {
    cudaDestroyExternalSemaphore(arg1);
  }
}

template<hipExternalSemaphore_t  arg1>
[[clang::replace("cudaDestroyExternalSemaphore 1 func")]]
auto cudaDestroyExternalSemaphore1_replace() {
  [[clang::matcher_block]]
  {
    hipDestroyExternalSemaphore(arg1);
  }
}

template<cudaSurfaceObject_t arg1>
[[clang::matcher("cudaDestroySurfaceObject 1 func")]]
auto cudaDestroySurfaceObject1_func() {
  [[clang::matcher_block]]
  {
    cudaDestroySurfaceObject(arg1);
  }
}

template<hipSurfaceObject_t  arg1>
[[clang::replace("cudaDestroySurfaceObject 1 func")]]
auto cudaDestroySurfaceObject1_replace() {
  [[clang::matcher_block]]
  {
    hipDestroySurfaceObject(arg1);
  }
}

template<cudaTextureObject_t arg1>
[[clang::matcher("cudaDestroyTextureObject 1 func")]]
auto cudaDestroyTextureObject1_func() {
  [[clang::matcher_block]]
  {
    cudaDestroyTextureObject(arg1);
  }
}

template<hipTextureObject_t  arg1>
[[clang::replace("cudaDestroyTextureObject 1 func")]]
auto cudaDestroyTextureObject1_replace() {
  [[clang::matcher_block]]
  {
    hipDestroyTextureObject(arg1);
  }
}

template<int * arg1, int arg2, int arg3>
[[clang::matcher("cudaDeviceCanAccessPeer 3 func")]]
auto cudaDeviceCanAccessPeer3_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceCanAccessPeer(arg1, arg2, arg3);
  }
}

template<int *  arg1, int  arg2, int  arg3>
[[clang::replace("cudaDeviceCanAccessPeer 3 func")]]
auto cudaDeviceCanAccessPeer3_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceCanAccessPeer(arg1, arg2, arg3);
  }
}

template<int arg1>
[[clang::matcher("cudaDeviceDisablePeerAccess 1 func")]]
auto cudaDeviceDisablePeerAccess1_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceDisablePeerAccess(arg1);
  }
}

template<int  arg1>
[[clang::replace("cudaDeviceDisablePeerAccess 1 func")]]
auto cudaDeviceDisablePeerAccess1_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceDisablePeerAccess(arg1);
  }
}

template<int arg1, unsigned int arg2>
[[clang::matcher("cudaDeviceEnablePeerAccess 2 func")]]
auto cudaDeviceEnablePeerAccess2_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceEnablePeerAccess(arg1, arg2);
  }
}

template<int  arg1, unsigned int  arg2>
[[clang::replace("cudaDeviceEnablePeerAccess 2 func")]]
auto cudaDeviceEnablePeerAccess2_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceEnablePeerAccess(arg1, arg2);
  }
}

template<int * arg1, enum cudaDeviceAttr arg2, int arg3>
[[clang::matcher("cudaDeviceGetAttribute 3 func")]]
auto cudaDeviceGetAttribute3_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceGetAttribute(arg1, arg2, arg3);
  }
}

template<int *  arg1, enum hipDeviceAttribute_t  arg2, int  arg3>
[[clang::replace("cudaDeviceGetAttribute 3 func")]]
auto cudaDeviceGetAttribute3_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceGetAttribute(arg1, arg2, arg3);
  }
}

template<int * arg1, const char * arg2>
[[clang::matcher("cudaDeviceGetByPCIBusId 2 func")]]
auto cudaDeviceGetByPCIBusId2_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceGetByPCIBusId(arg1, arg2);
  }
}

template<int *  arg1, const char *  arg2>
[[clang::replace("cudaDeviceGetByPCIBusId 2 func")]]
auto cudaDeviceGetByPCIBusId2_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceGetByPCIBusId(arg1, arg2);
  }
}

template<enum cudaFuncCache * arg1>
[[clang::matcher("cudaDeviceGetCacheConfig 1 func")]]
auto cudaDeviceGetCacheConfig1_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceGetCacheConfig(arg1);
  }
}

template<enum hipFuncCache_t *  arg1>
[[clang::replace("cudaDeviceGetCacheConfig 1 func")]]
auto cudaDeviceGetCacheConfig1_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceGetCacheConfig(arg1);
  }
}

template<int * arg1, enum cudaLimit arg2>
[[clang::matcher("cudaDeviceGetLimit 2 func")]]
auto cudaDeviceGetLimit2_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceGetLimit(arg1, arg2);
  }
}

template<int *  arg1, enum hipLimit_t  arg2>
[[clang::replace("cudaDeviceGetLimit 2 func")]]
auto cudaDeviceGetLimit2_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceGetLimit(arg1, arg2);
  }
}

template<int * arg1, enum cudaDeviceP2PAttr arg2, int arg3, int arg4>
[[clang::matcher("cudaDeviceGetP2PAttribute 4 func")]]
auto cudaDeviceGetP2PAttribute4_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceGetP2PAttribute(arg1, arg2, arg3, arg4);
  }
}

template<int *  arg1, enum hipDeviceP2PAttr  arg2, int  arg3, int  arg4>
[[clang::replace("cudaDeviceGetP2PAttribute 4 func")]]
auto cudaDeviceGetP2PAttribute4_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceGetP2PAttribute(arg1, arg2, arg3, arg4);
  }
}

template<char * arg1, int arg2, int arg3>
[[clang::matcher("cudaDeviceGetPCIBusId 3 func")]]
auto cudaDeviceGetPCIBusId3_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceGetPCIBusId(arg1, arg2, arg3);
  }
}

template<char *  arg1, int  arg2, int  arg3>
[[clang::replace("cudaDeviceGetPCIBusId 3 func")]]
auto cudaDeviceGetPCIBusId3_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceGetPCIBusId(arg1, arg2, arg3);
  }
}

template<enum cudaSharedMemConfig * arg1>
[[clang::matcher("cudaDeviceGetSharedMemConfig 1 func")]]
auto cudaDeviceGetSharedMemConfig1_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceGetSharedMemConfig(arg1);
  }
}

template<enum hipSharedMemConfig *  arg1>
[[clang::replace("cudaDeviceGetSharedMemConfig 1 func")]]
auto cudaDeviceGetSharedMemConfig1_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceGetSharedMemConfig(arg1);
  }
}

template<int * arg1, int * arg2>
[[clang::matcher("cudaDeviceGetStreamPriorityRange 2 func")]]
auto cudaDeviceGetStreamPriorityRange2_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceGetStreamPriorityRange(arg1, arg2);
  }
}

template<int *  arg1, int *  arg2>
[[clang::replace("cudaDeviceGetStreamPriorityRange 2 func")]]
auto cudaDeviceGetStreamPriorityRange2_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceGetStreamPriorityRange(arg1, arg2);
  }
}

template<>
[[clang::matcher("cudaDeviceReset 0 func")]]
auto cudaDeviceReset0_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceReset();
  }
}

template<>
[[clang::replace("cudaDeviceReset 0 func")]]
auto cudaDeviceReset0_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceReset();
  }
}

template<enum cudaFuncCache arg1>
[[clang::matcher("cudaDeviceSetCacheConfig 1 func")]]
auto cudaDeviceSetCacheConfig1_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceSetCacheConfig(arg1);
  }
}

template<enum hipFuncCache_t  arg1>
[[clang::replace("cudaDeviceSetCacheConfig 1 func")]]
auto cudaDeviceSetCacheConfig1_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceSetCacheConfig(arg1);
  }
}

template<enum cudaSharedMemConfig arg1>
[[clang::matcher("cudaDeviceSetSharedMemConfig 1 func")]]
auto cudaDeviceSetSharedMemConfig1_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceSetSharedMemConfig(arg1);
  }
}

template<enum hipSharedMemConfig  arg1>
[[clang::replace("cudaDeviceSetSharedMemConfig 1 func")]]
auto cudaDeviceSetSharedMemConfig1_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceSetSharedMemConfig(arg1);
  }
}

template<>
[[clang::matcher("cudaDeviceSynchronize 0 func")]]
auto cudaDeviceSynchronize0_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceSynchronize();
  }
}

template<>
[[clang::replace("cudaDeviceSynchronize 0 func")]]
auto cudaDeviceSynchronize0_replace() {
  [[clang::matcher_block]]
  {
    hipDeviceSynchronize();
  }
}

template<int * arg1>
[[clang::matcher("cudaDriverGetVersion 1 func")]]
auto cudaDriverGetVersion1_func() {
  [[clang::matcher_block]]
  {
    cudaDriverGetVersion(arg1);
  }
}

template<int *  arg1>
[[clang::replace("cudaDriverGetVersion 1 func")]]
auto cudaDriverGetVersion1_replace() {
  [[clang::matcher_block]]
  {
    hipDriverGetVersion(arg1);
  }
}

template<cudaEvent_t * arg1>
[[clang::matcher("cudaEventCreate 1 func")]]
auto cudaEventCreate1_func() {
  [[clang::matcher_block]]
  {
    cudaEventCreate(arg1);
  }
}

template<hipEvent_t *  arg1>
[[clang::replace("cudaEventCreate 1 func")]]
auto cudaEventCreate1_replace() {
  [[clang::matcher_block]]
  {
    hipEventCreate(arg1);
  }
}

template<cudaEvent_t * arg1, unsigned int arg2>
[[clang::matcher("cudaEventCreateWithFlags 2 func")]]
auto cudaEventCreateWithFlags2_func() {
  [[clang::matcher_block]]
  {
    cudaEventCreateWithFlags(arg1, arg2);
  }
}

template<hipEvent_t *  arg1, unsigned int  arg2>
[[clang::replace("cudaEventCreateWithFlags 2 func")]]
auto cudaEventCreateWithFlags2_replace() {
  [[clang::matcher_block]]
  {
    hipEventCreateWithFlags(arg1, arg2);
  }
}

template<cudaEvent_t arg1>
[[clang::matcher("cudaEventDestroy 1 func")]]
auto cudaEventDestroy1_func() {
  [[clang::matcher_block]]
  {
    cudaEventDestroy(arg1);
  }
}

template<hipEvent_t  arg1>
[[clang::replace("cudaEventDestroy 1 func")]]
auto cudaEventDestroy1_replace() {
  [[clang::matcher_block]]
  {
    hipEventDestroy(arg1);
  }
}

template<float * arg1, cudaEvent_t arg2, cudaEvent_t arg3>
[[clang::matcher("cudaEventElapsedTime 3 func")]]
auto cudaEventElapsedTime3_func() {
  [[clang::matcher_block]]
  {
    cudaEventElapsedTime(arg1, arg2, arg3);
  }
}

template<float *  arg1, hipEvent_t  arg2, hipEvent_t  arg3>
[[clang::replace("cudaEventElapsedTime 3 func")]]
auto cudaEventElapsedTime3_replace() {
  [[clang::matcher_block]]
  {
    hipEventElapsedTime(arg1, arg2, arg3);
  }
}

template<cudaEvent_t arg1>
[[clang::matcher("cudaEventQuery 1 func")]]
auto cudaEventQuery1_func() {
  [[clang::matcher_block]]
  {
    cudaEventQuery(arg1);
  }
}

template<hipEvent_t  arg1>
[[clang::replace("cudaEventQuery 1 func")]]
auto cudaEventQuery1_replace() {
  [[clang::matcher_block]]
  {
    hipEventQuery(arg1);
  }
}

template<cudaEvent_t arg1>
[[clang::matcher("cudaEventRecord 1 func")]]
auto cudaEventRecord1_func() {
  [[clang::matcher_block]]
  {
    cudaEventRecord(arg1);
  }
}

template<hipEvent_t  arg1>
[[clang::replace("cudaEventRecord 1 func")]]
auto cudaEventRecord1_replace() {
  [[clang::matcher_block]]
  {
    hipEventRecord(arg1);
  }
}

template<cudaEvent_t arg1, cudaStream_t arg2>
[[clang::matcher("cudaEventRecord 2 func")]]
auto cudaEventRecord2_func() {
  [[clang::matcher_block]]
  {
    cudaEventRecord(arg1, arg2);
  }
}

template<hipEvent_t  arg1, hipStream_t  arg2>
[[clang::replace("cudaEventRecord 2 func")]]
auto cudaEventRecord2_replace() {
  [[clang::matcher_block]]
  {
    hipEventRecord(arg1, arg2);
  }
}

template<cudaEvent_t arg1>
[[clang::matcher("cudaEventSynchronize 1 func")]]
auto cudaEventSynchronize1_func() {
  [[clang::matcher_block]]
  {
    cudaEventSynchronize(arg1);
  }
}

template<hipEvent_t  arg1>
[[clang::replace("cudaEventSynchronize 1 func")]]
auto cudaEventSynchronize1_replace() {
  [[clang::matcher_block]]
  {
    hipEventSynchronize(arg1);
  }
}

template<void ** arg1, cudaExternalMemory_t arg2, const struct cudaExternalMemoryBufferDesc * arg3>
[[clang::matcher("cudaExternalMemoryGetMappedBuffer 3 func")]]
auto cudaExternalMemoryGetMappedBuffer3_func() {
  [[clang::matcher_block]]
  {
    cudaExternalMemoryGetMappedBuffer(arg1, arg2, arg3);
  }
}

template<void **  arg1, hipExternalMemory_t  arg2, const struct hipExternalMemoryBufferDesc *  arg3>
[[clang::replace("cudaExternalMemoryGetMappedBuffer 3 func")]]
auto cudaExternalMemoryGetMappedBuffer3_replace() {
  [[clang::matcher_block]]
  {
    hipExternalMemoryGetMappedBuffer(arg1, arg2, arg3);
  }
}

template<void * arg1>
[[clang::matcher("cudaFree 1 func")]]
auto cudaFree1_func() {
  [[clang::matcher_block]]
  {
    cudaFree(arg1);
  }
}

template<void *  arg1>
[[clang::replace("cudaFree 1 func")]]
auto cudaFree1_replace() {
  [[clang::matcher_block]]
  {
    hipFree(arg1);
  }
}

template<cudaArray_t arg1>
[[clang::matcher("cudaFreeArray 1 func")]]
auto cudaFreeArray1_func() {
  [[clang::matcher_block]]
  {
    cudaFreeArray(arg1);
  }
}

template<hipArray_t  arg1>
[[clang::replace("cudaFreeArray 1 func")]]
auto cudaFreeArray1_replace() {
  [[clang::matcher_block]]
  {
    hipFreeArray(arg1);
  }
}

template<void * arg1>
[[clang::matcher("cudaFreeHost 1 func")]]
auto cudaFreeHost1_func() {
  [[clang::matcher_block]]
  {
    cudaFreeHost(arg1);
  }
}

template<void *  arg1>
[[clang::replace("cudaFreeHost 1 func")]]
auto cudaFreeHost1_replace() {
  [[clang::matcher_block]]
  {
    hipHostFree(arg1);
  }
}

template<cudaMipmappedArray_t arg1>
[[clang::matcher("cudaFreeMipmappedArray 1 func")]]
auto cudaFreeMipmappedArray1_func() {
  [[clang::matcher_block]]
  {
    cudaFreeMipmappedArray(arg1);
  }
}

template<hipMipmappedArray_t  arg1>
[[clang::replace("cudaFreeMipmappedArray 1 func")]]
auto cudaFreeMipmappedArray1_replace() {
  [[clang::matcher_block]]
  {
    hipFreeMipmappedArray(arg1);
  }
}

template<struct cudaFuncAttributes * arg1, const void * arg2>
[[clang::matcher("cudaFuncGetAttributes 2 func")]]
auto cudaFuncGetAttributes2_func() {
  [[clang::matcher_block]]
  {
    cudaFuncGetAttributes(arg1, arg2);
  }
}

template<struct hipFuncAttributes *  arg1, const void *  arg2>
[[clang::replace("cudaFuncGetAttributes 2 func")]]
auto cudaFuncGetAttributes2_replace() {
  [[clang::matcher_block]]
  {
    hipFuncGetAttributes(arg1, arg2);
  }
}

template<const void * arg1, enum cudaFuncAttribute arg2, int arg3>
[[clang::matcher("cudaFuncSetAttribute 3 func")]]
auto cudaFuncSetAttribute3_func() {
  [[clang::matcher_block]]
  {
    cudaFuncSetAttribute(arg1, arg2, arg3);
  }
}

template<const void *  arg1, enum hipFuncAttribute  arg2, int  arg3>
[[clang::replace("cudaFuncSetAttribute 3 func")]]
auto cudaFuncSetAttribute3_replace() {
  [[clang::matcher_block]]
  {
    hipFuncSetAttribute(arg1, arg2, arg3);
  }
}

template<const void * arg1, enum cudaFuncCache arg2>
[[clang::matcher("cudaFuncSetCacheConfig 2 func")]]
auto cudaFuncSetCacheConfig2_func() {
  [[clang::matcher_block]]
  {
    cudaFuncSetCacheConfig(arg1, arg2);
  }
}

template<const void *  arg1, enum hipFuncCache_t  arg2>
[[clang::replace("cudaFuncSetCacheConfig 2 func")]]
auto cudaFuncSetCacheConfig2_replace() {
  [[clang::matcher_block]]
  {
    hipFuncSetCacheConfig(arg1, arg2);
  }
}

template<const void * arg1, enum cudaSharedMemConfig arg2>
[[clang::matcher("cudaFuncSetSharedMemConfig 2 func")]]
auto cudaFuncSetSharedMemConfig2_func() {
  [[clang::matcher_block]]
  {
    cudaFuncSetSharedMemConfig(arg1, arg2);
  }
}

template<const void *  arg1, enum hipSharedMemConfig  arg2>
[[clang::replace("cudaFuncSetSharedMemConfig 2 func")]]
auto cudaFuncSetSharedMemConfig2_replace() {
  [[clang::matcher_block]]
  {
    hipFuncSetSharedMemConfig(arg1, arg2);
  }
}

template<unsigned int * arg1, int * arg2, unsigned int arg3, enum cudaGLDeviceList arg4>
[[clang::matcher("cudaGLGetDevices 4 func")]]
auto cudaGLGetDevices4_func() {
  [[clang::matcher_block]]
  {
    cudaGLGetDevices(arg1, arg2, arg3, arg4);
  }
}

template<unsigned int *  arg1, int *  arg2, unsigned int  arg3, enum hipGLDeviceList  arg4>
[[clang::replace("cudaGLGetDevices 4 func")]]
auto cudaGLGetDevices4_replace() {
  [[clang::matcher_block]]
  {
    hipGLGetDevices(arg1, arg2, arg3, arg4);
  }
}

template<struct cudaChannelFormatDesc * arg1, cudaArray_const_t arg2>
[[clang::matcher("cudaGetChannelDesc 2 func")]]
auto cudaGetChannelDesc2_func() {
  [[clang::matcher_block]]
  {
    cudaGetChannelDesc(arg1, arg2);
  }
}

template<struct hipChannelFormatDesc *  arg1, hipArray_const_t  arg2>
[[clang::replace("cudaGetChannelDesc 2 func")]]
auto cudaGetChannelDesc2_replace() {
  [[clang::matcher_block]]
  {
    hipGetChannelDesc(arg1, arg2);
  }
}

template<int * arg1>
[[clang::matcher("cudaGetDevice 1 func")]]
auto cudaGetDevice1_func() {
  [[clang::matcher_block]]
  {
    cudaGetDevice(arg1);
  }
}

template<int *  arg1>
[[clang::replace("cudaGetDevice 1 func")]]
auto cudaGetDevice1_replace() {
  [[clang::matcher_block]]
  {
    hipGetDevice(arg1);
  }
}

template<int * arg1>
[[clang::matcher("cudaGetDeviceCount 1 func")]]
auto cudaGetDeviceCount1_func() {
  [[clang::matcher_block]]
  {
    cudaGetDeviceCount(arg1);
  }
}

template<int *  arg1>
[[clang::replace("cudaGetDeviceCount 1 func")]]
auto cudaGetDeviceCount1_replace() {
  [[clang::matcher_block]]
  {
    hipGetDeviceCount(arg1);
  }
}

template<unsigned int * arg1>
[[clang::matcher("cudaGetDeviceFlags 1 func")]]
auto cudaGetDeviceFlags1_func() {
  [[clang::matcher_block]]
  {
    cudaGetDeviceFlags(arg1);
  }
}

template<unsigned int *  arg1>
[[clang::replace("cudaGetDeviceFlags 1 func")]]
auto cudaGetDeviceFlags1_replace() {
  [[clang::matcher_block]]
  {
    hipGetDeviceFlags(arg1);
  }
}

template<struct cudaDeviceProp * arg1, int arg2>
[[clang::matcher("cudaGetDeviceProperties 2 func")]]
auto cudaGetDeviceProperties2_func() {
  [[clang::matcher_block]]
  {
    cudaGetDeviceProperties(arg1, arg2);
  }
}

template<struct hipDeviceProp_t *  arg1, int  arg2>
[[clang::replace("cudaGetDeviceProperties 2 func")]]
auto cudaGetDeviceProperties2_replace() {
  [[clang::matcher_block]]
  {
    hipGetDeviceProperties(arg1, arg2);
  }
}

template<cudaError_t arg1>
[[clang::matcher("cudaGetErrorName 1 func")]]
auto cudaGetErrorName1_func() {
  [[clang::matcher_block]]
  {
    cudaGetErrorName(arg1);
  }
}

template<hipError_t  arg1>
[[clang::replace("cudaGetErrorName 1 func")]]
auto cudaGetErrorName1_replace() {
  [[clang::matcher_block]]
  {
    hipGetErrorName(arg1);
  }
}

template<cudaError_t arg1>
[[clang::matcher("cudaGetErrorString 1 func")]]
auto cudaGetErrorString1_func() {
  [[clang::matcher_block]]
  {
    cudaGetErrorString(arg1);
  }
}

template<hipError_t  arg1>
[[clang::replace("cudaGetErrorString 1 func")]]
auto cudaGetErrorString1_replace() {
  [[clang::matcher_block]]
  {
    hipGetErrorString(arg1);
  }
}

template<>
[[clang::matcher("cudaGetLastError 0 func")]]
auto cudaGetLastError0_func() {
  [[clang::matcher_block]]
  {
    cudaGetLastError();
  }
}

template<>
[[clang::replace("cudaGetLastError 0 func")]]
auto cudaGetLastError0_replace() {
  [[clang::matcher_block]]
  {
    hipGetLastError();
  }
}

template<cudaArray_t * arg1, cudaMipmappedArray_const_t arg2, unsigned int arg3>
[[clang::matcher("cudaGetMipmappedArrayLevel 3 func")]]
auto cudaGetMipmappedArrayLevel3_func() {
  [[clang::matcher_block]]
  {
    cudaGetMipmappedArrayLevel(arg1, arg2, arg3);
  }
}

template<hipArray_t *  arg1, hipMipmappedArray_const_t  arg2, unsigned int  arg3>
[[clang::replace("cudaGetMipmappedArrayLevel 3 func")]]
auto cudaGetMipmappedArrayLevel3_replace() {
  [[clang::matcher_block]]
  {
    hipGetMipmappedArrayLevel(arg1, arg2, arg3);
  }
}

template<void ** arg1, const void * arg2>
[[clang::matcher("cudaGetSymbolAddress 2 func")]]
auto cudaGetSymbolAddress2_func() {
  [[clang::matcher_block]]
  {
    cudaGetSymbolAddress(arg1, arg2);
  }
}

template<void **  arg1, const void *  arg2>
[[clang::replace("cudaGetSymbolAddress 2 func")]]
auto cudaGetSymbolAddress2_replace() {
  [[clang::matcher_block]]
  {
    hipGetSymbolAddress(arg1, arg2);
  }
}

template<int * arg1, const void * arg2>
[[clang::matcher("cudaGetSymbolSize 2 func")]]
auto cudaGetSymbolSize2_func() {
  [[clang::matcher_block]]
  {
    cudaGetSymbolSize(arg1, arg2);
  }
}

template<int *  arg1, const void *  arg2>
[[clang::replace("cudaGetSymbolSize 2 func")]]
auto cudaGetSymbolSize2_replace() {
  [[clang::matcher_block]]
  {
    hipGetSymbolSize(arg1, arg2);
  }
}

template<struct cudaResourceDesc * arg1, cudaTextureObject_t arg2>
[[clang::matcher("cudaGetTextureObjectResourceDesc 2 func")]]
auto cudaGetTextureObjectResourceDesc2_func() {
  [[clang::matcher_block]]
  {
    cudaGetTextureObjectResourceDesc(arg1, arg2);
  }
}

template<struct hipResourceDesc *  arg1, hipTextureObject_t  arg2>
[[clang::replace("cudaGetTextureObjectResourceDesc 2 func")]]
auto cudaGetTextureObjectResourceDesc2_replace() {
  [[clang::matcher_block]]
  {
    hipGetTextureObjectResourceDesc(arg1, arg2);
  }
}

template<struct cudaResourceViewDesc * arg1, cudaTextureObject_t arg2>
[[clang::matcher("cudaGetTextureObjectResourceViewDesc 2 func")]]
auto cudaGetTextureObjectResourceViewDesc2_func() {
  [[clang::matcher_block]]
  {
    cudaGetTextureObjectResourceViewDesc(arg1, arg2);
  }
}

template<struct hipResourceViewDesc *  arg1, hipTextureObject_t  arg2>
[[clang::replace("cudaGetTextureObjectResourceViewDesc 2 func")]]
auto cudaGetTextureObjectResourceViewDesc2_replace() {
  [[clang::matcher_block]]
  {
    hipGetTextureObjectResourceViewDesc(arg1, arg2);
  }
}

template<cudaGraph_t arg1, const cudaGraphNode_t * arg2, const cudaGraphNode_t * arg3, int arg4>
[[clang::matcher("cudaGraphAddDependencies 4 func")]]
auto cudaGraphAddDependencies4_func() {
  [[clang::matcher_block]]
  {
    cudaGraphAddDependencies(arg1, arg2, arg3, arg4);
  }
}

template<hipGraph_t  arg1, const hipGraphNode_t *  arg2, const hipGraphNode_t *  arg3, int  arg4>
[[clang::replace("cudaGraphAddDependencies 4 func")]]
auto cudaGraphAddDependencies4_replace() {
  [[clang::matcher_block]]
  {
    hipGraphAddDependencies(arg1, arg2, arg3, arg4);
  }
}

template<cudaGraphNode_t * arg1, cudaGraph_t arg2, const cudaGraphNode_t * arg3, int arg4>
[[clang::matcher("cudaGraphAddEmptyNode 4 func")]]
auto cudaGraphAddEmptyNode4_func() {
  [[clang::matcher_block]]
  {
    cudaGraphAddEmptyNode(arg1, arg2, arg3, arg4);
  }
}

template<hipGraphNode_t *  arg1, hipGraph_t  arg2, const hipGraphNode_t *  arg3, int  arg4>
[[clang::replace("cudaGraphAddEmptyNode 4 func")]]
auto cudaGraphAddEmptyNode4_replace() {
  [[clang::matcher_block]]
  {
    hipGraphAddEmptyNode(arg1, arg2, arg3, arg4);
  }
}

template<cudaGraphNode_t * arg1, cudaGraph_t arg2, const cudaGraphNode_t * arg3, int arg4, const struct cudaKernelNodeParams * arg5>
[[clang::matcher("cudaGraphAddKernelNode 5 func")]]
auto cudaGraphAddKernelNode5_func() {
  [[clang::matcher_block]]
  {
    cudaGraphAddKernelNode(arg1, arg2, arg3, arg4, arg5);
  }
}

template<hipGraphNode_t *  arg1, hipGraph_t  arg2, const hipGraphNode_t *  arg3, int  arg4, const struct hipKernelNodeParams *  arg5>
[[clang::replace("cudaGraphAddKernelNode 5 func")]]
auto cudaGraphAddKernelNode5_replace() {
  [[clang::matcher_block]]
  {
    hipGraphAddKernelNode(arg1, arg2, arg3, arg4, arg5);
  }
}

template<cudaGraphNode_t * arg1, cudaGraph_t arg2, const cudaGraphNode_t * arg3, int arg4, const struct cudaMemcpy3DParms * arg5>
[[clang::matcher("cudaGraphAddMemcpyNode 5 func")]]
auto cudaGraphAddMemcpyNode5_func() {
  [[clang::matcher_block]]
  {
    cudaGraphAddMemcpyNode(arg1, arg2, arg3, arg4, arg5);
  }
}

template<hipGraphNode_t *  arg1, hipGraph_t  arg2, const hipGraphNode_t *  arg3, int  arg4, const struct hipMemcpy3DParms *  arg5>
[[clang::replace("cudaGraphAddMemcpyNode 5 func")]]
auto cudaGraphAddMemcpyNode5_replace() {
  [[clang::matcher_block]]
  {
    hipGraphAddMemcpyNode(arg1, arg2, arg3, arg4, arg5);
  }
}

template<cudaGraphNode_t * arg1, cudaGraph_t arg2, const cudaGraphNode_t * arg3, size_t arg4, void * arg5, void * arg6, size_t arg7, cudaMemcpyKind arg8>
[[clang::matcher("cudaGraphAddMemcpyNode1D 8 func")]]
auto cudaGraphAddMemcpyNode1D8_func() {
  [[clang::matcher_block]]
  {
    cudaGraphAddMemcpyNode1D(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template<hipGraphNode_t *  arg1, hipGraph_t  arg2, const hipGraphNode_t *  arg3, size_t  arg4, void *  arg5, void *  arg6, size_t  arg7, hipMemcpyKind  arg8>
[[clang::replace("cudaGraphAddMemcpyNode1D 8 func")]]
auto cudaGraphAddMemcpyNode1D8_replace() {
  [[clang::matcher_block]]
  {
    hipGraphAddMemcpyNode1D(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template<cudaGraphNode_t * arg1, cudaGraph_t arg2, const cudaGraphNode_t * arg3, int arg4, const struct cudaMemsetParams * arg5>
[[clang::matcher("cudaGraphAddMemsetNode 5 func")]]
auto cudaGraphAddMemsetNode5_func() {
  [[clang::matcher_block]]
  {
    cudaGraphAddMemsetNode(arg1, arg2, arg3, arg4, arg5);
  }
}

template<hipGraphNode_t *  arg1, hipGraph_t  arg2, const hipGraphNode_t *  arg3, int  arg4, const struct hipMemsetParams *  arg5>
[[clang::replace("cudaGraphAddMemsetNode 5 func")]]
auto cudaGraphAddMemsetNode5_replace() {
  [[clang::matcher_block]]
  {
    hipGraphAddMemsetNode(arg1, arg2, arg3, arg4, arg5);
  }
}

template<cudaGraph_t * arg1, unsigned int arg2>
[[clang::matcher("cudaGraphCreate 2 func")]]
auto cudaGraphCreate2_func() {
  [[clang::matcher_block]]
  {
    cudaGraphCreate(arg1, arg2);
  }
}

template<hipGraph_t *  arg1, unsigned int  arg2>
[[clang::replace("cudaGraphCreate 2 func")]]
auto cudaGraphCreate2_replace() {
  [[clang::matcher_block]]
  {
    hipGraphCreate(arg1, arg2);
  }
}

template<cudaGraph_t arg1>
[[clang::matcher("cudaGraphDestroy 1 func")]]
auto cudaGraphDestroy1_func() {
  [[clang::matcher_block]]
  {
    cudaGraphDestroy(arg1);
  }
}

template<hipGraph_t  arg1>
[[clang::replace("cudaGraphDestroy 1 func")]]
auto cudaGraphDestroy1_replace() {
  [[clang::matcher_block]]
  {
    hipGraphDestroy(arg1);
  }
}

template<cudaGraphExec_t arg1>
[[clang::matcher("cudaGraphExecDestroy 1 func")]]
auto cudaGraphExecDestroy1_func() {
  [[clang::matcher_block]]
  {
    cudaGraphExecDestroy(arg1);
  }
}

template<hipGraphExec_t  arg1>
[[clang::replace("cudaGraphExecDestroy 1 func")]]
auto cudaGraphExecDestroy1_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExecDestroy(arg1);
  }
}

template<cudaGraphExec_t arg1, cudaGraphNode_t arg2, const struct cudaKernelNodeParams * arg3>
[[clang::matcher("cudaGraphExecKernelNodeSetParams 3 func")]]
auto cudaGraphExecKernelNodeSetParams3_func() {
  [[clang::matcher_block]]
  {
    cudaGraphExecKernelNodeSetParams(arg1, arg2, arg3);
  }
}

template<hipGraphExec_t  arg1, hipGraphNode_t  arg2, const struct hipKernelNodeParams *  arg3>
[[clang::replace("cudaGraphExecKernelNodeSetParams 3 func")]]
auto cudaGraphExecKernelNodeSetParams3_replace() {
  [[clang::matcher_block]]
  {
    hipGraphExecKernelNodeSetParams(arg1, arg2, arg3);
  }
}

template<cudaGraph_t arg1, cudaGraphNode_t * arg2, int * arg3>
[[clang::matcher("cudaGraphGetNodes 3 func")]]
auto cudaGraphGetNodes3_func() {
  [[clang::matcher_block]]
  {
    cudaGraphGetNodes(arg1, arg2, arg3);
  }
}

template<hipGraph_t  arg1, hipGraphNode_t *  arg2, int *  arg3>
[[clang::replace("cudaGraphGetNodes 3 func")]]
auto cudaGraphGetNodes3_replace() {
  [[clang::matcher_block]]
  {
    hipGraphGetNodes(arg1, arg2, arg3);
  }
}

template<cudaGraph_t arg1, cudaGraphNode_t * arg2, int * arg3>
[[clang::matcher("cudaGraphGetRootNodes 3 func")]]
auto cudaGraphGetRootNodes3_func() {
  [[clang::matcher_block]]
  {
    cudaGraphGetRootNodes(arg1, arg2, arg3);
  }
}

template<hipGraph_t  arg1, hipGraphNode_t *  arg2, int *  arg3>
[[clang::replace("cudaGraphGetRootNodes 3 func")]]
auto cudaGraphGetRootNodes3_replace() {
  [[clang::matcher_block]]
  {
    hipGraphGetRootNodes(arg1, arg2, arg3);
  }
}

template<cudaGraphExec_t * arg1, cudaGraph_t arg2, cudaGraphNode_t * arg3, char * arg4, int arg5>
[[clang::matcher("cudaGraphInstantiate 5 func")]]
auto cudaGraphInstantiate5_func() {
  [[clang::matcher_block]]
  {
    cudaGraphInstantiate(arg1, arg2, arg3, arg4, arg5);
  }
}

template<hipGraphExec_t *  arg1, hipGraph_t  arg2, hipGraphNode_t *  arg3, char *  arg4, int  arg5>
[[clang::replace("cudaGraphInstantiate 5 func")]]
auto cudaGraphInstantiate5_replace() {
  [[clang::matcher_block]]
  {
    hipGraphInstantiate(arg1, arg2, arg3, arg4, arg5);
  }
}

template<cudaGraphNode_t arg1, struct cudaKernelNodeParams * arg2>
[[clang::matcher("cudaGraphKernelNodeGetParams 2 func")]]
auto cudaGraphKernelNodeGetParams2_func() {
  [[clang::matcher_block]]
  {
    cudaGraphKernelNodeGetParams(arg1, arg2);
  }
}

template<hipGraphNode_t  arg1, struct hipKernelNodeParams *  arg2>
[[clang::replace("cudaGraphKernelNodeGetParams 2 func")]]
auto cudaGraphKernelNodeGetParams2_replace() {
  [[clang::matcher_block]]
  {
    hipGraphKernelNodeGetParams(arg1, arg2);
  }
}

template<cudaGraphNode_t arg1, const struct cudaKernelNodeParams * arg2>
[[clang::matcher("cudaGraphKernelNodeSetParams 2 func")]]
auto cudaGraphKernelNodeSetParams2_func() {
  [[clang::matcher_block]]
  {
    cudaGraphKernelNodeSetParams(arg1, arg2);
  }
}

template<hipGraphNode_t  arg1, const struct hipKernelNodeParams *  arg2>
[[clang::replace("cudaGraphKernelNodeSetParams 2 func")]]
auto cudaGraphKernelNodeSetParams2_replace() {
  [[clang::matcher_block]]
  {
    hipGraphKernelNodeSetParams(arg1, arg2);
  }
}

template<cudaGraphExec_t arg1, cudaStream_t arg2>
[[clang::matcher("cudaGraphLaunch 2 func")]]
auto cudaGraphLaunch2_func() {
  [[clang::matcher_block]]
  {
    cudaGraphLaunch(arg1, arg2);
  }
}

template<hipGraphExec_t  arg1, hipStream_t  arg2>
[[clang::replace("cudaGraphLaunch 2 func")]]
auto cudaGraphLaunch2_replace() {
  [[clang::matcher_block]]
  {
    hipGraphLaunch(arg1, arg2);
  }
}

template<cudaGraphNode_t arg1, struct cudaMemcpy3DParms * arg2>
[[clang::matcher("cudaGraphMemcpyNodeGetParams 2 func")]]
auto cudaGraphMemcpyNodeGetParams2_func() {
  [[clang::matcher_block]]
  {
    cudaGraphMemcpyNodeGetParams(arg1, arg2);
  }
}

template<hipGraphNode_t  arg1, struct hipMemcpy3DParms *  arg2>
[[clang::replace("cudaGraphMemcpyNodeGetParams 2 func")]]
auto cudaGraphMemcpyNodeGetParams2_replace() {
  [[clang::matcher_block]]
  {
    hipGraphMemcpyNodeGetParams(arg1, arg2);
  }
}

template<cudaGraphNode_t arg1, const struct cudaMemcpy3DParms * arg2>
[[clang::matcher("cudaGraphMemcpyNodeSetParams 2 func")]]
auto cudaGraphMemcpyNodeSetParams2_func() {
  [[clang::matcher_block]]
  {
    cudaGraphMemcpyNodeSetParams(arg1, arg2);
  }
}

template<hipGraphNode_t  arg1, const struct hipMemcpy3DParms *  arg2>
[[clang::replace("cudaGraphMemcpyNodeSetParams 2 func")]]
auto cudaGraphMemcpyNodeSetParams2_replace() {
  [[clang::matcher_block]]
  {
    hipGraphMemcpyNodeSetParams(arg1, arg2);
  }
}

template<cudaGraphNode_t arg1, struct cudaMemsetParams * arg2>
[[clang::matcher("cudaGraphMemsetNodeGetParams 2 func")]]
auto cudaGraphMemsetNodeGetParams2_func() {
  [[clang::matcher_block]]
  {
    cudaGraphMemsetNodeGetParams(arg1, arg2);
  }
}

template<hipGraphNode_t  arg1, struct hipMemsetParams *  arg2>
[[clang::replace("cudaGraphMemsetNodeGetParams 2 func")]]
auto cudaGraphMemsetNodeGetParams2_replace() {
  [[clang::matcher_block]]
  {
    hipGraphMemsetNodeGetParams(arg1, arg2);
  }
}

template<cudaGraphNode_t arg1, const struct cudaMemsetParams * arg2>
[[clang::matcher("cudaGraphMemsetNodeSetParams 2 func")]]
auto cudaGraphMemsetNodeSetParams2_func() {
  [[clang::matcher_block]]
  {
    cudaGraphMemsetNodeSetParams(arg1, arg2);
  }
}

template<hipGraphNode_t  arg1, const struct hipMemsetParams *  arg2>
[[clang::replace("cudaGraphMemsetNodeSetParams 2 func")]]
auto cudaGraphMemsetNodeSetParams2_replace() {
  [[clang::matcher_block]]
  {
    hipGraphMemsetNodeSetParams(arg1, arg2);
  }
}

template<struct cudaGraphicsResource ** arg1, GLuint arg2, unsigned int arg3>
[[clang::matcher("cudaGraphicsGLRegisterBuffer 3 func")]]
auto cudaGraphicsGLRegisterBuffer3_func() {
  [[clang::matcher_block]]
  {
    cudaGraphicsGLRegisterBuffer(arg1, arg2, arg3);
  }
}

template<struct hipGraphicsResource **  arg1, GLuint  arg2, unsigned int  arg3>
[[clang::replace("cudaGraphicsGLRegisterBuffer 3 func")]]
auto cudaGraphicsGLRegisterBuffer3_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsGLRegisterBuffer(arg1, arg2, arg3);
  }
}

template<int arg1, cudaGraphicsResource_t * arg2>
[[clang::matcher("cudaGraphicsMapResources 2 func")]]
auto cudaGraphicsMapResources2_func() {
  [[clang::matcher_block]]
  {
    cudaGraphicsMapResources(arg1, arg2);
  }
}

template<int  arg1, hipGraphicsResource_t *  arg2>
[[clang::replace("cudaGraphicsMapResources 2 func")]]
auto cudaGraphicsMapResources2_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsMapResources(arg1, arg2);
  }
}

template<int arg1, cudaGraphicsResource_t * arg2, cudaStream_t arg3>
[[clang::matcher("cudaGraphicsMapResources 3 func")]]
auto cudaGraphicsMapResources3_func() {
  [[clang::matcher_block]]
  {
    cudaGraphicsMapResources(arg1, arg2, arg3);
  }
}

template<int  arg1, hipGraphicsResource_t *  arg2, hipStream_t  arg3>
[[clang::replace("cudaGraphicsMapResources 3 func")]]
auto cudaGraphicsMapResources3_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsMapResources(arg1, arg2, arg3);
  }
}

template<void ** arg1, int * arg2, cudaGraphicsResource_t arg3>
[[clang::matcher("cudaGraphicsResourceGetMappedPointer 3 func")]]
auto cudaGraphicsResourceGetMappedPointer3_func() {
  [[clang::matcher_block]]
  {
    cudaGraphicsResourceGetMappedPointer(arg1, arg2, arg3);
  }
}

template<void **  arg1, int *  arg2, hipGraphicsResource_t  arg3>
[[clang::replace("cudaGraphicsResourceGetMappedPointer 3 func")]]
auto cudaGraphicsResourceGetMappedPointer3_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsResourceGetMappedPointer(arg1, arg2, arg3);
  }
}

template<int arg1, cudaGraphicsResource_t * arg2>
[[clang::matcher("cudaGraphicsUnmapResources 2 func")]]
auto cudaGraphicsUnmapResources2_func() {
  [[clang::matcher_block]]
  {
    cudaGraphicsUnmapResources(arg1, arg2);
  }
}

template<int  arg1, hipGraphicsResource_t *  arg2>
[[clang::replace("cudaGraphicsUnmapResources 2 func")]]
auto cudaGraphicsUnmapResources2_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsUnmapResources(arg1, arg2);
  }
}

template<int arg1, cudaGraphicsResource_t * arg2, cudaStream_t arg3>
[[clang::matcher("cudaGraphicsUnmapResources 3 func")]]
auto cudaGraphicsUnmapResources3_func() {
  [[clang::matcher_block]]
  {
    cudaGraphicsUnmapResources(arg1, arg2, arg3);
  }
}

template<int  arg1, hipGraphicsResource_t *  arg2, hipStream_t  arg3>
[[clang::replace("cudaGraphicsUnmapResources 3 func")]]
auto cudaGraphicsUnmapResources3_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsUnmapResources(arg1, arg2, arg3);
  }
}

template<cudaGraphicsResource_t arg1>
[[clang::matcher("cudaGraphicsUnregisterResource 1 func")]]
auto cudaGraphicsUnregisterResource1_func() {
  [[clang::matcher_block]]
  {
    cudaGraphicsUnregisterResource(arg1);
  }
}

template<hipGraphicsResource_t  arg1>
[[clang::replace("cudaGraphicsUnregisterResource 1 func")]]
auto cudaGraphicsUnregisterResource1_replace() {
  [[clang::matcher_block]]
  {
    hipGraphicsUnregisterResource(arg1);
  }
}

template<void ** arg1, int arg2, unsigned int arg3>
[[clang::matcher("cudaHostAlloc 3 func")]]
auto cudaHostAlloc3_func() {
  [[clang::matcher_block]]
  {
    cudaHostAlloc(arg1, arg2, arg3);
  }
}

template<void **  arg1, int  arg2, unsigned int  arg3>
[[clang::replace("cudaHostAlloc 3 func")]]
auto cudaHostAlloc3_replace() {
  [[clang::matcher_block]]
  {
    hipHostAlloc(arg1, arg2, arg3);
  }
}

template<void ** arg1, void * arg2, unsigned int arg3>
[[clang::matcher("cudaHostGetDevicePointer 3 func")]]
auto cudaHostGetDevicePointer3_func() {
  [[clang::matcher_block]]
  {
    cudaHostGetDevicePointer(arg1, arg2, arg3);
  }
}

template<void **  arg1, void *  arg2, unsigned int  arg3>
[[clang::replace("cudaHostGetDevicePointer 3 func")]]
auto cudaHostGetDevicePointer3_replace() {
  [[clang::matcher_block]]
  {
    hipHostGetDevicePointer(arg1, arg2, arg3);
  }
}

template<unsigned int * arg1, void * arg2>
[[clang::matcher("cudaHostGetFlags 2 func")]]
auto cudaHostGetFlags2_func() {
  [[clang::matcher_block]]
  {
    cudaHostGetFlags(arg1, arg2);
  }
}

template<unsigned int *  arg1, void *  arg2>
[[clang::replace("cudaHostGetFlags 2 func")]]
auto cudaHostGetFlags2_replace() {
  [[clang::matcher_block]]
  {
    hipHostGetFlags(arg1, arg2);
  }
}

template<void * arg1, int arg2, unsigned int arg3>
[[clang::matcher("cudaHostRegister 3 func")]]
auto cudaHostRegister3_func() {
  [[clang::matcher_block]]
  {
    cudaHostRegister(arg1, arg2, arg3);
  }
}

template<void *  arg1, int  arg2, unsigned int  arg3>
[[clang::replace("cudaHostRegister 3 func")]]
auto cudaHostRegister3_replace() {
  [[clang::matcher_block]]
  {
    hipHostRegister(arg1, arg2, arg3);
  }
}

template<void * arg1>
[[clang::matcher("cudaHostUnregister 1 func")]]
auto cudaHostUnregister1_func() {
  [[clang::matcher_block]]
  {
    cudaHostUnregister(arg1);
  }
}

template<void *  arg1>
[[clang::replace("cudaHostUnregister 1 func")]]
auto cudaHostUnregister1_replace() {
  [[clang::matcher_block]]
  {
    hipHostUnregister(arg1);
  }
}

template<cudaExternalMemory_t * arg1, const struct cudaExternalMemoryHandleDesc * arg2>
[[clang::matcher("cudaImportExternalMemory 2 func")]]
auto cudaImportExternalMemory2_func() {
  [[clang::matcher_block]]
  {
    cudaImportExternalMemory(arg1, arg2);
  }
}

template<hipExternalMemory_t *  arg1, const struct hipExternalMemoryHandleDesc *  arg2>
[[clang::replace("cudaImportExternalMemory 2 func")]]
auto cudaImportExternalMemory2_replace() {
  [[clang::matcher_block]]
  {
    hipImportExternalMemory(arg1, arg2);
  }
}

template<cudaExternalSemaphore_t * arg1, const struct cudaExternalSemaphoreHandleDesc * arg2>
[[clang::matcher("cudaImportExternalSemaphore 2 func")]]
auto cudaImportExternalSemaphore2_func() {
  [[clang::matcher_block]]
  {
    cudaImportExternalSemaphore(arg1, arg2);
  }
}

template<hipExternalSemaphore_t *  arg1, const struct hipExternalSemaphoreHandleDesc *  arg2>
[[clang::replace("cudaImportExternalSemaphore 2 func")]]
auto cudaImportExternalSemaphore2_replace() {
  [[clang::matcher_block]]
  {
    hipImportExternalSemaphore(arg1, arg2);
  }
}

template<void * arg1>
[[clang::matcher("cudaIpcCloseMemHandle 1 func")]]
auto cudaIpcCloseMemHandle1_func() {
  [[clang::matcher_block]]
  {
    cudaIpcCloseMemHandle(arg1);
  }
}

template<void *  arg1>
[[clang::replace("cudaIpcCloseMemHandle 1 func")]]
auto cudaIpcCloseMemHandle1_replace() {
  [[clang::matcher_block]]
  {
    hipIpcCloseMemHandle(arg1);
  }
}

template<cudaIpcEventHandle_t * arg1, cudaEvent_t arg2>
[[clang::matcher("cudaIpcGetEventHandle 2 func")]]
auto cudaIpcGetEventHandle2_func() {
  [[clang::matcher_block]]
  {
    cudaIpcGetEventHandle(arg1, arg2);
  }
}

template<hipIpcEventHandle_t *  arg1, hipEvent_t  arg2>
[[clang::replace("cudaIpcGetEventHandle 2 func")]]
auto cudaIpcGetEventHandle2_replace() {
  [[clang::matcher_block]]
  {
    hipIpcGetEventHandle(arg1, arg2);
  }
}

template<cudaIpcMemHandle_t * arg1, void * arg2>
[[clang::matcher("cudaIpcGetMemHandle 2 func")]]
auto cudaIpcGetMemHandle2_func() {
  [[clang::matcher_block]]
  {
    cudaIpcGetMemHandle(arg1, arg2);
  }
}

template<hipIpcMemHandle_t *  arg1, void *  arg2>
[[clang::replace("cudaIpcGetMemHandle 2 func")]]
auto cudaIpcGetMemHandle2_replace() {
  [[clang::matcher_block]]
  {
    hipIpcGetMemHandle(arg1, arg2);
  }
}

template<cudaEvent_t * arg1, cudaIpcEventHandle_t arg2>
[[clang::matcher("cudaIpcOpenEventHandle 2 func")]]
auto cudaIpcOpenEventHandle2_func() {
  [[clang::matcher_block]]
  {
    cudaIpcOpenEventHandle(arg1, arg2);
  }
}

template<hipEvent_t *  arg1, hipIpcEventHandle_t  arg2>
[[clang::replace("cudaIpcOpenEventHandle 2 func")]]
auto cudaIpcOpenEventHandle2_replace() {
  [[clang::matcher_block]]
  {
    hipIpcOpenEventHandle(arg1, arg2);
  }
}

template<void ** arg1, cudaIpcMemHandle_t arg2, unsigned int arg3>
[[clang::matcher("cudaIpcOpenMemHandle 3 func")]]
auto cudaIpcOpenMemHandle3_func() {
  [[clang::matcher_block]]
  {
    cudaIpcOpenMemHandle(arg1, arg2, arg3);
  }
}

template<void **  arg1, hipIpcMemHandle_t  arg2, unsigned int  arg3>
[[clang::replace("cudaIpcOpenMemHandle 3 func")]]
auto cudaIpcOpenMemHandle3_replace() {
  [[clang::matcher_block]]
  {
    hipIpcOpenMemHandle(arg1, arg2, arg3);
  }
}

template<const void * arg1, dim3 arg2, dim3 arg3, void ** arg4, int arg5, cudaStream_t arg6>
[[clang::matcher("cudaLaunchCooperativeKernel 6 func")]]
auto cudaLaunchCooperativeKernel6_func() {
  [[clang::matcher_block]]
  {
    cudaLaunchCooperativeKernel(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<const void *  arg1, dim3  arg2, dim3  arg3, void **  arg4, int  arg5, hipStream_t  arg6>
[[clang::replace("cudaLaunchCooperativeKernel 6 func")]]
auto cudaLaunchCooperativeKernel6_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchCooperativeKernel(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<const void * arg1, dim3 arg2, dim3 arg3, void ** arg4, int arg5, cudaStream_t arg6>
[[clang::matcher("cudaLaunchKernel 6 func")]]
auto cudaLaunchKernel6_func() {
  [[clang::matcher_block]]
  {
    cudaLaunchKernel(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<const void *  arg1, dim3  arg2, dim3  arg3, void **  arg4, int  arg5, hipStream_t  arg6>
[[clang::replace("cudaLaunchKernel 6 func")]]
auto cudaLaunchKernel6_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernel(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<void ** arg1, int arg2>
[[clang::matcher("cudaMalloc 2 func")]]
auto cudaMalloc2_func() {
  [[clang::matcher_block]]
  {
    cudaMalloc(arg1, arg2);
  }
}

template<void **  arg1, int  arg2>
[[clang::replace("cudaMalloc 2 func")]]
auto cudaMalloc2_replace() {
  [[clang::matcher_block]]
  {
    hipMalloc(arg1, arg2);
  }
}

template<struct cudaPitchedPtr * arg1, struct cudaExtent arg2>
[[clang::matcher("cudaMalloc3D 2 func")]]
auto cudaMalloc3D2_func() {
  [[clang::matcher_block]]
  {
    cudaMalloc3D(arg1, arg2);
  }
}

template<struct hipPitchedPtr *  arg1, struct hipExtent  arg2>
[[clang::replace("cudaMalloc3D 2 func")]]
auto cudaMalloc3D2_replace() {
  [[clang::matcher_block]]
  {
    hipMalloc3D(arg1, arg2);
  }
}

template<cudaArray_t * arg1, const struct cudaChannelFormatDesc * arg2, struct cudaExtent arg3>
[[clang::matcher("cudaMalloc3DArray 3 func")]]
auto cudaMalloc3DArray3_func() {
  [[clang::matcher_block]]
  {
    cudaMalloc3DArray(arg1, arg2, arg3);
  }
}

template<hipArray_t *  arg1, const struct hipChannelFormatDesc *  arg2, struct hipExtent  arg3>
[[clang::replace("cudaMalloc3DArray 3 func")]]
auto cudaMalloc3DArray3_replace() {
  [[clang::matcher_block]]
  {
    hipMalloc3DArray(arg1, arg2, arg3);
  }
}

template<cudaArray_t * arg1, const struct cudaChannelFormatDesc * arg2, struct cudaExtent arg3, unsigned int arg4>
[[clang::matcher("cudaMalloc3DArray 4 func")]]
auto cudaMalloc3DArray4_func() {
  [[clang::matcher_block]]
  {
    cudaMalloc3DArray(arg1, arg2, arg3, arg4);
  }
}

template<hipArray_t *  arg1, const struct hipChannelFormatDesc *  arg2, struct hipExtent  arg3, unsigned int  arg4>
[[clang::replace("cudaMalloc3DArray 4 func")]]
auto cudaMalloc3DArray4_replace() {
  [[clang::matcher_block]]
  {
    hipMalloc3DArray(arg1, arg2, arg3, arg4);
  }
}

template<cudaArray_t * arg1, const struct cudaChannelFormatDesc * arg2, int arg3>
[[clang::matcher("cudaMallocArray 3 func")]]
auto cudaMallocArray3_func() {
  [[clang::matcher_block]]
  {
    cudaMallocArray(arg1, arg2, arg3);
  }
}

template<hipArray_t *  arg1, const struct hipChannelFormatDesc *  arg2, int  arg3>
[[clang::replace("cudaMallocArray 3 func")]]
auto cudaMallocArray3_replace() {
  [[clang::matcher_block]]
  {
    hipMallocArray(arg1, arg2, arg3);
  }
}

template<cudaArray_t * arg1, const struct cudaChannelFormatDesc * arg2, int arg3, int arg4>
[[clang::matcher("cudaMallocArray 4 func")]]
auto cudaMallocArray4_func() {
  [[clang::matcher_block]]
  {
    cudaMallocArray(arg1, arg2, arg3, arg4);
  }
}

template<hipArray_t *  arg1, const struct hipChannelFormatDesc *  arg2, int  arg3, int  arg4>
[[clang::replace("cudaMallocArray 4 func")]]
auto cudaMallocArray4_replace() {
  [[clang::matcher_block]]
  {
    hipMallocArray(arg1, arg2, arg3, arg4);
  }
}

template<cudaArray_t * arg1, const struct cudaChannelFormatDesc * arg2, int arg3, int arg4, unsigned int arg5>
[[clang::matcher("cudaMallocArray 5 func")]]
auto cudaMallocArray5_func() {
  [[clang::matcher_block]]
  {
    cudaMallocArray(arg1, arg2, arg3, arg4, arg5);
  }
}

template<hipArray_t *  arg1, const struct hipChannelFormatDesc *  arg2, int  arg3, int  arg4, unsigned int  arg5>
[[clang::replace("cudaMallocArray 5 func")]]
auto cudaMallocArray5_replace() {
  [[clang::matcher_block]]
  {
    hipMallocArray(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void ** arg1, int arg2>
[[clang::matcher("cudaMallocHost 2 func")]]
auto cudaMallocHost2_func() {
  [[clang::matcher_block]]
  {
    cudaMallocHost(arg1, arg2);
  }
}

template<void **  arg1, int  arg2>
[[clang::replace("cudaMallocHost 2 func")]]
auto cudaMallocHost2_replace() {
  [[clang::matcher_block]]
  {
    hipMallocHost(arg1, arg2);
  }
}

template<void ** arg1, int arg2>
[[clang::matcher("cudaMallocManaged 2 func")]]
auto cudaMallocManaged2_func() {
  [[clang::matcher_block]]
  {
    cudaMallocManaged(arg1, arg2);
  }
}

template<void **  arg1, int  arg2>
[[clang::replace("cudaMallocManaged 2 func")]]
auto cudaMallocManaged2_replace() {
  [[clang::matcher_block]]
  {
    hipMallocManaged(arg1, arg2);
  }
}

template<void ** arg1, int arg2, unsigned int arg3>
[[clang::matcher("cudaMallocManaged 3 func")]]
auto cudaMallocManaged3_func() {
  [[clang::matcher_block]]
  {
    cudaMallocManaged(arg1, arg2, arg3);
  }
}

template<void **  arg1, int  arg2, unsigned int  arg3>
[[clang::replace("cudaMallocManaged 3 func")]]
auto cudaMallocManaged3_replace() {
  [[clang::matcher_block]]
  {
    hipMallocManaged(arg1, arg2, arg3);
  }
}

template<cudaMipmappedArray_t * arg1, const struct cudaChannelFormatDesc * arg2, struct cudaExtent arg3, unsigned int arg4>
[[clang::matcher("cudaMallocMipmappedArray 4 func")]]
auto cudaMallocMipmappedArray4_func() {
  [[clang::matcher_block]]
  {
    cudaMallocMipmappedArray(arg1, arg2, arg3, arg4);
  }
}

template<hipMipmappedArray_t *  arg1, const struct hipChannelFormatDesc *  arg2, struct hipExtent  arg3, unsigned int  arg4>
[[clang::replace("cudaMallocMipmappedArray 4 func")]]
auto cudaMallocMipmappedArray4_replace() {
  [[clang::matcher_block]]
  {
    hipMallocMipmappedArray(arg1, arg2, arg3, arg4);
  }
}

template<cudaMipmappedArray_t * arg1, const struct cudaChannelFormatDesc * arg2, struct cudaExtent arg3, unsigned int arg4, unsigned int arg5>
[[clang::matcher("cudaMallocMipmappedArray 5 func")]]
auto cudaMallocMipmappedArray5_func() {
  [[clang::matcher_block]]
  {
    cudaMallocMipmappedArray(arg1, arg2, arg3, arg4, arg5);
  }
}

template<hipMipmappedArray_t *  arg1, const struct hipChannelFormatDesc *  arg2, struct hipExtent  arg3, unsigned int  arg4, unsigned int  arg5>
[[clang::replace("cudaMallocMipmappedArray 5 func")]]
auto cudaMallocMipmappedArray5_replace() {
  [[clang::matcher_block]]
  {
    hipMallocMipmappedArray(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void ** arg1, int * arg2, int arg3, int arg4>
[[clang::matcher("cudaMallocPitch 4 func")]]
auto cudaMallocPitch4_func() {
  [[clang::matcher_block]]
  {
    cudaMallocPitch(arg1, arg2, arg3, arg4);
  }
}

template<void **  arg1, int *  arg2, int  arg3, int  arg4>
[[clang::replace("cudaMallocPitch 4 func")]]
auto cudaMallocPitch4_replace() {
  [[clang::matcher_block]]
  {
    hipMallocPitch(arg1, arg2, arg3, arg4);
  }
}

template<const void * arg1, int arg2, enum cudaMemoryAdvise arg3, int arg4>
[[clang::matcher("cudaMemAdvise 4 func")]]
auto cudaMemAdvise4_func() {
  [[clang::matcher_block]]
  {
    cudaMemAdvise(arg1, arg2, arg3, arg4);
  }
}

template<const void *  arg1, int  arg2, enum hipMemoryAdvise  arg3, int  arg4>
[[clang::replace("cudaMemAdvise 4 func")]]
auto cudaMemAdvise4_replace() {
  [[clang::matcher_block]]
  {
    hipMemAdvise(arg1, arg2, arg3, arg4);
  }
}

template<int * arg1, int * arg2>
[[clang::matcher("cudaMemGetInfo 2 func")]]
auto cudaMemGetInfo2_func() {
  [[clang::matcher_block]]
  {
    cudaMemGetInfo(arg1, arg2);
  }
}

template<int *  arg1, int *  arg2>
[[clang::replace("cudaMemGetInfo 2 func")]]
auto cudaMemGetInfo2_replace() {
  [[clang::matcher_block]]
  {
    hipMemGetInfo(arg1, arg2);
  }
}

template<const void * arg1, int arg2, int arg3>
[[clang::matcher("cudaMemPrefetchAsync 3 func")]]
auto cudaMemPrefetchAsync3_func() {
  [[clang::matcher_block]]
  {
    cudaMemPrefetchAsync(arg1, arg2, arg3);
  }
}

template<const void *  arg1, int  arg2, int  arg3>
[[clang::replace("cudaMemPrefetchAsync 3 func")]]
auto cudaMemPrefetchAsync3_replace() {
  [[clang::matcher_block]]
  {
    hipMemPrefetchAsync(arg1, arg2, arg3);
  }
}

template<const void * arg1, int arg2, int arg3, cudaStream_t arg4>
[[clang::matcher("cudaMemPrefetchAsync 4 func")]]
auto cudaMemPrefetchAsync4_func() {
  [[clang::matcher_block]]
  {
    cudaMemPrefetchAsync(arg1, arg2, arg3, arg4);
  }
}

template<const void *  arg1, int  arg2, int  arg3, hipStream_t  arg4>
[[clang::replace("cudaMemPrefetchAsync 4 func")]]
auto cudaMemPrefetchAsync4_replace() {
  [[clang::matcher_block]]
  {
    hipMemPrefetchAsync(arg1, arg2, arg3, arg4);
  }
}

template<void * arg1, int arg2, enum cudaMemRangeAttribute arg3, const void * arg4, int arg5>
[[clang::matcher("cudaMemRangeGetAttribute 5 func")]]
auto cudaMemRangeGetAttribute5_func() {
  [[clang::matcher_block]]
  {
    cudaMemRangeGetAttribute(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void *  arg1, int  arg2, enum hipMemRangeAttribute  arg3, const void *  arg4, int  arg5>
[[clang::replace("cudaMemRangeGetAttribute 5 func")]]
auto cudaMemRangeGetAttribute5_replace() {
  [[clang::matcher_block]]
  {
    hipMemRangeGetAttribute(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void ** arg1, int * arg2, enum cudaMemRangeAttribute * arg3, int arg4, const void * arg5, int arg6>
[[clang::matcher("cudaMemRangeGetAttributes 6 func")]]
auto cudaMemRangeGetAttributes6_func() {
  [[clang::matcher_block]]
  {
    cudaMemRangeGetAttributes(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<void **  arg1, int *  arg2, enum hipMemRangeAttribute *  arg3, int  arg4, const void *  arg5, int  arg6>
[[clang::replace("cudaMemRangeGetAttributes 6 func")]]
auto cudaMemRangeGetAttributes6_replace() {
  [[clang::matcher_block]]
  {
    hipMemRangeGetAttributes(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<void * arg1, const void * arg2, int arg3, enum cudaMemcpyKind arg4>
[[clang::matcher("cudaMemcpy 4 func")]]
auto cudaMemcpy4_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy(arg1, arg2, arg3, arg4);
  }
}

template<void *  arg1, const void *  arg2, int  arg3, enum hipMemcpyKind  arg4>
[[clang::replace("cudaMemcpy 4 func")]]
auto cudaMemcpy4_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy(arg1, arg2, arg3, arg4);
  }
}

template<void * arg1, int arg2, const void * arg3, int arg4, int arg5, int arg6, enum cudaMemcpyKind arg7>
[[clang::matcher("cudaMemcpy2D 7 func")]]
auto cudaMemcpy2D7_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy2D(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
  }
}

template<void *  arg1, int  arg2, const void *  arg3, int  arg4, int  arg5, int  arg6, enum hipMemcpyKind  arg7>
[[clang::replace("cudaMemcpy2D 7 func")]]
auto cudaMemcpy2D7_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy2D(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
  }
}

template<void * arg1, int arg2, const void * arg3, int arg4, int arg5, int arg6, enum cudaMemcpyKind arg7>
[[clang::matcher("cudaMemcpy2DAsync 7 func")]]
auto cudaMemcpy2DAsync7_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy2DAsync(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
  }
}

template<void *  arg1, int  arg2, const void *  arg3, int  arg4, int  arg5, int  arg6, enum hipMemcpyKind  arg7>
[[clang::replace("cudaMemcpy2DAsync 7 func")]]
auto cudaMemcpy2DAsync7_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy2DAsync(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
  }
}

template<void * arg1, int arg2, const void * arg3, int arg4, int arg5, int arg6, enum cudaMemcpyKind arg7, cudaStream_t arg8>
[[clang::matcher("cudaMemcpy2DAsync 8 func")]]
auto cudaMemcpy2DAsync8_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy2DAsync(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template<void *  arg1, int  arg2, const void *  arg3, int  arg4, int  arg5, int  arg6, enum hipMemcpyKind  arg7, hipStream_t  arg8>
[[clang::replace("cudaMemcpy2DAsync 8 func")]]
auto cudaMemcpy2DAsync8_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy2DAsync(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template<void * arg1, int arg2, cudaArray_const_t arg3, int arg4, int arg5, int arg6, int arg7, enum cudaMemcpyKind arg8>
[[clang::matcher("cudaMemcpy2DFromArray 8 func")]]
auto cudaMemcpy2DFromArray8_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy2DFromArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template<void *  arg1, int  arg2, hipArray_const_t  arg3, int  arg4, int  arg5, int  arg6, int  arg7, enum hipMemcpyKind  arg8>
[[clang::replace("cudaMemcpy2DFromArray 8 func")]]
auto cudaMemcpy2DFromArray8_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy2DFromArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template<void * arg1, int arg2, cudaArray_const_t arg3, int arg4, int arg5, int arg6, int arg7, enum cudaMemcpyKind arg8>
[[clang::matcher("cudaMemcpy2DFromArrayAsync 8 func")]]
auto cudaMemcpy2DFromArrayAsync8_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy2DFromArrayAsync(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template<void *  arg1, int  arg2, hipArray_const_t  arg3, int  arg4, int  arg5, int  arg6, int  arg7, enum hipMemcpyKind  arg8>
[[clang::replace("cudaMemcpy2DFromArrayAsync 8 func")]]
auto cudaMemcpy2DFromArrayAsync8_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy2DFromArrayAsync(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template<void * arg1, int arg2, cudaArray_const_t arg3, int arg4, int arg5, int arg6, int arg7, enum cudaMemcpyKind arg8, cudaStream_t arg9>
[[clang::matcher("cudaMemcpy2DFromArrayAsync 9 func")]]
auto cudaMemcpy2DFromArrayAsync9_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy2DFromArrayAsync(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
  }
}

template<void *  arg1, int  arg2, hipArray_const_t  arg3, int  arg4, int  arg5, int  arg6, int  arg7, enum hipMemcpyKind  arg8, hipStream_t  arg9>
[[clang::replace("cudaMemcpy2DFromArrayAsync 9 func")]]
auto cudaMemcpy2DFromArrayAsync9_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy2DFromArrayAsync(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
  }
}

template<cudaArray_t arg1, int arg2, int arg3, const void * arg4, int arg5, int arg6, int arg7, enum cudaMemcpyKind arg8>
[[clang::matcher("cudaMemcpy2DToArray 8 func")]]
auto cudaMemcpy2DToArray8_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy2DToArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template<hipArray_t  arg1, int  arg2, int  arg3, const void *  arg4, int  arg5, int  arg6, int  arg7, enum hipMemcpyKind  arg8>
[[clang::replace("cudaMemcpy2DToArray 8 func")]]
auto cudaMemcpy2DToArray8_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy2DToArray(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template<cudaArray_t arg1, int arg2, int arg3, const void * arg4, int arg5, int arg6, int arg7, enum cudaMemcpyKind arg8>
[[clang::matcher("cudaMemcpy2DToArrayAsync 8 func")]]
auto cudaMemcpy2DToArrayAsync8_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy2DToArrayAsync(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template<hipArray_t  arg1, int  arg2, int  arg3, const void *  arg4, int  arg5, int  arg6, int  arg7, enum hipMemcpyKind  arg8>
[[clang::replace("cudaMemcpy2DToArrayAsync 8 func")]]
auto cudaMemcpy2DToArrayAsync8_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy2DToArrayAsync(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template<cudaArray_t arg1, int arg2, int arg3, const void * arg4, int arg5, int arg6, int arg7, enum cudaMemcpyKind arg8, cudaStream_t arg9>
[[clang::matcher("cudaMemcpy2DToArrayAsync 9 func")]]
auto cudaMemcpy2DToArrayAsync9_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy2DToArrayAsync(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
  }
}

template<hipArray_t  arg1, int  arg2, int  arg3, const void *  arg4, int  arg5, int  arg6, int  arg7, enum hipMemcpyKind  arg8, hipStream_t  arg9>
[[clang::replace("cudaMemcpy2DToArrayAsync 9 func")]]
auto cudaMemcpy2DToArrayAsync9_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy2DToArrayAsync(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
  }
}

template<const struct cudaMemcpy3DParms * arg1>
[[clang::matcher("cudaMemcpy3D 1 func")]]
auto cudaMemcpy3D1_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy3D(arg1);
  }
}

template<const struct hipMemcpy3DParms *  arg1>
[[clang::replace("cudaMemcpy3D 1 func")]]
auto cudaMemcpy3D1_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy3D(arg1);
  }
}

template<const struct cudaMemcpy3DParms * arg1>
[[clang::matcher("cudaMemcpy3DAsync 1 func")]]
auto cudaMemcpy3DAsync1_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy3DAsync(arg1);
  }
}

template<const struct hipMemcpy3DParms *  arg1>
[[clang::replace("cudaMemcpy3DAsync 1 func")]]
auto cudaMemcpy3DAsync1_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy3DAsync(arg1);
  }
}

template<const struct cudaMemcpy3DParms * arg1, cudaStream_t arg2>
[[clang::matcher("cudaMemcpy3DAsync 2 func")]]
auto cudaMemcpy3DAsync2_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpy3DAsync(arg1, arg2);
  }
}

template<const struct hipMemcpy3DParms *  arg1, hipStream_t  arg2>
[[clang::replace("cudaMemcpy3DAsync 2 func")]]
auto cudaMemcpy3DAsync2_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpy3DAsync(arg1, arg2);
  }
}

template<void * arg1, const void * arg2, int arg3, enum cudaMemcpyKind arg4>
[[clang::matcher("cudaMemcpyAsync 4 func")]]
auto cudaMemcpyAsync4_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyAsync(arg1, arg2, arg3, arg4);
  }
}

template<void *  arg1, const void *  arg2, int  arg3, enum hipMemcpyKind  arg4>
[[clang::replace("cudaMemcpyAsync 4 func")]]
auto cudaMemcpyAsync4_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyAsync(arg1, arg2, arg3, arg4);
  }
}

template<void * arg1, const void * arg2, int arg3, enum cudaMemcpyKind arg4, cudaStream_t arg5>
[[clang::matcher("cudaMemcpyAsync 5 func")]]
auto cudaMemcpyAsync5_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyAsync(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void *  arg1, const void *  arg2, int  arg3, enum hipMemcpyKind  arg4, hipStream_t  arg5>
[[clang::replace("cudaMemcpyAsync 5 func")]]
auto cudaMemcpyAsync5_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyAsync(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void * arg1, const void * arg2, int arg3>
[[clang::matcher("cudaMemcpyFromSymbol 3 func")]]
auto cudaMemcpyFromSymbol3_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyFromSymbol(arg1, arg2, arg3);
  }
}

template<void *  arg1, const void *  arg2, int  arg3>
[[clang::replace("cudaMemcpyFromSymbol 3 func")]]
auto cudaMemcpyFromSymbol3_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyFromSymbol(arg1, arg2, arg3);
  }
}

template<void * arg1, const void * arg2, int arg3, int arg4>
[[clang::matcher("cudaMemcpyFromSymbol 4 func")]]
auto cudaMemcpyFromSymbol4_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyFromSymbol(arg1, arg2, arg3, arg4);
  }
}

template<void *  arg1, const void *  arg2, int  arg3, int  arg4>
[[clang::replace("cudaMemcpyFromSymbol 4 func")]]
auto cudaMemcpyFromSymbol4_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyFromSymbol(arg1, arg2, arg3, arg4);
  }
}

template<void * arg1, const void * arg2, int arg3, int arg4, enum cudaMemcpyKind arg5>
[[clang::matcher("cudaMemcpyFromSymbol 5 func")]]
auto cudaMemcpyFromSymbol5_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyFromSymbol(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void *  arg1, const void *  arg2, int  arg3, int  arg4, enum hipMemcpyKind  arg5>
[[clang::replace("cudaMemcpyFromSymbol 5 func")]]
auto cudaMemcpyFromSymbol5_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyFromSymbol(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void * arg1, const void * arg2, int arg3, int arg4, enum cudaMemcpyKind arg5>
[[clang::matcher("cudaMemcpyFromSymbolAsync 5 func")]]
auto cudaMemcpyFromSymbolAsync5_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyFromSymbolAsync(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void *  arg1, const void *  arg2, int  arg3, int  arg4, enum hipMemcpyKind  arg5>
[[clang::replace("cudaMemcpyFromSymbolAsync 5 func")]]
auto cudaMemcpyFromSymbolAsync5_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyFromSymbolAsync(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void * arg1, const void * arg2, int arg3, int arg4, enum cudaMemcpyKind arg5, cudaStream_t arg6>
[[clang::matcher("cudaMemcpyFromSymbolAsync 6 func")]]
auto cudaMemcpyFromSymbolAsync6_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyFromSymbolAsync(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<void *  arg1, const void *  arg2, int  arg3, int  arg4, enum hipMemcpyKind  arg5, hipStream_t  arg6>
[[clang::replace("cudaMemcpyFromSymbolAsync 6 func")]]
auto cudaMemcpyFromSymbolAsync6_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyFromSymbolAsync(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<void * arg1, int arg2, const void * arg3, int arg4, int arg5>
[[clang::matcher("cudaMemcpyPeer 5 func")]]
auto cudaMemcpyPeer5_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyPeer(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void *  arg1, int  arg2, const void *  arg3, int  arg4, int  arg5>
[[clang::replace("cudaMemcpyPeer 5 func")]]
auto cudaMemcpyPeer5_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyPeer(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void * arg1, int arg2, const void * arg3, int arg4, int arg5>
[[clang::matcher("cudaMemcpyPeerAsync 5 func")]]
auto cudaMemcpyPeerAsync5_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyPeerAsync(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void *  arg1, int  arg2, const void *  arg3, int  arg4, int  arg5>
[[clang::replace("cudaMemcpyPeerAsync 5 func")]]
auto cudaMemcpyPeerAsync5_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyPeerAsync(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void * arg1, int arg2, const void * arg3, int arg4, int arg5, cudaStream_t arg6>
[[clang::matcher("cudaMemcpyPeerAsync 6 func")]]
auto cudaMemcpyPeerAsync6_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyPeerAsync(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<void *  arg1, int  arg2, const void *  arg3, int  arg4, int  arg5, hipStream_t  arg6>
[[clang::replace("cudaMemcpyPeerAsync 6 func")]]
auto cudaMemcpyPeerAsync6_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyPeerAsync(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<const void * arg1, const void * arg2, int arg3>
[[clang::matcher("cudaMemcpyToSymbol 3 func")]]
auto cudaMemcpyToSymbol3_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyToSymbol(arg1, arg2, arg3);
  }
}

template<const void *  arg1, const void *  arg2, int  arg3>
[[clang::replace("cudaMemcpyToSymbol 3 func")]]
auto cudaMemcpyToSymbol3_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyToSymbol(arg1, arg2, arg3);
  }
}

template<const void * arg1, const void * arg2, int arg3, int arg4>
[[clang::matcher("cudaMemcpyToSymbol 4 func")]]
auto cudaMemcpyToSymbol4_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyToSymbol(arg1, arg2, arg3, arg4);
  }
}

template<const void *  arg1, const void *  arg2, int  arg3, int  arg4>
[[clang::replace("cudaMemcpyToSymbol 4 func")]]
auto cudaMemcpyToSymbol4_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyToSymbol(arg1, arg2, arg3, arg4);
  }
}

template<const void * arg1, const void * arg2, int arg3, int arg4, enum cudaMemcpyKind arg5>
[[clang::matcher("cudaMemcpyToSymbol 5 func")]]
auto cudaMemcpyToSymbol5_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyToSymbol(arg1, arg2, arg3, arg4, arg5);
  }
}

template<const void *  arg1, const void *  arg2, int  arg3, int  arg4, enum hipMemcpyKind  arg5>
[[clang::replace("cudaMemcpyToSymbol 5 func")]]
auto cudaMemcpyToSymbol5_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyToSymbol(arg1, arg2, arg3, arg4, arg5);
  }
}

template<const void * arg1, const void * arg2, int arg3, int arg4, enum cudaMemcpyKind arg5>
[[clang::matcher("cudaMemcpyToSymbolAsync 5 func")]]
auto cudaMemcpyToSymbolAsync5_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyToSymbolAsync(arg1, arg2, arg3, arg4, arg5);
  }
}

template<const void *  arg1, const void *  arg2, int  arg3, int  arg4, enum hipMemcpyKind  arg5>
[[clang::replace("cudaMemcpyToSymbolAsync 5 func")]]
auto cudaMemcpyToSymbolAsync5_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyToSymbolAsync(arg1, arg2, arg3, arg4, arg5);
  }
}

template<const void * arg1, const void * arg2, int arg3, int arg4, enum cudaMemcpyKind arg5, cudaStream_t arg6>
[[clang::matcher("cudaMemcpyToSymbolAsync 6 func")]]
auto cudaMemcpyToSymbolAsync6_func() {
  [[clang::matcher_block]]
  {
    cudaMemcpyToSymbolAsync(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<const void *  arg1, const void *  arg2, int  arg3, int  arg4, enum hipMemcpyKind  arg5, hipStream_t  arg6>
[[clang::replace("cudaMemcpyToSymbolAsync 6 func")]]
auto cudaMemcpyToSymbolAsync6_replace() {
  [[clang::matcher_block]]
  {
    hipMemcpyToSymbolAsync(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<void * arg1, int arg2, int arg3>
[[clang::matcher("cudaMemset 3 func")]]
auto cudaMemset3_func() {
  [[clang::matcher_block]]
  {
    cudaMemset(arg1, arg2, arg3);
  }
}

template<void *  arg1, int  arg2, int  arg3>
[[clang::replace("cudaMemset 3 func")]]
auto cudaMemset3_replace() {
  [[clang::matcher_block]]
  {
    hipMemset(arg1, arg2, arg3);
  }
}

template<void * arg1, int arg2, int arg3, int arg4, int arg5>
[[clang::matcher("cudaMemset2D 5 func")]]
auto cudaMemset2D5_func() {
  [[clang::matcher_block]]
  {
    cudaMemset2D(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void *  arg1, int  arg2, int  arg3, int  arg4, int  arg5>
[[clang::replace("cudaMemset2D 5 func")]]
auto cudaMemset2D5_replace() {
  [[clang::matcher_block]]
  {
    hipMemset2D(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void * arg1, int arg2, int arg3, int arg4, int arg5>
[[clang::matcher("cudaMemset2DAsync 5 func")]]
auto cudaMemset2DAsync5_func() {
  [[clang::matcher_block]]
  {
    cudaMemset2DAsync(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void *  arg1, int  arg2, int  arg3, int  arg4, int  arg5>
[[clang::replace("cudaMemset2DAsync 5 func")]]
auto cudaMemset2DAsync5_replace() {
  [[clang::matcher_block]]
  {
    hipMemset2DAsync(arg1, arg2, arg3, arg4, arg5);
  }
}

template<void * arg1, int arg2, int arg3, int arg4, int arg5, cudaStream_t arg6>
[[clang::matcher("cudaMemset2DAsync 6 func")]]
auto cudaMemset2DAsync6_func() {
  [[clang::matcher_block]]
  {
    cudaMemset2DAsync(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<void *  arg1, int  arg2, int  arg3, int  arg4, int  arg5, hipStream_t  arg6>
[[clang::replace("cudaMemset2DAsync 6 func")]]
auto cudaMemset2DAsync6_replace() {
  [[clang::matcher_block]]
  {
    hipMemset2DAsync(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<struct cudaPitchedPtr arg1, int arg2, struct cudaExtent arg3>
[[clang::matcher("cudaMemset3D 3 func")]]
auto cudaMemset3D3_func() {
  [[clang::matcher_block]]
  {
    cudaMemset3D(arg1, arg2, arg3);
  }
}

template<struct hipPitchedPtr  arg1, int  arg2, struct hipExtent  arg3>
[[clang::replace("cudaMemset3D 3 func")]]
auto cudaMemset3D3_replace() {
  [[clang::matcher_block]]
  {
    hipMemset3D(arg1, arg2, arg3);
  }
}

template<struct cudaPitchedPtr arg1, int arg2, struct cudaExtent arg3>
[[clang::matcher("cudaMemset3DAsync 3 func")]]
auto cudaMemset3DAsync3_func() {
  [[clang::matcher_block]]
  {
    cudaMemset3DAsync(arg1, arg2, arg3);
  }
}

template<struct hipPitchedPtr  arg1, int  arg2, struct hipExtent  arg3>
[[clang::replace("cudaMemset3DAsync 3 func")]]
auto cudaMemset3DAsync3_replace() {
  [[clang::matcher_block]]
  {
    hipMemset3DAsync(arg1, arg2, arg3);
  }
}

template<struct cudaPitchedPtr arg1, int arg2, struct cudaExtent arg3, cudaStream_t arg4>
[[clang::matcher("cudaMemset3DAsync 4 func")]]
auto cudaMemset3DAsync4_func() {
  [[clang::matcher_block]]
  {
    cudaMemset3DAsync(arg1, arg2, arg3, arg4);
  }
}

template<struct hipPitchedPtr  arg1, int  arg2, struct hipExtent  arg3, hipStream_t  arg4>
[[clang::replace("cudaMemset3DAsync 4 func")]]
auto cudaMemset3DAsync4_replace() {
  [[clang::matcher_block]]
  {
    hipMemset3DAsync(arg1, arg2, arg3, arg4);
  }
}

template<void * arg1, int arg2, int arg3>
[[clang::matcher("cudaMemsetAsync 3 func")]]
auto cudaMemsetAsync3_func() {
  [[clang::matcher_block]]
  {
    cudaMemsetAsync(arg1, arg2, arg3);
  }
}

template<void *  arg1, int  arg2, int  arg3>
[[clang::replace("cudaMemsetAsync 3 func")]]
auto cudaMemsetAsync3_replace() {
  [[clang::matcher_block]]
  {
    hipMemsetAsync(arg1, arg2, arg3);
  }
}

template<void * arg1, int arg2, int arg3, cudaStream_t arg4>
[[clang::matcher("cudaMemsetAsync 4 func")]]
auto cudaMemsetAsync4_func() {
  [[clang::matcher_block]]
  {
    cudaMemsetAsync(arg1, arg2, arg3, arg4);
  }
}

template<void *  arg1, int  arg2, int  arg3, hipStream_t  arg4>
[[clang::replace("cudaMemsetAsync 4 func")]]
auto cudaMemsetAsync4_replace() {
  [[clang::matcher_block]]
  {
    hipMemsetAsync(arg1, arg2, arg3, arg4);
  }
}

template<int * arg1, const void * arg2, int arg3, int arg4>
[[clang::matcher("cudaOccupancyMaxActiveBlocksPerMultiprocessor 4 func")]]
auto cudaOccupancyMaxActiveBlocksPerMultiprocessor4_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxActiveBlocksPerMultiprocessor(arg1, arg2, arg3, arg4);
  }
}

template<int *  arg1, const void *  arg2, int  arg3, int  arg4>
[[clang::replace("cudaOccupancyMaxActiveBlocksPerMultiprocessor 4 func")]]
auto cudaOccupancyMaxActiveBlocksPerMultiprocessor4_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxActiveBlocksPerMultiprocessor(arg1, arg2, arg3, arg4);
  }
}

template<int * arg1, const void * arg2, int arg3, int arg4, unsigned int arg5>
[[clang::matcher("cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags 5 func")]]
auto cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags5_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(arg1, arg2, arg3, arg4, arg5);
  }
}

template<int *  arg1, const void *  arg2, int  arg3, int  arg4, unsigned int  arg5>
[[clang::replace("cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags 5 func")]]
auto cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags5_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(arg1, arg2, arg3, arg4, arg5);
  }
}

template<int * arg1, int * arg2, T arg3>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSize 3 func")]]
auto cudaOccupancyMaxPotentialBlockSize3_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSize(arg1, arg2, arg3);
  }
}

template<int *  arg1, int *  arg2, T  arg3>
[[clang::replace("cudaOccupancyMaxPotentialBlockSize 3 func")]]
auto cudaOccupancyMaxPotentialBlockSize3_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSize(arg1, arg2, arg3);
  }
}

template<int * arg1, int * arg2, T arg3, size_t arg4>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSize 4 func")]]
auto cudaOccupancyMaxPotentialBlockSize4_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSize(arg1, arg2, arg3, arg4);
  }
}

template<int *  arg1, int *  arg2, T  arg3, size_t  arg4>
[[clang::replace("cudaOccupancyMaxPotentialBlockSize 4 func")]]
auto cudaOccupancyMaxPotentialBlockSize4_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSize(arg1, arg2, arg3, arg4);
  }
}

template<int * arg1, int * arg2, T arg3, size_t arg4, int arg5>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSize 5 func")]]
auto cudaOccupancyMaxPotentialBlockSize5_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSize(arg1, arg2, arg3, arg4, arg5);
  }
}

template<int *  arg1, int *  arg2, T  arg3, size_t  arg4, int  arg5>
[[clang::replace("cudaOccupancyMaxPotentialBlockSize 5 func")]]
auto cudaOccupancyMaxPotentialBlockSize5_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSize(arg1, arg2, arg3, arg4, arg5);
  }
}

template<int * arg1, int * arg2, T arg3>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSizeWithFlags 3 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags3_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3);
  }
}

template<int *  arg1, int *  arg2, T  arg3>
[[clang::replace("cudaOccupancyMaxPotentialBlockSizeWithFlags 3 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags3_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3);
  }
}

template<int * arg1, int * arg2, T arg3, size_t arg4>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSizeWithFlags 4 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags4_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3, arg4);
  }
}

template<int *  arg1, int *  arg2, T  arg3, size_t  arg4>
[[clang::replace("cudaOccupancyMaxPotentialBlockSizeWithFlags 4 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags4_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3, arg4);
  }
}

template<int * arg1, int * arg2, T arg3, size_t arg4, int arg5>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSizeWithFlags 5 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags5_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3, arg4, arg5);
  }
}

template<int *  arg1, int *  arg2, T  arg3, size_t  arg4, int  arg5>
[[clang::replace("cudaOccupancyMaxPotentialBlockSizeWithFlags 5 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags5_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3, arg4, arg5);
  }
}

template<int * arg1, int * arg2, T arg3, size_t arg4, int arg5, unsigned int arg6>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSizeWithFlags 6 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags6_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<int *  arg1, int *  arg2, T  arg3, size_t  arg4, int  arg5, unsigned int  arg6>
[[clang::replace("cudaOccupancyMaxPotentialBlockSizeWithFlags 6 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags6_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<>
[[clang::matcher("cudaPeekAtLastError 0 func")]]
auto cudaPeekAtLastError0_func() {
  [[clang::matcher_block]]
  {
    cudaPeekAtLastError();
  }
}

template<>
[[clang::replace("cudaPeekAtLastError 0 func")]]
auto cudaPeekAtLastError0_replace() {
  [[clang::matcher_block]]
  {
    hipPeekAtLastError();
  }
}

template<struct cudaPointerAttributes * arg1, const void * arg2>
[[clang::matcher("cudaPointerGetAttributes 2 func")]]
auto cudaPointerGetAttributes2_func() {
  [[clang::matcher_block]]
  {
    cudaPointerGetAttributes(arg1, arg2);
  }
}

template<struct hipPointerAttribute_t *  arg1, const void *  arg2>
[[clang::replace("cudaPointerGetAttributes 2 func")]]
auto cudaPointerGetAttributes2_replace() {
  [[clang::matcher_block]]
  {
    hipPointerGetAttributes(arg1, arg2);
  }
}

template<int * arg1>
[[clang::matcher("cudaRuntimeGetVersion 1 func")]]
auto cudaRuntimeGetVersion1_func() {
  [[clang::matcher_block]]
  {
    cudaRuntimeGetVersion(arg1);
  }
}

template<int *  arg1>
[[clang::replace("cudaRuntimeGetVersion 1 func")]]
auto cudaRuntimeGetVersion1_replace() {
  [[clang::matcher_block]]
  {
    hipRuntimeGetVersion(arg1);
  }
}

template<int arg1>
[[clang::matcher("cudaSetDevice 1 func")]]
auto cudaSetDevice1_func() {
  [[clang::matcher_block]]
  {
    cudaSetDevice(arg1);
  }
}

template<int  arg1>
[[clang::replace("cudaSetDevice 1 func")]]
auto cudaSetDevice1_replace() {
  [[clang::matcher_block]]
  {
    hipSetDevice(arg1);
  }
}

template<unsigned int arg1>
[[clang::matcher("cudaSetDeviceFlags 1 func")]]
auto cudaSetDeviceFlags1_func() {
  [[clang::matcher_block]]
  {
    cudaSetDeviceFlags(arg1);
  }
}

template<unsigned int  arg1>
[[clang::replace("cudaSetDeviceFlags 1 func")]]
auto cudaSetDeviceFlags1_replace() {
  [[clang::matcher_block]]
  {
    hipSetDeviceFlags(arg1);
  }
}

template<const cudaExternalSemaphore_t * arg1, const struct cudaExternalSemaphoreSignalParams * arg2, unsigned int arg3>
[[clang::matcher("cudaSignalExternalSemaphoresAsync 3 func")]]
auto cudaSignalExternalSemaphoresAsync3_func() {
  [[clang::matcher_block]]
  {
    cudaSignalExternalSemaphoresAsync(arg1, arg2, arg3);
  }
}

template<const hipExternalSemaphore_t *  arg1, const struct hipExternalSemaphoreSignalParams *  arg2, unsigned int  arg3>
[[clang::replace("cudaSignalExternalSemaphoresAsync 3 func")]]
auto cudaSignalExternalSemaphoresAsync3_replace() {
  [[clang::matcher_block]]
  {
    hipSignalExternalSemaphoresAsync(arg1, arg2, arg3);
  }
}

template<const cudaExternalSemaphore_t * arg1, const struct cudaExternalSemaphoreSignalParams * arg2, unsigned int arg3, cudaStream_t arg4>
[[clang::matcher("cudaSignalExternalSemaphoresAsync 4 func")]]
auto cudaSignalExternalSemaphoresAsync4_func() {
  [[clang::matcher_block]]
  {
    cudaSignalExternalSemaphoresAsync(arg1, arg2, arg3, arg4);
  }
}

template<const hipExternalSemaphore_t *  arg1, const struct hipExternalSemaphoreSignalParams *  arg2, unsigned int  arg3, hipStream_t  arg4>
[[clang::replace("cudaSignalExternalSemaphoresAsync 4 func")]]
auto cudaSignalExternalSemaphoresAsync4_replace() {
  [[clang::matcher_block]]
  {
    hipSignalExternalSemaphoresAsync(arg1, arg2, arg3, arg4);
  }
}

template<cudaStream_t arg1, cudaStreamCallback_t arg2, void * arg3, unsigned int arg4>
[[clang::matcher("cudaStreamAddCallback 4 func")]]
auto cudaStreamAddCallback4_func() {
  [[clang::matcher_block]]
  {
    cudaStreamAddCallback(arg1, arg2, arg3, arg4);
  }
}

template<hipStream_t  arg1, hipStreamCallback_t  arg2, void *  arg3, unsigned int  arg4>
[[clang::replace("cudaStreamAddCallback 4 func")]]
auto cudaStreamAddCallback4_replace() {
  [[clang::matcher_block]]
  {
    hipStreamAddCallback(arg1, arg2, arg3, arg4);
  }
}

template<cudaStream_t arg1, void * arg2>
[[clang::matcher("cudaStreamAttachMemAsync 2 func")]]
auto cudaStreamAttachMemAsync2_func() {
  [[clang::matcher_block]]
  {
    cudaStreamAttachMemAsync(arg1, arg2);
  }
}

template<hipStream_t  arg1, void *  arg2>
[[clang::replace("cudaStreamAttachMemAsync 2 func")]]
auto cudaStreamAttachMemAsync2_replace() {
  [[clang::matcher_block]]
  {
    hipStreamAttachMemAsync(arg1, arg2);
  }
}

template<cudaStream_t arg1, void * arg2, int arg3>
[[clang::matcher("cudaStreamAttachMemAsync 3 func")]]
auto cudaStreamAttachMemAsync3_func() {
  [[clang::matcher_block]]
  {
    cudaStreamAttachMemAsync(arg1, arg2, arg3);
  }
}

template<hipStream_t  arg1, void *  arg2, int  arg3>
[[clang::replace("cudaStreamAttachMemAsync 3 func")]]
auto cudaStreamAttachMemAsync3_replace() {
  [[clang::matcher_block]]
  {
    hipStreamAttachMemAsync(arg1, arg2, arg3);
  }
}

template<cudaStream_t arg1, void * arg2, int arg3, unsigned int arg4>
[[clang::matcher("cudaStreamAttachMemAsync 4 func")]]
auto cudaStreamAttachMemAsync4_func() {
  [[clang::matcher_block]]
  {
    cudaStreamAttachMemAsync(arg1, arg2, arg3, arg4);
  }
}

template<hipStream_t  arg1, void *  arg2, int  arg3, unsigned int  arg4>
[[clang::replace("cudaStreamAttachMemAsync 4 func")]]
auto cudaStreamAttachMemAsync4_replace() {
  [[clang::matcher_block]]
  {
    hipStreamAttachMemAsync(arg1, arg2, arg3, arg4);
  }
}

template<cudaStream_t arg1, enum cudaStreamCaptureMode arg2>
[[clang::matcher("cudaStreamBeginCapture 2 func")]]
auto cudaStreamBeginCapture2_func() {
  [[clang::matcher_block]]
  {
    cudaStreamBeginCapture(arg1, arg2);
  }
}

template<hipStream_t  arg1, enum hipStreamCaptureMode  arg2>
[[clang::replace("cudaStreamBeginCapture 2 func")]]
auto cudaStreamBeginCapture2_replace() {
  [[clang::matcher_block]]
  {
    hipStreamBeginCapture(arg1, arg2);
  }
}

template<cudaStream_t * arg1>
[[clang::matcher("cudaStreamCreate 1 func")]]
auto cudaStreamCreate1_func() {
  [[clang::matcher_block]]
  {
    cudaStreamCreate(arg1);
  }
}

template<hipStream_t *  arg1>
[[clang::replace("cudaStreamCreate 1 func")]]
auto cudaStreamCreate1_replace() {
  [[clang::matcher_block]]
  {
    hipStreamCreate(arg1);
  }
}

template<cudaStream_t * arg1, unsigned int arg2>
[[clang::matcher("cudaStreamCreateWithFlags 2 func")]]
auto cudaStreamCreateWithFlags2_func() {
  [[clang::matcher_block]]
  {
    cudaStreamCreateWithFlags(arg1, arg2);
  }
}

template<hipStream_t *  arg1, unsigned int  arg2>
[[clang::replace("cudaStreamCreateWithFlags 2 func")]]
auto cudaStreamCreateWithFlags2_replace() {
  [[clang::matcher_block]]
  {
    hipStreamCreateWithFlags(arg1, arg2);
  }
}

template<cudaStream_t * arg1, unsigned int arg2, int arg3>
[[clang::matcher("cudaStreamCreateWithPriority 3 func")]]
auto cudaStreamCreateWithPriority3_func() {
  [[clang::matcher_block]]
  {
    cudaStreamCreateWithPriority(arg1, arg2, arg3);
  }
}

template<hipStream_t *  arg1, unsigned int  arg2, int  arg3>
[[clang::replace("cudaStreamCreateWithPriority 3 func")]]
auto cudaStreamCreateWithPriority3_replace() {
  [[clang::matcher_block]]
  {
    hipStreamCreateWithPriority(arg1, arg2, arg3);
  }
}

template<cudaStream_t arg1>
[[clang::matcher("cudaStreamDestroy 1 func")]]
auto cudaStreamDestroy1_func() {
  [[clang::matcher_block]]
  {
    cudaStreamDestroy(arg1);
  }
}

template<hipStream_t  arg1>
[[clang::replace("cudaStreamDestroy 1 func")]]
auto cudaStreamDestroy1_replace() {
  [[clang::matcher_block]]
  {
    hipStreamDestroy(arg1);
  }
}

template<cudaStream_t arg1, cudaGraph_t * arg2>
[[clang::matcher("cudaStreamEndCapture 2 func")]]
auto cudaStreamEndCapture2_func() {
  [[clang::matcher_block]]
  {
    cudaStreamEndCapture(arg1, arg2);
  }
}

template<hipStream_t  arg1, hipGraph_t *  arg2>
[[clang::replace("cudaStreamEndCapture 2 func")]]
auto cudaStreamEndCapture2_replace() {
  [[clang::matcher_block]]
  {
    hipStreamEndCapture(arg1, arg2);
  }
}

template<cudaStream_t arg1, unsigned int * arg2>
[[clang::matcher("cudaStreamGetFlags 2 func")]]
auto cudaStreamGetFlags2_func() {
  [[clang::matcher_block]]
  {
    cudaStreamGetFlags(arg1, arg2);
  }
}

template<hipStream_t  arg1, unsigned int *  arg2>
[[clang::replace("cudaStreamGetFlags 2 func")]]
auto cudaStreamGetFlags2_replace() {
  [[clang::matcher_block]]
  {
    hipStreamGetFlags(arg1, arg2);
  }
}

template<cudaStream_t arg1, int * arg2>
[[clang::matcher("cudaStreamGetPriority 2 func")]]
auto cudaStreamGetPriority2_func() {
  [[clang::matcher_block]]
  {
    cudaStreamGetPriority(arg1, arg2);
  }
}

template<hipStream_t  arg1, int *  arg2>
[[clang::replace("cudaStreamGetPriority 2 func")]]
auto cudaStreamGetPriority2_replace() {
  [[clang::matcher_block]]
  {
    hipStreamGetPriority(arg1, arg2);
  }
}

template<cudaStream_t arg1>
[[clang::matcher("cudaStreamQuery 1 func")]]
auto cudaStreamQuery1_func() {
  [[clang::matcher_block]]
  {
    cudaStreamQuery(arg1);
  }
}

template<hipStream_t  arg1>
[[clang::replace("cudaStreamQuery 1 func")]]
auto cudaStreamQuery1_replace() {
  [[clang::matcher_block]]
  {
    hipStreamQuery(arg1);
  }
}

template<cudaStream_t arg1>
[[clang::matcher("cudaStreamSynchronize 1 func")]]
auto cudaStreamSynchronize1_func() {
  [[clang::matcher_block]]
  {
    cudaStreamSynchronize(arg1);
  }
}

template<hipStream_t  arg1>
[[clang::replace("cudaStreamSynchronize 1 func")]]
auto cudaStreamSynchronize1_replace() {
  [[clang::matcher_block]]
  {
    hipStreamSynchronize(arg1);
  }
}

template<cudaStream_t arg1, cudaEvent_t arg2, unsigned int arg3>
[[clang::matcher("cudaStreamWaitEvent 3 func")]]
auto cudaStreamWaitEvent3_func() {
  [[clang::matcher_block]]
  {
    cudaStreamWaitEvent(arg1, arg2, arg3);
  }
}

template<hipStream_t  arg1, hipEvent_t  arg2, unsigned int  arg3>
[[clang::replace("cudaStreamWaitEvent 3 func")]]
auto cudaStreamWaitEvent3_replace() {
  [[clang::matcher_block]]
  {
    hipStreamWaitEvent(arg1, arg2, arg3);
  }
}

template<const cudaExternalSemaphore_t * arg1, const struct cudaExternalSemaphoreWaitParams * arg2, unsigned int arg3>
[[clang::matcher("cudaWaitExternalSemaphoresAsync 3 func")]]
auto cudaWaitExternalSemaphoresAsync3_func() {
  [[clang::matcher_block]]
  {
    cudaWaitExternalSemaphoresAsync(arg1, arg2, arg3);
  }
}

template<const hipExternalSemaphore_t *  arg1, const struct hipExternalSemaphoreWaitParams *  arg2, unsigned int  arg3>
[[clang::replace("cudaWaitExternalSemaphoresAsync 3 func")]]
auto cudaWaitExternalSemaphoresAsync3_replace() {
  [[clang::matcher_block]]
  {
    hipWaitExternalSemaphoresAsync(arg1, arg2, arg3);
  }
}

template<const cudaExternalSemaphore_t * arg1, const struct cudaExternalSemaphoreWaitParams * arg2, unsigned int arg3, cudaStream_t arg4>
[[clang::matcher("cudaWaitExternalSemaphoresAsync 4 func")]]
auto cudaWaitExternalSemaphoresAsync4_func() {
  [[clang::matcher_block]]
  {
    cudaWaitExternalSemaphoresAsync(arg1, arg2, arg3, arg4);
  }
}

template<const hipExternalSemaphore_t *  arg1, const struct hipExternalSemaphoreWaitParams *  arg2, unsigned int  arg3, hipStream_t  arg4>
[[clang::replace("cudaWaitExternalSemaphoresAsync 4 func")]]
auto cudaWaitExternalSemaphoresAsync4_replace() {
  [[clang::matcher_block]]
  {
    hipWaitExternalSemaphoresAsync(arg1, arg2, arg3, arg4);
  }
}

template<int arg1, int arg2, int arg3>
[[clang::matcher("make_cudaExtent 3 func")]]
auto make_cudaExtent3_func() {
  [[clang::matcher_block]]
  {
    make_cudaExtent(arg1, arg2, arg3);
  }
}

template<int  arg1, int  arg2, int  arg3>
[[clang::replace("make_cudaExtent 3 func")]]
auto make_cudaExtent3_replace() {
  [[clang::matcher_block]]
  {
    make_hipExtent(arg1, arg2, arg3);
  }
}

template<void * arg1, int arg2, int arg3, int arg4>
[[clang::matcher("make_cudaPitchedPtr 4 func")]]
auto make_cudaPitchedPtr4_func() {
  [[clang::matcher_block]]
  {
    make_cudaPitchedPtr(arg1, arg2, arg3, arg4);
  }
}

template<void *  arg1, int  arg2, int  arg3, int  arg4>
[[clang::replace("make_cudaPitchedPtr 4 func")]]
auto make_cudaPitchedPtr4_replace() {
  [[clang::matcher_block]]
  {
    make_hipPitchedPtr(arg1, arg2, arg3, arg4);
  }
}

template<int arg1, int arg2, int arg3>
[[clang::matcher("make_cudaPos 3 func")]]
auto make_cudaPos3_func() {
  [[clang::matcher_block]]
  {
    make_cudaPos(arg1, arg2, arg3);
  }
}

template<int  arg1, int  arg2, int  arg3>
[[clang::replace("make_cudaPos 3 func")]]
auto make_cudaPos3_replace() {
  [[clang::matcher_block]]
  {
    make_hipPos(arg1, arg2, arg3);
  }
}
