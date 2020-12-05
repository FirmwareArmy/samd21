message("cmsis-samd21 library path $ENV{LIBRARY_PATH}")

set(CPU "cortex-m0plus")

set(COMMON_FLAGS "${COMMON_FLAGS} -D__SAMD21G17L__")

list(APPEND sources
	$ENV{LIBRARY_PATH}/dfp/samd21d/${CMAKE_CXX_COMPILER_ID}/system_samd21.c
	$ENV{LIBRARY_PATH}/dfp/samd21d/${CMAKE_CXX_COMPILER_ID}/${CMAKE_CXX_COMPILER_ID}/startup_samd21.c
)

include_directories(
	$ENV{LIBRARY_PATH}/dfp/samd21d/include
	$ENV{LIBRARY_PATH}/dfp/samd21d/include
)

set(LINKER_FLAGS "${LINKER_FLAGS} -T $ENV{LIBRARY_PATH}/dfp/samd21d/${CMAKE_CXX_COMPILER_ID}/${CMAKE_CXX_COMPILER_ID}/samd21g17l_flash.ld")

