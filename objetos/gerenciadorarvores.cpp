#include "gerenciadorarvores.h"
#include "objetos/arvoresimples.h"
#include "objetos/arvorecomplexa.h"

std::vector<std::unique_ptr<Objeto>> GerenciadorArvores::objetos;

void GerenciadorArvores::adicionarArvoresFixas() {
    float posicaoX = 1.5;
    float posicaoZInicial = -6.0;
    float espacamentoZ = 1.5;
    int quantidadeArvores = 4;

    for (int i = 0; i < quantidadeArvores; i++) {
        float posicaoZ = posicaoZInicial + i * espacamentoZ;

        if (i % 2 == 0) {
            auto arvore = std::make_unique<ArvoreSimples>(
                posicaoX, 0.0, posicaoZ,
                1.2f, 0.2f, 0.5f, 0.3f,
                0.55f, 0.27f, 0.07f, 0.0f, 0.8f, 0.0f
                );
            arvore->setMostrarEixos(false);
            objetos.push_back(std::move(arvore));
        } else {
            auto arvore = std::make_unique<ArvoreComplexa>(
                posicaoX, 0.0, posicaoZ,
                1.0f, 0.25f, 0.8f, 0.35f,
                0.6f, 0.3f, 0.1f, 0.0f, 0.7f, 0.0f
                );
            arvore->setMostrarEixos(false);
            objetos.push_back(std::move(arvore));
        }
    }
}

void GerenciadorArvores::desenharArvores() {
    for (auto& arvore : objetos) {
        if (arvore) {
            arvore->desenhar();
        }
    }
}
