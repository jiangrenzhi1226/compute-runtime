/*
* Copyright (c) 2018, Intel Corporation
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once
#include "runtime/gmm_helper/gmm_lib.h"
#include <memory>

namespace OCLRT {
class GmmMemoryBase {
  public:
    virtual ~GmmMemoryBase() = default;

    MOCKABLE_VIRTUAL bool configureDeviceAddressSpace(GMM_ESCAPE_HANDLE hAdapter,
                                                      GMM_ESCAPE_HANDLE hDevice,
                                                      GMM_ESCAPE_FUNC_TYPE pfnEscape,
                                                      GMM_GFX_SIZE_T SvmSize,
                                                      BOOLEAN FaultableSvm,
                                                      BOOLEAN SparseReady,
                                                      BOOLEAN BDWL3Coherency,
                                                      GMM_GFX_SIZE_T SizeOverride,
                                                      GMM_GFX_SIZE_T SlmGfxSpaceReserve) {
        return GmmConfigureDeviceAddressSpace(
                   hAdapter,
                   hDevice,
                   pfnEscape,
                   SvmSize,
                   FaultableSvm,
                   SparseReady,
                   BDWL3Coherency,
                   SizeOverride,
                   SlmGfxSpaceReserve) != 0
                   ? true
                   : false;
    }

    MOCKABLE_VIRTUAL uintptr_t getInternalGpuVaRangeLimit() {
        return static_cast<uintptr_t>(pGmmGlobalContext->GetInternalGpuVaRangeLimit());
    }

  protected:
    GmmMemoryBase() = default;
};
} // namespace OCLRT
