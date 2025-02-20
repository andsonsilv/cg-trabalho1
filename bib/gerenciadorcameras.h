#ifndef GERENCIADORCAMERAS_H
#define GERENCIADORCAMERAS_H

#include <vector>
#include <memory>
#include <string>
#include "Camera.h"
#include "CameraDistante.h"
#include "CameraJogo.h"

class GerenciadorCameras {
public:
    GerenciadorCameras();
    void alternarCamera(int indice);
    Camera* getCamera();

private:
    struct CameraConfig {
        std::string nome;
        std::unique_ptr<Camera> cam;
        CameraConfig(std::string nome, std::unique_ptr<Camera> cam)
            : nome(std::move(nome)), cam(std::move(cam)) {}
    };

    std::vector<CameraConfig> configuracoesCamera;
    int indiceCameraAtual;
    std::unique_ptr<Camera> camera;
};

#endif
