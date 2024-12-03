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

#ifndef INCLUDE_UPGINE_CORE_MANAGERS_SERVICES_MANAGER_H_
#define INCLUDE_UPGINE_CORE_MANAGERS_SERVICES_MANAGER_H_

namespace Upgine::Core::Services{
  class WindowService;
  class PlatformService;
  class InputService;
  class ProfilerService;
  class GraphicsResourcesService;
  class DrawService;
  class ChunkService;
  class SystemService;
  class CameraService;
  class TimeService;
}

namespace Upgine::Core::Managers {
  class ServicesManager {
  private:
    ServicesManager();
    ~ServicesManager();
    ServicesManager(const ServicesManager&) = delete;
    ServicesManager(ServicesManager&&) = delete;
    ServicesManager& operator=(const ServicesManager&) = delete;
    ServicesManager& operator=(ServicesManager&&) = delete;

  public:
    static ServicesManager & GetInstance();
    Services::WindowService * GetWindowService() const;
    Services::PlatformService * GetPlatformService() const;
    Services::InputService * GetInputService() const;
    Services::ProfilerService * GetProfilerService() const;
    Services::GraphicsResourcesService * GetGraphicsResourcesService() const;
    Services::DrawService * GetDrawService() const;
    Services::ChunkService * GetChunkService() const;
    Services::SystemService * GetSystemService() const;
    Services::CameraService * GetCameraService() const;
    Services::TimeService * GetTimeService() const;

    void Alloc() const;
    void Init() const;
    void Update() const;
    void Shutdown() const;

  private:
    struct Data;
    Data *data_;
  };
}

#endif // INCLUDE_UPGINE_CORE_MANAGERS_SERVICES_MANAGER_H_
