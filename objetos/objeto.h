#ifndef OBJETO_H
#define OBJETO_H

#include <GL/glut.h>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Objeto {
public:
    float translacaoX, translacaoY, translacaoZ;
    float rotacaoX, rotacaoY, rotacaoZ;
    float escalaX, escalaY, escalaZ;
    bool selecionado;
    bool mostrarEixos;

public:
    Objeto() : translacaoX(0), translacaoY(0), translacaoZ(0),
        rotacaoX(0), rotacaoY(0), rotacaoZ(0),
        escalaX(1), escalaY(1), escalaZ(1),
        selecionado(false), mostrarEixos(false) {}

    virtual ~Objeto() = default;

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

    void setSelecionado(bool sel) {
        selecionado = sel;
    }

    void setMostrarEixos(bool mostrar) {
        mostrarEixos = mostrar;
    }

    virtual void desenhar() = 0;

    // 🔥 Métodos obrigatórios para serialização JSON
    virtual json toJSON() const = 0;
    virtual void fromJSON(const json& j) = 0;

    // 🔥 Método para identificar o tipo do objeto (deve ser implementado nas subclasses)
    virtual std::string getTipo() const = 0;
};

#endif // OBJETO_H
