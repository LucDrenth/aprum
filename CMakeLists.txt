cmake_minimum_required(VERSION 3.20)
project(aprum)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/engine/vendor)
include_directories(src/engine)
add_executable(aprum src/application/Application.cpp src/engine/logger/Logger.cpp src/engine/logger/Logger.h src/engine/logger/LogLevel.cpp src/engine/logger/LogLevel.h src/engine/graphics/shader/Shader.cpp src/engine/graphics/shader/Shader.h src/engine/graphics/renderer/Renderer.cpp src/engine/graphics/renderer/Renderer.h src/engine/graphics/renderer/VertexBuffer.cpp src/engine/graphics/renderer/VertexBuffer.h src/engine/graphics/renderer/IndexBuffer.cpp src/engine/graphics/renderer/IndexBuffer.h src/application/Game.cpp src/application/Game.h src/engine/graphics/window/Window.cpp src/engine/graphics/window/Window.h src/engine/IGame.h src/engine/graphics/renderer/VertexArray.cpp src/engine/graphics/renderer/VertexArray.h src/engine/graphics/renderer/VertexBufferLayout.cpp src/engine/graphics/renderer/VertexBufferLayout.h src/engine/graphics/shader/ShaderProgram.cpp src/engine/graphics/shader/ShaderProgram.h src/engine/logger/GLErrorHandler.cpp src/engine/logger/GLErrorHandler.h src/engine/vendor/stb_image/stb_image.h src/engine/vendor/stb_image/stb_image.cpp src/engine/graphics/texture/Texture.cpp src/engine/graphics/texture/Texture.h src/engine/vendor/imgui/imgui_impl_glfw.cpp
        src/engine/vendor/imgui/imgui_impl_glfw.h src/engine/graphics/camera/Camera.cpp src/engine/graphics/camera/Camera.h src/engine/input/Input.cpp src/engine/input/Input.h)

# glfw
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(aprum glfw)
target_link_libraries(aprum ${GLFW_STATIC_LIBRARIES})

if (APPLE)
    target_link_libraries(aprum "-framework OpenGL")
endif()

#glew
find_package(GLEW REQUIRED)
target_link_libraries(aprum GLEW::GLEW)

#imgui
set(IMGUI_PATH  "src/engine/vendor/imgui")
file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp)
add_library("ImGui" STATIC ${IMGUI_SOURCES})
target_include_directories("ImGui" PUBLIC ${IMGUI_PATH})
target_link_libraries(aprum ImGui)
target_link_libraries(ImGui glfw)
