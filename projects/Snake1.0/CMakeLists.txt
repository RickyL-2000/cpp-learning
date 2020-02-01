cmake_minimum_required(VERSION 3.10)

project(Snake1.0)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SNAKE_SOURCE ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB SNAKE_HEADER ${PROJECT_SOURCE_DIR}/include/*.h)
add_executable(snake ${PROJECT_SOURCE_DIR}/main.cpp ${SNAKE_SOURCE} ${SNAKE_HEADER})