

add_executable(tests 
               tests.cpp
               test-print_container.cpp)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR})
set_target_properties(tests PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)