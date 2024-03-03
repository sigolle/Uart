cmake_minimum_required(VERSION 3.14)

if(WIN32)
    project(QT6_CMake_Uart LANGUAGES CXX)
elseif(UNIX)
    project(QT6_CMake_Uart)
endif()

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)

#===INCLUSION OF Project Files===#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(IMG_DIR "${CMAKE_SOURCE_DIR}/img")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})
include_directories(${IMG_DIR})

file(GLOB_RECURSE PROJECT_SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
    "${IMG_DIR}/*.rc"
    "${IMG_DIR}/*.ico"
)

set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

if(WIN32)
    add_executable(QT6_CMake_Uart WIN32 ${PROJECT_SOURCES})
elseif(UNIX)
    add_executable(QT6_CMake_Uart ${PROJECT_SOURCES})
endif()

target_include_directories(QT6_CMake_Uart PRIVATE ${FORMS_DIR})
target_include_directories(QT6_CMake_Uart PRIVATE ${INCLUDE_DIR})
target_include_directories(QT6_CMake_Uart PRIVATE ${SOURCE_DIR})
target_include_directories(QT6_CMake_Uart PRIVATE ${IMG_DIR})

target_link_libraries(QT6_CMake_Uart Qt6::Widgets)
