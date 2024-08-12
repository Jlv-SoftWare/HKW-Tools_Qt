# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\HKW-Tools_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\HKW-Tools_autogen.dir\\ParseCache.txt"
  "HKW-Tools_autogen"
  )
endif()
