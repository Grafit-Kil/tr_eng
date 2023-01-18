cmake_minimum_required(VERSION 3.1)

project(main)

add_compile_options(-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wcast-align -Wunused)

set(SOURCES
	main.cpp
	src/dictionary.cpp
	src/file_process.cpp
	src/file_process.h
	src/parser.cpp
	src/parser.h
	include/dictionary.h
)

add_executable(main ${SOURCES})
