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
    
    lines += get_pins(tree)
    lines += ["\n"]
    
    lines += get_ports(tree)
    lines += ["\n"]
    
    lines += get_mux_positions(tree)
    lines += ["\n"]

    lines += get_sercoms(tree)
    lines += ["\n"]

    lines += ["", "}"]
    
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
    res += "}"
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
    res += "}"
    return res

def get_mux_positions(tree):
    res = [
        "enum class mux_position_t : uint8_t {"
        ]
    
    muxes = tree.xpath("//modules/module/value-group[@name='PORT_PMUX__PMUXE']/value")
    for mux in muxes:
        res += [f"\t{mux.get('name')}={mux.get('value')},"]
    res += [f"\tCount={len(muxes)}"]
    res += "}"
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
    res += "}"
    return res

if __name__ == "__main__":
    main()
