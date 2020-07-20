import sys
from lxml import etree
import tomlkit
import os
import re

def main():

    if len(sys.argv)!=2:
        print("usage: atdf-tool <atdf file>", file=sys.stderr)
        exit(1)
        
    atdf = sys.argv[1]
    output = os.path.abspath(os.path.join(os.path.dirname(sys.argv[0]), '..'))
    
    # open pdsc file
    tree = etree.parse(atdf).getroot()

    device = tree.xpath("//devices/device")[0].get("name").lower()
    print("device:", device)
    
    lines = [
        "#pragma once",
        "",
        "#include <cstdint>",
        "",
        "",
        "namespace core {",
        ""
        ]
    
    # in core namespace
    
    lines += get_pins(tree)
    lines += [""]
    
    lines += get_ports(tree)
    lines += [""]
    
    lines += get_mux_positions(tree)
    lines += [""]

    lines += get_sercoms(tree)
    lines += [""]

    lines += get_gclks(tree)
    lines += [""]

    lines += ["}"]
    lines += [""]
    
    # in global namespace 
    lines += ["#define _U_(x)         x ## U            /**< C code: Unsigned integer literal constant value */"]
    lines += ["#define _L_(x)         x ## L            /**< C code: Long integer literal constant value */"]
    lines += ["#define _UL_(x)        x ## UL           /**< C code: Unsigned Long integer literal constant value */"]
    lines += [""]    
    
    lines += get_typedefs(tree)
    lines += [""]

    lines += get_irqs(tree)
    lines += [""]

    lines += get_irq_handlers(tree)
    lines += [""]

    lines += get_core(tree)
    lines += [""]

    lines += get_component_includes(tree)
    lines += [""]

    lines += get_instance_includes(tree)
    lines += [""]

    lines += get_peripherals(tree)
    lines += [""]

    with open(f"src/core/{device}++.h", "w") as f:
        for line in lines:
            f.write(line+"\n")
        
def get_pins(tree):
    res = [
        "enum class pin_t : uint8_t {"
        ]
    
    pins = tree.xpath("//devices/device/peripherals/module[@name='PORT']/instance/signals/signal")
    for pin in pins:
        res += [f"\t{pin.get('pad')}={pin.get('index')},"]
    res += [f"\tCount={len(pins)}"]
    res += ["} ;"]
    return res
    
def get_ports(tree):
    res = [
        "enum class port_t : uint8_t {"
        ]
    
    pins = tree.xpath("//devices/device/peripherals/module[@name='PORT']/instance/signals/signal")
    max = 0
    for pin in pins:
        if int(pin.get('index'))>max:
            max = int(pin.get('index'))
    num = int(max/32)+1
    for port in range(num):
        res += [f"\t{chr(ord('A')+port)}={port},"]
    res += [f"\tCount={num}"]
    res += ["} ;"]
    return res

def get_mux_positions(tree):
    res = [
        "enum class mux_position_t : uint8_t {"
        ]
    
    muxes = tree.xpath("//modules/module/value-group[@name='PORT_PMUX__PMUXE']/value")
    for mux in muxes:
        res += [f"\t{mux.get('name')}={mux.get('value')},"]
    res += [f"\tCount={len(muxes)}"]
    res += ["} ;"]
    return res

def get_sercoms(tree):
    res = [
        "enum class sercom_t : uint8_t {"
        ]
    
    sercoms = tree.xpath("//devices/device/peripherals/module[@name='SERCOM']/instance")
    index = 0
    for sercom in sercoms:
        res += [f"\t{sercom.get('name')}={index},"]
        index += 1
    res += [f"\tCount={len(sercoms)}"]
    res += ["} ;"]
    res += [f"const int SERCOM_NUMBER=(int)sercom_t::Count ;"]
    return res

def get_gclks(tree):
    res = [
        "enum class gclk_gen_t : uint8_t {"
        ]
    
    gclks = tree.xpath("//modules/module/value-group[@name='GCLK_CLKCTRL__GEN']/value")
    for gclk in gclks:
        res += [f"\t{gclk.get('name')}={gclk.get('value')},"]
    res += [f"\tCount={len(gclks)}"]
    res += ["} ;"]
    return res

def get_irqs(tree):
    res = [
        "typedef enum IRQn {"
        ]
    
    interrupts = tree.xpath("//devices/device/interrupts/interrupt")
    periph_count = 0
    for interrupt in interrupts:
        res += [f"\t{interrupt.get('name')}_IRQn={interrupt.get('index')}, // {interrupt.get('caption')}"]
        if int(interrupt.get('index'))>=0:
            periph_count += 1
    nvic = tree.xpath("//devices/device/peripherals/module[@name='NVIC']/instance/parameters/param[@name='NUM_IRQ']")[0]
    res += [f"\tPERIPH_COUNT_IRQn={nvic.get('value')}"]
    res += ["} IRQn_Type ;"]
    return res

def get_irq_handlers(tree):
    res = [
        'extern "C" {'
        ]
    
    interrupts = tree.xpath("//devices/device/interrupts/interrupt")
    for interrupt in interrupts:
        res += [f"void {interrupt.get('name')}_Handler(void) ;"]
    res += ["} ;"]
    return res

def get_core(tree):
    res = []
    
    params = tree.xpath("//devices/device/parameters/param")
    for param in params:
        res += [f"#define {param.get('name')} {param.get('value')}"]
    
    res += [""]
    res += ['extern "C" {']
    res += ['#include <core_cm0plus.h>']
    res += ['}']
    return res

def get_typedefs(tree):
    res = [
        "typedef volatile const uint32_t RoReg;   /**< Read only 32-bit register (volatile const unsigned int) */",
        "typedef volatile const uint16_t RoReg16; /**< Read only 16-bit register (volatile const unsigned int) */",
        "typedef volatile const uint8_t  RoReg8;  /**< Read only  8-bit register (volatile const unsigned int) */",
        "typedef volatile       uint32_t WoReg;   /**< Write only 32-bit register (volatile unsigned int) */",
        "typedef volatile       uint16_t WoReg16; /**< Write only 16-bit register (volatile unsigned int) */",
        "typedef volatile       uint8_t  WoReg8;  /**< Write only  8-bit register (volatile unsigned int) */",
        "typedef volatile       uint32_t RwReg;   /**< Read-Write 32-bit register (volatile unsigned int) */",
        "typedef volatile       uint16_t RwReg16; /**< Read-Write 16-bit register (volatile unsigned int) */",
        "typedef volatile       uint8_t  RwReg8;  /**< Read-Write  8-bit register (volatile unsigned int) */",
        ]
    return res

def get_component_includes(tree):
    res = []
    
    modules = tree.xpath("//devices/device/peripherals/module")
    for module in modules:
        if module.get("name") not in ["FUSES", "PTC", "NVIC", "SysTick", "SystemControl"]:
            res += [f"#include <component/{module.get('name').lower()}.h>"]
        if module.get("name")=="SystemControl":
            res += [f"#include <component/sysctrl.h>"]

    return res

def get_instance_includes(tree):
    res = []
    
    instances = tree.xpath("//devices/device/peripherals/module/instance")
    for instance in instances:
        if instance.get("name") not in ["FUSES", "PTC", "NVIC", "SysTick", "SystemControl"]:
            res += [f"#include <instance/{instance.get('name').lower()}.h>"]
        if instance.get("name")=="SystemControl":
            res += [f"#include <instance/sysctrl.h>"]
            
    return res

def get_peripherals(tree):
    res = []
    
    modules = tree.xpath("//devices/device/peripherals/module")
    for module in modules:
        classname = module.get('name')[0]+module.get('name').lower()[1:]
        
        if module.get("name") not in ["FUSES", "PTC", "NVIC", "SysTick", "SystemControl"]:
            instances = module.xpath("instance")
            for instance in instances:
                address = instance.xpath("register-group")[0].get('offset')
                if instance.get("name")=="SBMATRIX":
                    classname = "Hmatrixb"
                res += [f"#define {instance.get('name')} ((::{classname}*){address}) "]
            res += [f"#define {module.get('name')}_INST_NUM {len(instances)}"]
            insts = f"#define {module.get('name')}_INSTS "+"{"
            for instance in instances:
                insts += f" {instance.get('name')},"
            insts += " }"
            res += [insts]
            res += [""]
    return res

if __name__ == "__main__":
    main()