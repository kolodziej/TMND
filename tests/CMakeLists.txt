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

add_executable(buddy src/buddy.cpp)
target_link_libraries(buddy "${LINK_LIBS}")


