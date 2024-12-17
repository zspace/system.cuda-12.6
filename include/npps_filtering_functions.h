 /* Copyright 2010-2023 NVIDIA CORPORATION & AFFILIATES.  All rights reserved. 
  * 
  * NOTICE TO LICENSEE: 
  * 
  * The source code and/or documentation ("Licensed Deliverables") are 
  * subject to NVIDIA intellectual property rights under U.S. and 
  * international Copyright laws. 
  * 
  * The Licensed Deliverables contained herein are PROPRIETARY and 
  * CONFIDENTIAL to NVIDIA and are being provided under the terms and 
  * conditions of a form of NVIDIA software license agreement by and 
  * between NVIDIA and Licensee ("License Agreement") or electronically 
  * accepted by Licensee.  Notwithstanding any terms or conditions to 
  * the contrary in the License Agreement, reproduction or disclosure 
  * of the Licensed Deliverables to any third party without the express 
  * written consent of NVIDIA is prohibited. 
  * 
  * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE 
  * LICENSE AGREEMENT, NVIDIA MAKES NO REPRESENTATION ABOUT THE 
  * SUITABILITY OF THESE LICENSED DELIVERABLES FOR ANY PURPOSE.  THEY ARE 
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
  * C.F.R. 12.212 (SEPT 1995) and are provided to the U.S. Government 
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
#ifndef NV_NPPS_FILTERING_FUNCTIONS_H
#define NV_NPPS_FILTERING_FUNCTIONS_H
 
/**
 * \file npps_filtering_functions.h
 * NPP Signal Processing Functionality.
 */
 
#include "nppdefs.h"


#ifdef __cplusplus
extern "C" {
#endif

/** 
 *  \page signal_filtering_functions Filtering Functions
 *  @defgroup signal_filtering_functions Filtering Functions
 *  @ingroup npps
 * Functions that provide functionality of generating output signal
 * based on the input signal like signal integral, etc.
 *
 * @{
 *
 */

/** 
 * \section signal_integral Integral
 * @defgroup signal_integral Integral
 * Compute the indefinite integral of a given signal.
 * The i-th element is computed to be
 * \f[
 *      s'_i = \sum_0^i s_j
 * \f]
 *
 * @{
 */
 
/**
 * Device scratch buffer size (in bytes) for 32s nppsIntegral.
 *
 * This primitive provides the correct buffer size for nppsIntegral_32s.
 * \param nLength \ref length_specification.
 * \param hpBufferSize Required buffer size. Important: hpBufferSize is a 
 *        <em>host pointer.</em> \ref general_scratch_buffer.
 */
NppStatus
nppsIntegralGetBufferSize_32s(size_t nLength,  size_t * hpBufferSize);

/** 
 * Compute cumulative sum of 32-bit signed integer signal
 *
 * \param pSrc \ref source_signal_pointer.
 * \param pDst Pointer to the output result.
 * \param nLength \ref length_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation.
 * \param nppStreamCtx \ref application_managed_stream_context. 
 * \return \ref signal_data_error_codes, \ref length_error_codes.
 */
NppStatus 
nppsIntegral_32s_Ctx(const Npp32s * pSrc, Npp32s * pDst, size_t nLength, Npp8u * pDeviceBuffer, NppStreamContext nppStreamCtx);

/** 
 * Compute cumulative sum of 32-bit signed integer signal
 *
 * \param pSrc \ref source_signal_pointer.
 * \param pDst Pointer to the output result.
 * \param nLength \ref length_specification.
 * \param pDeviceBuffer Pointer to the required device memory allocation.
 * \return \ref signal_data_error_codes, \ref length_error_codes.
 */
NppStatus 
nppsIntegral_32s(const Npp32s * pSrc, Npp32s * pDst, size_t nLength, Npp8u * pDeviceBuffer);

/** @} signal_integral */

/** @} signal_filtering_functions */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NV_NPPS_FILTERING_FUNCTIONS_H */
