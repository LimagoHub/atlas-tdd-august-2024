cmake_minimum_required (VERSION 3.12)

project(LaborProjekt)

set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)

enable_testing()

add_executable(
	LaborProjekt 
	source/main.cpp
		source/Dependency.h
		source/DependencyImpl.h
		source/MyServiceUsingDependency.h
)


# Add tests
add_subdirectory(tests)

