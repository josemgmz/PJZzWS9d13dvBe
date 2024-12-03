#include "upgine/core/services/window_service.h"
#include "upgine/core/services/platform_service.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

// Define data structure
struct Upgine::Core::Services::WindowService::Data {
  GLFWwindow * context;
  uint32 width = UINT32_MAX;
  uint32 height = UINT32_MAX;
};

// Define function callback
void OnResizeEvent(GLFWwindow * window, int width, int height){
  glViewport(0, 0, width, height);
}

void Upgine::Core::Services::WindowService::OnConstructor() {
  data_ = new Data;
}

Upgine::Core::Services::WindowService::~WindowService() {
  delete data_;
}

void Upgine::Core::Services::WindowService::Init() {
  auto context = GetServiceManager().GetPlatformService()->GetContext();
  data_->context = static_cast<GLFWwindow*>(context);
    if (data_->context == NULL)
    {
      glfwTerminate();
      throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(data_->context);
    glfwSetFramebufferSizeCallback(data_->context, OnResizeEvent);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      throw std::runtime_error("Failed to initialize GLAD");
    }
}

void Upgine::Core::Services::WindowService::Update() {
  ProcessInput();
  //Do the magichere
  glfwSwapBuffers(data_->context);
}

void Upgine::Core::Services::WindowService::Shutdown() {
}

void Upgine::Core::Services::WindowService::SetSize(uint32 width, uint32 height) {
  data_->width = width;
  data_->height = height;
}

void Upgine::Core::Services::WindowService::ProcessInput() {
}

bool Upgine::Core::Services::WindowService::IsOpen() const {
  return !glfwWindowShouldClose(data_->context);
}

uint32 Upgine::Core::Services::WindowService::GetWidth() const {
  return data_->width;
}

uint32 Upgine::Core::Services::WindowService::GetHeight() const {
  return data_->height;
}
