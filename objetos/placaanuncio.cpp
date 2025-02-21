#include "placaanuncio.h"
#include "gui.h"

PlacaAnuncio::PlacaAnuncio(float x, float y, float z, float rX, float rZ, float sX, float sY, float sZ)
    : posX(x), posY(y), posZ(z), rotX(rX), rotZ(rZ), escalaX(sX), escalaY(sY), escalaZ(sZ) {}

void PlacaAnuncio::desenhar() {
    glEnable(GL_TEXTURE_2D);
    GUI::selecionaTextura(1);
    glColor3f(1, 1, 1); // Garante que a textura mantenha suas cores originais
    glDisable(GL_LIGHTING);

    glPushMatrix();

    glTranslatef(posX, posY, posZ);
    glRotatef(rotX, 1, 0, 0);
    glRotatef(rotZ, 0, 0, 1);
    glScalef(escalaX, escalaY, escalaZ);

    // Corrigindo a iluminação da textura
    glDisable(GL_COLOR_MATERIAL);
    glColor3f(1, 1, 1); // Define a cor branca para evitar o esverdeado

    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1); // Normal apontando para frente

    glTexCoord2f(0, 1); glVertex3f(-0.8, 0, 0);
    glTexCoord2f(1, 1); glVertex3f(0.8, 0, 0);
    glTexCoord2f(1, 0); glVertex3f(0.8, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(-0.8, 1, 0);

    glEnd();

    glPopMatrix();

    glEnable(GL_LIGHTING); // Reativa iluminação depois
    glDisable(GL_TEXTURE_2D);
}
