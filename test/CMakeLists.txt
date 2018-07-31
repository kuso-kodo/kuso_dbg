enable_testing()
set(LIBS libkusodbg)
include_directories(. ../include)

add_executable(load_inferior_test load_inferior_test.c)

target_link_libraries(load_inferior_test ${LIBS})

add_test(load_inferior_test ${CMAKE_CURRENT_BINARY_DIR}/load_inferior_test)

add_subdirectory(inferior)
