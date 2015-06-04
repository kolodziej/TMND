cmake_minimum_required(VERSION 3.0.0)

project(example_socks5)

link_directories(
  "${Boost_LIBRARY_DIRS}"
  "../../build/lib/debug"
)

add_executable(socks5 "${PROJECT_SOURCE_DIR}/socks5.cpp")
if (BUILD_SHARED_LIBS)
  target_link_libraries(socks5 "${TMND_LIBRARY_NAME} ${Boost_LIBRARIES}")
else (BUILD_SHARED_LIBS)
  target_link_libraries(socks5 "${TMND_LIBRARY_NAME}-static ${Boost_LIBRARIES}")  
endif (BUILD_SHARED_LIBS)