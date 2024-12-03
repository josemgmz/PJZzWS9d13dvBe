/*
MIT License
Copyright (c) 22/01/2023 Jose Manuel Gomez Castellana (josemgmz)
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


//This file is generated automatically by archetypes_generator.py

#ifndef INCLUDE_UPGINE_AUTO_GENERATE_CHUNK_SERVICE_H_
#define INCLUDE_UPGINE_AUTO_GENERATE_CHUNK_SERVICE_H_

#include "upgine/core/services/service_interface.h"
#include "upgine/memory/smart_pointer/reference.h"

#include "upgine/core/types/basic_types.h"

#include "upgine/ecs/memory/memory_chunks.h"

namespace Upgine::ECS::DTO { class ComponentDTO; }

namespace Upgine::Core::Services{
  class ChunkService : public IService, public Upgine::Memory::SmartPointer::Reference {
   public:
    ChunkService();
    ~ChunkService() override;

    void Init() override;
    void Update() override;
    void Shutdown() override;

    template<typename T>
    T* Get(uint32 chunkId, uint32 slotId);

    template<typename T>
    T* Get(uint32 chunkId);

    template<typename T>
    Upgine::ECS::Entities::Entity Add();

    template<typename T>
    bool Remove(uint32 chunkId, uint32 slotId);

    template<typename T>
    uint32 UsedChunks();

    template<typename T>
    std::vector<Upgine::ECS::DTO::ComponentDTO> GetComponents();

  private:
    struct Data;
    Data * data_;
  };
}
#endif // INCLUDE_UPGINE_AUTO_GENERATE_CHUNK_SERVICE_H_
