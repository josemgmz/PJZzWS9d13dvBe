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
#include "upgine/ecs/systems/transform_system.h"
#include "upgine/auto_generate/chunk_service.h"
#include "upgine/ecs/components/transform_component.h"
#include "upgine/ecs/dto/component_dto.h"
#include "glfw/glfw3.h"
#include "upgine/graphics/draw/draw_uniform_matrix4.h"
#include "upgine/core/services/draw_service.h"
#include "upgine/core/services/camera_service.h"
#include "upgine/core/services/graphics_resources_service.h"
#include "upgine/objects/camera_object.h"

void Upgine::ECS::Systems::TransformSystem::Update() {
    auto drawService = dependencyServiceManager_.GetDrawService();
    auto chunkService = dependencyServiceManager_.GetChunkService();
    auto chunk = chunkService->GetComponents<Upgine::ECS::Components::Transform>();
    auto graphicsResourcesService = dependencyServiceManager_.GetGraphicsResourcesService();
    auto camerasService = dependencyServiceManager_.GetCameraService();
    auto mainCamera = camerasService->GetCameras()->front();

    for (auto transformDTO: chunk) {
        auto transform = static_cast<Components::Transform*>(transformDTO.component);
        auto material = graphicsResourcesService->GetMaterial(transform->materialId);

        Upgine::Graphics::Draw::DrawUniformMatrix4 drawUniformMatrix4;
        drawUniformMatrix4.SetMatrix( transform->model );
        drawUniformMatrix4.SetName("model");
        drawUniformMatrix4.SetMaterial(material);
        drawService->Insert(&drawUniformMatrix4, transformDTO.archetypeId, transformDTO.entityId);

        Upgine::Graphics::Draw::DrawUniformMatrix4 drawUniformMatrix4View;
        drawUniformMatrix4View.SetMatrix(mainCamera->GetView());
        drawUniformMatrix4View.SetName("view");
        drawUniformMatrix4View.SetMaterial(material);
        drawService->Insert(&drawUniformMatrix4View, transformDTO.archetypeId, transformDTO.entityId);

        Upgine::Graphics::Draw::DrawUniformMatrix4 drawUniformMatrix4Projection;
        drawUniformMatrix4Projection.SetMatrix(mainCamera->GetProjection());
        drawUniformMatrix4Projection.SetName("projection");
        drawUniformMatrix4Projection.SetMaterial(material);
        drawService->Insert(&drawUniformMatrix4Projection, transformDTO.archetypeId, transformDTO.entityId);
    }
}

int Upgine::ECS::Systems::TransformSystem::GetPriority() const {
    return 1;
}

