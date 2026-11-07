cmake_minimum_required(VERSION 3.20)

project("larpwtf" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${CMAKE_PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/extern"
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/lib/libssl.lib"
    "${CMAKE_SOURCE_DIR}/lib/libcrypto.lib"
)

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/bin/libssl-4-x64.dll"
        "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/bin/libcrypto-4-x64.dll"
        "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>"
)
