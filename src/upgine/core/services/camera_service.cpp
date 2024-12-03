/*
MIT License

Copyright (c) 18/02/2023 Jose Manuel Gomez Castellana (josemgmz)

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
#include <vector>
#include "upgine/core/services/camera_service.h"
#include "upgine/objects/camera_object.h"

struct Upgine::Core::Services::CameraService::Data {
  std::vector<Upgine::Objects::CameraObject *> cameras;
  Upgine::Objects::CameraObject * mainCamera;
};

Upgine::Core::Services::CameraService::CameraService() {
  data_ = new Data();
}

Upgine::Core::Services::CameraService::~CameraService() {
  delete data_;
}

void Upgine::Core::Services::CameraService::Init() {

}

void Upgine::Core::Services::CameraService::Update() {

  for (auto camera : data_->cameras) {
    camera->Update();
  }
}

void Upgine::Core::Services::CameraService::Shutdown() {

}

void Upgine::Core::Services::CameraService::AddCamera(Upgine::Objects::CameraObject *camera) {
  if(data_->mainCamera == nullptr) data_->mainCamera = camera;
  data_->cameras.push_back(camera);
}

void Upgine::Core::Services::CameraService::RemoveCamera(Upgine::Objects::CameraObject *camera) {
  for (auto it = data_->cameras.begin(); it != data_->cameras.end(); ++it) {
    if (*it == camera) {
      data_->cameras.erase(it);
      break;
    }
  }
}

std::vector<Upgine::Objects::CameraObject *> *Upgine::Core::Services::CameraService::GetCameras() {
  return &data_->cameras;
}

void Upgine::Core::Services::CameraService::SetMainCamera(Upgine::Objects::CameraObject *camera) {
  data_->mainCamera = camera;
}

