cmake_minimum_required(VERSION 3.0)
project(startRenderer)

find_package(Eigen3)
INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})

file(GLOB SOURCES ./src/include/*.h ./src/source/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})