project(tree-sitter C CXX)

file(GLOB_RECURSE 
    SOURCE 
        ${PROJECT_SOURCE_DIR}/src/lib.c
        ${PROJECT_SOURCE_DIR}/src/typescript/parser.c
        ${PROJECT_SOURCE_DIR}/src/typescript/scanner.c
)

add_library(tree-sitter STATIC ${SOURCE})

target_include_directories(tree-sitter 
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/include
)