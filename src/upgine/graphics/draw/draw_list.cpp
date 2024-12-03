/*
MIT License

Copyright (c) 17/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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
#include "upgine/graphics/draw/draw_list.h"

//In order to avoid branching and memory allocation, we will use a single buffer to store all the draw commands
//even if they are of different types. This will allow us to iterate over the buffer and execute the commands faster.

Upgine::Graphics::Draw::DrawList::~DrawList() {

}

void Upgine::Graphics::Draw::DrawList::OnConstructor() {
  size_ = 0;
}

void Upgine::Graphics::Draw::DrawList::Execute() {
  uint32 offset = 0;
  for(int x = 0; x < size_; x++){
    uint8_t* ptr = drawCommands_.data() + offset;
    auto result = reinterpret_cast<IDrawCommand*>(ptr);
    result->Execute();
    offset += result->Size();
  }
}

void Upgine::Graphics::Draw::DrawList::InsertCommand(Upgine::Graphics::Draw::IDrawCommand *command) {
  auto size = command->Size();
  auto *ptr = reinterpret_cast<uint8_t*>(command);
  drawCommands_.insert(drawCommands_.end(), ptr, ptr + size);
  size_++;
}



void Upgine::Graphics::Draw::DrawList::InsertCommandAt(Upgine::Graphics::Draw::IDrawCommand *command, uint32 position) {
  auto size = command->Size();
  auto *ptr = reinterpret_cast<uint8_t*>(command);
  drawCommands_.insert(drawCommands_.end(), ptr, ptr + size);
  size_++;
}


