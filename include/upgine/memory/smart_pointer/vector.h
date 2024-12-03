/*
MIT License

Copyright (c) 13/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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

#ifndef INCLUDE_UPGINE_MEMORY_SMART_POINTER_VECTOR_H_
#define INCLUDE_UPGINE_MEMORY_SMART_POINTER_VECTOR_H_

#include "upgine/core/types/basic_types.h"
#include <vector>
#include <stdexcept>

namespace Upgine::Memory::SmartPointer {
  template <class T>
  class Vector {
  public:
    explicit Vector(uint32 size);
    Vector() = default;

    void Init(uint32 size);
    T* AllocateElement();
    void ReleaseElement(uint32 index);
    T* Get(uint32 index);
    const T* Get(uint32 index) const;

   private:

    bool isAllocated_ = false;
    std::vector<T> data_;
    std::vector<uint32> free_;
  };

template<class T>
void Vector<T>::Init(uint32 size) {
  if(isAllocated_){
    throw std::runtime_error("Vector already allocated, cannot allocate again");
  };
  isAllocated_ = true;
  data_.resize(size);
  for (uint32 i = 0; i < size; ++i) {
    free_.push_back(i);
  }
}

template <class T> T *Vector<T>::AllocateElement() {
    //Get the first item in the free list
    uint32 index = free_.front();
    //Remove the first item from the free list
    free_.erase(free_.begin());
    //Return the pointer to the allocated memory
    return &data_[index];
  }

  template <class T> Vector<T>::Vector(uint32 size) {
    Init(size);
  }

  template <class T> void Vector<T>::ReleaseElement(uint32 index) {
    for (uint32 i = 0; i < free_.size(); ++i) {
      if (free_[i] == index) {
        free_.erase(free_.begin() + i);
        break;
      }
    }
  }

  template <class T> const T *Vector<T>::Get(uint32 index) const {
    return &data_[index];
  }

  template <class T> T *Vector<T>::Get(uint32 index) {
    return &data_[index];
  }
}  // namespace Upgine::Memory::SmartPointer

#endif // INCLUDE_UPGINE_MEMORY_SMART_POINTER_VECTOR_H_
