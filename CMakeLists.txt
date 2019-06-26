cmake_minimum_required(VERSION 3.9)
project(article-support)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall 
                    -Wextra
                    -Wno-unused-parameter
                    -Wold-style-cast
                    -Wnon-virtual-dtor
                    -Woverloaded-virtual
                    -Wdouble-promotion
                    -Wformat=2
                    -Wredundant-decls
                    -Wconversion
                    -Wdouble-promotion)

add_executable(print src/print_container.cpp)
target_compile_features(print PUBLIC cxx_std_11)
set_target_properties(print PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)


add_subdirectory(tests)