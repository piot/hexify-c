cmake_minimum_required(VERSION 3.17)

set(CMAKE_C_STANDARD 99)


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(isDebug TRUE)
else ()
    set(isDebug FALSE)
endif ()

if (isDebug)
    message("Debug build detected")
    add_compile_definitions(CONFIGURATION_DEBUG TYRAN_CONFIGURATION_DEBUG)
    set(CONFIGURATION_DEBUG 1)
endif ()

add_executable(hexify_test
        main.c
        test.c
)

add_test(NAME hexify_test
        COMMAND hexify_test)

if (WIN32)
    target_link_libraries(hexify_test hexify clog)
else ()
    target_link_libraries(hexify_test hexify clog m)
endif (WIN32)

