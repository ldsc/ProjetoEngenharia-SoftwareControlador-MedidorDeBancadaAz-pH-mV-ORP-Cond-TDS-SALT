# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Pedro_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Pedro_autogen.dir\\ParseCache.txt"
  "Pedro_autogen"
  )
endif()
