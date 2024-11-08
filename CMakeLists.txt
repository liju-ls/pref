cmake_minimum_required(VERSION 3.5.0)

project("pref")

add_executable(pref main.cpp)

set_target_properties(pref PROPERTIES WIN32 $<CONFIG:Release>)