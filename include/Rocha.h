#ifndef ROCHA_H
#define ROCHA_H

class Rocha
{
private:
    int linha;
    int coluna;

public:
    Rocha();

    void iniciar();
    void mover();

    int getLinha();
    int getColuna();
};

#endif