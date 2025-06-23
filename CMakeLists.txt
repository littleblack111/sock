cmake_minimum_required(VERSION 4.0.3)

project(
  sock-tool
  VERSION 1.0.0
  DESCRIPTION "CLI tool using libsock")

set(CMAKE_CXX_STANDARD 26)
add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-parameter)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SOCK REQUIRED libsock)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(sock-tool ${SOURCES})

target_include_directories(sock-tool PRIVATE ${SOCK_INCLUDE_DIRS})
target_link_libraries(sock-tool PRIVATE ${SOCK_LIBRARIES})
target_link_directories(sock-tool PRIVATE ${SOCK_LIBRARY_DIRS})
target_compile_options(sock-tool PRIVATE ${SOCK_CFLAGS_OTHER})

install(TARGETS sock-tool DESTINATION ${CMAKE_INSTALL_BINDIR})
