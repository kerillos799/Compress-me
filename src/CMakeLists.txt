cmake_minimum_required(VERSION 3.26)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        const.hpp
        main.cpp
        build_huffman_tree.cpp
        decoder.cpp
        build_table.cpp
        write_encoded.cpp
)
