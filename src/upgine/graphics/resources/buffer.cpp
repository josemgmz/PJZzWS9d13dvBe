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
#include "upgine/graphics/resources/buffer.h"
#include <glad/glad.h>
#include <fstream>
#include <sstream>

uint32 Upgine::Graphics::Resources::Buffer::GetId() const {
  return id_;
}

void Upgine::Graphics::Resources::Buffer::Execute() {
  glBindBuffer(type_ == Type::kArrayBuffer ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, id_);
}

void Upgine::Graphics::Resources::Buffer::Release() {

}

void Upgine::Graphics::Resources::Buffer::Init( Upgine::Graphics::Resources::Buffer::Type type) {
  type_ = type;
  glGenBuffers(1, &id_);
}

void Upgine::Graphics::Resources::Buffer::Remove() {
  glBindBuffer(type_ == Type::kArrayBuffer ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, 0);
}
void Upgine::Graphics::Resources::Buffer::SetData(void *data, uint32 size) {
    Execute();
    glBufferData(type_ == Type::kArrayBuffer ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}