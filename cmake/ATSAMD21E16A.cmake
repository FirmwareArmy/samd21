message("cmsis-samd21 library path $ENV{LIBRARY_PATH}")

set(CPU "cortex-m0plus")

set(COMMON_FLAGS "${COMMON_FLAGS} -D__SAMD21E16A__")

list(APPEND sources
	$ENV{LIBRARY_PATH}/dfp/samd21a/gcc/system_samd21.c
	$ENV{LIBRARY_PATH}/dfp/samd21a/gcc/gcc/startup_samd21.c
)

include_directories(
	$ENV{LIBRARY_PATH}/dfp/samd21a/include
	$ENV{LIBRARY_PATH}/dfp/samd21a/include
)

set(LINKER_FLAGS "${LINKER_FLAGS} -T $ENV{LIBRARY_PATH}/dfp/samd21a/gcc/gcc/samd21e16a_flash.ld")

