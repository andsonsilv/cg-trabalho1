#ifndef ARVORE_SIMPLES_H
#define ARVORE_SIMPLES_H

#include "arvore.h"
#include <GL/glut.h>
#include <math.h>

class ArvoreSimples : public Arvore {
public:
    ArvoreSimples(float posX, float posY, float posZ,
                  float alturaTronco, float larguraTronco,
                  float alturaCopa, float raioCopa,
                  float corTroncoR, float corTroncoG, float corTroncoB,
                  float corCopaR, float corCopaG, float corCopaB);

    virtual void desenhar() override;

    static void desenharTroncoComEspessura(float largura, float altura, float profundidade);
};

#endif // ARVORE_SIMPLES_H
