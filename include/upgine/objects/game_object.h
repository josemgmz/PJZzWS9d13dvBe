/*
MIT License

Copyright (c) 23/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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

#ifndef INCLUDE_UPGINE_OBJECTS_GAME_OBJECT_H_
#define INCLUDE_UPGINE_OBJECTS_GAME_OBJECT_H_

#include "upgine/ecs/entity/entity.h"
#include "upgine/core/types/basic_types.h"
#include "upgine/core/managers/services_manager.h"
#include "upgine/macros/dependency_injector.h"
#include "upgine/auto_generate/chunk_service.h"

namespace Upgine::Objects
{
    template<typename Type>
    class GameObject
    {
    public:
      INJECT_SERVICES_TEMPLATE(GameObject)

      void OnConstructor(){
        GetServiceManager().Alloc();
        entity_ = dependencyServiceManager_.GetChunkService()->Add<Type>();
      };

      virtual ~GameObject(){
        dependencyServiceManager_.GetChunkService()->Remove<Type>(entity_.chunkId, entity_.archetypeId);
        entity_.archetypeId = UINT32_MAX;
        entity_.chunkId = UINT32_MAX;
      };

      uint32 GetId() const {
        return entity_.archetypeId;
      }

      Type * GetArchetype()
      {
        return dependencyServiceManager_.GetChunkService()->Get<Type>(
            entity_.chunkId, entity_.archetypeId);
      }

      void Controlled(bool value){
      }

     private:
      Upgine::ECS::Entities::Entity entity_;
    };
}

#endif //INCLUDE_UPGINE_OBJECTS_GAME_OBJECT_H_
