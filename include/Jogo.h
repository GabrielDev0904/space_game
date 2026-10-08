#ifndef JOGO_H
#define JOGO_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "Nave.h"
#include "Rocha.h"

class Jogo
{
private:
    LiquidCrystal_I2C &lcd;

    Nave nave;
    Rocha rochas[3];

    int pontos;
    bool jogando;
    bool gameOver;

    unsigned long tempoAnterior;
    unsigned long intervalo;

    int botaoCima;
    int botaoBaixo;
    int botaoEnter;

    void lerBotoes();
    void moverRochas();
    void verificarColisao();
    void desenhar();

public:
    Jogo(LiquidCrystal_I2C &lcd);

    void iniciar();
    void atualizar();
};

#endif