cmake_minimum_required(VERSION 3.5)

project(StudyCMakeGtest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

option(BUILD_TESTS "Build test programs" ON)

configure_file(
	${PROJECT_SOURCE_DIR}/include/config.h.in
 	${PROJECT_SOURCE_DIR}/include/config.h
 	@ONLY)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)
if(BUILD_TESTS)
	configure_file(GTestCmake.txt.in googletest-download/CMakeLists.txt)
	execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	  RESULT_VARIABLE result
	  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
	if(result)
	  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
	endif()
	execute_process(COMMAND ${CMAKE_COMMAND} --build .
	  RESULT_VARIABLE result
	  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
	if(result)
	  message(FATAL_ERROR "Build step for googletest failed: ${result}")
	endif()
	
	# Prevent overriding the parent project's compiler/linker
	# settings on Windows
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	
	# Add googletest directly to our build. This defines
	# the gtest and gtest_main targets.
	add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
	                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
	                 EXCLUDE_FROM_ALL)
	
	# The gtest/gtest_main targets carry header search path
	# dependencies automatically when using CMake 2.8.11 or
	# later. Otherwise we have to add them here ourselves.
	if (CMAKE_VERSION VERSION_LESS 2.8.11)
	  include_directories("${gtest_SOURCE_DIR}/include")
	endif()
	add_subdirectory(test)
endif(BUILD_TESTS)