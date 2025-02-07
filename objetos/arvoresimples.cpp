#include "arvoresimples.h"

ArvoreSimples::ArvoreSimples(float posX, float posY, float posZ,
                             float alturaTronco, float larguraTronco,
                             float alturaCopa, float raioCopa,
                             float corTroncoR, float corTroncoG, float corTroncoB,
                             float corCopaR, float corCopaG, float corCopaB)
    : Arvore(posX, posY, posZ, alturaTronco, larguraTronco,
             alturaCopa, raioCopa, corTroncoR, corTroncoG, corTroncoB,
             corCopaR, corCopaG, corCopaB)
{
}

// Função auxiliar que desenha um cuboide centrado em x e z com base na largura, altura e profundidade
void ArvoreSimples::desenharTroncoComEspessura(float largura, float altura, float profundidade) {
    glBegin(GL_QUADS);
    // Face frontal (z = +profundidade/2)
    glNormal3f(0, 0, 1);
    glVertex3f(-largura/2, 0,  profundidade/2);
    glVertex3f(  largura/2, 0,  profundidade/2);
    glVertex3f(  largura/2, altura,  profundidade/2);
    glVertex3f(-largura/2, altura,  profundidade/2);

    // Face traseira (z = -profundidade/2)
    glNormal3f(0, 0, -1);
    glVertex3f(  largura/2, 0, -profundidade/2);
    glVertex3f(-largura/2, 0, -profundidade/2);
    glVertex3f(-largura/2, altura, -profundidade/2);
    glVertex3f(  largura/2, altura, -profundidade/2);

    // Face direita (x = +largura/2)
    glNormal3f(1, 0, 0);
    glVertex3f(largura/2, 0,  profundidade/2);
    glVertex3f(largura/2, 0, -profundidade/2);
    glVertex3f(largura/2, altura, -profundidade/2);
    glVertex3f(largura/2, altura,  profundidade/2);

    // Face esquerda (x = -largura/2)
    glNormal3f(-1, 0, 0);
    glVertex3f(-largura/2, 0, -profundidade/2);
    glVertex3f(-largura/2, 0,  profundidade/2);
    glVertex3f(-largura/2, altura,  profundidade/2);
    glVertex3f(-largura/2, altura, -profundidade/2);

    // Face superior (y = altura)
    glNormal3f(0, 1, 0);
    glVertex3f(-largura/2, altura,  profundidade/2);
    glVertex3f( largura/2, altura,  profundidade/2);
    glVertex3f( largura/2, altura, -profundidade/2);
    glVertex3f(-largura/2, altura, -profundidade/2);

    // Face inferior (y = 0)
    glNormal3f(0, -1, 0);
    glVertex3f(-largura/2, 0, -profundidade/2);
    glVertex3f( largura/2, 0, -profundidade/2);
    glVertex3f( largura/2, 0,  profundidade/2);
    glVertex3f(-largura/2, 0,  profundidade/2);
    glEnd();
}

void ArvoreSimples::desenhar() {
    glPushMatrix();

    // Translada para a posição da árvore
    glTranslatef(posX, posY, posZ);

    // ----- Desenho do Tronco com Espessura -----
    glColor3f(corTroncoR, corTroncoG, corTroncoB);
    float profundidadeTronco = 0.5f * larguraTronco;
    desenharTroncoComEspessura(larguraTronco, alturaTronco, profundidadeTronco);

    // ----- Desenho da Copa com glPolygonOffset para evitar conflito -----
    // Translada para o topo do tronco
    glTranslatef(0.0f, alturaTronco, 0.0f);

    // Habilita o offset de polígono para "empurrar" a copa para frente (no eixo z)
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(1.0f, 1.0f);

    // Desabilita temporariamente o face culling para que a copa seja renderizada dos dois lados
    glDisable(GL_CULL_FACE);

    glColor3f(corCopaR, corCopaG, corCopaB);
    const int segments = 30;
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 1.0f, 0.0f); // Normal para cima
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * 3.14159265f * i / segments;
        float dx = raioCopa * cosf(angle);
        float dz = raioCopa * sinf(angle);
        glVertex3f(dx, 0.0f, dz);
    }
    glEnd();

    // Desabilita o polygon offset e reabilita o culling para os próximos objetos
    glDisable(GL_POLYGON_OFFSET_FILL);
    glEnable(GL_CULL_FACE);

    glPopMatrix();
}
