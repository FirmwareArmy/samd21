message("samd21 library path ${LIBRARY_PATH}")

list(APPEND sources
	${LIBRARY_PATH}/src/core/Core.cpp
)

include_directories(
	${LIBRARY_PATH}/src

	${LIBRARY_PATH}/dfp/samd21a/include
	${LIBRARY_PATH}/dfp/samd21b/include
	${LIBRARY_PATH}/dfp/samd21c/include
	${LIBRARY_PATH}/dfp/samd21d/include
)
