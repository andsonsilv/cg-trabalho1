void carregarObjetos(const string& objetossalvos) {
    ifstream arquivo(objetossalvos);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para carregar!" << endl;
        return;
    }

    json j;
    arquivo >> j;
    arquivo.close();

    objetos.clear();

    for (const auto& objetoJson : j) {
        unique_ptr<Objeto> obj = nullptr;

        string tipo = objetoJson["tipo"];
        if (tipo == "ArvoreSimples") {
            obj = make_unique<ArvoreSimples>();
        } else if (tipo == "ArvoreComplexa") {
            obj = make_unique<ArvoreComplexa>();
        } else {
            cerr << "Tipo desconhecido: " << tipo << endl;
            continue;
        }

        obj->translacaoX = objetoJson["translacaoX"];
        obj->translacaoY = objetoJson["translacaoY"];
        obj->translacaoZ = objetoJson["translacaoZ"];
        obj->rotacaoX = objetoJson["rotacaoX"];
        obj->rotacaoY = objetoJson["rotacaoY"];
        obj->rotacaoZ = objetoJson["rotacaoZ"];
        obj->escalaX = objetoJson["escalaX"];
        obj->escalaY = objetoJson["escalaY"];
        obj->escalaZ = objetoJson["escalaZ"];

        objetos.push_back(move(obj));
    }

    cout << "Objetos carregados de " << objetossalvos << endl;
}

