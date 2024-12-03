/*
MIT License

Copyright (c) 11/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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

#include "upgine/core/services/platform_service.h"
#include "upgine/core/services/window_service.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <exception>
#include <stdexcept>

struct Upgine::Core::Services::PlatformService::Data {
  void * context;
};

void Upgine::Core::Services::PlatformService::OnConstructor(){
  data_ = new Data();
  data_->context = nullptr;
}

Upgine::Core::Services::PlatformService::~PlatformService() {
  delete data_;
}

void Upgine::Core::Services::PlatformService::Init() {
  if(data_->context != nullptr) return;

  // glfw: initialize and configure
  // ------------------------------
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // glfw window creation
  // --------------------
  auto width =  GetServiceManager().GetWindowService()->GetWidth();
  auto height = GetServiceManager().GetWindowService()->GetHeight();

  if((width == UINT32_MAX) || (height == UINT32_MAX)) {
    throw std::runtime_error("Window size is not defined, please set it before initializing the platform service");
  }

  data_->context = glfwCreateWindow(width, height, "Cousin Engine", NULL, NULL);
}

void *Upgine::Core::Services::PlatformService::GetContext() {
  if(data_->context == nullptr) { Init();}
  return data_->context;
}
void Upgine::Core::Services::PlatformService::Update() {
  glfwPollEvents();
}
void Upgine::Core::Services::PlatformService::Shutdown() {
  glfwTerminate();
}


