/*
MIT License

Copyright (c) 18/02/2023 Jose Manuel Gomez Castellana (josemgmz)

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

#ifndef INCLUDE_UPGINE_GRAPHICS_DRAW_DRAW_UNIFORM_MATRIX4_H
#define INCLUDE_UPGINE_GRAPHICS_DRAW_DRAW_UNIFORM_MATRIX4_H

#include "draw_uniform_base.h"
#include "upgine/core/types/math_types.h"

namespace Upgine::Graphics::Draw{
  class DrawUniformMatrix4 : public BDrawUniform
  {
  public:
    DrawUniformMatrix4() = default;
    ~DrawUniformMatrix4() override = default;

    void Execute() override;
    uint32 Size() override;

    void SetMatrix(Mat4 value);

  private:
    Mat4 matrix_;
  };
}

#endif //INCLUDE_UPGINE_GRAPHICS_DRAW_DRAW_UNIFORM_MATRIX4_H
