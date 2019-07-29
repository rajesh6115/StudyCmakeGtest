add_executable(${CMAKE_PROJECT_NAME}_test main_test.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_test gtest)
add_test(NAME main_test COMMAND ${CMAKE_PROJECT_NAME}_test)