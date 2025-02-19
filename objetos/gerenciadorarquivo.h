#ifndef GERENCIADORARQUIVO_H
#define GERENCIADORARQUIVO_H

#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "objeto.h"
#include "arvoresimples.h"
#include "arvorecomplexa.h"

using json = nlohmann::json;

class GerenciadorArquivo {
public:
    static void salvarObjetos(const std::vector<std::unique_ptr<Objeto>>& objetos, const std::string& caminho);
    static void carregarObjetos(std::vector<std::unique_ptr<Objeto>>& objetos, const std::string& caminho);

    // Adicionando função para criar objetos a partir do JSON
    static std::unique_ptr<Objeto> fromJSON(const json& j);
};

#endif // GERENCIADORARQUIVO_H
