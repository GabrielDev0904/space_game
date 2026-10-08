#include "Nave.h"

Nave::Nave()
{
    linha = 1;
    coluna = 0;
}

void Nave::subir()
{
    if (linha > 0)
    {
        linha--;
    }
}

void Nave::descer()
{
    if(linha < 3)
    {
        linha++;
    }
}

int Nave::getLinha()
{
    return linha;
}

int Nave::getColuna()
{
    return coluna;
}