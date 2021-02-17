cmake_minimum_required(VERSION 3.19)
project(chess_bot)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
endif(CMAKE_COMPILER_IS_GNUCXX)
add_executable(chess_bot src/main.cpp src/chess/board.cpp src/chess/board.hpp src/chess/vector_2.hpp src/chess/piece_board.cpp src/chess/piece_board.hpp)