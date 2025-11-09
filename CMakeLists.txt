cmake_minimum_required(VERSION 3.10)
project(gype C CXX)

add_subdirectory(quickjs)
add_subdirectory(godot-cpp)
add_subdirectory(tree-sitter)

file(GLOB_RECURSE 
    SOURCES 
        "src/*.cpp"
)

add_library(gype SHARED ${SOURCES})

# --- 通用属性设置 ---
set_target_properties(gype PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/example/addons/gype/extension"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/example/addons/gype/extension"
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/example/addons/gype/extension"
    
    OUTPUT_NAME "gype"
    DEBUG_POSTFIX "_debug"
    RELEASE_POSTFIX "_release"
)

target_include_directories(gype 
    PRIVATE 
        include
)

target_link_libraries(gype 
    PRIVATE 
        quickjs
        tree-sitter
        godot-cpp
)

