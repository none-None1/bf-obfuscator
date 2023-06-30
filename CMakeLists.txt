
cmake_minimum_required (VERSION 3.8)



project ("bf-obfuscator")
link_directories(${CMAKE_BINARY_DIR})
add_library (bf-obfuscator SHARED "bf-obfuscator.cpp" "bf-obfuscator.h"  "bfotest.cpp")
add_executable (bfotest "bfotest.cpp" "bf-obfuscator.h")
target_link_libraries(bfotest bf-obfuscator)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET bf-obfuscator PROPERTY CXX_STANDARD 20)
endif()


