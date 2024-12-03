/*
MIT License

Copyright (c) 14/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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
#include "upgine/core/managers/gpu_manager.h"
#include "upgine/graphics/gpu/gpu_interface.h"
#include "upgine/graphics/gpu/opengl_api.h"

struct Upgine::Core::Managers::GPUManager::Data {
  Upgine::Graphics::GPU::IGPU * context;
};

const Upgine::Core::Managers::GPUManager &
Upgine::Core::Managers::GPUManager::GetInstance() {
  static GPUManager instance;
  return instance;
}

Upgine::Core::Managers::GPUManager::GPUManager() {
  data_ = new Data();
}

Upgine::Core::Managers::GPUManager::~GPUManager() {
  data_->context->Release();
  delete data_;
}

void Upgine::Core::Managers::GPUManager::Init() {
  auto isOpenGL = true;
  if(isOpenGL) {
    GetInstance().data_->context = new Upgine::Graphics::GPU::OpenglAPI();
  }
}

void Upgine::Core::Managers::GPUManager::Clear(float *color) {
  GetInstance().data_->context->Clear(color);
}

void Upgine::Core::Managers::GPUManager::Draw() {
  GetInstance().data_->context->Draw();
}

void Upgine::Core::Managers::GPUManager::SetBackFaceCulling(bool enable) {
  GetInstance().data_->context->SetBackFaceCulling(enable);
}

void Upgine::Core::Managers::GPUManager::SetFrontFaceCulling(bool enable) {
  GetInstance().data_->context->SetFrontFaceCulling(enable);
}

void Upgine::Core::Managers::GPUManager::SetDepthTest(bool enable) {
  GetInstance().data_->context->SetDepthTest(enable);
}


