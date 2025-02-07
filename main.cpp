#include <iostream>
using namespace std;

#include <gui.h>


Vetor3D posicaoLuz = Vetor3D(0.0,1.0,1.0);



void desenhar(){
    GUI::displayInit();
    GUI::setLight(0, posicaoLuz.x, posicaoLuz.y, posicaoLuz.z, true, false);
    GUI::drawOrigin(1.0);
    GUI::drawFloor();


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
