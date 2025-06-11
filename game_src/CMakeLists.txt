
project(InsertName VERSION 0.1.0 LANGUAGES C CXX)

add_executable(InsertName main.cpp)

target_link_libraries(InsertName PUBLIC VoltLib)