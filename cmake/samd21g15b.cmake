if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(compiler "gcc")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(compiler "clang")
else()
    set(compiler "gcc")
endif()


list(APPEND sources
    $ENV{LIBRARY_PATH}/dfp/samd21c/${compiler}/system_samd21.c
    $ENV{LIBRARY_PATH}/dfp/samd21c/${compiler}/${compiler}/startup_samd21.c
)

include_directories(
    $ENV{LIBRARY_PATH}/dfp/samd21c/include
)


