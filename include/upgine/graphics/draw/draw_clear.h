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

#ifndef INCLUDE_UPGINE_GRAPHICS_DRAW_DRAW_CLEAR_H_
#define INCLUDE_UPGINE_GRAPHICS_DRAW_DRAW_CLEAR_H_

#include "draw_command_interface.h"
namespace Upgine::Graphics::Draw{
  class DrawClear : public IDrawCommand
  {
   public:
    ~DrawClear() override = default;

    void Execute() override;
    uint32 Size() override;

    void SetClearColor(float r, float g, float b, float a);

   private:
    float clear_color_[4];
  };
}

#endif //INCLUDE_UPGINE_GRAPHICS_DRAW_DRAW_CLEAR_H_
