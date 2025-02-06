#include "veiculo.h"
#include <GL/glut.h>

Veiculo::Veiculo(float x, float y, float z, float largura, float altura, float profundidade, float r, float g, float b)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->largura = largura;
    this->altura = altura;
    this->profundidade = profundidade;
    this->corR = r;
    this->corG = g;
    this->corB = b;
}

void Veiculo::desenhar()
{
    // Método virtual, será sobrescrito pelas subclasses
}

void Veiculo::setPosicao(float novoX, float novoY, float novoZ)
{
    x = novoX;
    y = novoY;
    z = novoZ;
}

void Veiculo::setCor(float r, float g, float b)
{
    corR = r;
    corG = g;
    corB = b;
}
