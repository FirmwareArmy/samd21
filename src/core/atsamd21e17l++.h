#pragma once

#include <cstdint>


namespace core {

enum class pin_t : uint8_t {
	PA02=2,
	PA03=3,
	PA04=4,
	PA05=5,
	PA06=6,
	PA07=7,
	PA08=8,
	PA09=9,
	PA10=10,
	PA11=11,
	PA14=14,
	PA15=15,
	PA16=16,
	PA17=17,
	PA18=18,
	PA19=19,
	PA22=22,
	PA23=23,
	PA24=24,
	PA25=25,
	PA30=30,
	PA31=31,
	PB02=34,
	PB03=35,
	PB04=36,
	PB05=37,
	Count=26
}


enum class port_t : uint8_t {
	A=0,
	B=1,
	Count=2
}


enum class mux_position_t : uint8_t {
	A=0x0,
	B=0x1,
	C=0x2,
	D=0x3,
	E=0x4,
	F=0x5,
	G=0x6,
	H=0x7,
	Count=8
}


enum class sercom_t : uint8_t {
	SERCOM0=0,
	SERCOM1=1,
	SERCOM2=2,
	SERCOM3=3,
	Count=4
}



}
