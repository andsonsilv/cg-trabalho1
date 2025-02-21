#include <iostream>
#include <vector>
#include <memory>
#include <objetos/arvoresimples.h>
#include <objetos/arvorecomplexa.h>
#include <GL/glut.h>
#include <gui.h>
#include "bib/gerenciadorarquivo.h"
#include "bib/Camera.h"
#include "bib/CameraDistante.h"
#include "bib/CameraJogo.h"
#include "bib/gerenciadorcameras.h"
#include "bib/model3ds.h"
#include "bib/teclado.h"
#include "objetos/placaanuncio.h"
#include "objetos/gerenciadorarvores.h"
#include "objetos/grama.h"
#include "objetos/carro3d.h"
#include "objetos/pista.h"


using namespace std;


// Vetor dinâmico de objetos
vector<unique_ptr<Objeto>> objetos;

// Índice do objeto atualmente selecionado
int objetoSelecionado = -1;

// Instância do Gerenciador de Câmeras
GerenciadorCameras gerenciadorCameras;

// Controle global da exibição dos eixos para todos os objetos
bool mostrarTodosEixos = false;

// Índice da configuração de câmera atual
int indiceCameraAtual = 0;

// Instância da Plana de Anúcios
PlacaAnuncio placaAnd(-2.0, 0.1, -3.5, -15, -15, 0.7, 0.7, 1.0);

// Instância do Carro3D com posição inicial e velocidade
Carro3D carro("../3ds/cartest.3DS", -10.0, 0.05);

// Instância da pista
Pista pista;


void desenhar() {
    // Inicializa a exibição da cena
    GUI::displayInit();

    // Obtém a câmera atual do gerenciador de câmeras
    Camera* camera = gerenciadorCameras.getCamera();
    if (camera) {
        camera->posicionar(); // Posiciona a câmera na cena
    }

    // Configuração da iluminação
    GUI::setLight(0, 0.0, 2.0, 1.0, true, false); // Define uma luz na posição (0,2,1)

    // Desenha o chão (grama)
    Grama::desenhar();

    // Desenha a pista
    pista.desenhar();

    // Desenha a placa de anúncio
    placaAnd.desenhar();

    // Atualiza a posição do carro e o desenha na nova posição
    carro.atualizarPosicao();
    carro.desenhar();

    // Desenha todas as árvores fixas do cenário
    GerenciadorArvores::desenharArvores();

    // Percorre o vetor de objetos e os desenha com as devidas transformações
    for (size_t i = 0; i < objetos.size(); i++) {
        auto& obj = objetos[i];
        glPushMatrix(); // Salva a matriz de transformação atual

        // Se o objeto estiver selecionado, permite movimentação e rotação com teclas
        if ((int)i == objetoSelecionado) {
            obj->rotacaoX += glutGUI::dax * 5.0;
            obj->rotacaoY += glutGUI::day * 5.0;
            obj->translacaoX += glutGUI::drx * 0.5;
            obj->translacaoY += glutGUI::dry * 0.5;
        }

        // Aplica as transformações ao objeto antes de desenhá-lo
        glTranslatef(obj->translacaoX, obj->translacaoY, obj->translacaoZ);
        glRotatef(obj->rotacaoX, 1, 0, 0);
        glRotatef(obj->rotacaoY, 0, 1, 0);
        glRotatef(obj->rotacaoZ, 0, 0, 1);
        glScalef(obj->escalaX, obj->escalaY, obj->escalaZ);

        // Se a opção de mostrar eixos estiver ativada, aplica a todos os objetos
        if (mostrarTodosEixos) {
            obj->setMostrarEixos(true);
        }

        obj->desenhar(); // Chama a função de desenho do objeto
        glPopMatrix(); // Restaura a matriz de transformação anterior
    }

    // Se um objeto estiver selecionado, permite que ele seja escalado
    if (objetoSelecionado >= 0) {
        auto& obj = objetos[objetoSelecionado];
        float scaleFactor = 1.0 + glutGUI::dsx;
        obj->escalaX *= scaleFactor;
        obj->escalaY *= scaleFactor;
        obj->escalaZ *= scaleFactor;
    }

    // Finaliza a exibição da cena
    GUI::displayEnd();
}


// Captura de teclado agora usa a classe Teclado
void teclado(unsigned char tecla, int x, int y) {
    Teclado::ativarTeclado(tecla, x, y, objetos, objetoSelecionado, gerenciadorCameras, mostrarTodosEixos);
}


int main() {
    cout << "Trabalho Computação Gráfica - Andson" << endl;
    GerenciadorArvores::adicionarArvoresFixas();
    GUI gui = GUI(800, 600, desenhar, teclado);
    return 0;
}
