cmake_minimum_required(VERSION 3.24)
project(Azmir)

set(CMAKE_CXX_STANDARD 17)

add_executable(Azmir main.cpp class/ColumnarTransposition.cpp class/ColumnarTransposition.h class/RailFenceCipher.cpp class/RailFenceCipher.h class/Myszkowski.cpp class/Myszkowski.h class/TranspositionCipher.cpp class/TranspositionCipher.h)
