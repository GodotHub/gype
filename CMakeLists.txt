cmake_minimum_required(VERSION 3.10...3.17)

project(gype C CXX)

add_subdirectory(quickjs)
add_subdirectory(godot-cpp)

file(GLOB_RECURSE 
    SOURCES
        "src/*.cpp"
)

add_library(gype SHARED ${SOURCES})

target_include_directories(gype 
    PRIVATE 
        include
)

target_link_libraries(gype PRIVATE godot-cpp)
target_link_libraries(gype PRIVATE quickjs)