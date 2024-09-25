cmake_minimum_required(VERSION 3.16.3)
project(hexify C)
enable_testing()

add_subdirectory(src)
add_subdirectory(deps/piot/tiny-libc/src/lib)
add_subdirectory(deps/piot/clog/src/lib)
