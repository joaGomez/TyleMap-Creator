cmake_minimum_required(VERSION 3.0.0)
project(TyleMapCreator VERSION 0.1.0)

include(CTest)
enable_testing()

# From "Working with CMake" documentation:
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # AddressSanitizer (ASan)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif()

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # UndefinedBehaviorSanitizer (UBSan)
    add_compile_options(-fsanitize=undefined)
    add_link_options(-fsanitize=undefined)
endif()

# Packages
find_package(raylib CONFIG REQUIRED)

add_executable(TyleMapCreator main.cpp Map.cpp Menu.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_include_directories(TyleMapCreator PRIVATE ${raylib_INCLUDE_DIRS} ${MOSQUITTO_INCLUDE_DIRS})
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    target_include_directories(TyleMapCreator PRIVATE ${raylib_INCLUDE_DIRS})
    target_link_libraries(TyleMapCreator PRIVATE ${raylib_LIBRARIES})
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # From "Working with CMake" documentation:
    target_link_libraries(TyleMapCreator PRIVATE raylib "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(TyleMapCreator PRIVATE raylib m ${CMAKE_DL_LIBS} pthread GL rt X11)
endif()