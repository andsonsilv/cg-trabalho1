#include <iostream>
#include <objetos/arvoresimples.h>
#include <objetos/arvorecomplexa.h>
#include <GL/glut.h>
#include <gui.h>

using namespace std;

Vetor3D posicaoLuz = Vetor3D(1.0, 1.5, 1.0);

// Árvores conforme o padrão fornecido
ArvoreSimples minhaArvore(1.0, 0.0, 0.0,
                          1.2, 0.2,
                          0.5, 0.3,
                          0.55, 0.27, 0.07,
                          0.0, 0.8, 0.0);

ArvoreComplexa minhaArvoreComplexa(2.0, 0.0, 0.0,
                                   1.0, 0.25,
                                   0.8, 0.35,
                                   0.6, 0.3, 0.1,
                                   0.0, 0.7, 0.0);

bool selecionaArvoreSimples = true;

void desenhar() {
    GUI::displayInit();
    GUI::setLight(0, posicaoLuz.x, posicaoLuz.y, posicaoLuz.z, true, false);
    GUI::drawOrigin(1.0);
    GUI::drawFloor();

    glPushMatrix();
    // Translada, rotaciona e escala a árvore simples
    glTranslatef(minhaArvore.translacaoX, minhaArvore.translacaoY, minhaArvore.translacaoZ);
    glRotatef(minhaArvore.rotacaoX, 1, 0, 0);
    glRotatef(minhaArvore.rotacaoY, 0, 1, 0);
    glRotatef(minhaArvore.rotacaoZ, 0, 0, 1);
    glScalef(minhaArvore.escalaX, minhaArvore.escalaY, minhaArvore.escalaZ);
    minhaArvore.desenhar();
    glPopMatrix();

    glPushMatrix();
    // Translada, rotaciona e escala a árvore complexa
    glTranslatef(minhaArvoreComplexa.translacaoX, minhaArvoreComplexa.translacaoY, minhaArvoreComplexa.translacaoZ);
    glRotatef(minhaArvoreComplexa.rotacaoX, 1, 0, 0);
    glRotatef(minhaArvoreComplexa.rotacaoY, 0, 1, 0);
    glRotatef(minhaArvoreComplexa.rotacaoZ, 0, 0, 1);
    glScalef(minhaArvoreComplexa.escalaX, minhaArvoreComplexa.escalaY, minhaArvoreComplexa.escalaZ);
    minhaArvoreComplexa.desenhar();
    glPopMatrix();

    GUI::displayEnd();
}

void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla, x, y);

    // Define o objeto ativo para transformar
    Objeto* obj = selecionaArvoreSimples ? (Objeto*)&minhaArvore : (Objeto*)&minhaArvoreComplexa;

    switch (tecla) {
    // Alternar árvore e alternar seleção visual
    case 't':
        // Desativa o objeto atualmente selecionado
        if (selecionaArvoreSimples) {
            minhaArvore.setSelecionado(false);
            minhaArvoreComplexa.setSelecionado(true);
            selecionaArvoreSimples = false;
            cout << "Selecionada: Arvore Complexa" << endl;
        } else {
            minhaArvoreComplexa.setSelecionado(false);
            minhaArvore.setSelecionado(true);
            selecionaArvoreSimples = true;
            cout << "Selecionada: Arvore Simples" << endl;
        }
        break;

        // Movimentação
    case 'w': obj->mover(0, 0.1, 0); break;
    case 's': obj->mover(0, -0.1, 0); break;
    case 'a': obj->mover(-0.1, 0, 0); break;
    case 'd': obj->mover(0.1, 0, 0); break;

        // Rotação
    case 'i': obj->rotacionar(5, 0, 0); break;
    case 'k': obj->rotacionar(-5, 0, 0); break;
    case 'j': obj->rotacionar(0, 5, 0); break;
    case 'l': obj->rotacionar(0, -5, 0); break;
    case 'u': obj->rotacionar(0, 0, 5); break;
    case 'o': obj->rotacionar(0, 0, -5); break;

        // Escala
    case '+': obj->escalar(1.1, 1.1, 1.1); break;
    case '-': obj->escalar(0.9, 0.9, 0.9); break;

        // Movimentação da luz
    case '4': posicaoLuz.x -= 0.2; break;
    case '6': posicaoLuz.x += 0.2; break;
    case '5': posicaoLuz.y -= 0.2; break;
    case '8': posicaoLuz.y += 0.2; break;
    case '[': posicaoLuz.z -= 0.2; break;
    case ']': posicaoLuz.z += 0.2; break;

    default:
        break;
    }
}

int main() {
    // Inicia com a árvore simples selecionada
    minhaArvore.setSelecionado(true);
    cout << "Iniciando o sistema com árvores e transformações." << endl;

    GUI gui = GUI(800, 600, desenhar, teclado);

    return 0;
}
