#include "arvore.h"

Arvore::Arvore(float posX, float posY, float posZ,
               float alturaTronco, float larguraTronco,
               float alturaCopa, float raioCopa,
               float corTroncoR, float corTroncoG, float corTroncoB,
               float corCopaR, float corCopaG, float corCopaB)
    : posX(posX), posY(posY), posZ(posZ),
    alturaTronco(alturaTronco), larguraTronco(larguraTronco),
    alturaCopa(alturaCopa), raioCopa(raioCopa),
    corTroncoR(corTroncoR), corTroncoG(corTroncoG), corTroncoB(corTroncoB),
    corCopaR(corCopaR), corCopaG(corCopaG), corCopaB(corCopaB)
{

}
