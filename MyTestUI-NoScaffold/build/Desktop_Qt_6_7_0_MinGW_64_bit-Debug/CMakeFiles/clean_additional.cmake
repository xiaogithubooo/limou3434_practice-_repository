# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appMyTestUI-NoScaffold_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appMyTestUI-NoScaffold_autogen.dir\\ParseCache.txt"
  "FluentUI\\CMakeFiles\\fluentuiplugin_autogen.dir\\AutogenUsed.txt"
  "FluentUI\\CMakeFiles\\fluentuiplugin_autogen.dir\\ParseCache.txt"
  "FluentUI\\fluentuiplugin_autogen"
  "appMyTestUI-NoScaffold_autogen"
  )
endif()
