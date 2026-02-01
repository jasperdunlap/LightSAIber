#include <Adafruit_NeoPixel.h>

// WS2812B LED strip configuration
#define LED_PIN 6           // Data pin connected to pin 6
#define LED_COUNT 10        // Number of LEDs (testing with 10)
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// State tracking
unsigned long startupTime = 0;
boolean isRunning = true;

void setup() {
  // Initialize built-in LED pin
  pinMode(13, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Arduino Nano is running! Hi Jasper!");
  
  // Initialize WS2812B strip
  strip.begin();
  strip.show();  // Initialize all pixels to off
  Serial.println("LED strip initialized!");
  
  delay(500);
  saberStartup();  // Mace Windu's deep purple startup!
}

void loop() {
  if (isRunning) {
    // Mace Windu's breathing blade - deep purple glow
    breathingSaber();
    
    // Check if 10 seconds have passed since startup
    if (millis() - startupTime >= 10000) {
      saberShutdown();
      isRunning = false;  // Shutdown complete
    }
  }
}

void starWarsTheme() {
  // Opening dramatic flash - yellow
  for(int flash = 0; flash < 3; flash++) {
    fillAllLEDs(strip.Color(255, 255, 0), 150);  // Yellow flash
    strip.clear();
    strip.show();
    delay(150);
  }
  
  // Descending opening notes - blue cascade from right to left
  for(int i = 9; i >= 0; i--) {
    strip.clear();
    strip.setPixelColor(i, strip.Color(0, 100, 255)); // Blue
    strip.show();
    delay(120);
  }
  
  // Rising pattern - red wave going left to right
  for(int i = 0; i < 10; i++) {
    strip.clear();
    strip.setPixelColor(i, strip.Color(255, 0, 0)); // Red
    strip.show();
    delay(100);
  }
  
  // Double pulse - dramatic moment
  for(int pulse = 0; pulse < 2; pulse++) {
    fillAllLEDs(strip.Color(255, 100, 0), 200);  // Orange
    strip.clear();
    strip.show();
    delay(200);
  }
  
  // Sweeping back and forth - cyan
  for(int sweep = 0; sweep < 2; sweep++) {
    for(int i = 0; i < 10; i++) {
      strip.clear();
      if(i > 0) strip.setPixelColor(i - 1, strip.Color(0, 255, 100)); // Dimmer
      strip.setPixelColor(i, strip.Color(0, 255, 255)); // Cyan bright
      strip.show();
      delay(60);
    }
    for(int i = 9; i >= 0; i--) {
      strip.clear();
      if(i < 9) strip.setPixelColor(i + 1, strip.Color(0, 255, 100)); // Dimmer
      strip.setPixelColor(i, strip.Color(0, 255, 255)); // Cyan bright
      strip.show();
      delay(60);
    }
  }
  
  // Grand finale - all colors lighting up simultaneously
  strip.setPixelColor(0, strip.Color(255, 0, 0));      // Red
  strip.setPixelColor(1, strip.Color(0, 255, 0));      // Green
  strip.setPixelColor(2, strip.Color(0, 0, 255));      // Blue
  strip.setPixelColor(3, strip.Color(255, 255, 0));    // Yellow
  strip.setPixelColor(4, strip.Color(255, 0, 255));    // Magenta
  strip.setPixelColor(5, strip.Color(0, 255, 255));    // Cyan
  strip.setPixelColor(6, strip.Color(255, 100, 0));    // Orange
  strip.setPixelColor(7, strip.Color(255, 0, 100));    // Pink
  strip.setPixelColor(8, strip.Color(100, 255, 0));    // Lime
  strip.setPixelColor(9, strip.Color(255, 255, 255));  // White
  strip.show();
  delay(400);
  
  // Rainbow pulse finish
  for(int pulse = 0; pulse < 2; pulse++) {
    strip.clear();
    strip.show();
    delay(150);
    fillAllLEDs(strip.Color(255, 255, 255), 150); // White pulse
  }
}

// Fill all LEDs with a color and hold for specified time
void fillAllLEDs(uint32_t color, int holdTime) {
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
  delay(holdTime);
}

// Blink all LEDs a specified number of times
void blinkLEDs(uint32_t color, int blinks, int delayTime) {
  for(int b = 0; b < blinks; b++) {
    // Turn on
    for(int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, color);
    }
    strip.show();
    delay(delayTime / 2);
    
    // Turn off
    strip.clear();
    strip.show();
    delay(delayTime / 2);
  }
}

// Mace Windu's deep purple saber startup - clean and fast!
void saberStartup() {
  // Phase 1: Fast laser ignition - lights bloom quickly from bottom to top (no flicker)
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(120, 0, 200));  // Deep purple
    strip.show();
    delay(25);  // Clean and fast
  }
  
  // Phase 2: Power surge - nice pulse as blade reaches full strength
  for (int pulse = 0; pulse < 2; pulse++) {
    for (int brightness = 150; brightness <= 255; brightness += 15) {
      strip.setBrightness(brightness);
      strip.show();
      delay(15);
    }
    for (int brightness = 255; brightness >= 150; brightness -= 15) {
      strip.setBrightness(brightness);
      strip.show();
      delay(15);
    }
  }
  
  // Reset to normal brightness for breathing
  strip.setBrightness(255);
  
  // Record startup time for 10-second timer
  startupTime = millis();
}

// Mace Windu's saber shutdown - reverse of startup!
void saberShutdown() {
  Serial.println("Saber shutting down...");
  
  // Phase 1: Power down pulse - reverse of the power surge
  for (int pulse = 0; pulse < 2; pulse++) {
    for (int brightness = 150; brightness <= 255; brightness += 15) {
      strip.setBrightness(brightness);
      strip.show();
      delay(15);
    }
    for (int brightness = 255; brightness >= 150; brightness -= 15) {
      strip.setBrightness(brightness);
      strip.show();
      delay(15);
    }
  }
  
  // Phase 2: Lights shut down from top to bottom (reverse order)
  for (int i = LED_COUNT - 1; i >= 0; i--) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.show();
    delay(25);  // Same speed as startup
  }
  
  // All lights off
  strip.clear();
  strip.show();
  
  Serial.println("Saber offline.");
}

// Breathing effect - fades in and out like the Force flowing
void breathingSaber() {
  // Fade in - breathing inward
  for (int brightness = 50; brightness <= 255; brightness += 5) {
    strip.setBrightness(brightness);
    strip.show();
    delay(15);  // Faster!
  }
  
  // Hold at full brightness briefly
  delay(200);
  
  // Fade out - breathing outward
  for (int brightness = 255; brightness >= 50; brightness -= 5) {
    strip.setBrightness(brightness);
    strip.show();
    delay(15);  // Faster!
  }
  
  // Brief pause before next breath
  delay(100);  // Faster!
}
