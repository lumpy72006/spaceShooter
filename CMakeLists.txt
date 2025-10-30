cmake_minimum_required(VERSION 3.16)
project(game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp
    Game.cpp
    Aircraft.cpp
    Entity.cpp
    SceneNode.cpp
    SpriteNode.cpp
    World.cpp
)

# Link SFML
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
