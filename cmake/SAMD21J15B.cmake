if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(compiler "gcc")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(compiler "clang")
else()
    set(compiler "gcc")
endif()

set(COMMON_FLAGS "${COMMON_FLAGS} -D__SAMD21J15B__")

set(LINKER_FLAGS "${LINKER_FLAGS} -T ${PACKAGE_PATH}/dfp/samd21c/${compiler}/${compiler}/samd21j15b_flash.ld")

