#----------------------------------------------------------------------------#
#                                                                            #
#                    ADVANCED GLOBAL ILLUMINATION C++ PROJECT                #
#                                                                            #
#                                                                            #
#                                                                            #
#----------------------------------------------------------------------------#

cmake_minimum_required(VERSION 3.16)

set(PROJECT_MAIN "AGI_path_tracer")
project(${PROJECT_MAIN} VERSION 1.0
                  	DESCRIPTION "Advanced Global Illumination Path Tracer.")

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)
					
set (PROJECT_MAIN_DIR ${CMAKE_CURRENT_LIST_DIR})
#include_directories(${PROJECT_MAIN_DIR})

# Add source and header files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp ${CMAKE_CURRENT_LIST_DIR}/src/*.c)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS ${CMAKE_CURRENT_LIST_DIR}/src/*.hpp ${CMAKE_CURRENT_LIST_DIR}/src/*.h)

# Create the VS filters based on the directory tree layout
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCES} ${HEADERS})

if (WIN32)
    set(OpenGlLibs opengl32 gdi32)
endif()
if (UNIX)
    set(OpenGlLibs GLU GL X11)
endif()

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} ${OpenGlLibs})