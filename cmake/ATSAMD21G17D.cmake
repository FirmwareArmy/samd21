message("cmsis-samd21 library path $ENV{LIBRARY_PATH}")

set(CPU "cortex-m0plus")

set(COMMON_FLAGS "${COMMON_FLAGS} -D__SAMD21G17D__")

list(APPEND sources
	$ENV{LIBRARY_PATH}/dfp/samd21d/gcc/system_samd21.c
	$ENV{LIBRARY_PATH}/dfp/samd21d/gcc/gcc/startup_samd21.c
)

include_directories(
	$ENV{LIBRARY_PATH}/dfp/samd21d/include
	$ENV{LIBRARY_PATH}/dfp/samd21d/include
)

set(LINKER_FLAGS "${LINKER_FLAGS} -T $ENV{LIBRARY_PATH}/dfp/samd21d/gcc/gcc/samd21g17d_flash.ld")

