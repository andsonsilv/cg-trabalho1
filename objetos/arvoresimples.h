#ifndef ARVORE_SIMPLES_H
#define ARVORE_SIMPLES_H

#include "arvore.h"
#include <GL/glut.h>
#include <math.h>
#include <string>

class ArvoreSimples : public Arvore {
public:
    ArvoreSimples(float posX, float posY, float posZ,
                  float alturaTronco, float larguraTronco,
                  float alturaCopa, float raioCopa,
                  float corTroncoR, float corTroncoG, float corTroncoB,
                  float corCopaR, float corCopaG, float corCopaB);

    virtual void desenhar() override;

    void desenharTroncoComEspessura(float largura, float altura, float profundidade);

    std::string getTipo() const override {
        return "ArvoreSimples";
    }

    json toJSON() const override {
        return {
            {"tipo", getTipo()},
            {"translacao", {translacaoX, translacaoY, translacaoZ}},
            {"rotacao", {rotacaoX, rotacaoY, rotacaoZ}},
            {"escala", {escalaX, escalaY, escalaZ}},
            {"selecionado", selecionado},
            {"mostrarEixos", mostrarEixos}
        };
    }

    void fromJSON(const json& j) override {
        translacaoX = j["translacao"][0];
        translacaoY = j["translacao"][1];
        translacaoZ = j["translacao"][2];
        rotacaoX = j["rotacao"][0];
        rotacaoY = j["rotacao"][1];
        rotacaoZ = j["rotacao"][2];
        escalaX = j["escala"][0];
        escalaY = j["escala"][1];
        escalaZ = j["escala"][2];
        selecionado = j["selecionado"];
        mostrarEixos = j["mostrarEixos"];
    }
};

#endif // ARVORE_SIMPLES_H
