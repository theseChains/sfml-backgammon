cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_BUILD_TYPE Debug)

project(hello VERSION 1.0)

file (GLOB_RECURSE project_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE project_HEADERS CONFIGURE_DEPENDS "src/*.h")

set (project_INCLUDE_DIRS "")
foreach (_headerFile ${project_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND project_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES project_INCLUDE_DIRS)

add_executable(app ${project_SOURCES})
target_include_directories(app PRIVATE ${project_INCLUDE_DIRS})

target_compile_options(app PRIVATE -I/Users/dusksher/goinfre/homebrew/Cellar/sfml/2.6.0/include -Wall -Wshadow -Wextra -Wpedantic -Wconversion)

target_link_libraries(app -L/Users/dusksher/goinfre/homebrew/Cellar/sfml/2.6.0/lib sfml-system sfml-window sfml-graphics)

find_package(OpenGL REQUIRED)
target_link_libraries(app OpenGL::GL)
