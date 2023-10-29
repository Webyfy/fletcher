set(TEST_NAME 
  fletcher_test
)

add_executable (${TEST_NAME} fletcher_test.c)

target_link_libraries (${TEST_NAME} fletcher ${CRITERION_LIBRARIES})

# use C99
set_property (TARGET ${TEST_NAME} PROPERTY C_STANDARD 99)

# Enable a few warnings
if (CMAKE_COMPILER_IS_GNUCC)
  target_compile_options (${TEST_NAME} PRIVATE -Wall -Wextra)
endif (CMAKE_COMPILER_IS_GNUCC)
if (MSVC)
  target_compile_options (${TEST_NAME} PRIVATE /W4)
endif (MSVC)

add_test (${TEST_NAME} ${TEST_NAME})
