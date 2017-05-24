project("Brainfuck Interpreter")

set(EXEC_NAME "bf")

add_executable(${EXEC_NAME} bf.cxx)

install(TARGETS ${EXEC_NAME} RUNTIME DESTINATION bin)
