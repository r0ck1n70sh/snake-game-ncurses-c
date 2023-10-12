cmake_minimum_required(VERSION 3.26.4)

set(CMAKE_C_STANDARD 99)

project(snake-game-ncurses-c)

FILE(GLOB GEOMETRY_LIB src/geometry/*.c)
FILE(GLOB RENDER_LIB src/render/*.c)

add_library(snake-game-ncurses-c
	STATIC
	${GEOMETRY_LIB}
	${RENDER_LIB}
)

target_include_directories(snake-game-ncurses-c
	PUBLIC
	${PROJECT_SOURCE_DIR}/include
)

add_executable(out src/main.c)

find_package(Curses REQUIRED)
if (CURSES_FOUND)
	message("FOUND ncurses")
	include_directories(${CURSES_INCLUDE_LIBS})
	target_link_libraries(out ${CURSES_LIBRARIES})
else()
	error("NOT FOUND ncurses")
endif()


target_link_libraries(out snake-game-ncurses-c)

