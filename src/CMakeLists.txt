cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)

project(novel)

# common

include_directories(${CMAKE_SOURCE_DIR})

# libstd sources

set(LIB_SOURCES lib/Logger.h
                lib/Logger.cpp)

add_library(std STATIC ${LIB_SOURCES})

# App sources

set (APP_SOURCES    app/DosedLove.h
                    app/DosedLove.cpp)

# Engine sources

set (ENGINE_SOURCES engine/Engine.h
                    engine/Engine.cpp
                    engine/EngineMain.cpp
                    engine/common/type.h
                    engine/systems/CvarSystem.h
                    engine/systems/CvarSystem.cpp
                    engine/systems/CmdSystem.h
                    engine/systems/CmdSystem.cpp
                    engine/systems/FileSystem.h
                    engine/systems/FileSystem.cpp
                    engine/systems/WindowSystem.h
                    engine/systems/WindowSystem.cpp)

add_executable(novel ${ENGINE_SOURCES} ${APP_SOURCES})
target_link_libraries(novel std SDL3)