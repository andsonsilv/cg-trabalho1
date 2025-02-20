#include "gerenciadorcameras.h"
#include <iostream>
#include <GL/glut.h>

GerenciadorCameras::GerenciadorCameras() : indiceCameraAtual(0) {
    configuracoesCamera.emplace_back("Vista Aérea", std::make_unique<CameraDistante>(Vetor3D(0, 8, 15), Vetor3D(0, 1, 0), Vetor3D(0, 1, 0)));
    configuracoesCamera.emplace_back("Lateral Esquerda", std::make_unique<CameraDistante>(Vetor3D(-10, 5, 5), Vetor3D(0, 1, 0), Vetor3D(0, 1, 0)));
    configuracoesCamera.emplace_back("Lateral Direita", std::make_unique<CameraDistante>(Vetor3D(10, 5, 5), Vetor3D(0, 1, 0), Vetor3D(0, 1, 0)));
    configuracoesCamera.emplace_back("Primeira Pessoa", std::make_unique<CameraJogo>(Vetor3D(0, 2, 5), Vetor3D(0, 1, 0), Vetor3D(0, 1, 0)));
    configuracoesCamera.emplace_back("Traseira", std::make_unique<CameraJogo>(Vetor3D(0, 1, -5), Vetor3D(0, 1, 0), Vetor3D(0, 1, 0)));
    configuracoesCamera.emplace_back("Vista de Baixo", std::make_unique<CameraJogo>(Vetor3D(0, -5, 0), Vetor3D(0, 1, 0), Vetor3D(0, 0, 1)));

    // Inicializa a câmera com a primeira configuração
    camera = std::make_unique<CameraDistante>(
        configuracoesCamera[indiceCameraAtual].cam->e,
        configuracoesCamera[indiceCameraAtual].cam->c,
        configuracoesCamera[indiceCameraAtual].cam->u
        );
}

void GerenciadorCameras::alternarCamera(int indice) {
    if (indice >= 0 && indice < (int)configuracoesCamera.size()) {
        indiceCameraAtual = indice;

        // Cria uma nova instância para evitar ponteiros inválidos
        camera = std::make_unique<CameraDistante>(
            configuracoesCamera[indiceCameraAtual].cam->e,
            configuracoesCamera[indiceCameraAtual].cam->c,
            configuracoesCamera[indiceCameraAtual].cam->u
            );

        camera->posicionar();
        glutPostRedisplay();
        std::cout << "📸 Mudando para câmera: " << configuracoesCamera[indiceCameraAtual].nome << std::endl;
    }
}

Camera* GerenciadorCameras::getCamera() {
    return camera.get();
}
