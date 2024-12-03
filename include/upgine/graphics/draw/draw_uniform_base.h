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

#ifndef INCLUDE_UPGINE_GRAPHICS_DRAW_DRAW_UNIFORM_BASE_H_
#define INCLUDE_UPGINE_GRAPHICS_DRAW_DRAW_UNIFORM_BASE_H_


#include "draw_command_interface.h"
#include "upgine/graphics/resources/constants.h"
#include <string>

namespace Upgine::Graphics::Resources {
class Material;
}

namespace Upgine::Graphics::Draw{
  class BDrawUniform : public IDrawCommand
  {
   public:
    BDrawUniform();
    ~BDrawUniform() override = default;

    void SetMaterial(Resources::Material * material);
    void SetName(const char * name);

   protected:
    char name_[Upgine::Graphics::Resources::MAX_CHAR_NAME];
    Resources::Material * material_;
  };
}
#endif //INCLUDE_UPGINE_GRAPHICS_DRAW_DRAW_UNIFORM_BASE_H_
