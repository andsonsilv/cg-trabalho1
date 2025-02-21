#ifndef GERENCIADORARVORES_H
#define GERENCIADORARVORES_H

#include <vector>
#include <memory>
#include "objetos/arvoresimples.h"
#include "objetos/arvorecomplexa.h"

class GerenciadorArvores {
public:
    static void adicionarArvoresFixas(std::vector<std::unique_ptr<Objeto>>& objetos);
};

#endif
