set (LIB_NAME 
  fletcher
)

option(BUILD_SHARED "Build shared libary" OFF)
if(BUILD_SHARED)
    message(STATUS "Building shared library")
    add_library(${LIB_NAME} SHARED)
else()
    message(STATUS "Building static libary")
    add_library(${LIB_NAME} STATIC)
endif()

target_sources(${LIB_NAME} 
    PRIVATE 
        fletcher.c 
)

target_include_directories(${LIB_NAME} 
    INTERFACE 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# use C99
set_property(TARGET ${LIB_NAME} PROPERTY C_STANDARD 99)

# Enable a few warnings
if (CMAKE_COMPILER_IS_GNUCC)
  target_compile_options(${LIB_NAME} PRIVATE -Wall -Wextra)
endif (CMAKE_COMPILER_IS_GNUCC)
if (MSVC)
  target_compile_options(${LIB_NAME} PRIVATE /W4)
endif (MSVC)
