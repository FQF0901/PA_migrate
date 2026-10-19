cmake_minimum_required(VERSION 3.21)
SET(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(_adas)

find_program(CCACHE ccache)
if(CCACHE)
  SET(CMAKE_C_COMPILER_LAUNCHER ${CCACHE})
endif()

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB_RECURSE children LIST_DIRECTORIES true RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${curdir}/${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

FILE(GLOB_RECURSE source_list *.c)
SET(SOURCES ${source_list})

list(LENGTH source_list source_list_count)
add_compile_options( -D__CPU__=tc27xd --iso=99
  --c++14
  --integer-enumeration
  --language=+volatile
  --exceptions
  --anachronisms
  --fp-model=3
  $<$<CONFIG:DEBUG>:-O3>
  $<$<CONFIG:DEBUG>:--tradeoff=0>
  $<$<CONFIG:RELEASE>:-O2>
  $<$<CONFIG:RELEASE>:--tradeoff=4>
  --compact-max-size=200
  $<$<CONFIG:RELEASE>:-g>
  -Wc-w544
  -Wc-w557
  $<$<BOOL:${CERT_ENABLE}>:--cert=${CERT}>
  -Ctc27xd
  -Wa-Og
  -Wa-Os
  #--no-warnings=
  -Wa--error-limit=42
  $<$<BOOL:${MISRAC_ENABLE}>:--misrac=${MISRAC}>
  --misrac-version=2012
  -N0
  -Z0
  -Y0)

add_library(${PROJECT_NAME} STATIC ${SOURCES})


SUBDIRLIST(dir_list ${CMAKE_CURRENT_SOURCE_DIR})
list(LENGTH dir_list dir_list_count)
message(STATUS "[INFO] ${PROJECT_NAME} Found ${dir_list_count} directories.")
SUBDIRLIST(dir_list2 ${CMAKE_CURRENT_SOURCE_DIR}/../em_lsad_tc277/lib_inc)
list(LENGTH dir_list2 dir_list_count)
message(STATUS "[INFO] ${PROJECT_NAME} Found ${dir_list_count} directories.")
LIST(APPEND dir_list ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../em_lsad_tc277/common ${CMAKE_CURRENT_SOURCE_DIR}/../em_lsad_tc277/source ${dir_list2}) 

list(FILTER dir_list EXCLUDE REGEX "\\.settings")
list(FILTER dir_list EXCLUDE REGEX "\\.git")
target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${dir_list}
)

list(LENGTH dir_list dir_list_count)
message(STATUS "[INFO] ${PROJECT_NAME} Found ${dir_list_count} directories.")
