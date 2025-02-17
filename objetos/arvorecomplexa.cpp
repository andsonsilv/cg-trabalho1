#include "arvorecomplexa.h"

ArvoreComplexa::ArvoreComplexa(float posX, float posY, float posZ,
                               float alturaTronco, float larguraTronco,
                               float alturaCopa, float raioCopa,
                               float corTroncoR, float corTroncoG, float corTroncoB,
                               float corCopaR, float corCopaG, float corCopaB)
    : Arvore(posX, posY, posZ, alturaTronco, larguraTronco,
             alturaCopa, raioCopa, corTroncoR, corTroncoG, corTroncoB,
             corCopaR, corCopaG, corCopaB)
{
}

void ArvoreComplexa::desenharTroncoComEspessura(float largura, float altura, float profundidade) {
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


void ArvoreComplexa::desenhar() {
    glPushMatrix();

    // Translada para a posição da árvore
    glTranslatef(posX, posY, posZ);

    // Destaca com cor branca se estiver selecionada
    glColor3f(selecionado ? 1.0 : corTroncoR,
              selecionado ? 1.0 : corTroncoG,
              selecionado ? 1.0 : corTroncoB);

    // ----- Desenho do Tronco com Espessura -----
    float profundidadeTronco = 0.5f * larguraTronco;
    desenharTroncoComEspessura(larguraTronco, alturaTronco, profundidadeTronco);

    // ----- Desenho da Copa com Espessura -----
    glTranslatef(0.0f, alturaTronco, 0.0f);

    glColor3f(selecionado ? 1.0 : corCopaR,
              selecionado ? 1.0 : corCopaG,
              selecionado ? 1.0 : corCopaB);

    const int segments = 30;
    float canopyThickness = 0.05f; // Espessura da copa

    glBegin(GL_QUADS);
    for (int i = 0; i < segments; i++) {
        int next = (i + 1) % segments;
        float angle = 2.0f * 3.14159265f * i / segments;
        float nextAngle = 2.0f * 3.14159265f * next / segments;

        float x1 = raioCopa * cosf(angle);
        float z1 = raioCopa * sinf(angle);
        float x2 = raioCopa * cosf(nextAngle);
        float z2 = raioCopa * sinf(nextAngle);

        glNormal3f(x1, 0, z1); // Normal apontando para fora
        glVertex3f(x1, 0, z1);
        glVertex3f(x2, 0, z2);
        glVertex3f(x2, -canopyThickness, z2);
        glVertex3f(x1, -canopyThickness, z1);
    }
    glEnd();

    // Desenha o topo da copa
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 1.0f, 0.0f);
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * 3.14159265f * i / segments;
        float x = raioCopa * cosf(angle);
        float z = raioCopa * sinf(angle);
        glVertex3f(x, 0, z);
    }
    glEnd();

    // Desenha a base da copa
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 1.0f, 0.0f);
    for (int i = segments - 1; i >= 0; i--) {
        float angle = 2.0f * 3.14159265f * i / segments;
        float x = raioCopa * cosf(angle);
        float z = raioCopa * sinf(angle);
        glVertex3f(x, -canopyThickness, z);
    }
    glEnd();

    // Desenha os eixos locais, se ativado
    if (mostrarEixos) {
        glDisable(GL_LIGHTING);
        glLineWidth(3.0f);
        glBegin(GL_LINES);

        // Eixo X (vermelho)
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(0, 0, 0);
        glVertex3f(1.0, 0, 0);

        // Eixo Y (verde)
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1.0, 0);

        // Eixo Z (azul)
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 1.0);

        glEnd();
        glLineWidth(1.0f);
        glEnable(GL_LIGHTING);
    }

    glPopMatrix();
}
