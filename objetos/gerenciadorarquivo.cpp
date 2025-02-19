#include "gerenciadorarquivo.h"
#include "arvoresimples.h"
#include "arvorecomplexa.h"
#include <fstream>

std::string caminho = "objetos.json";


void GerenciadorArquivo::salvarObjetos(const std::vector<std::unique_ptr<Objeto>>& objetos, const std::string& caminho) {
    json jArray = json::array();
    for (const auto& obj : objetos) {
        jArray.push_back(obj->toJSON());
    }

    std::ofstream arquivo(caminho);
    if (arquivo.is_open()) {
        arquivo << jArray.dump(4);
        arquivo.close();
    }
}

void GerenciadorArquivo::carregarObjetos(std::vector<std::unique_ptr<Objeto>>& objetos, const std::string& caminho) {
    std::ifstream arquivo(caminho);
    if (!arquivo.is_open()) return;

    json jArray;
    arquivo >> jArray;
    arquivo.close();

    objetos.clear();

    for (const auto& j : jArray) {
        std::unique_ptr<Objeto> obj;

        if (j["tipo"] == "ArvoreSimples") {
            obj = std::make_unique<ArvoreSimples>(0, 0, 0, 1, 1, 1, 1, 0.5, 0.3, 0.1, 0.3, 0.8, 0.3);
        } else if (j["tipo"] == "ArvoreComplexa") {
            obj = std::make_unique<ArvoreComplexa>(0, 0, 0, 1, 1, 1, 1, 0.5, 0.3, 0.1, 0.3, 0.8, 0.3);
        }

        if (obj) {
            obj->fromJSON(j);
            objetos.push_back(std::move(obj));
        }
    }
}
