cmake_minimum_required(VERSION 3.10...3.17)

project(gype C CXX)

add_subdirectory(quickjs)
add_subdirectory(godot-cpp)
add_subdirectory(tree-sitter)

file(GLOB_RECURSE 
    SOURCES 
        "src/*.cpp"
)

add_library(gype SHARED ${SOURCES})

set_target_properties(gype PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/example/addons/gype/extension"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/example/addons/gype/extension"
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/example/addons/gype/extension"
    
    OUTPUT_NAME "gype"

    DEBUG_POSTFIX "_debug"
)

target_include_directories(gype 
    PRIVATE 
        include
)

target_link_libraries(gype PRIVATE quickjs)
target_link_libraries(gype PRIVATE tree-sitter)
target_link_libraries(gype PRIVATE godot-cpp)

# add_custom_command(TARGET gype POST_BUILD
#                    COMMAND ${CMAKE_STRIP} $<TARGET_FILE:gype>
#                    COMMENT "Stripping symbols from gype...")