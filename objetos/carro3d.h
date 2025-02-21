#ifndef CARRO3D_H
#define CARRO3D_H

#include <string>
#include "bib/model3ds.h"
#include "gui.h"

class Carro3D {
private:
    Model3DS modelo;
    float posicaoZ;
    float velocidade;

public:
    Carro3D(const char* caminhoModelo, float posicaoInicial, float velocidadeInicial);

    void atualizarPosicao();
    void desenhar();

    float getPosicaoZ() const { return posicaoZ; }
    void setPosicaoZ(float novaPosicao) { posicaoZ = novaPosicao; }

    float getVelocidade() const { return velocidade; }
    void setVelocidade(float novaVelocidade) { velocidade = novaVelocidade; }

    Model3DS& getModelo() { return modelo; }
};

#endif // CARRO3D_H
