#ifndef TECLADO_H
#define TECLADO_H

#include <vector>
#include <memory>
#include <objetos/gerenciadorarquivo.h>
#include "bib/gerenciadorcameras.h"
#include "bib/Camera.h"

class Teclado {
public:
    static void ativarTeclado(unsigned char tecla, int x, int y,
                                std::vector<std::unique_ptr<Objeto>>& objetos,
                                int& objetoSelecionado,
                                GerenciadorCameras& gerenciadorCameras, bool& mostrarTodosEixos);
};

#endif // TECLADO_H
