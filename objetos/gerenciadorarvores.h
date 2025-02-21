#ifndef GERENCIADORARVORES_H
#define GERENCIADORARVORES_H

#include <vector>
#include <memory>
#include "objetos/arvoresimples.h"
#include "objetos/arvorecomplexa.h"
#include "objeto.h"

class GerenciadorArvores {
public:
    static void adicionarArvoresFixas();
private:
    static std::vector<std::unique_ptr<Objeto>> objetos;
};

#endif
