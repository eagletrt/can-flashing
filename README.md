# can-flashing

Instructions and scripts to flash our microcontrollers via CAN bus.

Flash a .srec to a device connected to CAN bus.

## Procedure

1. Build a .bin executable (the one to flash).
2. Convert the .bin to .screc using bin2srec.

## bin2srec

bin2srec allows to convert a binary file. To use this tool first you need to compile the bin2srec command:

~~~bash
cd thirdparty/srec
make
~~~

The executable is now available.

To convert the .bin file use:

~~~bash
bin2srec -i binary.bin -a 0x8004000 -o binary.srec
~~~

Where 0x8004000 is the shift address of your project.

This is the start address of your binary in the microcontroller flash.

The flash of your microcontroller should have the bootloader and then, starting from the address chosen, the actual program.

## Bootcommander

> **TODO**: installation

This script will transmit the .srec via CAN bus.

When everything is ready the project can be flashed by resetting the microcontroller (via an appropriate *CAN message*)
and then sending the program to flash using the **bootcommander** tool, with:

- The `-t` flag set to `xcp_can`
- The selected CAN peripheral (`-d` flag)
- The *baud rate* (`-b` flag)
- The transmission ID (`-tid` flag) and the reception ID (`-rid` flag)
- The **binary executable** converted to the `.srec` format