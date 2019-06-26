cmake_minimum_required(VERSION 3.9)
project(article-support)


add_executable(print print_container.cpp)
target_compile_features(print PUBLIC cxx_std_11)
set_target_properties(print PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)


add_subdirectory(tests)