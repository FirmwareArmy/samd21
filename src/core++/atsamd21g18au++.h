#pragma once

#include <cstdint>


#define _U_(x)         x ## U            /**< C code: Unsigned integer literal constant value */
#define _L_(x)         x ## L            /**< C code: Long integer literal constant value */
#define _UL_(x)        x ## UL           /**< C code: Unsigned Long integer literal constant value */

typedef volatile const uint32_t RoReg;   /**< Read only 32-bit register (volatile const unsigned int) */
typedef volatile const uint16_t RoReg16; /**< Read only 16-bit register (volatile const unsigned int) */
typedef volatile const uint8_t  RoReg8;  /**< Read only  8-bit register (volatile const unsigned int) */
typedef volatile       uint32_t WoReg;   /**< Write only 32-bit register (volatile unsigned int) */
typedef volatile       uint16_t WoReg16; /**< Write only 16-bit register (volatile unsigned int) */
typedef volatile       uint8_t  WoReg8;  /**< Write only  8-bit register (volatile unsigned int) */
typedef volatile       uint32_t RwReg;   /**< Read-Write 32-bit register (volatile unsigned int) */
typedef volatile       uint16_t RwReg16; /**< Read-Write 16-bit register (volatile unsigned int) */
typedef volatile       uint8_t  RwReg8;  /**< Read-Write  8-bit register (volatile unsigned int) */

typedef enum IRQn {
	Reset_IRQn=-15, // Reset Vector, invoked on Power up and warm reset
	NonMaskableInt_IRQn=-14, // Non maskable Interrupt, cannot be stopped or preempted
	HardFault_IRQn=-13, // Hard Fault, all classes of Fault
	SVCall_IRQn=-5, // System Service Call via SVC instruction
	PendSV_IRQn=-2, // Pendable request for system service
	SysTick_IRQn=-1, // System Tick Timer
	PM_IRQn=0, // Power Manager
	SYSCTRL_IRQn=1, // System Controller
	WDT_IRQn=2, // Watchdog Timer
	RTC_IRQn=3, // Real Time Counter
	EIC_IRQn=4, // External Interrupt Controller
	NVMCTRL_IRQn=5, // Non-Volatile Memory Controller
	DMAC_IRQn=6, // Direct Memory Controller
	USB_IRQn=7, // Universal Serial Bus
	EVSYS_IRQn=8, // Event Systems
	SERCOM0_IRQn=9, // Serial Communication Interface 0
	SERCOM1_IRQn=10, // Serial Communication Interface 1
	SERCOM2_IRQn=11, // Serial Communication Interface 2
	SERCOM3_IRQn=12, // Serial Communication Interface 3
	SERCOM4_IRQn=13, // Serial Communication Interface 4
	SERCOM5_IRQn=14, // Serial Communication Interface 5
	TCC0_IRQn=15, // Timer/Counter for Control Applications 0
	TCC1_IRQn=16, // Timer/Counter for Control Applications 1
	TCC2_IRQn=17, // Timer/Counter for Control Applications 2
	TC3_IRQn=18, // Timer/Counter 3
	TC4_IRQn=19, // Timer/Counter 4
	TC5_IRQn=20, // Timer/Counter 5
	TC6_IRQn=21, // Timer/Counter 6
	TC7_IRQn=22, // Timer/Counter 7
	ADC_IRQn=23, // Analog-to-Digital Converter
	AC_IRQn=24, // Analog Comparators
	DAC_IRQn=25, // Digital-to-Analog Converter
	PTC_IRQn=26, // Peripheral Touch Controller
	I2S_IRQn=27, // Inter-IC Sound Controller
	PERIPH_COUNT_IRQn=28
} IRQn_Type ;

extern "C" {
void Reset_Handler(void) ;
void NonMaskableInt_Handler(void) ;
void HardFault_Handler(void) ;
void SVCall_Handler(void) ;
void PendSV_Handler(void) ;
void SysTick_Handler(void) ;
void PM_Handler(void) ;
void SYSCTRL_Handler(void) ;
void WDT_Handler(void) ;
void RTC_Handler(void) ;
void EIC_Handler(void) ;
void NVMCTRL_Handler(void) ;
void DMAC_Handler(void) ;
void USB_Handler(void) ;
void EVSYS_Handler(void) ;
void SERCOM0_Handler(void) ;
void SERCOM1_Handler(void) ;
void SERCOM2_Handler(void) ;
void SERCOM3_Handler(void) ;
void SERCOM4_Handler(void) ;
void SERCOM5_Handler(void) ;
void TCC0_Handler(void) ;
void TCC1_Handler(void) ;
void TCC2_Handler(void) ;
void TC3_Handler(void) ;
void TC4_Handler(void) ;
void TC5_Handler(void) ;
void TC6_Handler(void) ;
void TC7_Handler(void) ;
void ADC_Handler(void) ;
void AC_Handler(void) ;
void DAC_Handler(void) ;
void PTC_Handler(void) ;
void I2S_Handler(void) ;
} ;

#define NUM_IRQ 28
#define __CM0PLUS_REV 0x0001
#define __MPU_PRESENT 0
#define __NVIC_PRIO_BITS 2
#define __VTOR_PRESENT 1
#define __Vendor_SysTickConfig 0
#define __ARCH_ARM 1
#define __ARCH_ARM_CORTEX_M 1
#define __DEVICE_IS_SAM 1

extern "C" {
#include <core_cm0plus.h>
}

#include <component/ac.h>
#include <component/adc.h>
#include <component/dac.h>
#include <component/dmac.h>
#include <component/dsu.h>
#include <component/eic.h>
#include <component/evsys.h>
#include <component/gclk.h>
#include <component/hmatrixb.h>
#include <component/i2s.h>
#include <component/mtb.h>
#include <component/nvmctrl.h>
#include <component/pac.h>
#include <component/pm.h>
#include <component/port.h>
#include <component/rtc.h>
#include <component/sercom.h>
#include <component/sysctrl.h>
#include <component/tc.h>
#include <component/tcc.h>
#include <component/usb.h>
#include <component/wdt.h>
#include <component/sysctrl.h>

#include <instance/ac.h>
#include <instance/adc.h>
#include <instance/dac.h>
#include <instance/dmac.h>
#include <instance/dsu.h>
#include <instance/eic.h>
#include <instance/evsys.h>
#include <instance/gclk.h>
#include <instance/sbmatrix.h>
#include <instance/i2s.h>
#include <instance/mtb.h>
#include <instance/nvmctrl.h>
#include <instance/pac0.h>
#include <instance/pac1.h>
#include <instance/pac2.h>
#include <instance/pm.h>
#include <instance/port.h>
#include <instance/rtc.h>
#include <instance/sercom0.h>
#include <instance/sercom1.h>
#include <instance/sercom2.h>
#include <instance/sercom3.h>
#include <instance/sercom4.h>
#include <instance/sercom5.h>
#include <instance/sysctrl.h>
#include <instance/tc3.h>
#include <instance/tc4.h>
#include <instance/tc5.h>
#include <instance/tc6.h>
#include <instance/tc7.h>
#include <instance/tcc0.h>
#include <instance/tcc1.h>
#include <instance/tcc2.h>
#include <instance/usb.h>
#include <instance/wdt.h>
#include <instance/sysctrl.h>

namespace core {

enum class pin_t : uint8_t {
	PA00=0,
	PA01=1,
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
	PA12=12,
	PA13=13,
	PA14=14,
	PA15=15,
	PA16=16,
	PA17=17,
	PA18=18,
	PA19=19,
	PA20=20,
	PA21=21,
	PA22=22,
	PA23=23,
	PA24=24,
	PA25=25,
	PA27=27,
	PA28=28,
	PA30=30,
	PA31=31,
	PB02=34,
	PB03=35,
	PB04=36,
	PB08=40,
	PB09=41,
	Count=35
} ;

enum class port_t : uint8_t {
	A=0,
	B=1,
	Count=2
} ;
inline ::Port* const PORT=(::Port*)0x41004400 ;
inline ::Port* const PORT_INSTS[]={ PORT, } ;

inline ::Sysctrl* const SYSCTRL=(::Sysctrl*)0x40000800 ;

inline ::Pm* const PM=(::Pm*)0x40000400 ;

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
} ;

enum class sercom_t : uint8_t {
	SERCOM0=0,
	SERCOM1=1,
	SERCOM2=2,
	SERCOM3=3,
	SERCOM4=4,
	SERCOM5=5,
	Count=6
} ;
#define SERCOM_NUMBER 6
inline ::Sercom* const SERCOM0=(::Sercom*)0x42000800 ;
inline ::Sercom* const SERCOM1=(::Sercom*)0x42000C00 ;
inline ::Sercom* const SERCOM2=(::Sercom*)0x42001000 ;
inline ::Sercom* const SERCOM3=(::Sercom*)0x42001400 ;
inline ::Sercom* const SERCOM4=(::Sercom*)0x42001800 ;
inline ::Sercom* const SERCOM5=(::Sercom*)0x42001C00 ;
inline ::Sercom* const SERCOM_INSTS[]={ SERCOM0, SERCOM1, SERCOM2, SERCOM3, SERCOM4, SERCOM5, } ;

enum class gclk_gen_t : uint8_t {
	GCLK0=0x0,
	GCLK1=0x1,
	GCLK2=0x2,
	GCLK3=0x3,
	GCLK4=0x4,
	GCLK5=0x5,
	GCLK6=0x6,
	GCLK7=0x7,
	GCLK8=0x8,
	Count=9
} ;
inline ::Gclk* const GCLK=(::Gclk*)0x40000C00 ;

struct sercom_pad_mux_t
{
    int pad    :16  ;
    mux_position_t mux  ;
} ;
sercom_pad_mux_t sercom_pin_to_pad(sercom_t sercom, pin_t pin) ;

inline ::Eic* const EIC=(::Eic*)0x40001800 ;
inline ::Eic* const EIC_INSTS[]={ EIC, } ;
#define EXTINT_NUMBER 34
#define NMI_NUMBER 1

int8_t pin_to_extint(pin_t pin) ;
int8_t pin_to_nmi(pin_t pin) ;

enum class tc_t : uint8_t {
	TC3=0,
	TC4=1,
	TC5=2,
	TC6=3,
	TC7=4,

	TC4_32=1, // 32 bits TC consumes two 16 bits TC
	TC6_32=3, // 32 bits TC consumes two 16 bits TC

	Count=5
} ;
#define TC_NUMBER 5
inline ::Tc* const TC3=(::Tc*)0x42002C00 ;
inline ::Tc* const TC4=(::Tc*)0x42003000 ;
inline ::Tc* const TC5=(::Tc*)0x42003400 ;
inline ::Tc* const TC6=(::Tc*)0x42003800 ;
inline ::Tc* const TC7=(::Tc*)0x42003C00 ;
inline ::Tc* const TC_INSTS[]={ TC3, TC4, TC5, TC6, TC7, } ;

inline ::Nvmctrl* const NVMCTRL=(::Nvmctrl*)0x41004000 ;
const uint32_t FLASH_SIZE=262144 ;
const uint32_t PAGE_SIZE=64 ;
const uint32_t PAGES=4096 ;
const uint32_t ROW_PAGES=4 ;
const uint32_t PAGES_PR_REGION=256 ;
const uint32_t USER_PAGE_OFFSET=0x00800000 ;
inline void* const NVMCTRL_CAL=(void*)0x00800000UL ;
inline void* const NVMCTRL_AUX3=(void*)0x0080A000UL ;
inline void* const NVMCTRL_LOCKBIT=(void*)0x00802000UL ;
inline void* const NVMCTRL_OTP1=(void*)0x00806000UL ;
inline void* const NVMCTRL_OTP2=(void*)0x00806008UL ;
inline void* const NVMCTRL_OTP4=(void*)0x00806020UL ;
inline void* const NVMCTRL_TEMP_LOG=(void*)0x00806030UL ;

inline ::Usb* const USB=(::Usb*)0x41005000 ;

inline ::Dsu* const DSU=(::Dsu*)0x41002000 ;

}

