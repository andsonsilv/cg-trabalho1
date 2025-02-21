#ifndef PLACAANUNCIO_H
#define PLACAANUNCIO_H

#include <GL/glut.h>
#include <gui.h>

class PlacaAnuncio {
private:
    float posX, posY, posZ;
    float rotX, rotZ;
    float escalaX, escalaY, escalaZ;

public:
    PlacaAnuncio(float x, float y, float z, float rX, float rZ, float sX, float sY, float sZ);
    void desenhar();
};

#endif // PLACAANUNCIO_H
