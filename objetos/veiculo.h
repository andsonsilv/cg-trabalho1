#ifndef VEICULO_H
#define VEICULO_H

class Veiculo
{
protected:
    float x, y, z;
    float largura, altura, profundidade;
    float corR, corG, corB;  // Cor sem struct

public:
    Veiculo(float x, float y, float z, float largura, float altura, float profundidade, float r, float g, float b);

    virtual void desenhar();
    void setPosicao(float novoX, float novoY, float novoZ);
    void setCor(float r, float g, float b);
};

#endif // VEICULO_H
