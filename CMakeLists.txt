cmake_minimum_required(VERSION 3.10.0)
project(unit-converter-arva VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(unit-converter-arva 
    src/main.cpp
    src/Length.cpp
    src/Time.cpp
    src/Mass.cpp
    src/CsvHandler.cpp
    src/JSONHandler.cpp
)

find_package(nlohmann_json 3.2.0 REQUIRED)
target_link_libraries(unit-converter-arva PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(unit-converter-arva PRIVATE include)