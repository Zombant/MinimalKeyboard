# Minimal Keyboard

### To program with preinstalled DFU (USB) bootloader:
```sudo avrdude -P /dev/ttyACM0 -p atmega32u4 -c flip1 -U lfuse:w:0xFF:m -U hfuse:w:0xD9:m -U efuse:w:0xCB:m -U flash:w:/tmp/arduino_build_817300/minimal_keyboard.ino.hex```

This will wipe the bootloader and you will need ISCP for reprogramming

### To program via FTDI/ISCP:
```sudo avrdude  -P /dev/ttyACM0 -p m32u4 -c stk500v2 -U lfuse:w:0xFF:m -U hfuse:w:0xD9:m -U efuse:w:0xCB:m -U flash:w:/tmp/arduino_build_817300/minimal_keyboard.ino.hex```

Note: MISO and MOSI are NOT switched

### Leonardo Bootloader
1. Download the Arduino IDE
2. Connect FTDI adapter
3. _Tools > Board > Arduino AVR Board > Arduino Leonardo_
4. Select the USB port in _Tools > Port_
5. Select _Tools > Burn Bootloader_
6. Program with Arduino IDE

#### Interact with Pololu Programmer:
```pavr2cmd``` or ```pavr2gui```

#### Read AVR Fuses:
```avrdude -c <programmer> -p atmega32u4 -U lfuse:r:-:i -U hfuse:r:-:i -U efuse:r:-:i```
