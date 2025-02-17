#include <iostream>
#include <objetos/arvoresimples.h>
#include <objetos/arvorecomplexa.h>

using namespace std;

#include <gui.h>


Vetor3D posicaoLuz = Vetor3D(1.0,1.5,1.0);

ArvoreSimples minhaArvore(1.0, 0.0, 0.0,
                          1.2, 0.2,
                          0.5, 0.3,
                          0.55, 0.27, 0.07,
                          0.0, 0.8, 0.0);

// Instância de ArvoreComplexa (nova árvore com copa volumosa)
ArvoreComplexa minhaArvoreComplexa(2.0, 0.0, 0.0,   // Posição (um pouco deslocada em x)
                                   1.0, 0.25,             // Tronco: altura = 1.0, largura = 0.25
                                   0.8, 0.35,             // Copa: altura offset = 0.6 (a partir do topo do tronco) e raio = 0.35
                                   0.6, 0.3, 0.1,         // Cor do tronco (um marrom um pouco diferente)
                                   0.0, 0.7, 0.0);


void desenhar(){
    GUI::displayInit();
    GUI::setLight(0, posicaoLuz.x, posicaoLuz.y, posicaoLuz.z, true, false);
    GUI::drawOrigin(1.0);
    GUI::drawFloor();

    minhaArvore.desenhar();
    minhaArvoreComplexa.desenhar();

    GUI::displayEnd();
}

void teclado(unsigned char tecla, int x, int y){
    GUI::keyInit(tecla, x, y);
    switch (tecla) {
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;
    case 'o':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case '-':
        posicaoLuz.z -= 0.2;
        break;
    case '+':
        posicaoLuz.z += 0.2;
        break;
    case '4':
        posicaoLuz.x -= 0.2;
        break;
    case '6':
        posicaoLuz.x += 0.2;
        break;
    case '5':
        posicaoLuz.y -= 0.2;
        break;
    case '8':
        posicaoLuz.y += 0.2;
        break;
    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800, 600, desenhar, teclado);

    return 0;
}
