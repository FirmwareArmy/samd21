message("cmsis-samd21 library path $ENV{LIBRARY_PATH}")

set(CPU "cortex-m0plus")

set(COMMON_FLAGS "${COMMON_FLAGS} -D__SAMD21J15A__")

list(APPEND sources
	$ENV{LIBRARY_PATH}/dfp/samd21a/${CMAKE_CXX_COMPILER_ID}/system_samd21.c
	$ENV{LIBRARY_PATH}/dfp/samd21a/${CMAKE_CXX_COMPILER_ID}/${CMAKE_CXX_COMPILER_ID}/startup_samd21.c
)

include_directories(
	$ENV{LIBRARY_PATH}/dfp/samd21a/include
	$ENV{LIBRARY_PATH}/dfp/samd21a/include
)

set(LINKER_FLAGS "${LINKER_FLAGS} -T $ENV{LIBRARY_PATH}/dfp/samd21a/${CMAKE_CXX_COMPILER_ID}/${CMAKE_CXX_COMPILER_ID}/samd21j15a_flash.ld")

