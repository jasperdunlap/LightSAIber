# Arduino Nano WS2812B LED Strip Project

## Hardware Setup

### Components Used
- **Arduino Nano** (Intel Mac compatible, plugged into MacBook via USB)
- **WS2812B LED Strip** - 144 LEDs total (currently testing with 10 LEDs)
- **Breadboard** - for connections
- **Jumper wires** - for wiring connections
- **5V Power Supply** - 30W USB power block (for powering LED strip)
- **USB Cable** - connects Arduino to MacBook for uploading code

### Wiring Configuration
```
MacBook USB → Arduino Nano (for programming only)

5V Power Supply USB
├─ 5V (red wire) → LED strip red wire (5V)
└─ GND (black wire) → LED strip black wire (GND) + Arduino GND (common ground)

Arduino Pin 6 → LED strip green wire (DIN - data input)
```

### Pin Connections on Arduino Nano
- **Pin 6** = Data line (DIN) to LED strip
- **5V pin** = Power (connected to 30W power supply)
- **GND pins** (either one) = Ground

### Key Power Information
- MacBook USB = ~1A max = supports ~10 LEDs safely
- 30W USB power supply = 2-3+ amps = supports 144+ LEDs
- Each WS2812B LED draws ~60mA at full white brightness
- For full 144-LED strip: need external 5V power supply

## Software Setup

### Libraries Required
- **Adafruit NeoPixel** - Install via Arduino IDE: Sketch → Include Library → Manage Libraries

### Current Code Status
- File: `sketch_jan31a.ino`
- Currently configured for 10 LEDs (LED_COUNT = 10)
- All LEDs turned OFF (cleared)
- Baud rate: 9600

### Previous Code Examples Tested
1. **LED Blink Test** - Verified Arduino uploads working (built-in LED on pin 13)
2. **Laser Scanning Effect** - Single point of light moving back/forth in different colors
3. **Color Fill Effect** - All LEDs fill with solid colors
4. **Star Wars Theme Animation** - Creative animation with cascading lights and pulses

## Next Steps

- Figure out how to get more than 5V of power to the Arduino Nano so that we can power all the lights
- Test with full 144-LED strip using 30W power supply
- Expand animations and create more complex light patterns
