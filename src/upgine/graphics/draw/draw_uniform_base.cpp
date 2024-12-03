/*
MIT License

Copyright (c) 22/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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
#include "upgine/graphics/draw/draw_uniform_base.h"
#include <stdexcept>
#include <cstring>

Upgine::Graphics::Draw::BDrawUniform::BDrawUniform() {
  for(int x = 0; x < 8; x++) name_[x] = '\0';
}

void Upgine::Graphics::Draw::BDrawUniform::SetMaterial(Resources::Material *material) {
  material_ = material;
}

void Upgine::Graphics::Draw::BDrawUniform::SetName(const char * name) {
    //Validate if the name is not bigger than 15 characters, 16 char saved for the null terminator
    auto size = strlen(name);
    if(size >= Upgine::Graphics::Resources::MAX_CHAR_NAME) throw std::runtime_error("The name of the uniform is bigger than 16 characters");
    for(int x = 0; x < size; x++) name_[x] = name[x];
}

