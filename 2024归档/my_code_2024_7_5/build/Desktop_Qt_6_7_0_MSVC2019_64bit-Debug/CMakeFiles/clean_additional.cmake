# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appmy_code_2024_7_5_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appmy_code_2024_7_5_autogen.dir\\ParseCache.txt"
  "appmy_code_2024_7_5_autogen"
  )
endif()
