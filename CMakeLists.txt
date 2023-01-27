cmake_minimum_required(VERSION 3.23)
project(Akinator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Akinator main.cpp Play/other.cpp Tree/tree.cpp Tree/node.cpp Play/akinator.cpp text.cpp Debug/debug.cpp Play/definitor.cpp Play/comparator.cpp)
