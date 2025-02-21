#include <iostream>
#include <vector>
#include <memory>
#include <objetos/arvoresimples.h>
#include <objetos/arvorecomplexa.h>
#include <GL/glut.h>
#include <gui.h>
#include <objetos/gerenciadorarquivo.h>
#include "bib/Camera.h"
#include "bib/CameraDistante.h"
#include "bib/CameraJogo.h"
#include "bib/gerenciadorcameras.h"
#include "bib/model3ds.h"
#include "objetos/teclado.h"
#include "objetos/placaanuncio.h"
#include "objetos/gerenciadorarvores.h"
#include "objetos/grama.h"
#include "objetos/carro3d.h"




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



void desenhar() {
    GUI::displayInit();

    Camera* camera = gerenciadorCameras.getCamera();
    if (camera) {
        camera->posicionar();
    }

    GUI::setLight(0,0.0, 2.0, 1.0, true, false);

    Grama::desenhar();

    // pista
    glEnable(GL_TEXTURE_2D);
    GUI::selecionaTextura(0);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0, 0);  glVertex3f(1, 0.002, -10);
    glTexCoord2f(1, 0);  glVertex3f(-1, 0.002, -10);
    glTexCoord2f(0, 1);  glVertex3f(-1, 0.002, 10);
    glTexCoord2f(1, 1);  glVertex3f(1, 0.002, 10);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    placaAnd.desenhar();

    carro.atualizarPosicao();
    carro.desenhar();



    for (size_t i = 0; i < objetos.size(); i++) {
        auto& obj = objetos[i];
        glPushMatrix();

        if ((int)i == objetoSelecionado) {
            obj->rotacaoX += glutGUI::dax * 5.0;
            obj->rotacaoY += glutGUI::day * 5.0;
            obj->translacaoX += glutGUI::drx * 0.5;
            obj->translacaoY += glutGUI::dry * 0.5;
        }

        // Aplicar transformações ao objeto
        glTranslatef(obj->translacaoX, obj->translacaoY, obj->translacaoZ);
        glRotatef(obj->rotacaoX, 1, 0, 0);
        glRotatef(obj->rotacaoY, 0, 1, 0);
        glRotatef(obj->rotacaoZ, 0, 0, 1);
        glScalef(obj->escalaX, obj->escalaY, obj->escalaZ);

        // Respeitar a exibição global dos eixos
        if (mostrarTodosEixos) {
            obj->setMostrarEixos(true);
        }

        obj->desenhar();
        glPopMatrix();
    }

    if (objetoSelecionado >= 0) {
        auto& obj = objetos[objetoSelecionado];
        float scaleFactor = 1.0 + glutGUI::dsx;
        obj->escalaX *= scaleFactor;
        obj->escalaY *= scaleFactor;
        obj->escalaZ *= scaleFactor;
    }

    GUI::displayEnd();
}



// Captura de teclado agora usa a classe Teclado
void teclado(unsigned char tecla, int x, int y) {
    Teclado::ativarTeclado(tecla, x, y, objetos, objetoSelecionado, gerenciadorCameras, mostrarTodosEixos);
}


int main() {
    cout << "Trabalho Computação Gráfica - Andson" << endl;
    GerenciadorArvores::adicionarArvoresFixas(objetos);
    GUI gui = GUI(800, 600, desenhar, teclado);
    return 0;
}
