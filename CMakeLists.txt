cmake_minimum_required(VERSION 3.1)

project(game)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "E:/Programming/C++/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
add_executable(game main.cpp GameObject.cpp Projectile.cpp Tank.cpp Enemy.cpp Map.cpp)
target_link_libraries(game sfml-graphics)