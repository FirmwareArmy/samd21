#include <core++/samd21e15cu++.h>
#include <assert.h>

#pragma GCC diagnostic ignored "-Waggregate-return"

namespace core {

sercom_pad_mux_t sercom_pin_to_pad(sercom_t sercom, pin_t pin)
{
    if(sercom==sercom_t::SERCOM0)
    {
        if(pin==pin_t::PA04)
            return {0, mux_position_t::D} ;
        if(pin==pin_t::PA08)
            return {0, mux_position_t::C} ;
        if(pin==pin_t::PA05)
            return {1, mux_position_t::D} ;
        if(pin==pin_t::PA09)
            return {1, mux_position_t::C} ;
        if(pin==pin_t::PA06)
            return {2, mux_position_t::D} ;
        if(pin==pin_t::PA10)
            return {2, mux_position_t::C} ;
        if(pin==pin_t::PA07)
            return {3, mux_position_t::D} ;
        if(pin==pin_t::PA11)
            return {3, mux_position_t::C} ;
    }

    if(sercom==sercom_t::SERCOM1)
    {
        if(pin==pin_t::PA16)
            return {0, mux_position_t::C} ;
        if(pin==pin_t::PA00)
            return {0, mux_position_t::D} ;
        if(pin==pin_t::PA17)
            return {1, mux_position_t::C} ;
        if(pin==pin_t::PA01)
            return {1, mux_position_t::D} ;
        if(pin==pin_t::PA30)
            return {2, mux_position_t::D} ;
        if(pin==pin_t::PA18)
            return {2, mux_position_t::C} ;
        if(pin==pin_t::PA31)
            return {3, mux_position_t::D} ;
        if(pin==pin_t::PA19)
            return {3, mux_position_t::C} ;
    }

    if(sercom==sercom_t::SERCOM2)
    {
        if(pin==pin_t::PA08)
            return {0, mux_position_t::D} ;
        if(pin==pin_t::PA09)
            return {1, mux_position_t::D} ;
        if(pin==pin_t::PA10)
            return {2, mux_position_t::D} ;
        if(pin==pin_t::PA14)
            return {2, mux_position_t::C} ;
        if(pin==pin_t::PA11)
            return {3, mux_position_t::D} ;
        if(pin==pin_t::PA15)
            return {3, mux_position_t::C} ;
    }

    if(sercom==sercom_t::SERCOM3)
    {
        if(pin==pin_t::PA16)
            return {0, mux_position_t::D} ;
        if(pin==pin_t::PA22)
            return {0, mux_position_t::C} ;
        if(pin==pin_t::PA17)
            return {1, mux_position_t::D} ;
        if(pin==pin_t::PA23)
            return {1, mux_position_t::C} ;
        if(pin==pin_t::PA18)
            return {2, mux_position_t::D} ;
        if(pin==pin_t::PA24)
            return {2, mux_position_t::C} ;
        if(pin==pin_t::PA19)
            return {3, mux_position_t::D} ;
        if(pin==pin_t::PA25)
            return {3, mux_position_t::C} ;
    }

    assert(false) ;
    return { -1, mux_position_t::Count } ; // dummy return to avoid compiler warning
}

int8_t pin_to_extint(pin_t pin)
{
    switch(pin)
    {
    case pin_t::PA16:
        return 0 ;
    case pin_t::PA00:
        return 0 ;
    case pin_t::PA17:
        return 1 ;
    case pin_t::PA01:
        return 1 ;
    case pin_t::PA02:
        return 2 ;
    case pin_t::PA18:
        return 2 ;
    case pin_t::PA03:
        return 3 ;
    case pin_t::PA19:
        return 3 ;
    case pin_t::PA04:
        return 4 ;
    case pin_t::PA05:
        return 5 ;
    case pin_t::PA06:
        return 6 ;
    case pin_t::PA22:
        return 6 ;
    case pin_t::PA07:
        return 7 ;
    case pin_t::PA23:
        return 7 ;
    case pin_t::PA28:
        return 8 ;
    case pin_t::PA09:
        return 9 ;
    case pin_t::PA10:
        return 10 ;
    case pin_t::PA30:
        return 10 ;
    case pin_t::PA11:
        return 11 ;
    case pin_t::PA31:
        return 11 ;
    case pin_t::PA24:
        return 12 ;
    case pin_t::PA25:
        return 13 ;
    case pin_t::PA14:
        return 14 ;
    case pin_t::PA27:
        return 15 ;
    case pin_t::PA15:
        return 15 ;
    default:
        assert(false) ;
        return -1 ;
    }
}

int8_t pin_to_nmi(pin_t pin)
{
    switch(pin)
    {
    case pin_t::PA08:
        return 0 ;
    default:
        assert(false) ;
        return -1 ;
    }
}


}

