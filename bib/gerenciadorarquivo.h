#ifndef GERENCIADORARVORES_H
#define GERENCIADORARVORES_H

#include <vector>
#include <memory>
#include "objetos/objeto.h"

class GerenciadorArvores {
public:
    static void adicionarArvoresFixas();
    static void desenharArvores();
private:
    static std::vector<std::unique_ptr<Objeto>> objetos;
};

#endif // GERENCIADORARVORES_H
