cmake_minimum_required(VERSION 3.0.0)

project(socks5_example)

link_directories(
  "${Boost_LIBRARY_DIRS}"
  "../../build/lib/debug"
)

add_executable(socks5 "${PROJECT_SOURCE_DIR}/socks5.cpp")
if (BUILD_SHARED_LIBS)
  set(LINK_LIBS "${TMND_LIBRARY_NAME}" "${Boost_LIBRARIES}" pthread)
else (BUILD_SHARED_LIBS)
  set(LINK_LIBS "${TMND_LIBRARY_NAME}-static" "${Boost_LIBRARIES}" pthread)
endif (BUILD_SHARED_LIBS)

target_link_libraries(socks5 "${LINK_LIBS}")