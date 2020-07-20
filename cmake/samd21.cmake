message("samd21 library path ${LIBRARY_PATH}")

list(APPEND sources
)

include_directories(
	${LIBRARY_PATH}/src

	${LIBRARY_PATH}/dfp/samd21a/include
	${LIBRARY_PATH}/dfp/samd21b/include
	${LIBRARY_PATH}/dfp/samd21c/include
	${LIBRARY_PATH}/dfp/samd21d/include
)
