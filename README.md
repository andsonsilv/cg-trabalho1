# 🌳 Modelador Gráfico Interativo - Computação Gráfica

Este é um modelador gráfico interativo desenvolvido em **C++** e **OpenGL/GLUT** para manipular objetos 3D, permitindo **transformações, seleção, movimentação, rotação, escalonamento, salvar e carregar objetos via JSON.**

---

## 🚀 **Como executar o projeto**
### 🔹 **Pré-requisitos**
- Compilador **g++** compatível com C++17 ou superior
- **GLUT** instalado (`freeglut`)
- **nlohmann/json** para manipulação de arquivos JSON

### 🔹 **Compilação e execução**
```sh
make        # Compila o projeto
./GLUTdoZero  # Executa o programa
```

---

## 🎮 **Comandos do Teclado**
| **Tecla** | **Ação** |
|-----------|---------|
| `1` | Adiciona uma **ArvoreSimples** ao cenário |
| `2` | Adiciona uma **ArvoreComplexa** ao cenário |
| `n` | Seleciona o próximo objeto |
| `b` | Seleciona o objeto anterior |
| `#` | Remove o objeto **selecionado** |
| `@` | Remove o **último** objeto adicionado |
| `$` | **Salva** todos os objetos no arquivo `objetos.json` |
| `%` | **Carrega** os objetos do arquivo `objetos.json` |

### ✨ **Transformações no Objeto Selecionado**
| **Transformação** | **Tecla(s)** |
|-------------------|-------------|
| **Mover para frente no eixo Z** | `r` |
| **Mover para trás no eixo Z** | `f` |
| **Mover para cima no eixo Y** | `w` |
| **Mover para baixo no eixo Y** | `s` |
| **Mover para a esquerda no eixo X** | `a` |
| **Mover para a direita no eixo X** | `d` |
| **Rotacionar para frente no eixo X** | `i` |
| **Rotacionar para trás no eixo X** | `k` |
| **Rotacionar para a esquerda no eixo Y** | `j` |
| **Rotacionar para a direita no eixo Y** | `l` |
| **Rotacionar no eixo Z sentido horário** | `u` |
| **Rotacionar no eixo Z sentido anti-horário** | `o` |
| **Aumentar escala do objeto** | `+` |
| **Diminuir escala do objeto** | `-` |

### 💡 **Controle de Exibição dos Eixos**
| **Tecla** | **Ação** |
|-----------|---------|
| `E` | Alterna a exibição dos eixos **apenas no objeto selecionado** |
| `T` | Ativa/desativa a exibição dos eixos **para todos os objetos** |

### 🔦 **Controle da Iluminação**
| **Tecla** | **Ação** |
|-----------|---------|
| `4` | Move a luz para a esquerda |
| `6` | Move a luz para a direita |
| `5` | Move a luz para baixo |
| `8` | Move a luz para cima |
| `[` | Move a luz para trás |
| `]` | Move a luz para frente |

---

## 📂 **Gerenciamento de Arquivos**
- **Salvar (`$`)** → Todos os objetos e seus atributos são armazenados no arquivo `objetos.json`.
- **Carregar (`%`)** → Recupera os objetos do arquivo e os adiciona ao cenário.

O arquivo JSON contém informações como **posição, rotação, escala, tipo de objeto e visibilidade dos eixos**.

---

## 🎯 **Objetivo do Projeto**
Este projeto foi desenvolvido para permitir a modelagem interativa de cenários com árvores e outros objetos 3D, explorando conceitos de **transformações geométricas**, **manipulação de câmera**, **persistência de dados** e **OpenGL**.

---

## 🛠 **Tecnologias Utilizadas**
- **C++**
- **OpenGL / GLUT**
- **nlohmann/json**
- **g++ / Makefile**

---

## 📌 **Autor**
Desenvolvido por **Antonio Andson da Silva**, Cientista da Computação. 🚀
