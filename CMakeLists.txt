cmake_minimum_required(VERSION 3.6)
project(GitterGas)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp Gitter.cpp Gitter.h Cell.cpp Cell.h Basis.cpp Basis.h Atom.cpp Atom.h MathParser.cpp MathParser.h)
add_executable(GitterGas ${SOURCE_FILES})