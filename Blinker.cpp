#include <Arduino.h>
#include <Blinker.h>

// Klasse-implementatie
Blinker::Blinker(unsigned int ledPin, unsigned long blinkInterval, const long startdelay) {
  _ledPin = ledPin;
  _blinkInterval = blinkInterval;
  _startDelay = startdelay;

  _nu = 0;
  _volgendeBlinkOm = _nu;
}

Blinker::~Blinker() {}

int Blinker::begin() {
  pinMode(_ledPin, OUTPUT);
  _volgendeBlinkOm = _now + _blinkInterval;

  return 0;
};

int Blinker::handle() {
  int retVal = false;
  unsigned long nu = millis();

  if (nu >= _volgendeBlinkOm) {
    _volgendeBlinkOm = nu + _blinkInterval;

    digitalWrite(_ledPin, !digitalRead(_ledPin));

    retVal = true;
  }

  return retVal;
}
