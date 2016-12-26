cmake_minimum_required(VERSION 3.2)
project(Dodaren)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# set default build type explicitly to Release
if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build type." FORCE)
endif (NOT CMAKE_BUILD_TYPE)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

if(NOT SFML_ROOT)
    set(SFML_ROOT "C:/SFML/2.4.1")
endif()

# Find SFML
set(SFML_STATIC_LIBRARIES FALSE)
find_package(SFML REQUIRED COMPONENTS audio graphics window system)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML couldn't be located!")
endif()

include_directories(${SFML_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCE_FILES
    src/Main.cpp
    src/Animation.cpp
    src/Game.cpp
    src/Entities/EntityManager.cpp
    src/Entities/Player.cpp
    src/States/StateManager.cpp
    src/States/GameState.cpp
    src/States/MenuState.cpp
)

add_executable(Dodaren ${SOURCE_FILES})

target_link_libraries(Dodaren ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# Install executable
install(TARGETS Dodaren
    RUNTIME DESTINATION .
)

# Install game data
#install(DIRECTORY bin/res
#    DESTINATION .
#)