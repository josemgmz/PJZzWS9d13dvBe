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

#ifndef INCLUDE_UPGINE_OBJECTS_CAMERA_OBJECT_H
#define INCLUDE_UPGINE_OBJECTS_CAMERA_OBJECT_H

#include "upgine/core/services/camera_service.h"
#include "upgine/core/services/time_service.h"
#include "upgine/ecs/archetypes/archetypes_declaration.h"
#include "upgine/core/math/math_operations.h"
#include "upgine/core/services/input_service.h"
#include "game_object.h"
#include "glfw/glfw3.h"

namespace Upgine::Objects
{
  class CameraObject : public GameObject<Upgine::ECS::Archetypes::T>
  {
  public:
    CameraObject() : GameObject<Upgine::ECS::Archetypes::T>() {
      GetServiceManager().GetCameraService()->AddCamera(this);
    };

    ~CameraObject() override{
      GetServiceManager().GetCameraService()->RemoveCamera(this);
    }

    void SetProjectionPerspective(const float radians,
                                  const float aspect_ratio,
                                  const float near_plane,
                                  const float far_plane)
    {
      projection_ = Math::Perspective(radians, aspect_ratio, near_plane, far_plane);
    }

    void SetProjectionOrthographic(const float left,
                                   const float right,
                                   const float bottom,
                                   const float top,
                                   const float near_plane,
                                   const float far_plane)
    {
      projection_ = Math::Orthographic(left, right, bottom, top, near_plane, far_plane);
    }

    Mat4 GetProjection() const{
      return projection_;
    }

    Mat4 GetView(){
      return view_;
    }

    void SetView(Mat4 value){ view_ = value; }

    void SetLookAt(Vec3 eye, Vec3 center, Vec3 up){
      position_ = eye;
      up_ = up;
      front_ = Vec3(0.0f, 0.0f, 1.0f);
      worldUp_ = up;
      yaw_ = -90.0f;
      pitch_ = 0.0f;
      zoom_ = 45.0f;
      view_ = Math::LookAt(eye, center, up);
    }

    void Update()  {
      auto inputKeyVector = *GetServiceManager().GetInputService()->GetInputKeyVector();
      auto inputMouseButton = *GetServiceManager().GetInputService()->GetInputMouseButtonVector();
      auto inputMousePosition = GetServiceManager().GetInputService()->GetMousePosition();
      auto inputLastMousePosition = GetServiceManager().GetInputService()->GetLastMousePosition();


      //view_ = Math::LookAt(position_, position_ + front_ , up_);
      const float radius = 10.0f;
      float camX = sin(glfwGetTime()) * radius;
      float camZ = cos(glfwGetTime()) * radius;
      view_ = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));

    };

  private:

    Mat4 projection_;
    Mat4 view_;

    Vec3 position_;
    Vec3 front_;
    Vec3 up_;
    Vec3 right_;
    Vec3 worldUp_;

    float yaw_ = -90.0f;
    float pitch_ = 0.0f ;

    float movementSpeed_;
    float mouseSensitivity_;
    float zoom_;
  };
}

#endif //INCLUDE_UPGINE_OBJECTS_CAMERA_OBJECT_H
