cmake_minimum_required(VERSION 3.5.0)

project("pref")

include_directories("include")
link_directories("lib")

add_executable(pref main.cpp)

target_link_libraries(pref sdl3)

