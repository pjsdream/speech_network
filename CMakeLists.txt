cmake_minimum_required(VERSION 2.8.12.2)

PROJECT(speech_network)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

message(${PROJECT_BINARY_DIR})

## show all files (http://wiki.ros.org/IEDs#QtCreator)
# Add all files in subdirectories of the project in a dummy_target so qtcreator have access to all files
FILE(GLOB children ${CMAKE_SOURCE_DIR})
FOREACH(child ${children})
  IF(IS_DIRECTORY ${child})
    file(GLOB_RECURSE dir_files "${child}/*")
    LIST(APPEND extra_files ${dir_files})
  ENDIF()
ENDFOREACH()
add_custom_target(dummy_${PROJECT_NAME} SOURCES ${extra_files})

include_directories(
  include
  lib
)

link_directories(
  lib
)

add_library(speech_subscriber
  src/speech_subscriber.cpp
)

target_link_libraries(speech_subscriber
  zmq
)
