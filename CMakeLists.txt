cmake_minimum_required(VERSION 3.1.0)

project(lipuma VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERISON VERSION_LESS "3.7.0")
	set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()



include_directories(${Qt5Gui_INCLUDE_DIRS}, {Qt5Widgets_INCLUDE_DIRS})
include_directories(src)

add_subdirectory(src)

