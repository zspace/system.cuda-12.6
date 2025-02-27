/*
 * Copyright 2018-2023 NVIDIA Corporation.  All rights reserved.
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

#if !defined(__SANITIZER_STREAM_H__)
#define __SANITIZER_STREAM_H__

#include <sanitizer_result.h>

#include <cuda.h>

#include <stdint.h>

#ifndef SANITIZERAPI
#ifdef _WIN32
#define SANITIZERAPI __stdcall
#else
#define SANITIZERAPI
#endif
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * \defgroup SANITIZER_STREAM_API Sanitizer Stream API
 * Functions, types, and enums that implement the Sanitizer Stream API.
 * @{
 */

typedef struct Sanitizer_Stream_st *Sanitizer_StreamHandle;

/**
 * \brief Synchronize a given stream
 *
 * Equivalent of cudaStreamSynchronize that can be called with a sanitizer stream handle
 * \note \b Thread-safety: this function is thread safe.
 *
 * \param stream Stream handle. If NULL, the NULL stream will be used.
 */
SanitizerResult SANITIZERAPI sanitizerStreamSynchronize(Sanitizer_StreamHandle stream);

/**
 * \brief Retrieve a CUstream handle from a Sanitizer_StreamHandle handle
 *
 * \note \b Thread-safety: this function is thread safe.
 *
 * \param[in] hStream Sanitizer Stream handle.
 * \param[out] stream Output CUstream handle.
 *
 * \retval SANITIZER_SUCCESS on success
 * \retval SANITIZER_ERROR_INVALID_PARAMETER if \p hStream is not a valid Sanitizer stream
 * handle or if \p stream is NULL.
 */
SanitizerResult SANITIZERAPI sanitizerGetStream(Sanitizer_StreamHandle hStream,
                                                CUstream* stream);

/**
 * \brief Retrieve a Sanitizer_StreamHandle handle from a CUstream handle
 *
 * \note \b Thread-safety: this function is thread safe.
 *
 * \param[in] ctx Context owning the stream. If NULL, the current context will be used.
 * \param[in] stream CUstream handle. If NULL, the NULL stream will be used.
 * \param[out] hStream Output Sanitizer Stream handle.
 *
 * \retval SANITIZER_SUCCESS on success
 * \retval SANITIZER_ERROR_INVALID_PARAMETER if \p stream is not a valid CUstream handle
 * or if \p hStream is NULL.
 */
SanitizerResult SANITIZERAPI sanitizerGetStreamHandle(CUcontext ctx,
                                                      CUstream stream,
                                                      Sanitizer_StreamHandle* hStream);

/** @} */ /* END SANITIZER_STREAM_API */

#if defined(__cplusplus)
}
#endif

#endif /* __SANITIZER_STREAM_H__ */
