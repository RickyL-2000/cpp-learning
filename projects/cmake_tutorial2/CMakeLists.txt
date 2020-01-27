project(hello)
# set(SRC_LIST hello.cpp add.cpp sub.cpp)
set(SRC_LIST hello.cpp)

# output build list
message(STATUS "This is HELLO_BINARY_DIR " ${HELLO_BINARY_DIR})
# output src list
message(STATUS "This is HELLO_SOURCE_DIR " ${HELLO_SOURCE_DIR})
# output src list
message(STATUS "This is PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
# output CMake src list
message(STATUS "This is CMAKE_SOURCE_DIR " ${CMAKE_SOURCE_DIR})
# generate executable, ${SRC_LIST} is var, the src file
add_executable(hello ${SRC_LIST})