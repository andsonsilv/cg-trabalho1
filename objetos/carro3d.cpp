#include "carro3d.h"

Carro3D::Carro3D(const char* caminhoModelo, float posicaoInicial, float velocidadeInicial)
    : modelo(caminhoModelo), posicaoZ(posicaoInicial), velocidade(velocidadeInicial) {}

void Carro3D::atualizarPosicao() {
    posicaoZ += velocidade;
    if (posicaoZ > 10.0) {
        posicaoZ = -10.0;
    }
}

void Carro3D::desenhar() {
    GUI::draw3ds(modelo, 0, 0.1, posicaoZ, 0, 0, 0, 1, 1, 1);
}
