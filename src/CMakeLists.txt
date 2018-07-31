include_directories(../include)

set(LIBS libkusodbg)

add_executable(kuso_dbg main.c)

target_link_libraries(kuso_dbg ${LIBS})
