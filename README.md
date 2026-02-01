# Jasper's Mace Windu Light Saber 🗡️💜

A WS2812B NeoPixel light saber built with Arduino Nano - featuring the legendary deep purple of Jedi Master Mace Windu!

## Features

✨ **Mace Windu Deep Purple Blade** - Iconic color (RGB: 120, 0, 200)
⚡ **Fast Laser Ignition** - Clean startup with no flicker
🫁 **Breathing Pulse** - Smooth breathing effect while idle
🔄 **Auto Shutdown** - Automatically powers down after 10 seconds in reverse

## Hardware Setup

### Components
- **Arduino Nano** - Microcontroller
- **WS2812B LED Strip** - 10 LEDs (expandable to 144)
- **5V Power Supply** - 30W USB for full strip
- **Breadboard & Jumper Wires** - Connections
- **USB Cable** - Programming

### Wiring
```
Arduino Pin 6 → LED Strip DIN (Data Input)
5V Power Supply → LED Strip 5V
GND (Arduino & Power) → LED Strip GND
```

## Software

### Libraries Required
- **Adafruit NeoPixel** - Install via Arduino IDE: Sketch → Include Library → Manage Libraries

### Code Structure
- `saberStartup()` - Ignition sequence (all 10 LEDs light up)
- `saberShutdown()` - Power down in reverse
- `breathingSaber()` - Idle breathing effect

## Timeline
- **0 sec** - Saber ignites
- **0-2 sec** - Power surge pulses
- **2-10 sec** - Breathing effect
- **10 sec** - Auto-shutdown (lights power down from top to bottom)

## Project Status
✅ 10 LEDs working perfectly
🔄 Testing with 30W power supply for full 144-LED strip
🎨 Color: Mace Windu deep purple

## Next Steps
- Test with all 144 LEDs using external power
- Add button control for manual toggle
- Create additional animation modes

---

**May the code be with you!** 🗡️✨
