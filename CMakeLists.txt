cmake_minimum_required(VERSION 3.17)
project(my_jump_king C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)          #Include project include directory(headers)
link_directories(${PROJECT_SOURCE_DIR}/lib)                 #Include lib folder (for .lib 's and .a 's)
include_directories(${PROJECT_SOURCE_DIR}/SDL_image/include)          #Include project include directory(headers)
link_directories(${PROJECT_SOURCE_DIR}/SDL_image/lib)                 #Include lib folder (for .lib 's and .a 's)

add_executable(my_jump_king main.c)
add_executable(src/struct.h src/map_initialization.c src/map_initialization.h src/standard_functions.c src/standard_functions.h src/events.h src/events.c src/gravity.c src/gravity.h)

target_link_libraries(my_jump_king SDL2 SDL2main SDL2_image)
