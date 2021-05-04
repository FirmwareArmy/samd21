#include <iostream>
#include <core++/regset.h>
#include <assert.h>
#include <bitset>


typedef unsigned int uint32_t ;

typedef union {
  struct {
    uint32_t BYTE_COUNT:14;    /*!< bit:  0..13  Byte Count                         */
    uint32_t MULTI_PACKET_SIZE:14; /*!< bit: 14..27  Multi Packet In or Out size        */
    uint32_t SIZE:3;           /*!< bit: 28..30  Enpoint size                       */
    uint32_t AUTO_ZLP:1;       /*!< bit:     31  Automatic Zero Length Packet       */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} USB_DEVICE_PCKSIZE_Type;

void test_regMask() ;
void test_regClrSet() ;
void test_regClrSetVal() ;
void test_regSet() ;
void test_regSetVal() ;
void test_regClr() ;
void test_regTgl() ;

int main()
{
	volatile USB_DEVICE_PCKSIZE_Type reg ;

	test_regMask() ;
	test_regClrSet() ;
	test_regClrSetVal() ;
	test_regSet() ;
	test_regSetVal() ;
	test_regClr() ;
	test_regTgl() ;
}

void test_regMask()
{
	volatile USB_DEVICE_PCKSIZE_Type reg ;

	uint32_t mask=regMask(reg, SIZE, AUTO_ZLP) ;

	reg.reg = 0 ;
	reg.bit.SIZE = 0b111 ;
	reg.bit.AUTO_ZLP = 1 ;
//	std::cout << std::bitset<32>(mask) << '\n';
//	std::cout << std::bitset<32>(reg.reg) << '\n';

	assert(mask==reg.reg) ;
}

void test_regClrSet()
{
	volatile USB_DEVICE_PCKSIZE_Type reg={{
		.BYTE_COUNT=4,
		.MULTI_PACKET_SIZE=3,
		.SIZE=2,
		.AUTO_ZLP=1
	}} ;

	regClrSet(reg, SIZE, AUTO_ZLP) ;
	assert(reg.bit.BYTE_COUNT==0) ;
	assert(reg.bit.MULTI_PACKET_SIZE==0) ;
	assert(reg.bit.SIZE==0b111) ;
	assert(reg.bit.AUTO_ZLP==0b1) ;
}

void test_regSet()
{
	volatile USB_DEVICE_PCKSIZE_Type reg={{
		.BYTE_COUNT=4,
		.MULTI_PACKET_SIZE=3,
		.SIZE=2,
		.AUTO_ZLP=1
	}} ;

	regSet(reg, SIZE, AUTO_ZLP) ;
	assert(reg.bit.BYTE_COUNT==4) ;
	assert(reg.bit.MULTI_PACKET_SIZE==3) ;
	assert(reg.bit.SIZE==0b111) ;
	assert(reg.bit.AUTO_ZLP==1) ;
}

void test_regClrSetVal()
{
	volatile USB_DEVICE_PCKSIZE_Type reg={{
		.BYTE_COUNT=4,
		.MULTI_PACKET_SIZE=3,
		.SIZE=2,
		.AUTO_ZLP=1
	}} ;

	regClrSetVal(reg, SIZE, 1, AUTO_ZLP, 0) ;
	assert(reg.bit.BYTE_COUNT==0) ;
	assert(reg.bit.MULTI_PACKET_SIZE==0) ;
	assert(reg.bit.SIZE==1) ;
	assert(reg.bit.AUTO_ZLP==0) ;
}

void test_regSetVal()
{
	volatile USB_DEVICE_PCKSIZE_Type reg={{
		.BYTE_COUNT=4,
		.MULTI_PACKET_SIZE=3,
		.SIZE=2,
		.AUTO_ZLP=1
	}} ;

	regSetVal(reg, SIZE, 1, AUTO_ZLP, 0) ;
	assert(reg.bit.BYTE_COUNT==4) ;
	assert(reg.bit.MULTI_PACKET_SIZE==3) ;
	assert(reg.bit.SIZE==1) ;
	assert(reg.bit.AUTO_ZLP==0) ;
}

void test_regClr()
{
	volatile USB_DEVICE_PCKSIZE_Type reg={{
		.BYTE_COUNT=4,
		.MULTI_PACKET_SIZE=3,
		.SIZE=2,
		.AUTO_ZLP=1
	}} ;

	regClr(reg, SIZE, AUTO_ZLP) ;
	assert(reg.bit.BYTE_COUNT==4) ;
	assert(reg.bit.MULTI_PACKET_SIZE==3) ;
	assert(reg.bit.SIZE==0) ;
	assert(reg.bit.AUTO_ZLP==0) ;
}

void test_regTgl()
{
	volatile USB_DEVICE_PCKSIZE_Type reg={{
		.BYTE_COUNT=4,
		.MULTI_PACKET_SIZE=3,
		.SIZE=0,
		.AUTO_ZLP=0
	}} ;

	regTgl(reg, SIZE, AUTO_ZLP) ;
	assert(reg.bit.BYTE_COUNT==4) ;
	assert(reg.bit.MULTI_PACKET_SIZE==3) ;
	assert(reg.bit.SIZE==0b111) ;
	assert(reg.bit.AUTO_ZLP==1) ;

	regTgl(reg, SIZE, AUTO_ZLP) ;
	assert(reg.bit.BYTE_COUNT==4) ;
	assert(reg.bit.MULTI_PACKET_SIZE==3) ;
	assert(reg.bit.SIZE==0) ;
	assert(reg.bit.AUTO_ZLP==0) ;
}
