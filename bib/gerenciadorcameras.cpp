#include "gerenciadorcameras.h"
#include <iostream>
#include <GL/glut.h>

GerenciadorCameras::GerenciadorCameras() : indiceCameraAtual(0) {
    configuracoesCamera.emplace_back("Visão Frontal",
                                     std::make_unique<CameraJogo>(Vetor3D(0, 2, 6), Vetor3D(0, 1, 0), Vetor3D(0, 1, 0)));

    configuracoesCamera.emplace_back("Lateral Esquerda Próxima",
                                     std::make_unique<CameraDistante>(Vetor3D(-5, 3, 3), Vetor3D(0, 1, 0), Vetor3D(0, 1, 0)));

    configuracoesCamera.emplace_back("Vista Superior",
                                     std::make_unique<CameraDistante>(Vetor3D(0, 6, 10), Vetor3D(0, 1, 0), Vetor3D(0, 1, 0)));

    configuracoesCamera.emplace_back("Lateral Direita Próxima",
                                     std::make_unique<CameraDistante>(Vetor3D(5, 3, 3), Vetor3D(0, 1, 0), Vetor3D(0, 1, 0)));

    configuracoesCamera.emplace_back("Traseira Aproximada",
                                     std::make_unique<CameraJogo>(Vetor3D(0, 2, -4), Vetor3D(0, 1, 0), Vetor3D(0, 1, 0)));

    configuracoesCamera.emplace_back("Vista Inferior",
                                     std::make_unique<CameraJogo>(Vetor3D(0, -3, 2), Vetor3D(0, 1, 0), Vetor3D(0, 0, 1)));



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
