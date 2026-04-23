#ifndef MMU_HPP
#define MMU_HPP

#include <vector>
#include <queue>
#include <iostream>

struct Pagina {
    int frame_id = -1;
    bool presente = false;
};

class MMU {
private:
    static const int TAM_MEM_PRINCIPAL = 65536; // 64K
    static const int TAM_MEM_VIRTUAL = 1048576; // 1MB
    static const int TAM_BLOCO = 8192;          // 8K
    
    // Cálculos de hardware
    static const int NUM_FRAMES = TAM_MEM_PRINCIPAL / TAM_BLOCO;  // 8 frames
    static const int NUM_PAGINAS = TAM_MEM_VIRTUAL / TAM_BLOCO;   // 128 páginas

    struct Frame {
        int pid = -1;
        int pagina_id = -1;
        bool ocupado = false;
    };

    std::vector<Frame> ram;
    std::queue<int> fila_fifo; 
    std::vector<Pagina> tabela_paginas[2]; // PID 0 e 1

public:
    MMU();
    void acessar(int pid, int endereco_virtual);
};

#endif