/*
MIT License

Copyright (c) 13/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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

#include "upgine/graphics/resources/shader.h"
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

uint32 Upgine::Graphics::Resources::Shader::GetId() const {
  return id_;
}

void Upgine::Graphics::Resources::Shader::Execute() {

}

void Upgine::Graphics::Resources::Shader::Release() {
    glDeleteShader(id_);
}

void Upgine::Graphics::Resources::Shader::Init(const char *source, Upgine::Graphics::Resources::Shader::Type type) {
  std::string code;
  std::ifstream file;

  try {
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    file.open(source);
    std::stringstream fileStream;
    fileStream << file.rdbuf();
    file.close();
    code = fileStream.str();
    shaderSourceCode_ = const_cast<char *>(code.c_str());
    type_ = type;
  }
  catch (std::ifstream::failure e){
    throw std::runtime_error("FILE_NOT_SUCCESFULLY_READ");
  }

  auto shaderType = type_ == Type::kTypeVertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;
  id_ = glCreateShader(shaderType);
  glShaderSource(id_, 1, &shaderSourceCode_, NULL);
  glCompileShader(id_);
  int success;
  char infoLog[512];
  glGetShaderiv(id_, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(id_, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
}
