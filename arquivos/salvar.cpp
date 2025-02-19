#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void salvarObjetos(const string& objetossalvos) {
    json j;
    
    for (const auto& obj : objetos) {
        json objetoJson;
        objetoJson["tipo"] = obj->getTipo(); // Função que retorna o tipo do objeto
        objetoJson["translacaoX"] = obj->translacaoX;
        objetoJson["translacaoY"] = obj->translacaoY;
        objetoJson["translacaoZ"] = obj->translacaoZ;
        objetoJson["rotacaoX"] = obj->rotacaoX;
        objetoJson["rotacaoY"] = obj->rotacaoY;
        objetoJson["rotacaoZ"] = obj->rotacaoZ;
        objetoJson["escalaX"] = obj->escalaX;
        objetoJson["escalaY"] = obj->escalaY;
        objetoJson["escalaZ"] = obj->escalaZ;

        j.push_back(objetoJson);
    }

    ofstream arquivo(objetossalvos);
    if (arquivo.is_open()) {
        arquivo << j.dump(4);
        arquivo.close();
        cout << "Objetos salvos em " << objetossalvos << endl;
    } else {
        cerr << "Erro ao abrir o arquivo para salvar!" << endl;
    }
}

