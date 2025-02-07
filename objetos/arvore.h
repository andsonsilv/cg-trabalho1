#ifndef ARVORE_H
#define ARVORE_H

class Arvore {
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
           float corCopaR, float corCopaG, float corCopaB);

    virtual void desenhar() = 0;
    virtual ~Arvore() {}
};

#endif // ARVORE_H
