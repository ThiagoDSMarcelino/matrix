cmake_minimum_required(VERSION 3.14)

set(This Matrix)

project(${This})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.cpp")

add_executable(${This} ${SOURCES})

include_directories(include)

add_custom_target(build
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target ${This}
    COMMENT "Building ${This}..."
)

add_custom_target(clean_bin
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/${This}
    COMMENT "Cleaning ${This} executable..."
)

add_custom_target(run
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean_bin
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target ${This} -- -B
    COMMAND ${CMAKE_BINARY_DIR}/${This}
    COMMENT "Cleaning, forcing rebuild, and running ${This}..."
)
