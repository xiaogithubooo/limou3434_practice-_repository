# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appQtDemo_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appQtDemo_autogen.dir\\ParseCache.txt"
  "appQtDemo_autogen"
  )
endif()
