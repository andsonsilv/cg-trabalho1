#ifndef OBJETO_H
#define OBJETO_H

#include <GL/glut.h>

class Objeto {
public:
    float translacaoX, translacaoY, translacaoZ;
    float rotacaoX, rotacaoY, rotacaoZ;
    float escalaX, escalaY, escalaZ;

public:
    Objeto() : translacaoX(0), translacaoY(0), translacaoZ(0),
        rotacaoX(0), rotacaoY(0), rotacaoZ(0),
        escalaX(1), escalaY(1), escalaZ(1) {}

    void mover(float dx, float dy, float dz) {
        translacaoX += dx;
        translacaoY += dy;
        translacaoZ += dz;
    }

    void rotacionar(float rx, float ry, float rz) {
        rotacaoX += rx;
        rotacaoY += ry;
        rotacaoZ += rz;
    }

    void escalar(float sx, float sy, float sz) {
        escalaX *= sx;
        escalaY *= sy;
        escalaZ *= sz;
    }

    virtual void desenhar() = 0;

    virtual ~Objeto() {}
};

#endif // OBJETO_H
