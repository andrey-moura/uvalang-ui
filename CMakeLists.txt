#Require a minimum version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(andylang-ui)

include_directories(include)

# PIC
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include("${CMAKE_CURRENT_LIST_DIR}/modules/andy/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/modules/andy/include/uva/xml/CMakeLists.txt") 
include("${CMAKE_CURRENT_LIST_DIR}/modules/andy-drawing/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/modules/andy-ui/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/modules/andy-widgets/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/modules/binary/CMakeLists.txt")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(andylang-ui SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/ui_extension.cpp
    $<TARGET_OBJECTS:andy-ui>
    $<TARGET_OBJECTS:uva-xml>
    $<TARGET_OBJECTS:uva-drawing>
    $<TARGET_OBJECTS:uva-widgets>
    $<TARGET_OBJECTS:uva-binary>
)

andy_ui_properties(andylang-ui)

# target_link_options(andylang-ui PRIVATE -static-libgcc -static-libstdc++ -static)