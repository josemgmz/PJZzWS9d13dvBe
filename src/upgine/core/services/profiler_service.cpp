/*
MIT License

Copyright (c) 15/01/2023 Jose Manuel Gomez Castellana (josemgmz)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <chrono>
#include <iostream>
#include "upgine/core/services/profiler_service.h"
#include "upgine/core/types/basic_types.h"

struct Upgine::Core::Services::ProfilerService::Data {
  std::chrono::_V2::system_clock::time_point frameTime;
  double fps;
  uint64 accumulatedFPS;
  uint64 frames;
};

Upgine::Core::Services::ProfilerService::ProfilerService() {
  data_ = new Data();
}

Upgine::Core::Services::ProfilerService::~ProfilerService() {
  Shutdown();
  delete data_;
}

void Upgine::Core::Services::ProfilerService::Init() {
  data_->frameTime = std::chrono::high_resolution_clock::now();
}

void Upgine::Core::Services::ProfilerService::Update() {
  //This method have a bug, because we can overflow the uint64_t if we run this code for a long time this is just for short testing
  auto currentTime = std::chrono::high_resolution_clock::now();
  double deltaTime = std::chrono::duration<double>(currentTime - data_->frameTime).count();
  data_->fps = 1.0 / deltaTime;
  data_->frameTime = currentTime;
  data_->accumulatedFPS += (uint64) data_->fps;
  data_->frames++;
}
void Upgine::Core::Services::ProfilerService::Shutdown() {
  auto averageFPS = data_->accumulatedFPS / data_->frames;
  std::cout << "Average FPS: " << averageFPS << std::endl;
}

