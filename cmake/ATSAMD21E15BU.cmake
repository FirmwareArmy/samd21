message("cmsis-samd21 library path $ENV{LIBRARY_PATH}")

set(CPU "cortex-m0plus")

set(COMMON_FLAGS "${COMMON_FLAGS} -D__SAMD21E15BU__")

list(APPEND sources
	$ENV{LIBRARY_PATH}/dfp/samd21b/gcc/system_samd21.c
	$ENV{LIBRARY_PATH}/dfp/samd21b/gcc/gcc/startup_samd21.c
)

include_directories(
	$ENV{LIBRARY_PATH}/dfp/samd21b/include
	$ENV{LIBRARY_PATH}/dfp/samd21b/include
)

set(LINKER_FLAGS "${LINKER_FLAGS} -T $ENV{LIBRARY_PATH}/dfp/samd21b/gcc/gcc/samd21e15bu_flash.ld")

