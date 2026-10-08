# 🚀 Space Game - ESP32

Um pequeno jogo desenvolvido com **ESP32**, **LCD 20x4 I2C** e botões, criado como projeto para praticar **Programação Orientada a Objetos (POO)** em C/C++.

O objetivo do jogo é controlar uma nave e desviar das rochas que aparecem e se movimentam pela tela.

---

## 🎮 Sobre o projeto

Neste projeto, a nave fica no lado esquerdo da tela e pode se movimentar para cima e para baixo.

As rochas aparecem no lado direito e se movimentam em direção à nave. O jogador precisa desviar delas para conseguir a maior pontuação possível.

Quando uma rocha passa pela nave sem atingir o jogador, a pontuação aumenta.

Se a nave colidir com uma rocha, o jogo termina.

---

## 🕹️ Como jogar

| Botão | Função |
|---|---|
| ⬆️ Cima | Move a nave para cima |
| ⬇️ Baixo | Move a nave para baixo |
| ENTER | Inicia ou reinicia o jogo |

### Objetivo

Evite as rochas `.` e tente conseguir a maior pontuação possível.

**Boa sorte, piloto! 🚀**

---

## 🛠️ Tecnologias utilizadas

- C++
- ESP32
- PlatformIO
- Arduino Framework
- LCD 20x4 I2C
- Programação Orientada a Objetos (POO)

---

## 📚 Conceitos praticados

Durante o desenvolvimento foram utilizados conceitos importantes de programação:

- Classes e objetos
- Encapsulamento
- Construtores
- Métodos
- Vetores de objetos
- Separação de código em `.h` e `.cpp`
- Referência de objetos
- Estruturas de decisão
- Estruturas de repetição
- `millis()`
- Leitura de botões
- Controle de display LCD
- Criação de caracteres personalizados
- Geração de posições aleatórias

---

## 📁 Estrutura do projeto

```text
POO/
│
├── include/
│   ├── Jogo.h
│   ├── Nave.h
│   └── Rocha.h
│
├── src/
│   ├── Jogo.cpp
│   ├── Nave.cpp
│   ├── Rocha.cpp
│   └── main.cpp
│
├── platformio.ini
└── README.md
