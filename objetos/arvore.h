#ifndef ARVORE_H
#define ARVORE_H

#include "objeto.h"

class Arvore : public Objeto {
protected:
    float posX, posY, posZ;
    float alturaTronco, larguraTronco;
    float alturaCopa, raioCopa;
    float corTroncoR, corTroncoG, corTroncoB;
    float corCopaR, corCopaG, corCopaB;

public:
    Arvore(float posX, float posY, float posZ,
           float alturaTronco, float larguraTronco,
           float alturaCopa, float raioCopa,
           float corTroncoR, float corTroncoG, float corTroncoB,
           float corCopaR, float corCopaG, float corCopaB)
        : posX(posX), posY(posY), posZ(posZ),
        alturaTronco(alturaTronco), larguraTronco(larguraTronco),
        alturaCopa(alturaCopa), raioCopa(raioCopa),
        corTroncoR(corTroncoR), corTroncoG(corTroncoG), corTroncoB(corTroncoB),
        corCopaR(corCopaR), corCopaG(corCopaG), corCopaB(corCopaB) {}

    virtual void desenhar() = 0;
};

#endif // ARVORE_H
