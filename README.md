# 🌳 Modelador Gráfico Interativo - Computação Gráfica

Este é um modelador gráfico interativo desenvolvido em **C++** e **OpenGL/GLUT** para manipular objetos 3D, permitindo **transformações, seleção, movimentação, rotação, escalonamento, salvar e carregar objetos via JSON.**

### 📌 **Trabalho da disciplina de Computação Gráfica**  
**Universidade Federal do Ceará - Campus Quixadá**  
**Professor: Rubens Nunes**  
**Autor: Antonio Andson da Silva**  

---

## 📸 **Cena do projeto**

A imagem abaixo representa a cena final do projeto. O ambiente inclui uma pista inclinada, um carro 3D, árvores fixas e uma placa de anúncio. O carro percorre a pista de forma interativa, e os objetos podem ser adicionados, manipulados e removidos dinamicamente.

![cena](https://github.com/user-attachments/assets/5efd2bc5-8300-46b4-aaca-8972d520625d)

---

## 🚀 **Como executar o projeto**
### 🔹 **Pré-requisitos**
- Compilador **g++** compatível com C++17 ou superior
- **GLUT** instalado (`freeglut`)
- **nlohmann/json** para manipulação de arquivos JSON
- **Makefile** configurado corretamente
- Ambiente configurado para execução de aplicações OpenGL

### 🔹 **Compilação e execução**
```sh
make        # Compila o projeto
./GLUTdoZero  # Executa o programa
```

---

## 📺 **Controles do Teclado**

### 📌 **Criação e Manipulação de Objetos**
| **Tecla** | **Ação** |
|-----------|---------|
| `1` | Adiciona uma **ArvoreSimples** ao cenário |
| `2` | Adiciona uma **ArvoreComplexa** ao cenário |
| `n` | Seleciona o **próximo** objeto |
| `b` | Seleciona o **objeto anterior** |
| `#` | Remove o **objeto selecionado** |
| `@` | Remove o **último** objeto adicionado |

### ✨ **Transformações no Objeto Selecionado**
| **Transformação** | **Tecla(s)** |
|-------------------|-------------|
| Mover nos eixos X, Y e Z | `w`, `s`, `a`, `d`, `r`, `f` |
| Rotacionar nos eixos X, Y e Z | `i`, `k`, `j`, `l`, `u`, `h` |
| Aumentar/Diminuir escala | `+`, `-` |

### 💡 **Exibição de Eixos**
| **Tecla** | **Ação** |
|-----------|---------|
| `R` | Alterna exibição dos eixos no objeto selecionado |
| `T` | Alterna exibição global dos eixos |

### 🎥 **Câmeras**
| **Tecla** | **Ação** |
|-----------|---------|
| `W`, `S`, `A`, `D`, `Q`, `E` | Movimentação da câmera |
| `3` a `8` | Alternar entre câmeras pré-definidas |

### 🔦 **Iluminação**
| **Tecla** | **Ação** |
|-----------|---------|
| `L` | Alterna visibilidade da luz |

---

## 📂 **Gerenciamento de Arquivos**
| **Tecla** | **Ação** |
|-----------|---------|
| `$` | **Salva** todos os objetos no arquivo `objetos.json` |
| `%` | **Carrega** os objetos do arquivo `objetos.json` |

O arquivo JSON contém informações como **posição, rotação, escala, tipo de objeto e visibilidade dos eixos**.

---

## 🎯 **Requisitos do Trabalho**

### **Implementação do Modelador (6.0 Pontos)**
- **Implementação Orientada a Objetos (2.5 Pontos)**
  - Herança e método `desenhar`
  - Transformações (Translação, Rotação, Escala)
  - Seleção e destaque do objeto
  - Exibição dos eixos locais

- **Manipulação do Vetor de Objetos (1.5 Ponto)**
  - Inclusão, seleção e remoção de objetos do vetor

- **Modificação dos Atributos do Objeto Selecionado (1.5 Ponto)**
  - Translação, rotação, escala e controle dos eixos locais

- **Salvar e carregar objetos (0.5 Ponto)**

### **Câmeras (1.0 Ponto)**
- Implementação da Câmera Base
- Definir pelo menos 6 câmeras pré-estabelecidas

### **Modelagem Final (3.0 Pontos)**
- Modelar um cenário detalhado
- Pelo menos 5 tipos de objetos diferentes
- Uso de `glBegin(...); glEnd();` em pelo menos 2 objetos
- Definir `glNormal3f(...)` corretamente
- Pelo menos 2 faces inclinadas no cenário

