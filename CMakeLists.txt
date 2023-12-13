cmake_minimum_required(VERSION 3.0)

project(my_executable)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Boost headers
include_directories(include)

# Get a list of all source files in the "src/" directory
file(GLOB SOURCE_FILES src/*.cpp)

find_package(Boost REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(my_executable main.cpp ${SOURCE_FILES})
  target_link_libraries(my_executable ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Boost not found. Please install Boost or specify its location.")
endif()
