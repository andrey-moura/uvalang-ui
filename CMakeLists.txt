#Require a minimum version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(uvalang-ui)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

uva_library(uva-ui)
uva_library(uva-drawing)
uva_library(uva-widgets)
uva_library(xml)
uva_library(binary)

add_library(uvalang-ui-shared SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/ui_extension.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/app_class.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/dialog_class.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/frame_class.cpp
)

target_link_libraries(uvalang-ui-shared uvaui uva-widgets uva-lang uva-extension uva-console uva-lexer uva-interpreter)