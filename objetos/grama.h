#ifndef GRAMA_H
#define GRAMA_H

#include <GL/glut.h>
#include <gui.h>

class Grama {
public:
    static void desenhar() {
        glColor3f(0.2, 0.35, 0.15);
        GUI::drawFloor(20, 20, 1, 1, 1, 1);
    }
};

#endif // GRAMA_H
