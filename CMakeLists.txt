project("Brainfuck Interpreter")

option(DEBUG "Include debug messages" OFF)

if(DEBUG)
    add_definitions(-DDEBUG)
endif()

add_executable(bf bf.cxx)
