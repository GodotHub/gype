cmake_minimum_required(VERSION 3.10)
project(gype C CXX)

set(QJS_BUILD_LIBC ON CACHE BOOL "Build standard library modules as part of the library")

add_subdirectory(quickjs)
add_subdirectory(godot-cpp)
add_subdirectory(tree-sitter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}/install" CACHE PATH "Install path")
set(GYPE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/example/addons/gype/extension")

file(GLOB_RECURSE 
    SOURCES 
        "src/*.cpp"
        "include/utils/func_utils.hpp"
)

add_library(gype SHARED ${SOURCES})

set_target_properties(gype PROPERTIES
    # 为 Debug 配置设置输出目录
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${GYPE_OUTPUT_PATH}"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${GYPE_OUTPUT_PATH}"
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${GYPE_OUTPUT_PATH}"
    
    # 为 Release 配置设置输出目录
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${GYPE_OUTPUT_PATH}"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${GYPE_OUTPUT_PATH}"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${GYPE_OUTPUT_PATH}"
    
    # 输出文件名和后缀保持不变
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
        qjs
        tree-sitter
        godot-cpp 
)

target_compile_options(gype PRIVATE /FS)