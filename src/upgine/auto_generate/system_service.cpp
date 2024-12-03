//This file is generated automatically by system_service_generator.py

#include "upgine/core/services/service_interface.h"
#include "upgine/ecs/components/renderer_component.h"
#include "upgine/ecs/components/transform_component.h"

#include "upgine/ecs/systems/renderer_system.h"
#include "upgine/ecs/systems/transform_system.h"
#include <vector>
#include <algorithm>
#include "upgine/auto_generate/system_service.h"

struct Upgine::Core::Services::SystemService::Data {
  Upgine::ECS::Systems::RendererSystem renderer;
  Upgine::ECS::Systems::TransformSystem transform;
  std::vector<Upgine::ECS::Systems::ISystem*> sortedSystems;
};

Upgine::Core::Services::SystemService::SystemService() {
  data_ = new Data();
}

Upgine::Core::Services::SystemService::~SystemService() {
  delete data_;
}

void Upgine::Core::Services::SystemService::Init() {
  data_->sortedSystems.push_back(&data_->renderer);
  data_->sortedSystems.push_back(&data_->transform);
  std::sort(data_->sortedSystems.begin(), data_->sortedSystems.end(), [](const ECS::Systems::ISystem* a, const ECS::Systems::ISystem* b) {
    return a->GetPriority() > b->GetPriority();
  });
}

void Upgine::Core::Services::SystemService::Update() {
  for (auto system : data_->sortedSystems) {
    system->Update();
  }
}

void Upgine::Core::Services::SystemService::Shutdown() {
  data_->sortedSystems.clear();
}

