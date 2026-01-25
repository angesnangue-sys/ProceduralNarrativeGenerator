CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
project(StoryGenerator)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL3 REQUIRED)

include_directories(include)

add_executable(StoryGenerator
    src/main.cpp
    src/App.cpp
    src/NarrativeEngine.cpp
    src/Story.cpp
)

target_link_libraries(StoryGenerator SDL3::SDL3)