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
#include "upgine/graphics/gpu/opengl_api.h"
#include <glad/glad.h>

void Upgine::Graphics::GPU::OpenglAPI::Init() {}

void Upgine::Graphics::GPU::OpenglAPI::Release() {}

void Upgine::Graphics::GPU::OpenglAPI::Clear(float color[4]) {
  glEnable(GL_DEPTH_TEST);
  glClearColor(color[0], color[1], color[2], color[3]);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Upgine::Graphics::GPU::OpenglAPI::Draw() {
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Upgine::Graphics::GPU::OpenglAPI::SetBackFaceCulling(bool enable) {
  if (enable) {
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
  } else {
    glDisable(GL_CULL_FACE);
  }
}

void Upgine::Graphics::GPU::OpenglAPI::SetFrontFaceCulling(bool enable) {
  if (enable) {
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
  } else {
    glDisable(GL_CULL_FACE);
  }
}

void Upgine::Graphics::GPU::OpenglAPI::SetDepthTest(bool enable) {
  if (enable) {
    glEnable(GL_DEPTH_TEST);
  } else {
    glDisable(GL_DEPTH_TEST);
  }
}
