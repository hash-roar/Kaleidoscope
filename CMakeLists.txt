set(CMAKE_EXPORT_COMPILE_COMMANDS on)

cmake_minimum_required(VERSION 3.5)

project(Kaleidoscope)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp)
# target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include)
find_package(fmt)
target_link_libraries(main PRIVATE fmt::fmt)
find_package(spdlog)
target_link_libraries(main PRIVATE spdlog::spdlog)
