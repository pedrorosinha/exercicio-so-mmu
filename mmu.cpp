#include "mmu.hpp"

// Construtor: Inicializa a RAM e as tabelas de páginas dos processos
MMU::MMU() : ram(NUM_FRAMES) {
    for (int i = 0; i < 2; ++i) 
        tabela_paginas[i].resize(NUM_PAGINAS); // Utiliza a constante NUM_PAGINAS
}

void MMU::acessar(int pid, int endereco_virtual) {
    // Mapeamento Virtual -> Página e Offset (Usando TAM_BLOCO)
    int num_pagina = endereco_virtual / TAM_BLOCO;
    int offset = endereco_virtual % TAM_BLOCO;

    std::cout << "\n[Processo " << pid << "] Requisitando endereço virtual: " << endereco_virtual 
              << " (Página " << num_pagina << ", Offset " << offset << ")" << std::endl;

    // Consulta a Tabela de Páginas da MMU
    if (tabela_paginas[pid][num_pagina].presente) {
        int frame_id = tabela_paginas[pid][num_pagina].frame_id;
        int endereco_fisico = (frame_id * TAM_BLOCO) + offset;
        
        std::cout << ">>> Sucesso: Endereço na RAM!" << std::endl;
        std::cout << ">>> Mapeamento: Página " << num_pagina << " -> Frame " << frame_id 
                  << " | Endereço Físico: " << endereco_fisico << std::endl;
    } 
    else {
        // Tratamento de Falta de Página
        std::cout << ">>> FALTA DE PÁGINA detectada para Página " << num_pagina << "!" << std::endl;
        
        int frame_alvo = -1;

        // Busca por frame livre
        for (int i = 0; i < NUM_FRAMES; ++i) {
            if (!ram[i].ocupado) {
                frame_alvo = i;
                break;
            }
        }

        // Se a RAM estiver cheia, aplica o algoritmo FIFO
        if (frame_alvo == -1) {
            frame_alvo = fila_fifo.front();
            fila_fifo.pop();
            
            // Invalida a página antiga que estava ocupando este frame
            tabela_paginas[ram[frame_alvo].pid][ram[frame_alvo].pagina_id].presente = false;
            
            std::cout << ">>> Algoritmo FIFO: Substituindo Frame " << frame_alvo 
                      << " (pertencente ao Proc " << ram[frame_alvo].pid << ")" << std::endl;
        }

        // Carrega nova página no frame escolhido
        ram[frame_alvo] = {pid, num_pagina, true};
        tabela_paginas[pid][num_pagina] = {frame_alvo, true};
        fila_fifo.push(frame_alvo);

        std::cout << ">>> Página " << num_pagina << " carregada no Frame " << frame_alvo << std::endl;
    }
}