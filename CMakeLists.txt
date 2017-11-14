project("Brainfuck Interpreter")

set(EXEC_NAME "bf")

add_executable(${EXEC_NAME} bf.cpp)

install(TARGETS ${EXEC_NAME} RUNTIME DESTINATION bin)
