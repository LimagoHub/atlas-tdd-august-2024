cmake_minimum_required (VERSION 3.12)





# Add dependencies
set( gtest_force_shared_crt ON CACHE BOOL "")
add_subdirectory(google)
set_target_properties(gtest PROPERTIES FOLDER Dependencies)
set_target_properties(gmock PROPERTIES FOLDER Dependencies)
set_target_properties(gtest_main PROPERTIES FOLDER Dependencies)
set_target_properties(gmock_main PROPERTIES FOLDER Dependencies)
set_target_properties(gmock_main gtest_main PROPERTIES EXCLUDE_FROM_ALL 1 EXCLUDE_FROM_DEFAULT_BUILD 1)

set(SOURCE
	main.cpp
		tiere/SchweinTest.cpp
		tiere/SchweinTest.h
		services/MockDependency.h
		services/MyServiceUsingDependencyTest.cpp
		services/MyServiceUsingDependencyTest.h

)



# Create test executable
add_executable(Tag1_02SchweineProjektTest ${SOURCE} ${HEADER}  )




# Linking
target_link_libraries(Tag1_02SchweineProjektTest PRIVATE gtest gmock)

# Mark it as test executable for CMake
add_test(NAME Tag1_02SchweineProjektTest COMMAND Tag1_02SchweineProjektTest)

# Push it to tests
set_target_properties(Tag1_02SchweineProjektTest PROPERTIES FOLDER Tests)

# Build tests where other libraries reside
set_target_properties(Tag1_02SchweineProjektTest
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
)
