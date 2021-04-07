find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

add_subdirectory(widget)
add_subdirectory(drawable)
add_subdirectory(tool)
add_executable(lipuma
	main.cpp
)

target_link_libraries(lipuma Qt5::Gui Qt5::Widgets widget drawable tool)