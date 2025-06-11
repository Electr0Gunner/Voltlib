cmake_minimum_required(VERSION 3.26 FATAL_ERROR)

project(VoltLib LANGUAGES C CXX ASM VERSION 0.0.1)

set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)

file(GLOB_RECURSE ALL_FILES CONFIGURE_DEPENDS
    "*.cpp" "*.c"
    "*.h" "*.hpp"
)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)


target_link_libraries(${PROJECT_NAME} PUBLIC 
SDL3::SDL3-static
)
