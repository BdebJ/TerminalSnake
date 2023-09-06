cmake_minimum_required (VERSION 3.21)

project ("TerminalSnake")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the executable
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")
add_executable (TerminalSnake ${SOURCES})

# Check the operating system and link PDCurses library if on Windows
if (WIN32)
    target_link_libraries(TerminalSnake PRIVATE ${CMAKE_SOURCE_DIR}/lib/PDCurses/wincon/pdcurses.lib)
    target_include_directories(TerminalSnake PRIVATE ${CMAKE_SOURCE_DIR}/lib/PDCurses)
# On Linux, use Curses
elseif (UNIX)
    find_package(Curses REQUIRED)
    include_directories(${CURSES_INCLUDE_DIR})
    target_link_libraries(TerminalSnake PRIVATE ${CURSES_LIBRARY})
endif()
