cmake_minimum_required(VERSION 3.20)

project("larpwtf")

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
    "include"
)