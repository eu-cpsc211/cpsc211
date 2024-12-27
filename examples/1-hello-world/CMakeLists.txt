cmake_minimum_required (VERSION 3.8)

project ("example")

add_executable (example
	"main.cpp"
)

set_property(TARGET example PROPERTY CXX_STANDARD 17)
