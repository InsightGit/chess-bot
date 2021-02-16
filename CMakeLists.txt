cmake_minimum_required(VERSION 3.19)
project(chess_bot)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Werror")

add_executable(chess_bot src/main.cpp src/chess/board.cpp src/chess/board.hpp src/chess/vector_2.hpp)