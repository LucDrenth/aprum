cmake_minimum_required(VERSION 3.20)
project(aprum)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
add_executable(aprum src/Application.cpp src/engine/logger/Logger.cpp src/engine/logger/Logger.h src/engine/logger/LogLevel.cpp src/engine/logger/LogLevel.h src/engine/graphics/shader/Shader.cpp src/engine/graphics/shader/Shader.h src/engine/graphics/renderer/Renderer.cpp src/engine/graphics/renderer/Renderer.h src/engine/graphics/renderer/VertexBuffer.cpp src/engine/graphics/renderer/VertexBuffer.h src/engine/graphics/renderer/IndexBuffer.cpp src/engine/graphics/renderer/IndexBuffer.h)

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