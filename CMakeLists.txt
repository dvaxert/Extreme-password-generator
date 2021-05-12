cmake_minimum_required(VERSION 2.8)

project(epg)

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

add_compile_options(
    -Wall
    -g
)

#set the project variables
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(LIBS_DIR "${PROJECT_SOURCE_DIR}/ThirdParty")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BUILD_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BUILD_DIR}/lib")

#configure and compile FLTK
set(FLTK_BUILD_TEST CACHE OFF FORCE)
set(FLTK_BUILD_EXAMPLES CACHE OFF FORCE)
set(OPTION_USE_SYSTEM_JIBJPEG CACHE OFF FORCE)
set(OPTION_USE_SYSTEM_ZLIB CACHE OFF FORCE)
set(OPTION_USE_SYSTEM_LIBPNG CACHE OFF FORCE)
set(OPTION_USE_GL CACHE OFF FORCE)
set(OPTION_PRINT_SUPPORT CACHE OFF FORCE)
set(OPTION_BUILD_HTML_DOCUMENTATION CACHE OFF FORCE)
set(OPTION_BUILD_PDF_DOCUMENTATION CACHE OFF FORCE)
add_subdirectory("${LIBS_DIR}/fltk")

#configure and build the program library files
configure_file("${INCLUDE_DIR}/epg_config.hpp.in"
               "${INCLUDE_DIR}/epg_config.hpp")

file(GLOB_RECURSE EPG_CORE_SRC "${SRC_DIR}/*.cpp")
add_library(epg_core STATIC ${EPG_CORE_SRC})
target_include_directories(epg_core
    PUBLIC ${INCLUDE_DIR}
    PUBLIC "${LIBS_DIR}/fltk"
    PUBLIC "${BUILD_DIR}/ThirdParty/fltk"
)
target_link_libraries(epg_core fltk)


#configure program
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} epg_core)

#configure program installing
install(TARGETS ${PROJECT_NAME} DESTINATION "/usr/local/bin/")
