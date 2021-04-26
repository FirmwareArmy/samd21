list(APPEND sources
	${PACKAGE_PATH}/src/core++/core.cpp
)

include_directories(
	${PACKAGE_PATH}/src

	${PACKAGE_PATH}/dfp/samd21a/include
	${PACKAGE_PATH}/dfp/samd21b/include
	${PACKAGE_PATH}/dfp/samd21c/include
	${PACKAGE_PATH}/dfp/samd21d/include
)
