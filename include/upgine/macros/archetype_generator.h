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

#ifndef INCLUDE_UPGINE_MACROS_ARCHETYPE_GENERATOR_H_
#define INCLUDE_UPGINE_MACROS_ARCHETYPE_GENERATOR_H_


#define ARCHETYPE_ADD_VARIABLE_32(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_31(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_31(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_30(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_30(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_29(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_29(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_28(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_28(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_27(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_27(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_26(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_26(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_25(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_25(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_24(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_24(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_23(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_23(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_22(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_22(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_21(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_21(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_20(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_20(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_19(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_19(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_18(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_18(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_17(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_17(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_16(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_16(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_15(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_15(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_14(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_14(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_13(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_13(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_12(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_12(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_11(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_11(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_10(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_10(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_9(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_9(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_8(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_8(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_7(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_7(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_6(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_6(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_5(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_5(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_4(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_4(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_3(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_3(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_2(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_2(x, y, ...) Upgine::ECS::Components::x y; ARCHETYPE_ADD_VARIABLE_1(__VA_ARGS__)
#define ARCHETYPE_ADD_VARIABLE_1(x, y) Upgine::ECS::Components::x y;

#define ARCHETYPE_ADD_VARIABLE(x, ...)  ARCHETYPE_ADD_VARIABLE_##x(__VA_ARGS__)

#define ARCHETYPE_GET_ID_FROM_VARIABLE_32(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_31(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_31(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_30(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_30(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_29(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_29(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_28(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_28(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_27(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_27(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_26(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_26(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_25(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_25(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_24(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_24(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_23(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_23(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_22(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_22(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_21(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_21(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_20(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_20(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_19(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_19(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_18(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_18(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_17(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_17(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_16(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_16(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_15(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_15(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_14(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_14(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_13(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_13(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_12(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_12(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_11(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_11(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_10(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_10(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_9(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_9(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_8(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_8(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_7(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_7(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_6(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_6(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_5(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_5(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_4(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_4(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_3(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_3(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_2(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_2(x, y, ...) Upgine::ECS::Components::x::GetId() + ARCHETYPE_GET_ID_FROM_VARIABLE_1(__VA_ARGS__)
#define ARCHETYPE_GET_ID_FROM_VARIABLE_1(x, y, ...) Upgine::ECS::Components::x::GetId();

#define ARCHETYPE_GET_ID_FROM_VARIABLE(x, ...)  ARCHETYPE_GET_ID_FROM_VARIABLE_##x(__VA_ARGS__)



#define CREATE_ARCHETYPE(ClassName, x, ...)                                                                         \
namespace Upgine::ECS::Archetypes{                                                                                  \
  class ClassName {                                                                                                 \
    public:                                                                                                         \
                                                                                                                    \
    ARCHETYPE_ADD_VARIABLE(x, __VA_ARGS__)                                                                          \
                                                                                                                    \
    static uint32 GetId() {                                                                                         \
        return ARCHETYPE_GET_ID_FROM_VARIABLE(x, __VA_ARGS__)                                                       \
    }                                                                                                               \
  };                                                                                                                \
}
#endif //INCLUDE_UPGINE_MACROS_ARCHETYPE_GENERATOR_H_
