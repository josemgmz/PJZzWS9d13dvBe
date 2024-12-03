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

#include "upgine/graphics/resources/material.h"
#include "upgine/graphics/resources/shader.h"
#include "upgine/graphics/resources/texture.h"
#include <glad/glad.h>
#include <iostream>

uint32 Upgine::Graphics::Resources::Material::GetId() const {
  return id_;
}

void Upgine::Graphics::Resources::Material::Execute() {
  glUseProgram(id_);
}

void Upgine::Graphics::Resources::Material::Release() {
    glDeleteProgram(id_);
}

void Upgine::Graphics::Resources::Material::Init(
    Upgine::Graphics::Resources::Shader *vertex,
    Upgine::Graphics::Resources::Shader *fragment) {
  id_ = glCreateProgram();
  glAttachShader(id_, vertex->GetId());
  glAttachShader(id_, fragment->GetId());
  glLinkProgram(id_);
  // check for linking errors
  int success;
  char infoLog[512];
  glGetProgramiv(id_, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(id_, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
  }

  vertex->Release();
  fragment->Release();
}

void Upgine::Graphics::Resources::Material::SetBool(const char *name, bool value) const {
  glUniform1i(glGetUniformLocation(id_, name), (int) value);
}

void Upgine::Graphics::Resources::Material::SetInt(const char *name, int value) const {
  glUniform1i(glGetUniformLocation(id_, name), value);
}

void Upgine::Graphics::Resources::Material::SetFloat(const char *name, float value) const {
  glUniform1f(glGetUniformLocation(id_, name), value);
}
void Upgine::Graphics::Resources::Material::SetTexture(const char *name, uint32 id) const {
  SetInt(name, id);
}

void Upgine::Graphics::Resources::Material::SetMatrix4(const char *name, const Mat4 *value) const {
  glUniformMatrix4fv(glGetUniformLocation(id_, name), 1, GL_FALSE, glm::value_ptr(*value));
}