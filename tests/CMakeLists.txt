cmake_minimum_required(VERSION 3.0.0)

link_directories(
  "../googletest/"
  "../build/lib/debug/"
)

include_directories(
  "../googletest/include/"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/tests/bin")

set(LINK_LIBS gtest gtest_main "${TMND_LIBRARY_NAME}-static")

set(TESTS
  "buddy"
  "message"
  "archive"
)

foreach(TEST ${TESTS})
  add_executable("${TEST}" "src/${TEST}.cpp")
  target_link_libraries("${TEST}" "${LINK_LIBS}")
endforeach(TEST)

