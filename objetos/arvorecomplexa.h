#ifndef ARVORE_COMPLEXA_H
#define ARVORE_COMPLEXA_H

#include "arvore.h"
#include <GL/glut.h>
#include <math.h>

class ArvoreComplexa : public Arvore {
public:
    ArvoreComplexa(float posX, float posY, float posZ,
                   float alturaTronco, float larguraTronco,
                   float alturaCopa, float raioCopa,
                   float corTroncoR, float corTroncoG, float corTroncoB,
                   float corCopaR, float corCopaG, float corCopaB);

    virtual void desenhar() override;

private:
    void desenharTroncoComEspessura(float largura, float altura, float profundidade);
};

#endif // ARVORE_COMPLEXA_H
