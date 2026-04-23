# Simulador de MMU (Memory Management Unit)

Este projeto implementa uma simulação de uma MMU (Unidade de Gerenciamento de Memória) utilizando paginação com política de substituição FIFO (First-In, First-Out).

O objetivo é demonstrar, de forma prática, como ocorre o gerenciamento de memória em sistemas operacionais.

---

## Funcionalidades

- Tradução de endereço virtual para físico  
- Gerenciamento de tabelas de páginas por processo  
- Alocação de frames na memória principal  
- Tratamento de page fault (falta de página)  
- Substituição de páginas utilizando algoritmo FIFO  

---

## Especificações do Sistema

| Componente           | Valor  |
|----------------------|--------|
| Memória Principal    | 64 KB  |
| Memória Virtual      | 1 MB   |
| Tamanho do Bloco     | 8 KB   |

---

## Cálculos

- Número de Frames (RAM): 8  
- Número de Páginas: 128

## Estruturas

### Pagina

```cpp
struct Pagina {
    int frame_id = -1;
    bool presente = false;
};
```

---


## Classe MMU

### Atributos principais

- ram: vetor de frames (memória principal)  
- fila_fifo: fila para controle de substituição FIFO  
- tabela_paginas: tabela de páginas para cada processo (PID 0 e 1)  

---

## Método principal

```cpp
void acessar(int pid, int endereco_virtual);
```

## Como compilar e executar

Para compilar o projeto, utilize um compilador compatível com C++ (como o `g++`). No terminal, navegue até a pasta do projeto e execute:

```bash
g++ main.cpp MMU.cpp -o simulador
```

Aqui está o bloco de código atualizado para o seu README.md, contendo as instruções claras de compilação e execução, conforme solicitado.

## Como compilar e executar

Para compilar o projeto, utilize um compilador compatível com C++ (como o `g++`). No terminal, navegue até a pasta do projeto e execute:

```bash
g++ main.cpp MMU.cpp -o simulador
```

Após a compilação bem-sucedida, um arquivo executável chamado simulador será gerado. Para rodá-lo, utilize o comando:

```bash
./simulador
```
