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

#ifndef INC_2_3DGEOMETRYSHAPES_MEMORY_CHUNKS_H
#define INC_2_3DGEOMETRYSHAPES_MEMORY_CHUNKS_H


#include <vector>
#include "upgine/core/types/basic_types.h"
#include "upgine/ecs/entity/entity.h"

namespace Upgine::ECS::Memory{

  template <class classType>
  class Chunks{
  public:
    Chunks(){
      capacity_ = 1024;
      data_.reserve(capacity_);
      data_.resize(capacity_);
    };
    ~Chunks() = default;

    template<typename name>
    name *Get(uint32 index, uint32 subIndex){
      return data_[index].Get(subIndex);
    }

    classType *Get(uint32 index){
      return &data_[index];
    }

    uint32 Count(){
      return capacity_;
    }

    uint32 UsedChunks(){
        uint32 count = 0;
        for(uint32 i = 0; i < capacity_; i++){
            if(data_[i].IsUsed()) count++;
        }
        return count;
    }

    template<typename name>
    Upgine::ECS::Entities::Entity Add(){
      for(uint32 i = 0; i < capacity_; i++){
        if(!data_[i].IsFull()){
          uint32 slot = data_[i].Add(name());
          return {i, slot};
        }
      }
      return {UINT32_MAX, UINT32_MAX};
    }

    template<typename name>
    bool Remove(uint32 index, uint32 subIndex){
      return data_[index].Remove(subIndex);
    }

  private:
    uint32 capacity_ = UINT32_MAX;
    std::vector<classType> data_;
  };
}

#endif //INC_2_3DGEOMETRYSHAPES_MEMORY_CHUNKS_H
