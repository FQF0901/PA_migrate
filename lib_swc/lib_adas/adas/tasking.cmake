SET(CMAKE_SYSTEM_NAME Generic)

find_program(CROSS_COMPILER_PATH "cctc")
if (NOT CROSS_COMPILER_PATH)
  message(FATAL_ERROR "Cannot find tasking compiler: cctc")
endif()

#SET(CMAKE_FIND_ROOT_PATH /opt/sw160800v63/TriCore/ctc)


# specify the cross compiler
SET(CMAKE_C_COMPILER   ${CROSS_COMPILER_PATH})
SET(CMAKE_CXX_COMPILER ${CROSS_COMPILER_PATH})

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
