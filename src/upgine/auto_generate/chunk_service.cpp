//This file is generated automatically by archetypes_generator.py

#include "upgine/auto_generate/chunk_service.h"
#include "upgine/ecs/memory/memory_chunks.h"
#include "upgine/ecs/dto/component_dto.h"
#include "upgine/ecs/archetypes/archetypes_declaration.h"

using namespace Upgine::ECS;
using namespace Upgine::ECS::Memory;

struct Upgine::Core::Services::ChunkService::Data {
  Chunks<Chunk<Archetypes::T>> T;
  Chunks<Chunk<Archetypes::TR>> TR;
};

Upgine::Core::Services::ChunkService::ChunkService() {
  data_ = new Data();
}

Upgine::Core::Services::ChunkService::~ChunkService() {
  delete data_;
}

void Upgine::Core::Services::ChunkService::Init() {
}

void Upgine::Core::Services::ChunkService::Update() {
}

void Upgine::Core::Services::ChunkService::Shutdown() {
}

template<> Archetypes::T *Upgine::Core::Services::ChunkService::Get<Archetypes::T>(uint32 chunkId, uint32 slotId) {
  return data_->T.Get<Upgine::ECS::Archetypes::T>(chunkId, slotId);
}

template<> Archetypes::TR *Upgine::Core::Services::ChunkService::Get<Archetypes::TR>(uint32 chunkId, uint32 slotId) {
  return data_->TR.Get<Upgine::ECS::Archetypes::TR>(chunkId, slotId);
}

template<> Upgine::ECS::Entities::Entity Upgine::Core::Services::ChunkService::Add<Archetypes::T>() {
  return data_->T.Add<Upgine::ECS::Archetypes::T>();
}

template<> Upgine::ECS::Entities::Entity Upgine::Core::Services::ChunkService::Add<Archetypes::TR>() {
  return data_->TR.Add<Upgine::ECS::Archetypes::TR>();
}

template<> bool Upgine::Core::Services::ChunkService::Remove<Archetypes::T>(uint32 chunkId, uint32 slotId) {
  return data_->T.Remove<Upgine::ECS::Archetypes::T>(chunkId, slotId);
}

template<> bool Upgine::Core::Services::ChunkService::Remove<Archetypes::TR>(uint32 chunkId, uint32 slotId) {
  return data_->TR.Remove<Upgine::ECS::Archetypes::TR>(chunkId, slotId);
}

template<> Chunk<Archetypes::T> *Upgine::Core::Services::ChunkService::Get<Chunk<Archetypes::T>>(uint32 chunkId) {
  return data_->T.Get(chunkId);
}

template<> Chunk<Archetypes::TR> *Upgine::Core::Services::ChunkService::Get<Chunk<Archetypes::TR>>(uint32 chunkId) {
  return data_->TR.Get(chunkId);
}

template<> uint32 Upgine::Core::Services::ChunkService::UsedChunks<Chunk<Archetypes::T>>() {
  return data_->T.UsedChunks();
}

template<> uint32 Upgine::Core::Services::ChunkService::UsedChunks<Chunk<Archetypes::TR>>() {
  return data_->TR.UsedChunks();
}

template<> std::vector<Upgine::ECS::DTO::ComponentDTO> Upgine::Core::Services::ChunkService::GetComponents<Upgine::ECS::Components::Transform>() {
    std::vector<Upgine::ECS::DTO::ComponentDTO> components;
    for (uint32 i = 0; i < data_->TR.UsedChunks(); ++i) {
        auto chunk = data_->TR.Get(i);
        for (uint32 j = 0; j < chunk->GetSize(); ++j) {
          Archetypes::TR * archetype = chunk->Get(j);
          Upgine::ECS::DTO::ComponentDTO componentDTO;
          componentDTO.component = &archetype->transform;
          componentDTO.archetypeId = Archetypes::TR::GetId();
          componentDTO.entityId = j;
          components.push_back(componentDTO);
        }
    }

    for (uint32 i = 0; i < data_->T.UsedChunks(); ++i) {
        auto chunk = data_->T.Get(i);
        for (uint32 j = 0; j < chunk->GetSize(); ++j) {
          Archetypes::T * archetype = chunk->Get(j);
          Upgine::ECS::DTO::ComponentDTO componentDTO;
          componentDTO.component = &archetype->transform;
          componentDTO.archetypeId = Archetypes::T::GetId();
          componentDTO.entityId = j;
          components.push_back(componentDTO);
        }
    }

    return components;
}

template<> std::vector<Upgine::ECS::DTO::ComponentDTO> Upgine::Core::Services::ChunkService::GetComponents<Upgine::ECS::Components::Renderer>() {
    std::vector<Upgine::ECS::DTO::ComponentDTO> components;
    for (uint32 i = 0; i < data_->TR.UsedChunks(); ++i) {
        auto chunk = data_->TR.Get(i);
        for (uint32 j = 0; j < chunk->GetSize(); ++j) {
          Archetypes::TR * archetype = chunk->Get(j);
          Upgine::ECS::DTO::ComponentDTO componentDTO;
          componentDTO.component = &archetype->renderer;
          componentDTO.archetypeId = Archetypes::TR::GetId();
          componentDTO.entityId = j;
          components.push_back(componentDTO);
        }
    }

    return components;
}

