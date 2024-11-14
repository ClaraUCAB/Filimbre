cmake_minimum_required(VERSION 3.31.0 FATAL_ERROR)


######## Project information ########
set(Project_Title       Filimbre)
set(Project_Version     0.0.0)
set(Project_Author)

list(APPEND Project_Author "Paris")
list(APPEND Project_Author "Xiao")
list(APPEND Project_Author "Clara")
#####################################


# Configure project
project(${Project_Title} LANGUAGES CXX VERSION ${Project_Version})
set(CMAKE_CXX_STANDARD 17 REQUIRED ON)


### Options ###

## OPTION: ENABLE_LTO
# Enable Link Time Optimizations (LTO) on Release build type. On by Default.
# This MAY cause problems on some systems.
# If it does, it can be disabled with -DENABLE_LTO=OFF.
option(ENABLE_LTO "Enable Link Time Optimizations" ON)

# Set the CMake Build Type to Release by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()


# Define some flags for increased performance
# NOTE: -pipe does not affect the final binary
# It only speeds up compilation by avoiding writing temp files
set(SYSTEM_TUNING_FLAGS "-march=native -mtune=native -pipe -O3")

# Add LTO flags if enabled
if(ENABLE_LTO)
   set(SYSTEM_TUNING_FLAGS "${SYSTEM_TUNING_FLAGS} -flto")
endif()


### Project Sources ###
set(PROJECT_HEADERS
    include/linea.h
    include/documento.h
)

set(PROJECT_SOURCES
   src/main.cpp
   src/linea.cpp
   src/documento.cpp
)


# Target binary
add_executable(${PROJECT_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES})


# Configure CXX properties
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Add additional flags for performance to Release build type
if(CMAKE_BUILD_TYPE EQUAL "Release")
    target_compile_options(${PROJECT_NAME} PUBLIC "${SYSTEM_TUNING_FLAGS}")
    target_link_libraries(${PROJECT_NAME} PUBLIC "${SYSTEM_TUNING_FLAGS} -s")
endif()


# Project include directory
target_include_directories(${PROJECT_NAME} PUBLIC include/)

