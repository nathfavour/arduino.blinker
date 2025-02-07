// This Arduino sketch blinks the main LED in a repeating pattern:
// three blinks in one second, then one blink in the next second, and so on.

const int ledPin = LED_BUILTIN;  // Use the built-in LED pin

void setup() {
  pinMode(ledPin, OUTPUT);
}

void blinkForDuration(int blinks, int durationMs) {
  // Calculate the interval for each blink cycle
  int interval = durationMs / blinks;

  for (int i = 0; i < blinks; i++) {
    digitalWrite(ledPin, HIGH);
    delay(100); // LED on for 100 ms
    digitalWrite(ledPin, LOW);
    // Ensure we don't delay too long if the blink duration is short
    int offDelay = interval - 100;
    if (offDelay < 0) offDelay = 0;
    delay(offDelay);
  }
}

void loop() {
  // Blink 3 times during the first second
  blinkForDuration(3, 1000);
  // Blink 1 time during the next second
  blinkForDuration(1, 1000);
}