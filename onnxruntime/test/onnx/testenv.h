// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#include <atomic>
#include <vector>
#include "TestResultStat.h"
#include <core/common/common.h>
#include <core/session/onnxruntime_cxx_api.h>

class ITestCase;
class TestCaseResult;
template <typename T>
class FixedCountFinishCallbackImpl;
using FixedCountFinishCallback = FixedCountFinishCallbackImpl<TestCaseResult>;

class TestEnv {
 public:
  std::vector<ITestCase*> tests;
  std::atomic_int next_test_to_run;
  TestResultStat& stat;
  FixedCountFinishCallback* finished;
  const onnxruntime::SessionOptionsWrapper& sf;
  TestEnv(const std::vector<ITestCase*>& tests, TestResultStat& stat1, onnxruntime::SessionOptionsWrapper& sf1);
  ~TestEnv();

 private:
  ONNXRUNTIME_DISALLOW_COPY_ASSIGNMENT_AND_MOVE(TestEnv);
};
