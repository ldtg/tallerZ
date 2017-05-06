cmake_minimum_required(VERSION 3.7)
project(tallerZ)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/model/main.cpp src/model/Movement.cpp src/model/Movement.h src/model/Map.cpp src/model/Map.h src/model/Position.cpp src/model/Position.h src/model/AStar.cpp src/model/AStar.h src/model/Node.cpp src/model/Node.h)
add_executable(tallerZ ${SOURCE_FILES})