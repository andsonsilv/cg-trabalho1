#include "pista.h"

void Pista::desenhar() const {
    glEnable(GL_TEXTURE_2D);
    GUI::selecionaTextura(0);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0, 0);  glVertex3f(1, 0.002, -10);
    glTexCoord2f(1, 0);  glVertex3f(-1, 0.002, -10);
    glTexCoord2f(0, 1);  glVertex3f(-1, 0.002, 10);
    glTexCoord2f(1, 1);  glVertex3f(1, 0.002, 10);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
