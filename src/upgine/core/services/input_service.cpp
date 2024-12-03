/*
MIT License

Copyright (c) 11/01/2023 Jose Manuel Gomez Castellana (josemgmz)

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
#include <vector>
#include <array>
#include <iostream>
#include "upgine/core/services/input_service.h"
#include "upgine/core/services/platform_service.h"
#include "glfw/glfw3.h"

void * internalData = nullptr;

struct Upgine::Core::Services::InputService::Data {
  GLFWwindow * context;
  std::vector<InputKey> inputKeyVector;
  std::vector<InputMouseButton> inputMouseVector;
  std::array<InputKeyState, KEY_KP_EQUAL + 1> inputKeyState;
  std::array<InputMouseButtonState, BUTTON_8 + 1> inputMouseButtonState;
  Vec2 mousePosition;
  Vec2 lastMousePosition;
  float mouseScroll;
};

void Upgine::Core::Services::InputService::OnConstructor() {
  data_ = new Data();

  for ( int key = InputKey::KEY_A; key != InputKey::KEY_KP_EQUAL + 1; key++ )
  {
    auto currentKey = static_cast<InputKey>(key);
    data_->inputKeyState[currentKey].action = InputAction::RELEASE;
    data_->inputKeyState[currentKey].key = currentKey;
  }

  for ( int button = InputMouseButton::BUTTON_1; button != InputMouseButton::BUTTON_8 + 1; button++ )
  {
    auto currentButton = static_cast<InputMouseButton>(button);
    data_->inputMouseButtonState[currentButton].action = InputAction::RELEASE;
    data_->inputMouseButtonState[currentButton].button = currentButton;
  }

  internalData = data_;
}

Upgine::Core::Services::InputService::~InputService() {
  delete data_;
  internalData = nullptr;
}

void Upgine::Core::Services::InputService::Init() {
  auto context = dependencyServiceManager_.GetPlatformService()->GetContext();
  data_->context = static_cast<GLFWwindow*>(context);

  auto keyCallback = [](GLFWwindow* window, int key, int scancode, int action, int mods)
  {
    auto data = static_cast<Data*>(internalData);
    auto currentKey = static_cast<InputKey>(key);
    auto currentAction = static_cast<InputAction>(action);
    data->inputKeyState[currentKey].action = currentAction;
    data->inputKeyState[currentKey].key = currentKey;
  };

  glfwSetKeyCallback(data_->context, keyCallback);

  auto mousePositionCallback = [](GLFWwindow* window, double xpos, double ypos)
  {
    auto data = static_cast<Data*>(internalData);
    data->mousePosition = Vec2(xpos, ypos);
  };

  auto mouseButtonCallback = [](GLFWwindow* window, int button, int action, int mods)
  {
    auto data = static_cast<Data*>(internalData);
    auto currentButton = static_cast<InputMouseButton>(button);
    auto currentAction = static_cast<InputAction>(action);
    data->inputMouseButtonState[currentButton].action = currentAction;
    data->inputMouseButtonState[currentButton].button = currentButton;
  };

  auto mouseScrollCallback = [](GLFWwindow* window, double xoffset, double yoffset)
  {
    auto data = static_cast<Data*>(internalData);
    data->mouseScroll = yoffset;
  };

  glfwSetInputMode(data_->context, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  glfwSetCursorPosCallback(data_->context, mousePositionCallback);
  glfwSetMouseButtonCallback( data_->context, mouseButtonCallback);
  glfwSetScrollCallback(data_->context, mouseScrollCallback);
}

void Upgine::Core::Services::InputService::Update() {
  if (glfwGetKey(data_->context, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(data_->context, true);

  for (auto &key : data_->inputKeyState)
  {
    if (key.action != InputAction::RELEASE) data_->inputKeyVector.push_back(key.key);
  }

  for (auto &button : data_->inputMouseButtonState)
  {
    if (button.action != InputAction::RELEASE) data_->inputMouseVector.push_back(button.button);
  }
}

void Upgine::Core::Services::InputService::Shutdown() {

}

void Upgine::Core::Services::InputService::PostUpdate() {
  data_->inputKeyVector.clear();
  data_->inputMouseVector.clear();
  data_->lastMousePosition = data_->mousePosition;
}

const std::vector<Upgine::Core::Services::InputService::InputKey> *Upgine::Core::Services::InputService::GetInputKeyVector() const {
  return &data_->inputKeyVector;
}

const std::vector<Upgine::Core::Services::InputService::InputMouseButton> *Upgine::Core::Services::InputService::GetInputMouseButtonVector() const {
  return &data_->inputMouseVector;
}

const float Upgine::Core::Services::InputService::GetMouseScroll() const {
  return data_->mouseScroll;
}

const Vec2 Upgine::Core::Services::InputService::GetLastMousePosition() const {
  return data_->lastMousePosition;
}
const Vec2 Upgine::Core::Services::InputService::GetMousePosition() const {
  return data_->mousePosition;
}