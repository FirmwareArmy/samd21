if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(compiler "gcc")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(compiler "clang")
else()
    set(compiler "gcc")
endif()


list(APPEND sources
    ${PACKAGE_PATH}/dfp/samd21d/${compiler}/system_samd21.c
    ${PACKAGE_PATH}/dfp/samd21d/${compiler}/${compiler}/startup_samd21.c
)

include_directories(
    ${PACKAGE_PATH}/dfp/samd21d/include
)


