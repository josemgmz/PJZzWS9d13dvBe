/*
MIT License

Copyright (c) 14/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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

#ifndef INCLUDE_UPGINE_GRAPHICS_GPU_GPU_INTERFACE_H_
#define INCLUDE_UPGINE_GRAPHICS_GPU_GPU_INTERFACE_H_

namespace Upgine::Graphics::GPU
{
  class IGPU
  {
  public:
    IGPU() = default;
    virtual ~IGPU() = default;

    virtual void Init() = 0;
    virtual void Release() = 0;

    virtual void Clear(float color[4]) = 0;
    virtual void Draw() = 0;

    virtual void SetBackFaceCulling(bool enable) = 0;
    virtual void SetFrontFaceCulling(bool enable) = 0;
    virtual void SetDepthTest(bool enable) = 0;

  };
}

#endif // INCLUDE_UPGINE_GRAPHICS_GPU_GPU_INTERFACE_H_
