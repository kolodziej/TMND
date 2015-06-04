cmake_minimum_required(VERSION 3.0.0)

project(TMND)

set(TMND_VERSION_MAJOR 0)
set(TMND_VERSION_MINOR 0)
set(TMND_VERSION_PATCH 0)

if ("${TMND_VERSION_PATCH}" GREATER 0)
  set(TMND_LIBRARY_NAME "tmnd-${TMND_VERSION_MAJOR}.${TMND_VERSION_MINOR}.${TMND_VERSION_PATCH}")
else ("${TMND_VERSION_PATCH}" GREATER 0)
  set(TMND_LIBRARY_NAME "tmnd-${TMND_VERSION_MAJOR}.${TMND_VERSION_MINOR}")
endif ("${TMND_VERSION_PATCH}" GREATER 0)

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

set(PROJECT_BINARY_DIR "${PROJECT_SOURCE_DIR}/build")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}/lib/release")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${PROJECT_BINARY_DIR}/lib/debug")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_BINARY_DIR}/bin/release")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${PROJECT_BINARY_DIR}/bin/debug")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -g -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DRELEASE")

if (NOT NOMAKE_TESTS)
  add_subdirectory(googletest)
  add_subdirectory(tests)
endif (NOT NOMAKE_TESTS)

if (NOT NOMAKE_EXAMPLES)
  add_subdirectory(examples)
endif (NOT NOMAKE_EXAMPLES)

set(LIB_TMND_SOURCES
  src/socks5/socks5.cpp
  src/socks5/request.cpp
  src/socks5/reply.cpp
  src/tor/process.cpp
)

set(LIB_TMND_HEADERS
  include/tmnd/socks5/socks5.hpp
  include/tmnd/socks5/address_type.hpp
  include/tmnd/socks5/auth_method.hpp
  include/tmnd/socks5/command.hpp
  include/tmnd/socks5/reply_code.hpp
  include/tmnd/socks5/reply.hpp
  include/tmnd/socks5/request.hpp
  include/tmnd/socks5/error.hpp
  include/tmnd/tor/process.hpp
)

if (BUILD_SHARED_LIBS)
  add_library("${TMND_LIBRARY_NAME}" SHARED "${LIB_TMND_SOURCES}" "${LIB_TMND_HEADERS}")
else (BUILD_SHARED_LIBS)
  add_library("${TMND_LIBRARY_NAME}-static" STATIC "${LIB_TMND_SOURCES}" "${LIB_TMND_HEADERS}")
endif (BUILD_SHARED_LIBS)


# target_link_libraries(exec "${Boost_LIBRARIES}")