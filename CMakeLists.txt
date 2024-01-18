cmake_minimum_required(VERSION 3.26)
project(Ykna)

set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/g++.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")

add_executable(Ykna main.cpp
        front/front.cpp
        front/front.h
)

find_package(PkgConfig REQUIRED)
find_package(CURL REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
target_link_libraries(Ykna PRIVATE Qt6::Core Qt6::Widgets)
target_include_directories(Ykna PRIVATE ${CURL_INCLUDE_DIRS})
target_link_libraries(Ykna PRIVATE ${CURL_LIBRARIES})
