if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(compiler "gcc")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(compiler "clang")
else()
    set(compiler "gcc")
endif()

set(COMMON_FLAGS "${COMMON_FLAGS} -D__SAMD21G16A__")

set(LINKER_FLAGS "${LINKER_FLAGS} -T $ENV{LIBRARY_PATH}/dfp/samd21a/${compiler}/${compiler}/samd21g16a_flash.ld")

