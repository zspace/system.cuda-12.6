/*
 * Copyright 1993-2012 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO LICENSEE:
 *
 * This source code and/or documentation ("Licensed Deliverables") are
 * subject to NVIDIA intellectual property rights under U.S. and
 * international Copyright laws.
 *
 * These Licensed Deliverables contained herein is PROPRIETARY and
 * CONFIDENTIAL to NVIDIA and is being provided under the terms and
 * conditions of a form of NVIDIA software license agreement by and
 * between NVIDIA and Licensee ("License Agreement") or electronically
 * accepted by Licensee.  Notwithstanding any terms or conditions to
 * the contrary in the License Agreement, reproduction or disclosure
 * of the Licensed Deliverables to any third party without the express
 * written consent of NVIDIA is prohibited.
 *
 * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE
 * LICENSE AGREEMENT, NVIDIA MAKES NO REPRESENTATION ABOUT THE
 * SUITABILITY OF THESE LICENSED DELIVERABLES FOR ANY PURPOSE.  IT IS
 * PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY OF ANY KIND.
 * NVIDIA DISCLAIMS ALL WARRANTIES WITH REGARD TO THESE LICENSED
 * DELIVERABLES, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
 * NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE
 * LICENSE AGREEMENT, IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY
 * SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THESE LICENSED DELIVERABLES.
 *
 * U.S. Government End Users.  These Licensed Deliverables are a
 * "commercial item" as that term is defined at 48 C.F.R. 2.101 (OCT
 * 1995), consisting of "commercial computer software" and "commercial
 * computer software documentation" as such terms are used in 48
 * C.F.R. 12.212 (SEPT 1995) and is provided to the U.S. Government
 * only as a commercial end item.  Consistent with 48 C.F.R.12.212 and
 * 48 C.F.R. 227.7202-1 through 227.7202-4 (JUNE 1995), all
 * U.S. Government End Users acquire the Licensed Deliverables with
 * only those rights set forth herein.
 *
 * Any use of the Licensed Deliverables in individual and commercial
 * software must include, in the user documentation and internal
 * comments to the code, the above Disclaimer and U.S. Government End
 * Users Notice.
 */

#if !defined(__CUDA_PROFILER_API_H__)
#define __CUDA_PROFILER_API_H__

#include "driver_types.h"

#if defined(__CUDA_API_VERSION_INTERNAL) || defined(__DOXYGEN_ONLY__) || defined(CUDA_ENABLE_DEPRECATED)
#define __CUDA_DEPRECATED
#elif defined(_MSC_VER)
#define __CUDA_DEPRECATED __declspec(deprecated)
#elif defined(__GNUC__)
#define __CUDA_DEPRECATED __attribute__((deprecated))
#else
#define __CUDA_DEPRECATED
#endif

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
 * \ingroup CUDART
 * \defgroup CUDART_PROFILER Profiler Control
 *
 * ___MANBRIEF___ profiler control functions of the CUDA runtime API
 * (___CURRENT_FILE___) ___ENDMANBRIEF___
 *
 * This section describes the profiler control functions of the CUDA runtime
 * application programming interface.
 *
 * @{
 */

/**
 * \brief Enable profiling.
 *
 * Enables profile collection by the active profiling tool for the
 * current context. If profiling is already enabled, then
 * cudaProfilerStart() has no effect.
 *
 * cudaProfilerStart and cudaProfilerStop APIs are used to
 * programmatically control the profiling granularity by allowing
 * profiling to be done only on selective pieces of code.
 * 
 *
 * \return
 * ::cudaSuccess
 * \notefnerr
 *
 * \sa
 * ::cudaProfilerStop,
 * ::cuProfilerStart
 */
extern __host__ cudaError_t CUDARTAPI cudaProfilerStart(void);

/**
 * \brief Disable profiling.
 *
 * Disables profile collection by the active profiling tool for the
 * current context. If profiling is already disabled, then
 * cudaProfilerStop() has no effect.
 *
 * cudaProfilerStart and cudaProfilerStop APIs are used to
 * programmatically control the profiling granularity by allowing
 * profiling to be done only on selective pieces of code.
 *
 * \return
 * ::cudaSuccess
 * \notefnerr
 *
 * \sa
 * ::cudaProfilerStart,
 * ::cuProfilerStop
 */
extern __host__ cudaError_t CUDARTAPI cudaProfilerStop(void);

/** @} */ /* END CUDART_PROFILER */

#undef __CUDA_DEPRECATED

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* !__CUDA_PROFILER_API_H__ */

