cmake_minimum_required(VERSION 3.10...3.17)

project(gype C CXX)

add_subdirectory(quickjs)
add_subdirectory(godot-cpp)

file(GLOB_RECURSE 
    SOURCES
        "src/*.cpp"
)

add_library(gype SHARED ${SOURCES})

set_target_properties(gype PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/example/bin"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/example/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/example/bin"
    
    OUTPUT_NAME "gype"

    DEBUG_POSTFIX "_debug"
)

target_include_directories(gype 
    PRIVATE
        include
)

target_link_libraries(gype PRIVATE godot-cpp)
target_link_libraries(gype PRIVATE quickjs)

# target_compile_features(gype PRIVATE cxx_std_20)
