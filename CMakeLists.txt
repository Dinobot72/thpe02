cmake_minimum_required(VERSION 3.10.0)

# name of your project
project(thpe02)

# make sure you have catch2 in your system
find_package( Catch2 3 REQUIRED )

# Set the bin directory for binaries and turn debuggin on
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" )
if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Debug )
endif()

# make an executable, add the files needed, compile options
# and linker options
add_executable( strtest )
