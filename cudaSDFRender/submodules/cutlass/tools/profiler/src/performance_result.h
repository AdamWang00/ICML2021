/***************************************************************************************************
 * Copyright (c) 2017-2019, NVIDIA CORPORATION.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright notice, this list of
 *       conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright notice, this list of
 *       conditions and the following disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name of the NVIDIA CORPORATION nor the names of its contributors may be used
 *       to endorse or promote products derived from this software without specific prior written
 *       permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NVIDIA CORPORATION BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TOR (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **************************************************************************************************/
/* \file
   \brief Defines a math function
*/

#pragma once

#include <vector>

#include "cutlass/cutlass.h"

#include "enumerated_types.h"

namespace cutlass {
namespace profiler {

/////////////////////////////////////////////////////////////////////////////////////////////////

/// Performance result object
struct PerformanceResult {

  /// Index of problem
  size_t problem_index;

  /// Provider
  Provider provider;

  /// Outcome of test
  Disposition disposition;

  /// CUTLASS status result from kernels
  cutStatus status;

  /// Operation object
  std::string operation_name;

  /// Stringified vector of argument values
  std::vector<std::pair<std::string, std::string> > arguments;

  /// Number of bytes read or written
  int64_t bytes;

  /// Number of DL flops performed by the math function
  int64_t flops;

  /// Average runtime in ms
  double runtime;

  //
  // Members
  //

  /// Ctor
  PerformanceResult(): 
    problem_index(0),
    provider(Provider::kInvalid), 
    disposition(Disposition::kNotRun),
    status(cutStatus::kInvalid),
    bytes(0), 
    flops(0), 
    runtime(0)
  { }

  /// Returns true if the runtime is valid
  bool good() const {
    return runtime > 0;
  }

  /// Math throughput in units of GFLOP/s
  double gflops_per_sec() const {
    return double(flops) / runtime / 1.0e6;
  }

  /// memory bandwidth in units of GiB/s
  double gbytes_per_sec() const {
    return double(bytes) / double(1 << 30) / runtime * 1000.0;
  }

};

using PerformanceResultVector = std::vector<PerformanceResult>;

/////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace profiler
} // namespace cutlass
