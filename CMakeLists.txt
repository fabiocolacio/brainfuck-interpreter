project("Brainfuck Interpreter")

option(DEBUG "Include debug messages" OFF)

if(DEBUG)
    add_definitions(-DDEBUG)
endif()

set(EXEC_NAME "bf")

add_executable(${EXEC_NAME} bf.cxx)

install(TARGETS ${EXEC_NAME} RUNTIME DESTINATION bin)
