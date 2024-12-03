/*
MIT License

Copyright (c) 03/02/2023 Jose Manuel Gomez Castellana (josemgmz)

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
#include <valarray>
#include "upgine/ecs/systems/renderer_system.h"
#include "upgine/auto_generate/chunk_service.h"
#include "upgine/core/services/graphics_resources_service.h"
#include "upgine/core/services/draw_service.h"
#include "upgine/ecs/components/renderer_component.h"
#include "upgine/ecs/dto/component_dto.h"
#include "upgine/graphics/draw/draw_element.h"
#include "upgine/graphics/draw/draw_material.h"
#include "upgine/graphics/draw/draw_uniform_texture.h"
#include "upgine/graphics/draw/draw_uniform_float.h"
#include "glad/glad.h"

void Upgine::ECS::Systems::RendererSystem::Update() {
    auto chunkService = dependencyServiceManager_.GetChunkService();
    auto chunk = chunkService->GetComponents<Upgine::ECS::Components::Renderer>();
    auto graphicsResourcesService = dependencyServiceManager_.GetGraphicsResourcesService();
    auto drawService = dependencyServiceManager_.GetDrawService();

    for (auto rendererDTO: chunk) {
        //Get the graphics resources
        auto renderer = static_cast<Components::Renderer*>(rendererDTO.component);
        auto material = graphicsResourcesService->GetMaterial(renderer->materialId);
        auto vertexBuffer = graphicsResourcesService->GetVertexBuffer(renderer->vertexBufferId);
        std::vector<Graphics::Resources::Texture*> textures;

        for(int x = 0; x < Graphics::Resources::MAX_TEXTURES; x++) {
            if(renderer->textureIds[x] != UINT32_MAX) {
              textures.push_back(graphicsResourcesService->GetTexture(renderer->textureIds[x]));
            }
        }

        //Create the draw elements
        Upgine::Graphics::Draw::DrawMaterial drawMaterial;
        drawMaterial.SetMaterial(material);
        drawService->InsertAt(&drawMaterial, rendererDTO.archetypeId, rendererDTO.entityId, 0);

        for(int x = 0; x < textures.size(); x++) {
          Upgine::Graphics::Draw::DrawUniformTexture drawUniformTexture;
          drawUniformTexture.SetTexture(textures[x], x);
          drawUniformTexture.SetMaterial(material);
          char charIndex;
          itoa(x + 1, &charIndex, 10);
          char name[9] = { 't', 'e', 'x', 't', 'u', 'r', 'e', charIndex,'\0' };
          drawUniformTexture.SetName(name);
          drawService->Insert(&drawUniformTexture, rendererDTO.archetypeId, rendererDTO.entityId);
        }

        Upgine::Graphics::Draw::DrawElement drawElement;
        drawElement.SetVertexBuffer(vertexBuffer);
        drawService->Insert(&drawElement, rendererDTO.archetypeId, rendererDTO.entityId);
    }
}

int Upgine::ECS::Systems::RendererSystem::GetPriority() const {
    return 0;
}

