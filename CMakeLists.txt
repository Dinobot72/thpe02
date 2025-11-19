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

# add the files for the project
target_sources( strtest PRIVATE src/stringTracker.h )
target_sources( strtest PRIVATE src/stringTracker1.cpp )
target_sources( strtest PRIVATE src/stringTracker2.cpp )
target_sources( strtest PRIVATE src/stringTrackerTests1.cpp )
target_sources( strtest PRIVATE src/stringTrackerTests2.cpp )
target_sources( strtest PRIVATE src/insttests.cpp )

# add the compile and linker options
target_compile_options( strtest PRIVATE -g -Wall -Wextra -Wshadow -Wpedantic -std=gnu++20 -Werror)
target_link_libraries( strtest PRIVATE Catch2::Catch2WithMain)

# setup to use Catch2
include( Catch )
catch_discover_tests( strtest )
enable_testing()

# added data and .vscode so you get everything.
# comment and uncomment what is needed for submission.
set ( TarFile "${PROJECT_NAME}.tgz")
set ( TarSourceFiles
    src/*
    .vscode/*
    CMakeLists.txt
)
add_custom_target(CreateTGZ
    COMMAND tar -zcvf ${TarFile} ${TarSourceFiles}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Create a tgz for submission"
)

# Build part 2 of the assignment
add_executable( thpe02 )

# add files
target_sources( thpe02 PRIVATE src/stringTracker1.cpp )
target_sources( thpe02 PRIVATE src/stringTracker2.cpp )
target_sources( thpe02 PRIVATE src/thpe02.cpp )
target_sources( thpe02 PRIVATE src/thpe02fn.cpp )


target_compile_options( thpe02 PRIVATE -g -Wall -Werror -Wextra -Wshadow -Wpedantic -std=gnu++20)
