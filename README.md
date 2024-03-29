# Minimal Keyboard
### To program with preinstalled DFU (USB) bootloader:
```sudo avrdude -p atmega32u4 -c flip1 -U flash:w:/tmp/arduino_build_817300/minimal_keyboard.ino.hex```

This will wipe the bootloader and you will need ISCP for programming

### To program via FTDI/ISCP:
```sudo avrdude -c stk500v2 -P /dev/ttyACM0 -p m32u4 -U flash:w:/tmp/arduino_build_672288/minimal_keyboard.ino.hex'```

Note: MISO and MOSI are NOT switched

#### Interact with Pololu Programmer:
```pavr2cmd``` or ```pavr2gui```
