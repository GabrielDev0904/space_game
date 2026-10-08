#ifndef NAVE_H
#define NAVE_H

class Nave
{
private:
    int linha;
    int coluna;

public:
    Nave();

    void subir();
    void descer();

    int getLinha();
    int getColuna();
};

#endif