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

#include "upgine/graphics/resources/vertex_buffer.h"
#include <glad/glad.h>

uint32 Upgine::Graphics::Resources::VertexBuffer::GetId() const {
  return id_;
}

void Upgine::Graphics::Resources::VertexBuffer::Execute() {
  glBindVertexArray(id_);
}

void Upgine::Graphics::Resources::VertexBuffer::Release() {
  glDeleteVertexArrays(1, &id_);
}

void Upgine::Graphics::Resources::VertexBuffer::Init() {
  glGenVertexArrays(1, &id_);
}
void Upgine::Graphics::Resources::VertexBuffer::Remove() {
  glBindVertexArray(0);
}
void Upgine::Graphics::Resources::VertexBuffer::SetVertexAttribute() {
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6* sizeof(float)));
  glEnableVertexAttribArray(2);
}
