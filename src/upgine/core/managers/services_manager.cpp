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
#include "upgine/core/managers/services_manager.h"
#include "upgine/core/services/window_service.h"
#include "upgine/core/services/input_service.h"
#include "upgine/core/services/platform_service.h"
#include "upgine/core/services/profiler_service.h"
#include "upgine/core/services/graphics_resources_service.h"
#include "upgine/core/services/draw_service.h"
#include "upgine/core/services/camera_service.h"
#include "upgine/core/services/time_service.h"
#include "upgine/auto_generate/chunk_service.h"
#include "upgine/auto_generate/system_service.h"
#include "upgine/memory/smart_pointer/reference_container.h"

using namespace Upgine::Memory::SmartPointer;

struct Upgine::Core::Managers::ServicesManager::Data {
  ReferenceContainer<Services::WindowService> windowService;
  ReferenceContainer<Services::PlatformService> platformService;
  ReferenceContainer<Services::InputService> inputService;
  ReferenceContainer<Services::ProfilerService> profilerService;
  ReferenceContainer<Services::GraphicsResourcesService> graphicsResourcesService;
  ReferenceContainer<Services::DrawService> drawService;
  ReferenceContainer<Services::ChunkService> chunkService;
  ReferenceContainer<Services::SystemService> systemService;
  ReferenceContainer<Services::CameraService> cameraService;
  ReferenceContainer<Services::TimeService> timeService;
  bool allocated = false;
};

Upgine::Core::Managers::ServicesManager::ServicesManager() {
  data_ = new Data();
}

Upgine::Core::Managers::ServicesManager::~ServicesManager() {
  delete data_;
}

Upgine::Core::Managers::ServicesManager &
Upgine::Core::Managers::ServicesManager::GetInstance() {
  static ServicesManager instance;
  return instance;
}

Upgine::Core::Services::WindowService *
Upgine::Core::Managers::ServicesManager::GetWindowService() const {
  return GetInstance().data_->windowService.get();
}

Upgine::Core::Services::InputService *
Upgine::Core::Managers::ServicesManager::GetInputService() const {
  return GetInstance().data_->inputService.get();
}

Upgine::Core::Services::PlatformService *
Upgine::Core::Managers::ServicesManager::GetPlatformService() const {
  return GetInstance().data_->platformService.get();
}

Upgine::Core::Services::ProfilerService *
Upgine::Core::Managers::ServicesManager::GetProfilerService() const {
  return GetInstance().data_->profilerService.get();
}

Upgine::Core::Services::GraphicsResourcesService *
Upgine::Core::Managers::ServicesManager::GetGraphicsResourcesService() const {
  return GetInstance().data_->graphicsResourcesService.get();
}

Upgine::Core::Services::DrawService *Upgine::Core::Managers::ServicesManager::GetDrawService() const {
  return GetInstance().data_->drawService.get();
}

Upgine::Core::Services::ChunkService *Upgine::Core::Managers::ServicesManager::GetChunkService() const {
  return GetInstance().data_->chunkService.get();
}

Upgine::Core::Services::SystemService *Upgine::Core::Managers::ServicesManager::GetSystemService() const {
    return GetInstance().data_->systemService.get();
}

Upgine::Core::Services::CameraService *Upgine::Core::Managers::ServicesManager::GetCameraService() const {
  return GetInstance().data_->cameraService.get();
}

Upgine::Core::Services::TimeService *Upgine::Core::Managers::ServicesManager::GetTimeService() const {
  return GetInstance().data_->timeService.get();
}

void Upgine::Core::Managers::ServicesManager::Alloc() const {
  if(data_->allocated) return;
  data_->platformService.alloc();
  data_->windowService.alloc();
  data_->inputService.alloc();
  data_->profilerService.alloc();
  data_->graphicsResourcesService.alloc();
  data_->drawService.alloc();
  data_->chunkService.alloc();
  data_->systemService.alloc();
  data_->cameraService.alloc();
  data_->timeService.alloc();
  data_->allocated = true;
}

void Upgine::Core::Managers::ServicesManager::Init() const {
  data_->platformService.get()->Init();
  data_->windowService.get()->Init();
  data_->inputService.get()->Init();
  data_->profilerService.get()->Init();
  data_->graphicsResourcesService.get()->Init();
  data_->drawService.get()->Init();
  data_->chunkService.get()->Init();
  data_->systemService.get()->Init();
  data_->cameraService.get()->Init();
  data_->timeService.get()->Init();
}

void Upgine::Core::Managers::ServicesManager::Update() const {
  data_->timeService.get()->Update();
  data_->inputService.get()->Update();
  data_->chunkService.get()->Update();
  data_->systemService.get()->Update();
  data_->cameraService.get()->Update();
  data_->graphicsResourcesService.get()->Update();
  data_->drawService.get()->Update();
  data_->windowService.get()->Update();
  data_->inputService.get()->PostUpdate();
  data_->platformService.get()->Update();
  data_->profilerService.get()->Update();
}

void Upgine::Core::Managers::ServicesManager::Shutdown() const {
  data_->timeService.get()->Shutdown();
  data_->cameraService.get()->Shutdown();
  data_->systemService.get()->Shutdown();
  data_->chunkService.get()->Shutdown();
  data_->drawService.get()->Shutdown();
  data_->graphicsResourcesService.get()->Shutdown();
  data_->inputService.get()->Shutdown();
  data_->windowService.get()->Shutdown();
  data_->platformService.get()->Shutdown();
  data_->profilerService.get()->Shutdown();
}


