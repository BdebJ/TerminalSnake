cmake_minimum_required (VERSION 3.21)

project ("TerminalSnake")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the executable
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")
add_executable (TerminalSnake "src/main.cpp" ${SOURCES})

# Link PDCurses library and include directories
target_link_libraries(TerminalSnake PRIVATE ${CMAKE_SOURCE_DIR}/lib/PDCurses/wincon/pdcurses.lib)
target_include_directories(TerminalSnake PRIVATE ${CMAKE_SOURCE_DIR}/lib/PDCurses)
