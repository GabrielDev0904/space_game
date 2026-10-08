#include "Rocha.h"
#include <Arduino.h>

Rocha::Rocha()
{
    iniciar();
}

void Rocha::iniciar()
{
    linha = random(0, 4);
    coluna = 19;
}

void Rocha::mover()
{
    coluna--;
}

int Rocha::getLinha()
{
    return linha;
}

int Rocha::getColuna()
{
    return coluna;
}