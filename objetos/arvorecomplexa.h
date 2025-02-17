#ifndef ARVORE_COMPLEXA_H
#define ARVORE_COMPLEXA_H

#include "arvore.h" // Certifique-se de que a classe base Arvore está definida
#include <GL/glut.h>
#include <math.h>

class ArvoreComplexa : public Arvore {
public:
    // Construtor da ArvoreComplexa
    ArvoreComplexa(float posX, float posY, float posZ,
                   float alturaTronco, float larguraTronco,
                   float alturaCopa, float raioCopa,
                   float corTroncoR, float corTroncoG, float corTroncoB,
                   float corCopaR, float corCopaG, float corCopaB);

    // Método que desenha a árvore
    virtual void desenhar() override;

private:
    // Método para desenhar um tronco com espessura (cuboide)
    void desenharTroncoComEspessura(float largura, float altura, float profundidade);
};

#endif // ARVORE_COMPLEXA_H
