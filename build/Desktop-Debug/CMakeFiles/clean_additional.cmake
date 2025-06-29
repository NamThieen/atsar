# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/atsar_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/atsar_autogen.dir/ParseCache.txt"
  "atsar_autogen"
  )
endif()
