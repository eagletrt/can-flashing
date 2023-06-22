cmake_minimum_required(VERSION 3.16)

project(can-flashing)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

FILE(GLOB sources ${PROJECT_SOURCE_DIR}/src/*)
FILE(GLOB can ${PROJECT_SOURCE_DIR}/thirdparty/can/lib/*/*)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/thirdparty
)

add_executable(can-flashing
  src/can-flashing.c

  ${sources}
  ${can}
  )