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
#ifndef INCLUDE_UPGINE_CORE_SERVICES_INPUT_SERVICE_H_
#define INCLUDE_UPGINE_CORE_SERVICES_INPUT_SERVICE_H_

#include "service_interface.h"
#include "upgine/macros/dependency_injector.h"
#include "upgine/core/managers/services_manager.h"
#include "upgine/core/observer/observer.h"
#include "upgine/memory/smart_pointer/reference.h"
#include "upgine/core/types/math_types.h"
#include <vector>

namespace Upgine::Core::Services {
class InputService : public IService, public Upgine::Memory::SmartPointer::Reference
  {
   public:
    enum InputType
    {
      KEYBOARD,
      MOUSE,
      GAMEPAD
    };

    enum InputAction
    {
      RELEASE = 0,
      PRESS,
      REPEAT
    };

    enum InputKey {
      KEY_A = 65,
      KEY_B,
      KEY_C,
      KEY_D,
      KEY_E,
      KEY_F,
      KEY_G,
      KEY_H,
      KEY_I,
      KEY_J,
      KEY_K,
      KEY_L,
      KEY_M,
      KEY_N,
      KEY_O,
      KEY_P,
      KEY_Q,
      KEY_R,
      KEY_S,
      KEY_T,
      KEY_U,
      KEY_V,
      KEY_W,
      KEY_X,
      KEY_Y,
      KEY_Z,
      KEY_LEFT_BRACKET = 91,
      KEY_BACKSLASH,
      KEY_RIGHT_BRACKET,
      KEY_GRAVE_ACCENT = 96,
      KEY_ESCAPE = 256,
      KEY_ENTER,
      KEY_TAB,
      KEY_BACKSPACE,
      KEY_INSERT,
      KEY_DELETE,
      KEY_RIGHT_ARROW = 262,
      KEY_LEFT_ARROW,
      KEY_DOWN_ARROW,
      KEY_UP_ARROW,
      KEY_PAGE_UP,
      KEY_PAGE_DOWN,
      KEY_HOME,
      KEY_END,
      KEY_CAPS_LOCK = 280,
      KEY_SCROLL_LOCK,
      KEY_NUM_LOCK,
      KEY_PRINT_SCREEN,
      KEY_PAUSE,
      KEY_F1 = 290,
      KEY_F2,
      KEY_F3,
      KEY_F4,
      KEY_F5,
      KEY_F6,
      KEY_F7,
      KEY_F8,
      KEY_F9,
      KEY_F10,
      KEY_F11,
      KEY_F12,
      KEY_KP_0 = 320,
      KEY_KP_1,
      KEY_KP_2,
      KEY_KP_3,
      KEY_KP_4,
      KEY_KP_5,
      KEY_KP_6,
      KEY_KP_7,
      KEY_KP_8,
      KEY_KP_9,
      KEY_KP_DECIMAL,
      KEY_KP_DIVIDE,
      KEY_KP_MULTIPLY,
      KEY_KP_SUBTRACT,
      KEY_KP_ADD,
      KEY_KP_ENTER,
      KEY_KP_EQUAL,
    };

    struct InputKeyState{
      InputAction action;
      InputKey key;
    };

    enum InputMouseButton {
      BUTTON_1 = 0,
      BUTTON_2,
      BUTTON_3,
      BUTTON_4,
      BUTTON_5,
      BUTTON_6,
      BUTTON_7,
      BUTTON_8,
      BUTTON_LAST = BUTTON_8,
      BUTTON_LEFT = BUTTON_1,
      BUTTON_RIGHT = BUTTON_2,
      BUTTON_MIDDLE = BUTTON_3
    };

    struct InputMouseButtonState {
      InputAction action;
      InputMouseButton button;
    };

    INJECT_SERVICES_CONSTRUCTOR(InputService)
    ~InputService() override;

    // IService overrides
    void Init() override;
    void Update() override;
    void Shutdown() override;
    void PostUpdate();

    const std::vector<InputKey> * GetInputKeyVector() const;
    const std::vector<InputMouseButton> * GetInputMouseButtonVector() const;
    const Vec2 GetMousePosition() const;
    const Vec2 GetLastMousePosition() const;
    const float GetMouseScroll() const;

  private:
    struct Data;
    Data *data_;



  };
}

#endif // INCLUDE_UPGINE_CORE_SERVICES_INPUT_SERVICE_H_
