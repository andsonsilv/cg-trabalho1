#include <iostream>
#include <vector>
#include <memory>
#include <objetos/arvoresimples.h>
#include <objetos/arvorecomplexa.h>
#include <GL/glut.h>
#include <gui.h>

using namespace std;

Vetor3D posicaoLuz = Vetor3D(1.0, 1.5, 1.0);

// Vetor dinâmico de objetos
vector<unique_ptr<Objeto>> objetos;

// Índice do objeto atualmente selecionado
int objetoSelecionado = -1;

void desenhar() {
    GUI::displayInit();
    GUI::setLight(0, posicaoLuz.x, posicaoLuz.y, posicaoLuz.z, true, false);
    GUI::drawOrigin(1.0);
    GUI::drawFloor();

    // Desenhar todos os objetos no vetor
    for (auto& obj : objetos) {
        glPushMatrix();
        glTranslatef(obj->translacaoX, obj->translacaoY, obj->translacaoZ);
        glRotatef(obj->rotacaoX, 1, 0, 0);
        glRotatef(obj->rotacaoY, 0, 1, 0);
        glRotatef(obj->rotacaoZ, 0, 0, 1);
        glScalef(obj->escalaX, obj->escalaY, obj->escalaZ);
        obj->desenhar();
        glPopMatrix();
    }

    GUI::displayEnd();
}

void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla, x, y);

    // Objeto ativo
    Objeto* obj = (objetoSelecionado >= 0) ? objetos[objetoSelecionado].get() : nullptr;

    switch (tecla) {
    // Incluir nova ArvoreSimples
    case '1': {
        ArvoreSimples* novaArvore = new ArvoreSimples(
            0.0f, 0.0f, 0.0f,    // Posição inicial (origem)
            1.2f, 0.2f,          // Altura e largura do tronco
            0.5f, 0.3f,          // Altura e raio da copa
            0.55f, 0.27f, 0.07f, // Cor do tronco
            0.0f, 0.8f, 0.0f     // Cor da copa
            );
        novaArvore->setSelecionado(true);
        novaArvore->setMostrarEixos(false);

        // Deselecionar o objeto anterior
        if (objetoSelecionado >= 0) {
            objetos[objetoSelecionado]->setSelecionado(false);
        }

        // Adicionar o novo objeto e atualizar o índice
        objetos.push_back(unique_ptr<Objeto>(novaArvore));
        objetoSelecionado = objetos.size() - 1;

        cout << "Nova ArvoreSimples adicionada na origem." << endl;
        break;
    }

        // Incluir nova ArvoreComplexa
    case '2': {
        ArvoreComplexa* novaArvore = new ArvoreComplexa(
            0.0f, 0.0f, 0.0f,    // Posição inicial (origem)
            1.0f, 0.25f,         // Altura e largura do tronco
            0.8f, 0.35f,         // Altura e raio da copa
            0.6f, 0.3f, 0.1f,    // Cor do tronco
            0.0f, 0.7f, 0.0f     // Cor da copa
            );
        novaArvore->setSelecionado(true);
        novaArvore->setMostrarEixos(false);

        // Deselecionar o objeto anterior
        if (objetoSelecionado >= 0) {
            objetos[objetoSelecionado]->setSelecionado(false);
        }

        // Adicionar o novo objeto e atualizar o índice
        objetos.push_back(unique_ptr<Objeto>(novaArvore));
        objetoSelecionado = objetos.size() - 1;

        cout << "Nova ArvoreComplexa adicionada na origem." << endl;
        break;
    }

        // Alternar para o próximo objeto (avançar)
    case 'n':
        if (!objetos.empty()) {
            objetos[objetoSelecionado]->setSelecionado(false);
            objetoSelecionado = (objetoSelecionado + 1) % objetos.size();
            objetos[objetoSelecionado]->setSelecionado(true);
            cout << "Selecionado próximo objeto." << endl;
        }
        break;

        // Alternar para o objeto anterior (retroceder)
    case 'b':
        if (!objetos.empty()) {
            objetos[objetoSelecionado]->setSelecionado(false);
            objetoSelecionado = (objetoSelecionado - 1 + objetos.size()) % objetos.size();
            objetos[objetoSelecionado]->setSelecionado(true);
            cout << "Selecionado objeto anterior." << endl;
        }
        break;

        // Apagar o objeto atualmente selecionado
    case '#':
        if (!objetos.empty() && objetoSelecionado >= 0) {
            cout << "Removendo objeto selecionado: " << objetoSelecionado << endl;
            objetos.erase(objetos.begin() + objetoSelecionado);

            if (objetos.empty()) {
                objetoSelecionado = -1;
            } else {
                objetoSelecionado = objetoSelecionado % objetos.size();
                objetos[objetoSelecionado]->setSelecionado(true);
            }
        } else {
            cout << "Nenhum objeto para remover!" << endl;
        }
        break;

        // Apagar o último objeto do vetor
    case '@':
        if (!objetos.empty()) {
            cout << "Removendo o último objeto." << endl;
            objetos.pop_back();

            // Ajustar o índice da seleção após a remoção
            if (objetos.empty()) {
                objetoSelecionado = -1;
            } else if (objetoSelecionado >= (int)objetos.size()) {
                objetoSelecionado = objetos.size() - 1;
                objetos[objetoSelecionado]->setSelecionado(true);
            }
        } else {
            cout << "Nenhum objeto no vetor para remover!" << endl;
        }
        break;

        // Alternar exibição dos eixos do objeto ativo
    case 'e':
        if (obj) {
            obj->setMostrarEixos(!obj->mostrarEixos);
            cout << "Eixos " << (obj->mostrarEixos ? "mostrados" : "ocultos") << "." << endl;
        }
        break;

        // Movimentação
    case 'w': if (obj) obj->mover(0, 0.1, 0); break;
    case 's': if (obj) obj->mover(0, -0.1, 0); break;
    case 'a': if (obj) obj->mover(-0.1, 0, 0); break;
    case 'd': if (obj) obj->mover(0.1, 0, 0); break;

        // Rotação
    case 'i': if (obj) obj->rotacionar(5, 0, 0); break;
    case 'k': if (obj) obj->rotacionar(-5, 0, 0); break;
    case 'j': if (obj) obj->rotacionar(0, 5, 0); break;
    case 'l': if (obj) obj->rotacionar(0, -5, 0); break;
    case 'u': if (obj) obj->rotacionar(0, 0, 5); break;
    case 'o': if (obj) obj->rotacionar(0, 0, -5); break;

        // Escala
    case '+': if (obj) obj->escalar(1.1, 1.1, 1.1); break;
    case '-': if (obj) obj->escalar(0.9, 0.9, 0.9); break;

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
    cout << "Iniciando o sistema com teclas # e @ para remoção." << endl;

    GUI gui = GUI(800, 600, desenhar, teclado);

    return 0;
}
