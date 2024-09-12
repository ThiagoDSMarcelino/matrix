cmake_minimum_required(VERSION 3.14)

set(This Matrix)

project(${This})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download GoogleTest framework
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# Getting all source files to compile
file(GLOB SOURCES "src/*.cpp")
file(GLOB TESTS "tests/*.cpp")

add_executable(${This} ${TESTS} ${SOURCES})

include_directories(include)

enable_testing()

gtest_discover_tests(${This})

target_link_libraries(
  ${This}
  GTest::gtest_main
)
