/*
MIT License

Copyright (c) 24/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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

#ifndef INCLUDE_UPGINE_ECS_MEMORY_MEMORY_CHUNK_H_
#define INCLUDE_UPGINE_ECS_MEMORY_MEMORY_CHUNK_H_

#include "upgine/core/types/basic_types.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <deque>

namespace Upgine::ECS::Memory{
  template <class classType>
  class Chunk{
  public:
    ~Chunk() = default;
    Chunk(){
      uint32 typeSize = sizeof(classType);
      capacity_ = maxChunkSize_ / typeSize;
      data_.reserve(capacity_);
      data_.resize(capacity_);

      for(uint32 i = 0; i < capacity_; i++){
        freeSlots_.push_back(i);
      }
    }

    uint32 Add(classType value) {
      if(freeSlots_.empty()) return UINT32_MAX;
      uint32 slot = freeSlots_.front();
      freeSlots_.pop_front();
      data_[slot] = value;
      if(slot >= size_) size_ = slot + 1;
      return slot;
    }

    bool Remove(uint32 index) {
      if(index >= capacity_) return false;
      if(std::find(freeSlots_.begin(), freeSlots_.end(), index) != freeSlots_.end()) return false;
      freeSlots_.push_back(index);
      return true;
    }

    classType *Get(uint32 index) {
      return &data_[index];
    }

    bool IsFull() {
      return freeSlots_.empty();
    }

    bool IsEmpty() {
      return freeSlots_.size() == capacity_;
    }

    bool IsUsed(){
        return !IsEmpty();
    }

    uint32 GetCapacity(){
      return capacity_;
    }

    uint32 GetSize(){
      return size_;
    }


   private:
    uint32 size_ = 0;
    uint32 capacity_ = UINT32_MAX;
    uint32 maxChunkSize_ = (16 * 1024) - 256;
    std::vector<classType> data_;
    std::deque<uint32> freeSlots_;
  };
}

#endif //INCLUDE_UPGINE_ECS_MEMORY_MEMORY_CHUNK_H_
