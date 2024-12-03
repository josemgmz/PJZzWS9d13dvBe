/*
MIT License

Copyright (c) 15/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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

#include "upgine/core/services/graphics_resources_service.h"
#include "upgine/memory/smart_pointer/vector.h"
#include "upgine/graphics/resources/buffer.h"
#include "upgine/graphics/resources/shader.h"
#include "upgine/graphics/resources/material.h"
#include "upgine/graphics/resources/texture.h"
#include "upgine/graphics/resources/vertex_buffer.h"

using namespace Upgine::Memory;
using namespace Upgine::Graphics::Resources;

struct Upgine::Core::Services::GraphicsResourcesService::Data {
  SmartPointer::Vector<Buffer> buffers;
  SmartPointer::Vector<Shader> shaders;
  SmartPointer::Vector<Material> material;
  SmartPointer::Vector<Texture> textures;
  SmartPointer::Vector<VertexBuffer> vertexBuffer;
};
Upgine::Core::Services::GraphicsResourcesService::GraphicsResourcesService() {
  data_ = new Data();
}

Upgine::Core::Services::GraphicsResourcesService::~GraphicsResourcesService() {
  Shutdown();
  delete data_;
}

void Upgine::Core::Services::GraphicsResourcesService::Init() {
  data_->buffers.Init(1000);
  data_->shaders.Init(1000);
  data_->material.Init(1000);
  data_->textures.Init(1000);
  data_->vertexBuffer.Init(1000);
}

void Upgine::Core::Services::GraphicsResourcesService::Shutdown() {
}
Upgine::Graphics::Resources::Buffer *
Upgine::Core::Services::GraphicsResourcesService::GetBuffer(uint32 index) {
  return data_->buffers.Get(index);
}
Upgine::Graphics::Resources::Shader *
Upgine::Core::Services::GraphicsResourcesService::GetShader(uint32 index) {
  return data_->shaders.Get(index);
}
Upgine::Graphics::Resources::Material *
Upgine::Core::Services::GraphicsResourcesService::GetMaterial(uint32 index) {
  return data_->material.Get(index);
}
Upgine::Graphics::Resources::VertexBuffer *
Upgine::Core::Services::GraphicsResourcesService::GetVertexBuffer(uint32 index) {
  return data_->vertexBuffer.Get(index);
}
Upgine::Graphics::Resources::Texture *Upgine::Core::Services::GraphicsResourcesService::GetTexture(uint32 index) {
  return data_->textures.Get(index);
}
