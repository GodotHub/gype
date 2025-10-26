project(tree-sitter C CXX)

file(GLOB_RECURSE SOURCE ${PROJECT_SOURCE_DIR}/src/*.c)

add_library(tree-sitter STATIC ${SOURCE})

target_include_directories(tree-sitter 
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/include
)