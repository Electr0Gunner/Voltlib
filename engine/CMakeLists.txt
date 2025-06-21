cmake_minimum_required(VERSION 3.26 FATAL_ERROR)

project(VoltLib LANGUAGES C CXX ASM VERSION 0.0.1)

set(BUILD_SHARED_LIBS OFF)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)

file(GLOB_RECURSE ALL_FILES CONFIGURE_DEPENDS
    "Voltlib/*.cpp" "Voltlib/*.c"
    "Voltlib/*.h" "Voltlib/*.hpp"
)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        Voltlib
        dependencies/misc
        dependencies/Chipmunk2D/include
)

add_subdirectory(dependencies/SDL)
add_subdirectory(dependencies/Chipmunk2D)

target_link_libraries(${PROJECT_NAME} PUBLIC 
SDL3::SDL3-static
chipmunk_static
)
