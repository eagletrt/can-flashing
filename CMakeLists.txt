cmake_minimum_required(VERSION 3.16)

project(can-flashing)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_C_FLAGS "-lm -std=gnu23")

FILE(GLOB sources ${PROJECT_SOURCE_DIR}/src/*)
FILE(GLOB can ${PROJECT_SOURCE_DIR}/thirdparty/can/src/*/*.c)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/thirdparty/can/include
  ${PROJECT_SOURCE_DIR}/thirdparty/can/include/bms
  ${PROJECT_SOURCE_DIR}/thirdparty/can/include/primary
  ${PROJECT_SOURCE_DIR}/thirdparty/can/include/inverters
  ${PROJECT_SOURCE_DIR}/thirdparty/eagletrt/include
)

add_executable(can-flashing
  src/can-flashing.c

  ${sources}
  ${eagletrt}
  ${can}
)
