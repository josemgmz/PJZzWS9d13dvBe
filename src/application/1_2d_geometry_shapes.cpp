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

#include "application/1_2d_geometry_shapes.h"
#include "upgine/core/services/draw_service.h"
#include "upgine/auto_generate/chunk_service.h"
#include "upgine/core/services/graphics_resources_service.h"
#include "upgine/graphics/resources/buffer.h"
#include "upgine/graphics/resources/material.h"
#include "upgine/graphics/resources/shader.h"
#include "upgine/graphics/resources/texture.h"
#include "upgine/graphics/resources/vertex_buffer.h"
#include "upgine/graphics/draw/draw_element.h"
#include "upgine/ecs/archetypes/archetypes_declaration.h"
#include "upgine/objects/game_object.h"
#include "upgine/objects/camera_object.h"
#include "glfw/glfw3.h"

int main()
{
  Application app;
  app.Start(800, 600, "1_2d_geometry_shapes", false);
  return 0;
}

Upgine::Objects::GameObject<Upgine::ECS::Archetypes::TR> gameobject;
Upgine::Objects::GameObject<Upgine::ECS::Archetypes::TR> gameobject2;
Upgine::Objects::CameraObject cameraObject;

void Application::Init() {
  gameobject.GetArchetype()->renderer.materialId = 0;
  gameobject.GetArchetype()->renderer.vertexBufferId = 0;
  gameobject.GetArchetype()->renderer.textureIds[0] = 0;
  gameobject.GetArchetype()->transform.materialId = 0;

  gameobject2.GetArchetype()->renderer.materialId = 0;
  gameobject2.GetArchetype()->renderer.vertexBufferId = 0;
  gameobject2.GetArchetype()->renderer.textureIds[0] = 0;
  gameobject2.GetArchetype()->transform.materialId = 0;
  gameobject2.GetArchetype()->transform.model = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, -2.0f));

  cameraObject.SetLookAt(Vec3(0.0f, 0.0f, -4.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));
  cameraObject.SetProjectionPerspective(Math::ToRadians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
  cameraObject.Controlled(true);

  auto graphicsResourcesService = GetServiceManager().GetGraphicsResourcesService();
  auto * vertex = graphicsResourcesService->GetShader(0);
  auto * fragment = graphicsResourcesService->GetShader(1);

  vertex->Init("shader.vs", Upgine::Graphics::Resources::Shader::Type::kTypeVertex);
  fragment->Init("shader.fs", Upgine::Graphics::Resources::Shader::Type::kTypeFragment);

  auto material = graphicsResourcesService->GetMaterial(0);
  material->Init(vertex, fragment);

  auto texture = graphicsResourcesService->GetTexture(0);
  texture->Init("container.jpg");

  float vertices[] = {
      // front face
      0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,// top right
      0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,// bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,0.0f, 0.0f,// bottom left
      -0.5f,  0.5f, 0.0f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,// top left
  };

  unsigned int indices[] = {  // note that we start from 0!
      // front face
      1, 2, 3,   // second Triangle
      0, 1, 3,  // first Triangle
  };

  auto buffer = graphicsResourcesService->GetBuffer(0);
  auto bufferElement = graphicsResourcesService->GetBuffer(1);
  auto vertexBuffer = graphicsResourcesService->GetVertexBuffer(0);


  vertexBuffer->Init();
  buffer->Init(Upgine::Graphics::Resources::Buffer::Type::kArrayBuffer);
  bufferElement->Init(Upgine::Graphics::Resources::Buffer::Type::kElementArrayBuffer);

  vertexBuffer->Execute();
  buffer->SetData(vertices, sizeof(vertices));
  bufferElement->SetData(indices, sizeof(indices));
  vertexBuffer->SetVertexAttribute();

  buffer->Remove();
  vertexBuffer->Remove();
}
void Application::Update() {

}

void Application::Shutdown() {

}
