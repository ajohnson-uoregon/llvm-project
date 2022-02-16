#include "fake_hip_runtime_api.h"
#include <vector>
#include <string>
#include <cuda_gl_interop.h>

std::vector<std::string> clang_rewrite_literal_names = {
"cudaArray_const_t",
"cudaArray_t",
"cudaChannelFormatDesc",
"cudaChannelFormatKind",
"cudaComputeMode",
"cudaDeviceAttr",
"cudaDeviceP2PAttr",
"cudaDeviceProp",
"cudaError",
"cudaError_t",
"cudaEvent_t",
"cudaExtent",
"cudaExternalMemoryBufferDesc",
"cudaExternalMemoryHandleDesc",
"cudaExternalMemoryHandleType",
"cudaExternalMemory_t",
"cudaExternalSemaphoreHandleDesc",
"cudaExternalSemaphoreHandleType",
"cudaExternalSemaphoreSignalParams",
"cudaExternalSemaphoreWaitParams",
"cudaExternalSemaphore_t",
"cudaFuncAttribute",
"cudaFuncAttributes",
"cudaFuncCache",
"cudaFunction_t",
"cudaGLDeviceList",
"cudaGraphExecUpdateResult",
"cudaGraphExec_t",
"cudaGraphNodeType",
"cudaGraphNode_t",
"cudaGraph_t",
"cudaGraphicsRegisterFlags",
"cudaGraphicsResource_t",
"cudaHostFn_t",
"cudaHostNodeParams",
"cudaIpcEventHandle_t",
"cudaIpcMemHandle_t",
"cudaKernelNodeParams",
"cudaLaunchParams",
"cudaLimit",
"cudaMemRangeAttribute",
"cudaMemcpy3DParms",
"cudaMemcpyKind",
"cudaMemoryAdvise",
"cudaMemoryType",
"cudaMemsetParams",
"cudaMipmappedArray_const_t",
"cudaMipmappedArray_t",
"cudaPitchedPtr",
"cudaPointerAttributes",
"cudaPos",
"cudaResourceDesc",
"cudaResourceType",
"cudaResourceViewDesc",
"cudaResourceViewFormat",
"cudaSharedMemConfig",
"cudaStreamCallback_t",
"cudaStreamCaptureMode",
"cudaStreamCaptureStatus",
"cudaStream_t",
"cudaSurfaceBoundaryMode",
"cudaSurfaceObject_t",
"cudaTextureAddressMode",
"cudaTextureDesc",
"cudaTextureFilterMode",
"cudaTextureObject_t",
"cudaTextureReadMode",
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream>
[[clang::matcher("kernel_launch 0 args 4 params")]]
auto cuda_kernel_launch_0_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>();
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1>
[[clang::matcher("kernel_launch 1 args 4 params")]]
auto cuda_kernel_launch_1_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2>
[[clang::matcher("kernel_launch 2 args 4 params")]]
auto cuda_kernel_launch_2_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3>
[[clang::matcher("kernel_launch 3 args 4 params")]]
auto cuda_kernel_launch_3_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4>
[[clang::matcher("kernel_launch 4 args 4 params")]]
auto cuda_kernel_launch_4_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5>
[[clang::matcher("kernel_launch 5 args 4 params")]]
auto cuda_kernel_launch_5_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6>
[[clang::matcher("kernel_launch 6 args 4 params")]]
auto cuda_kernel_launch_6_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7>
[[clang::matcher("kernel_launch 7 args 4 params")]]
auto cuda_kernel_launch_7_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8>
[[clang::matcher("kernel_launch 8 args 4 params")]]
auto cuda_kernel_launch_8_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9>
[[clang::matcher("kernel_launch 9 args 4 params")]]
auto cuda_kernel_launch_9_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10>
[[clang::matcher("kernel_launch 10 args 4 params")]]
auto cuda_kernel_launch_10_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11>
[[clang::matcher("kernel_launch 11 args 4 params")]]
auto cuda_kernel_launch_11_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12>
[[clang::matcher("kernel_launch 12 args 4 params")]]
auto cuda_kernel_launch_12_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13>
[[clang::matcher("kernel_launch 13 args 4 params")]]
auto cuda_kernel_launch_13_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14>
[[clang::matcher("kernel_launch 14 args 4 params")]]
auto cuda_kernel_launch_14_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15>
[[clang::matcher("kernel_launch 15 args 4 params")]]
auto cuda_kernel_launch_15_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16>
[[clang::matcher("kernel_launch 16 args 4 params")]]
auto cuda_kernel_launch_16_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17>
[[clang::matcher("kernel_launch 17 args 4 params")]]
auto cuda_kernel_launch_17_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18>
[[clang::matcher("kernel_launch 18 args 4 params")]]
auto cuda_kernel_launch_18_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19>
[[clang::matcher("kernel_launch 19 args 4 params")]]
auto cuda_kernel_launch_19_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20>
[[clang::matcher("kernel_launch 20 args 4 params")]]
auto cuda_kernel_launch_20_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21>
[[clang::matcher("kernel_launch 21 args 4 params")]]
auto cuda_kernel_launch_21_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22>
[[clang::matcher("kernel_launch 22 args 4 params")]]
auto cuda_kernel_launch_22_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23>
[[clang::matcher("kernel_launch 23 args 4 params")]]
auto cuda_kernel_launch_23_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24>
[[clang::matcher("kernel_launch 24 args 4 params")]]
auto cuda_kernel_launch_24_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25>
[[clang::matcher("kernel_launch 25 args 4 params")]]
auto cuda_kernel_launch_25_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26>
[[clang::matcher("kernel_launch 26 args 4 params")]]
auto cuda_kernel_launch_26_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27>
[[clang::matcher("kernel_launch 27 args 4 params")]]
auto cuda_kernel_launch_27_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28>
[[clang::matcher("kernel_launch 28 args 4 params")]]
auto cuda_kernel_launch_28_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29>
[[clang::matcher("kernel_launch 29 args 4 params")]]
auto cuda_kernel_launch_29_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30>
[[clang::matcher("kernel_launch 30 args 4 params")]]
auto cuda_kernel_launch_30_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31>
[[clang::matcher("kernel_launch 31 args 4 params")]]
auto cuda_kernel_launch_31_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31>
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

template <int numblocks, int numthreads, int shmem, cudaStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31, int arg32>
[[clang::matcher("kernel_launch 32 args 4 params")]]
auto cuda_kernel_launch_32_4() {
  [[clang::matcher_block]]
  {
    kern<<<numblocks, numthreads, shmem, stream>>>(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32);
  }
}

template <int numblocks, int numthreads, int shmem, hipStream_t stream, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12, int arg13, int arg14, int arg15, int arg16, int arg17, int arg18, int arg19, int arg20, int arg21, int arg22, int arg23, int arg24, int arg25, int arg26, int arg27, int arg28, int arg29, int arg30, int arg31, int arg32>
[[clang::replace("kernel_launch 32 args 4 params")]]
auto cuda_kernel_launch_32_4_replace() {
  [[clang::matcher_block]]
  {
    hipLaunchKernelGGL(kern, numblocks, numthreads, shmem, stream, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28, arg29, arg30, arg31, arg32);
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
      hipGetTextureObjectTextureDesc((hipTextureDesc*)arg1, (hipTextureObject_t)arg2);
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
#ifndef CUDART_VERSION
#error CUDART_VERSION Undefined!
#elif (CUDART_VERSION == 1104)
      cudaCreateChannelDesc();
#else
    cudaCreateChannelDesc(arg1, arg2, arg3, arg4, arg5);
#endif
  }
}

/*
template<int  arg1, int  arg2, int  arg3, int  arg4, enum hipChannelFormatKind  arg5>
[[clang::replace("cudaCreateChannelDesc 5 func")]]
auto cudaCreateChannelDesc5_replace() {
  [[clang::matcher_block]]
  {
    hipCreateChannelDesc(arg1, arg2, arg3, arg4, arg5);
  }
}
*/

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

template<size_t * arg1, enum cudaLimit arg2>
[[clang::matcher("cudaDeviceGetLimit 2 func")]]
auto cudaDeviceGetLimit2_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceGetLimit(arg1, arg2);
  }
}

template<size_t *  arg1, enum hipLimit_t  arg2>
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

[[clang::matcher("cudaDeviceReset 0 func")]]
auto cudaDeviceReset0_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceReset();
  }
}

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

[[clang::matcher("cudaDeviceSynchronize 0 func")]]
auto cudaDeviceSynchronize0_func() {
  [[clang::matcher_block]]
  {
    cudaDeviceSynchronize();
  }
}

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

template<void ** arg1, cudaExternalMemory_t arg2, const cudaExternalMemoryBufferDesc * arg3>
[[clang::matcher("cudaExternalMemoryGetMappedBuffer 3 func")]]
auto cudaExternalMemoryGetMappedBuffer3_func() {
  [[clang::matcher_block]]
  {
    cudaExternalMemoryGetMappedBuffer(arg1, arg2, arg3);
  }
}

template<void **  arg1, hipExternalMemory_t  arg2, const hipExternalMemoryBufferDesc *  arg3>
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

[[clang::matcher("cudaGetLastError 0 func")]]
auto cudaGetLastError0_func() {
  [[clang::matcher_block]]
  {
    cudaGetLastError();
  }
}

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

template<size_t * arg1, const void * arg2>
[[clang::matcher("cudaGetSymbolSize 2 func")]]
auto cudaGetSymbolSize2_func() {
  [[clang::matcher_block]]
  {
    cudaGetSymbolSize(arg1, arg2);
  }
}

template<size_t *  arg1, const void *  arg2>
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

/* CC
 * you are using int* as the third argument type, Cuda doesn't know that. 
 * Also some size_t* -> int* mismatches
 * I also added pointer conversions such as CUtexObject (aka unsigned long long)
 * to hipTextureObject_t' (aka __hip_texture *) 
 * hipMalloc3DArray takes 4 arguments -> I added 0 as the flags, which is the default value with cudaMalloc3DArray
 * cudaCreateChannelDesc takes no argument with Cuda 11.4, 5 with Cuda 10.2
 * hipOccupancyMaxPotentialBlockSize needs a 5th argument -> I added 0 as the blockSizeLimit, which is the default value with cudaOccupancyMaxPotentialBlockSize
 * Definition of hipCreateChannelDesc is missing -> I commented out the matcher
 * Same for hipExternalMemoryGetMappedBuffer
 * hipExternalMemoryHandleDesc is typedefed so we don't use it with struct
 * I fixed template errors when template parameters and template types are mixed
 * and other minor template errors
 * hipSignalExternalSemaphoresAsync needs 4 arguments, I added 0 as the stream which is the default value with cudaSignalExternalSemaphoresAsync
 * TODO: check what the correct interfaces are
 */

template<cudaGraph_t arg1, cudaGraphNode_t * arg2, size_t * arg3>
[[clang::matcher("cudaGraphGetNodes 3 func")]]
auto cudaGraphGetNodes3_func() {
  [[clang::matcher_block]]
  {
      cudaGraphGetNodes(arg1, arg2, arg3);
  }
}

template<hipGraph_t  arg1, hipGraphNode_t *  arg2, size_t *  arg3>
[[clang::replace("cudaGraphGetNodes 3 func")]]
auto cudaGraphGetNodes3_replace() {
  [[clang::matcher_block]]
  {
    hipGraphGetNodes(arg1, arg2, arg3);
  }
}

template<cudaGraph_t arg1, cudaGraphNode_t * arg2, size_t * arg3>
[[clang::matcher("cudaGraphGetRootNodes 3 func")]]
auto cudaGraphGetRootNodes3_func() {
  [[clang::matcher_block]]
  {
    cudaGraphGetRootNodes(arg1, arg2, arg3);
  }
}

template<hipGraph_t  arg1, hipGraphNode_t *  arg2, size_t *  arg3>
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

template<struct cudaGraphicsResource **  arg1, GLuint  arg2, unsigned int  arg3>
[[clang::replace("cudaGraphicsGLRegisterBuffer 3 func")]]
auto cudaGraphicsGLRegisterBuffer3_replace() {
  [[clang::matcher_block]]
  {
      hipGraphicsGLRegisterBuffer((hipGraphicsResource **)arg1, arg2, arg3);
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

template<void ** arg1, size_t * arg2, cudaGraphicsResource_t arg3>
[[clang::matcher("cudaGraphicsResourceGetMappedPointer 3 func")]]
auto cudaGraphicsResourceGetMappedPointer3_func() {
  [[clang::matcher_block]]
  {
    cudaGraphicsResourceGetMappedPointer(arg1, arg2, arg3);
  }
}

template<void **  arg1, size_t *  arg2, hipGraphicsResource_t  arg3>
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

template<cudaExternalMemory_t * arg1, const cudaExternalMemoryHandleDesc * arg2>
[[clang::matcher("cudaImportExternalMemory 2 func")]]
auto cudaImportExternalMemory2_func() {
  [[clang::matcher_block]]
  {
    cudaImportExternalMemory(arg1, arg2);
  }
}

template<hipExternalMemory_t *  arg1, const hipExternalMemoryHandleDesc *  arg2>
[[clang::replace("cudaImportExternalMemory 2 func")]]
auto cudaImportExternalMemory2_replace() {
  [[clang::matcher_block]]
  {
    hipImportExternalMemory(arg1, arg2);
  }
}

template<cudaExternalSemaphore_t * arg1, const cudaExternalSemaphoreHandleDesc * arg2>
[[clang::matcher("cudaImportExternalSemaphore 2 func")]]
auto cudaImportExternalSemaphore2_func() {
  [[clang::matcher_block]]
  {
    cudaImportExternalSemaphore(arg1, arg2);
  }
}

template<hipExternalSemaphore_t *  arg1, const hipExternalSemaphoreHandleDesc *  arg2>
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
      hipMalloc3DArray(arg1, arg2, arg3, 0);
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

template<void ** arg1, size_t * arg2, int arg3, int arg4>
[[clang::matcher("cudaMallocPitch 4 func")]]
auto cudaMallocPitch4_func() {
  [[clang::matcher_block]]
  {
    cudaMallocPitch(arg1, arg2, arg3, arg4);
  }
}

template<void **  arg1, size_t *  arg2, int  arg3, int  arg4>
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

template<size_t * arg1, size_t * arg2>
[[clang::matcher("cudaMemGetInfo 2 func")]]
auto cudaMemGetInfo2_func() {
  [[clang::matcher_block]]
  {
    cudaMemGetInfo(arg1, arg2);
  }
}

template<size_t *  arg1, size_t *  arg2>
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

template<void ** arg1, size_t * arg2, enum cudaMemRangeAttribute * arg3, int arg4, const void * arg5, int arg6>
[[clang::matcher("cudaMemRangeGetAttributes 6 func")]]
auto cudaMemRangeGetAttributes6_func() {
  [[clang::matcher_block]]
  {
    cudaMemRangeGetAttributes(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<void **  arg1, size_t *  arg2, enum hipMemRangeAttribute *  arg3, int  arg4, const void *  arg5, int  arg6>
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

template<int * arg1, int * arg2, typename T, T arg3>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSize 3 func")]]
auto cudaOccupancyMaxPotentialBlockSize3_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSize(arg1, arg2, arg3);
  }
}

template<int *  arg1, int *  arg2, typename T, T  arg3>
[[clang::replace("cudaOccupancyMaxPotentialBlockSize 3 func")]]
auto cudaOccupancyMaxPotentialBlockSize3_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSize(arg1, arg2, arg3);
  }
}

template<int * arg1, int * arg2, typename T, T arg3, size_t arg4>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSize 4 func")]]
auto cudaOccupancyMaxPotentialBlockSize4_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSize(arg1, arg2, arg3, arg4);
  }
}

template<int *  arg1, int *  arg2, typename T, T  arg3, size_t  arg4>
[[clang::replace("cudaOccupancyMaxPotentialBlockSize 4 func")]]
auto cudaOccupancyMaxPotentialBlockSize4_replace() {
  [[clang::matcher_block]]
  {
      hipOccupancyMaxPotentialBlockSize(arg1, arg2, arg3, arg4, 0);
  }
}

template<int * arg1, int * arg2, typename T, T arg3, size_t arg4, int arg5>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSize 5 func")]]
auto cudaOccupancyMaxPotentialBlockSize5_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSize(arg1, arg2, arg3, arg4, arg5);
  }
}

template<int *  arg1, int *  arg2, typename T, T  arg3, size_t  arg4, int  arg5>
[[clang::replace("cudaOccupancyMaxPotentialBlockSize 5 func")]]
auto cudaOccupancyMaxPotentialBlockSize5_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSize(arg1, arg2, arg3, arg4, arg5);
  }
}

template<int * arg1, int * arg2, typename T, T arg3>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSizeWithFlags 3 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags3_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3);
  }
}

template<int *  arg1, int *  arg2, typename T, T  arg3>
[[clang::replace("cudaOccupancyMaxPotentialBlockSizeWithFlags 3 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags3_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3);
  }
}

template<int * arg1, int * arg2, typename T, T arg3, size_t arg4>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSizeWithFlags 4 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags4_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3, arg4);
  }
}

template<int *  arg1, int *  arg2, typename T, T  arg3, size_t  arg4>
[[clang::replace("cudaOccupancyMaxPotentialBlockSizeWithFlags 4 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags4_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3, arg4);
  }
}

template<int * arg1, int * arg2, typename T, T arg3, size_t arg4, int arg5>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSizeWithFlags 5 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags5_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3, arg4, arg5);
  }
}

template<int *  arg1, int *  arg2, typename T, T  arg3, size_t  arg4, int  arg5>
[[clang::replace("cudaOccupancyMaxPotentialBlockSizeWithFlags 5 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags5_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3, arg4, arg5);
  }
}

template<int * arg1, int * arg2, typename T, T arg3, size_t arg4, int arg5, unsigned int arg6>
[[clang::matcher("cudaOccupancyMaxPotentialBlockSizeWithFlags 6 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags6_func() {
  [[clang::matcher_block]]
  {
    cudaOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

template<int *  arg1, int *  arg2, typename T, T  arg3, size_t  arg4, int  arg5, unsigned int  arg6>
[[clang::replace("cudaOccupancyMaxPotentialBlockSizeWithFlags 6 func")]]
auto cudaOccupancyMaxPotentialBlockSizeWithFlags6_replace() {
  [[clang::matcher_block]]
  {
    hipOccupancyMaxPotentialBlockSizeWithFlags(arg1, arg2, arg3, arg4, arg5, arg6);
  }
}

[[clang::matcher("cudaPeekAtLastError 0 func")]]
auto cudaPeekAtLastError0_func() {
  [[clang::matcher_block]]
  {
    cudaPeekAtLastError();
  }
}

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

template<const cudaExternalSemaphore_t * arg1, const  cudaExternalSemaphoreSignalParams * arg2, unsigned int arg3>
[[clang::matcher("cudaSignalExternalSemaphoresAsync 3 func")]]
auto cudaSignalExternalSemaphoresAsync3_func() {
  [[clang::matcher_block]]
  {
    cudaSignalExternalSemaphoresAsync(arg1, arg2, arg3);
  }
}

template<const hipExternalSemaphore_t *  arg1, const  hipExternalSemaphoreSignalParams *  arg2, unsigned int  arg3>
[[clang::replace("cudaSignalExternalSemaphoresAsync 3 func")]]
auto cudaSignalExternalSemaphoresAsync3_replace() {
  [[clang::matcher_block]]
  {
      hipSignalExternalSemaphoresAsync(arg1, arg2, arg3, 0);
  }
}

template<const cudaExternalSemaphore_t * arg1, const  cudaExternalSemaphoreSignalParams * arg2, unsigned int arg3, cudaStream_t arg4>
[[clang::matcher("cudaSignalExternalSemaphoresAsync 4 func")]]
auto cudaSignalExternalSemaphoresAsync4_func() {
  [[clang::matcher_block]]
  {
    cudaSignalExternalSemaphoresAsync(arg1, arg2, arg3, arg4);
  }
}

template<const hipExternalSemaphore_t *  arg1, const  hipExternalSemaphoreSignalParams *  arg2, unsigned int  arg3, hipStream_t  arg4>
[[clang::replace("cudaSignalExternalSemaphoresAsync 4 func")]]
auto cudaSignalExternalSemaphoresAsync4_replace() {
  [[clang::matcher_block]]
  {
      hipSignalExternalSemaphoresAsync(arg1, (const hipExternalSemaphoreSignalParams *)arg2, arg3, arg4);
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

template<const cudaExternalSemaphore_t * arg1, const cudaExternalSemaphoreWaitParams * arg2, unsigned int arg3>
[[clang::matcher("cudaWaitExternalSemaphoresAsync 3 func")]]
auto cudaWaitExternalSemaphoresAsync3_func() {
  [[clang::matcher_block]]
  {
    cudaWaitExternalSemaphoresAsync(arg1, arg2, arg3);
  }
}

template<const hipExternalSemaphore_t *  arg1, const hipExternalSemaphoreWaitParams *  arg2, unsigned int  arg3>
[[clang::replace("cudaWaitExternalSemaphoresAsync 3 func")]]
auto cudaWaitExternalSemaphoresAsync3_replace() {
  [[clang::matcher_block]]
  {
      hipWaitExternalSemaphoresAsync(arg1, arg2, arg3, 0);
  }
}

template<const cudaExternalSemaphore_t * arg1, const cudaExternalSemaphoreWaitParams * arg2, unsigned int arg3, cudaStream_t arg4>
[[clang::matcher("cudaWaitExternalSemaphoresAsync 4 func")]]
auto cudaWaitExternalSemaphoresAsync4_func() {
  [[clang::matcher_block]]
  {
    cudaWaitExternalSemaphoresAsync(arg1, arg2, arg3, arg4);
  }
}

template<const hipExternalSemaphore_t *  arg1, const hipExternalSemaphoreWaitParams *  arg2, unsigned int  arg3, hipStream_t  arg4>
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
