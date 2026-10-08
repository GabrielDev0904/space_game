#include "Jogo.h"

Jogo::Jogo(LiquidCrystal_I2C &lcd)
    : lcd(lcd)
{
    pontos = 0;
    jogando = false;
    gameOver = false;

    tempoAnterior = 0;
    intervalo = 400;

    botaoCima = 12;
    botaoBaixo = 13;
    botaoEnter = 14;
}

void Jogo::iniciar()
{
    pinMode(botaoCima, INPUT_PULLUP);
    pinMode(botaoBaixo, INPUT_PULLUP);
    pinMode(botaoEnter, INPUT_PULLUP);

    randomSeed(millis());

    pontos = 0;
    gameOver = false;
    jogando = false;

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("SPACE GAME");

    lcd.setCursor(0, 1);
    lcd.print("ENTER = INICIAR");
}

void Jogo::atualizar()
{
    if (!jogando)
    {
        if (digitalRead(botaoEnter) == LOW)
        {
            jogando = true;
            pontos = 0;
            gameOver = false;

            nave = Nave();

            for (int i = 0; i < 3; i++)
            {
                rochas[i].iniciar();
            }

            lcd.clear();

            delay(200);
        }

        return;
    }

    lerBotoes();

    unsigned long tempoAtual = millis();

    if (tempoAtual - tempoAnterior >= intervalo)
    {
        tempoAnterior = tempoAtual;

        moverRochas();
        verificarColisao();

        if (!gameOver)
        {
            desenhar();
        }
    }
}

void Jogo::lerBotoes()
{
    if (digitalRead(botaoCima) == LOW)
    {
        nave.subir();
        delay(150);
    }

    if (digitalRead(botaoBaixo) == LOW)
    {
        nave.descer();
        delay(150);
    }
}

void Jogo::moverRochas()
{
    for (int i = 0; i < 3; i++)
    {
        rochas[i].mover();

        if (rochas[i].getColuna() < 0)
        {
            pontos++;
            rochas[i].iniciar();
        }
    }
}

void Jogo::verificarColisao()
{
    for (int i = 0; i < 3; i++)
    {
        if (rochas[i].getColuna() == nave.getColuna() &&
            rochas[i].getLinha() == nave.getLinha())
        {
            gameOver = true;
            jogando = false;

            lcd.clear();

            lcd.setCursor(4, 0);
            lcd.print("GAME OVER!");

            lcd.setCursor(5, 1);
            lcd.print("Pontos: ");
            lcd.print(pontos);

            lcd.setCursor(2, 3);
            lcd.print("ENTER = JOGAR");

            return;
        }
    }
}

void Jogo::desenhar()
{
    lcd.clear();

    lcd.setCursor(14, 0);
    lcd.print("P:");
    lcd.print(pontos);

    lcd.setCursor(nave.getColuna(), nave.getLinha());
    lcd.write(byte(0));

    for (int i = 0; i < 3; i++)
    {
        if (rochas[i].getColuna() >= 0 &&
            rochas[i].getColuna() < 20)
        {
            lcd.setCursor(
                rochas[i].getColuna(),
                rochas[i].getLinha()
            );

            lcd.print(".");
        }
    }
}