/*
MIT License

Copyright (c) 21/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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
#include <stdexcept>
#include "upgine/core/services/draw_service.h"
#include "upgine/graphics/draw/draw_list.h"
#include "upgine/core/managers/gpu_manager.h"
#include "upgine/core/services/dto/draw_service_dto.h"
#include "upgine/graphics/draw/draw_clear.h"

struct Upgine::Core::Services::DrawService::Data {
  std::vector<Upgine::Graphics::Draw::DrawList> data;
  std::vector<Upgine::Core::Services::DTO::DrawServiceDTO> internalData;
};


Upgine::Core::Services::DrawService::DrawService() {
  data_ = new Data();
}

Upgine::Core::Services::DrawService::~DrawService() {
  delete data_;
}

void Upgine::Core::Services::DrawService::Init() {
  Upgine::Core::Managers::GPUManager::Init();
}

void Upgine::Core::Services::DrawService::Update() {

  Upgine::Core::Managers::GPUManager::SetBackFaceCulling(true);
  Upgine::Core::Managers::GPUManager::SetDepthTest(true);
  //merge the data from internalData to data
  data_->data.push_back(Upgine::Graphics::Draw::DrawList());
  Upgine::Graphics::Draw::DrawClear drawClear;
  drawClear.SetClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  data_->data.back().InsertCommand(&drawClear);

  for (auto & internalData : data_->internalData) {
    for (auto & internalDrawList : internalData.drawLists){
      data_->data.push_back(internalDrawList);
    }
  }

  for (auto & drawList : data_->data) {
      drawList.Execute();
  }

  data_->data.clear();
  data_->internalData.clear();
}

void Upgine::Core::Services::DrawService::Shutdown() {

}

void Upgine::Core::Services::DrawService::Insert(
  Upgine::Graphics::Draw::IDrawCommand *drawCommand,
  uint32_t archetypeId,
  uint32_t entityId) {

  //Find in internal data if the archetypeId is already in the list
  auto it = std::ranges::find_if(data_->internalData.begin(), data_->internalData.end(),
    [archetypeId](const Upgine::Core::Services::DTO::DrawServiceDTO &dto) {
     return dto.archetypeId == archetypeId;
    });

  auto foundArchetype = it != data_->internalData.end();

  if(foundArchetype){
    //check if entity id is already in the list
    if(it->drawLists.size() > entityId){
      //if it is, add the draw command to the list
      it->drawLists[entityId].InsertCommand(drawCommand);
    } else {
      //if it is not, create a new list and add the draw command to it
      it->drawLists.push_back(Upgine::Graphics::Draw::DrawList());
      it->drawLists.back().InsertCommand(drawCommand);
    }
    return;
  }

  CreateDTO(drawCommand, archetypeId);
}

void Upgine::Core::Services::DrawService::InsertAt(
  Upgine::Graphics::Draw::IDrawCommand *drawCommand,
  uint32_t archetypeId,
  uint32_t entityId,
  uint32_t position) {

  auto it = std::ranges::find_if(data_->internalData.begin(), data_->internalData.end(),
   [archetypeId](const Upgine::Core::Services::DTO::DrawServiceDTO &dto) {
     return dto.archetypeId == archetypeId;
   });

  auto foundArchetype = it != data_->internalData.end();
  if(foundArchetype){

    if(it->drawLists.size() > entityId){
      //if it is, add the draw command to the list
      it->drawLists[entityId].InsertCommandAt(drawCommand, position);
    } else {
      //if it is not, create a new list and add the draw command to it
      it->drawLists.push_back(Upgine::Graphics::Draw::DrawList());
      it->drawLists.back().InsertCommand(drawCommand);
    }
    return;
  }

  CreateDTO(drawCommand, archetypeId);
}

void Upgine::Core::Services::DrawService::CreateDTO(
    Upgine::Graphics::Draw::IDrawCommand *drawCommand,
    uint32_t archetypeId) {

  Upgine::Core::Services::DTO::DrawServiceDTO dto;
  dto.archetypeId = archetypeId;
  dto.drawLists.push_back(Upgine::Graphics::Draw::DrawList());
  dto.drawLists.back().InsertCommand(drawCommand);
  data_->internalData.push_back(dto);
}

