cmake_minimum_required(VERSION 3.10)
project(2048)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB PROJ_SOURCE ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB PROJ_HEADER ${PROJECT_SOURCE_DIR}/include/*.h)
set(PROJ_MAIN ${PROJECT_SOURCE_DIR}/main.cpp)

add_executable(2048 ${PROJ_MAIN} ${PROJ_SOURCE} ${PROJ_HEADER})