cmake_minimum_required(VERSION 3.5.1)
cmake_policy(VERSION 3.5)
project(TERMIATE_PROGRAM LANGUAGES C VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_executable(terminate
    terminate.c
)
