#ifndef FAKE_HIP_H
#define FAKE_HIP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// #define __host__
// #define __device__
//
// #define __global__

// #define __noinline__
// #define __forceinline__ inline
//
// #define __shared__
// #define __constant__

namespace clang_rewrite_literals {

extern "C" __device__ __attribute__((const)) size_t __ockl_get_local_id(uint);
#define hipThreadIdx_x (__ockl_get_local_id(0))
#define hipThreadIdx_y (__ockl_get_local_id(1))
#define hipThreadIdx_z (__ockl_get_local_id(2))

extern "C" __device__ __attribute__((const)) size_t __ockl_get_group_id(uint);
#define hipBlockIdx_x (__ockl_get_group_id(0))
#define hipBlockIdx_y (__ockl_get_group_id(1))
#define hipBlockIdx_z (__ockl_get_group_id(2))

extern "C" __device__ __attribute__((const)) size_t __ockl_get_local_size(uint);
#define hipBlockDim_x (__ockl_get_local_size(0))
#define hipBlockDim_y (__ockl_get_local_size(1))
#define hipBlockDim_z (__ockl_get_local_size(2))

extern "C" __device__ __attribute__((const)) size_t __ockl_get_num_groups(uint);
#define hipGridDim_x (__ockl_get_num_groups(0))
#define hipGridDim_y (__ockl_get_num_groups(1))
#define hipGridDim_z (__ockl_get_num_groups(2))

// typedef struct dim3 {
//     uint32_t x;  ///< x
//     uint32_t y;  ///< y
//     uint32_t z;  ///< z
// #ifdef __cplusplus
//     constexpr __device__ dim3(uint32_t _x = 1, uint32_t _y = 1, uint32_t _z = 1) : x(_x), y(_y), z(_z){};
// #endif
// } dim3;

typedef struct ihipStream_t* hipStream_t;

template <typename... Args, typename F = void (*)(Args...)>
void hipLaunchKernelGGL(F kernel, const dim3& numBlocks, const dim3& dimBlocks,
                        uint32_t sharedMemBytes, hipStream_t stream, Args... args);

}
#endif
