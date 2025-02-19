#include "gerenciadorarquivo.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "objetos/arvoresimples.h"
#include "objetos/arvorecomplexa.h"

using json = nlohmann::json;

void GerenciadorArquivo::salvarObjetos(const std::vector<std::unique_ptr<Objeto>>& objetos) {
    std::string caminho = "/home/andson/Documentos/cg-trabalho1/arquivos/objetos.json";

    json jArray;
    for (const auto& obj : objetos) {
        jArray.push_back(obj->toJSON());
    }

    std::ofstream arquivo(caminho);
    if (arquivo.is_open()) {
        arquivo << jArray.dump(4);
        arquivo.close();
        std::cout << "✅ Objetos salvos em: " << caminho << std::endl;
    } else {
        std::cerr << "X Erro ao abrir o arquivo para salvar: " << caminho << std::endl;
    }
}

void GerenciadorArquivo::carregarObjetos(std::vector<std::unique_ptr<Objeto>>& objetos, int& objetoSelecionado) {
    std::string caminho = "/home/andson/Documentos/cg-trabalho1/arquivos/objetos.json";

    std::ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        std::cerr << "X Erro ao abrir o arquivo para carregar: " << caminho << std::endl;
        return;
    }

    json jsonArray;
    arquivo >> jsonArray;
    arquivo.close();

    std::cout << "📜 JSON carregado:\n" << jsonArray.dump(4) << std::endl;

    objetos.clear();  // Limpa todos os objetos antes de carregar

    int novoObjetoSelecionado = -1; // Índice do novo objeto selecionado

    for (size_t i = 0; i < jsonArray.size(); i++) {
        auto& jsonObj = jsonArray[i];

        std::unique_ptr<Objeto> obj;
        if (jsonObj["tipo"] == "ArvoreSimples") {
            obj = std::make_unique<ArvoreSimples>(0.0f, 0.0f, 0.0f, 1.2f, 0.2f, 0.5f, 0.3f, 0.55f, 0.27f, 0.07f, 0.0f, 0.8f, 0.0f);
        } else if (jsonObj["tipo"] == "ArvoreComplexa") {
            obj = std::make_unique<ArvoreComplexa>(0.0f, 0.0f, 0.0f, 1.0f, 0.25f, 0.8f, 0.35f, 0.6f, 0.3f, 0.1f, 0.0f, 0.7f, 0.0f);
        } else {
            std::cerr << "⚠ Tipo desconhecido: " << jsonObj["tipo"] << std::endl;
            continue;
        }

        // Definir transformações
        obj->translacaoX = jsonObj["translacao"][0];
        obj->translacaoY = jsonObj["translacao"][1];
        obj->translacaoZ = jsonObj["translacao"][2];

        obj->rotacaoX = jsonObj["rotacao"][0];
        obj->rotacaoY = jsonObj["rotacao"][1];
        obj->rotacaoZ = jsonObj["rotacao"][2];

        obj->escalaX = jsonObj["escala"][0];
        obj->escalaY = jsonObj["escala"][1];
        obj->escalaZ = jsonObj["escala"][2];

        obj->mostrarEixos = jsonObj["mostrarEixos"];

        // Garante que apenas um objeto será selecionado
        if (jsonObj["selecionado"]) {
            if (novoObjetoSelecionado == -1) {
                novoObjetoSelecionado = i;
                obj->setSelecionado(true);
            } else {
                obj->setSelecionado(false);
            }
        }

        objetos.push_back(std::move(obj));
    }

    // Define qual objeto está selecionado, se houver algum
    objetoSelecionado = (novoObjetoSelecionado != -1) ? novoObjetoSelecionado : -1;

    std::cout << "Objetos carregados com sucesso!\n";
}
