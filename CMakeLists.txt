cmake_minimum_required(VERSION 3.20)
project(aprum)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
add_executable(aprum src/Application.cpp src/logger/Logger.cpp src/logger/Logger.h src/logger/LogLevel.cpp src/logger/LogLevel.h src/shader/Shader.cpp src/shader/Shader.h)

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