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

# ------------------------------------------------------------------
# -- 包体优化设置 (主要针对 MSVC 的 Release 构建) --
# ------------------------------------------------------------------

# 1. 启用链接时代码生成 (LTCG)，也称为全程序优化
# 这允许链接器进行跨模块的深度优化，对减小体积和提升性能都非常有效。
# CMake 会自动为 Release 配置添加 /LTCG 标志。
set_property(TARGET gype PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)

# 2. 为 Release 配置添加特定的编译器优化标志
# 使用生成器表达式 $<CONFIG:Release> 来确保这些标志只在 Release 模式下生效
target_compile_options(gype PRIVATE 
    /FS # 你原来就有的标志，用于解决 PDB 文件并发访问问题
    $<$<CONFIG:Release>:/O1>  # /O1: 最小化体积 (Minimize Size)
    $<$<CONFIG:Release>:/Gy>  # /Gy: 启用函数级链接 (Function-Level Linking)
)

# 3. 为 Release 配置添加特定的链接器优化标志
target_link_options(gype PRIVATE
    $<$<CONFIG:Release>:/OPT:REF>   # /OPT:REF: 移除未被引用的函数和数据
    $<$<CONFIG:Release>:/OPT:ICF>   # /OPT:ICF: 合并完全相同的代码段 (COMDAT Folding)
)

# 4. (可选但强烈推荐) 为 gype 目标设置 MSVC 运行时库
# 使用动态运行时库 (/MD) 可以显著减小包体，因为它不会将 C/C++ 标准库静态链接进去。
# 这是 Windows 应用开发的标准实践。
if(MSVC)
    set_target_properties(gype PROPERTIES
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
    )
endif()