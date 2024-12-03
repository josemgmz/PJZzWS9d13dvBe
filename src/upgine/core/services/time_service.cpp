/*
MIT License

Copyright (c) 25/02/2023 Jose Manuel Gomez Castellana (josemgmz)

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
#include "upgine/core/services/time_service.h"
#include "glfw/glfw3.h"

struct Upgine::Core::Services::TimeService::Data {
  float lastFrame;
  float deltaTime;
};

Upgine::Core::Services::TimeService::TimeService() {
  data_ = new Data();
}

Upgine::Core::Services::TimeService::~TimeService() {
  delete data_;
}

void Upgine::Core::Services::TimeService::Init() {
  data_->deltaTime = 0.0f;
  data_->lastFrame = 0.0f;
}

void Upgine::Core::Services::TimeService::Update() {
  float currentFrame = glfwGetTime();
  data_->deltaTime = currentFrame - data_->lastFrame;
  data_->lastFrame = currentFrame;
}

void Upgine::Core::Services::TimeService::Shutdown() {
  data_->deltaTime = 0.0f;
  data_->lastFrame = 0.0f;
}

float Upgine::Core::Services::TimeService::GetDeltaTime() const {
  return data_->deltaTime;
}

float Upgine::Core::Services::TimeService::GetTimeSinceStartup() const {
  return glfwGetTime();
}

