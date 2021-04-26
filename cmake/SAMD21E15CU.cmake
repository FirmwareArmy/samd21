if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(compiler "gcc")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(compiler "clang")
else()
    set(compiler "gcc")
endif()

set(COMMON_FLAGS "${COMMON_FLAGS} -D__SAMD21E15CU__")

set(LINKER_FLAGS "${LINKER_FLAGS} -T $ENV{LIBRARY_PATH}/dfp/samd21c/${compiler}/${compiler}/samd21e15cu_flash.ld")

