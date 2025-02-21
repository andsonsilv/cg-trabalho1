#ifndef GERENCIADORARQUIVO_H
#define GERENCIADORARQUIVO_H

#include <vector>
#include <memory>
#include "objetos/objeto.h"

class GerenciadorArquivo {
public:
    static void salvarObjetos(const std::vector<std::unique_ptr<Objeto>>& objetos);
    static void carregarObjetos(std::vector<std::unique_ptr<Objeto>>& objetos, int& objetoSelecionado);
};

#endif // GERENCIADORARQUIVO_H
