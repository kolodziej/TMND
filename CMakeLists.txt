cmake_minimum_required(VERSION 3.0.0)

project(TMND)

set(TMND_VERSION_MAJOR 0)
set(TMND_VERSION_MINOR 0)
set(TMND_VERSION_PATCH 0)

configure_file(
  "${PROJECT_SOURCE_DIR}/include/tmnd/config/version.hpp.in"
  "${PROJECT_SOURCE_DIR}/include/tmnd/config/version.hpp"
)

find_package(Boost 1.58 COMPONENTS system program_options REQUIRED)

include_directories(
  "${PROJECT_SOURCE_DIR}/"
  "${PROJECT_SOURCE_DIR}/include"
  "${Boost_INCLUDE_DIR}"
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}/lib/release")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${PROJECT_BINARY_DIR}/lib/debug")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}/bin/release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${PROJECT_BINARY_DIR}/bin/debug")

if (NOT NOMAKE_TESTS)
  add_subdirectory(googletest)
  add_subdirectory(tests)
endif (NOT NOMAKE_TESTS)


# target_link_libraries(exec "${Boost_LIBRARIES}")