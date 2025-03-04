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

#ifndef INCLUDE_UPGINE_CORE_SERVICES_TIME_SERVICE_H
#define INCLUDE_UPGINE_CORE_SERVICES_TIME_SERVICE_H

#include "service_interface.h"
#include "upgine/memory/smart_pointer/reference.h"

namespace Upgine::Core::Services {
  class TimeService : public IService, public Upgine::Memory::SmartPointer::Reference
  {
  public:
    TimeService();
    ~TimeService() override;

    // IService overrides
    void Init() override;
    void Update() override;
    void Shutdown() override;

    float GetDeltaTime() const;
    float GetTimeSinceStartup() const;

    private:
      struct Data;
      Data *data_;
  };
}

#endif //INCLUDE_UPGINE_CORE_SERVICES_TIME_SERVICE_H
