#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "Jogo.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);

Jogo jogo(lcd);

byte naveChar[8] =
{
    B00000,
    B00100,
    B01100,
    B11111,
    B01100,
    B00100,
    B00000,
    B00000
};

void setup()
{
    lcd.init();
    lcd.backlight();

    lcd.createChar(0, naveChar);

    jogo.iniciar();
}

void loop()
{
    jogo.atualizar();
}