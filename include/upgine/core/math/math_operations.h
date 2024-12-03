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

#ifndef INCLUDE_UPGINE_CORE_MATH_MATH_OPERATIONS_H
#define INCLUDE_UPGINE_CORE_MATH_MATH_OPERATIONS_H


#include "upgine/core/types/math_types.h"

class Math{
  public:
    static Mat4 Rotate(Mat4 const& m, float angle, Vec3 const& v)
    {
      return glm::rotate(m, angle, v);
    }

    static Mat4 Translate(Mat4 const& m, Vec3 const& v)
    {
      return glm::translate(m, v);
    }

    static Mat4 Scale(Mat4 const& m, Vec3 const& v)
    {
      return glm::scale(m, v);
    }

    static Mat4 Perspective(float fov, float aspect, float near, float far)
    {
      return glm::perspective(fov, aspect, near, far);
    }

    static Mat4 Orthographic(float left, float right, float bottom, float top, float near, float far)
    {
      return glm::ortho(left, right, bottom, top, near, far);
    }

    static Mat4 LookAt(Vec3 const& eye, Vec3 const& center, Vec3 const& up)
    {
      return glm::lookAt(eye, center, up);
    }

    static float ToRadians(float degrees)
    {
      return glm::radians(degrees);
    }

    static float ToDegrees(float radians)
    {
      return glm::degrees(radians);
    }

    static Vec3 Normalize(Vec3 const& v)
    {
      return glm::normalize(v);
    }

    static Vec3 Cross(Vec3 const& v1, Vec3 const& v2)
    {
      return glm::cross(v1, v2);
    }

    static float Dot(Vec3 const& v1, Vec3 const& v2)
    {
      return glm::dot(v1, v2);
    }

    static float Length(Vec3 const& v)
    {
      return glm::length(v);
    }

    static float Cos(const float angle)
    {
      return glm::cos(angle);
    }

    static float Sin(const float angle)
    {
      return glm::sin(angle);
    }

    static float Radians(const float angle)
    {
      return glm::radians(angle);
    }
};

#endif //INCLUDE_UPGINE_CORE_MATH_MATH_OPERATIONS_H
