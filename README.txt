To program via FTDI/ISCP:

'sudo avrdude -c stk500v2 -P /dev/ttyACM0 -p m32u4 -U flash:w:/tmp/arduino_build_672288/minimal_keyboard.ino.hex'
MISO and MOSI are NOT switched


To program with DFU bootloader that is preinstalled: use '-c flip1
'sudo avrdude -p atmega32u4 -c flip1 -U flash:w:/tmp/arduino_build_817300/minimal_keyboard.ino.hex'
This can be done over usb
This will wipe bootloader and you will need ISCP for programming
