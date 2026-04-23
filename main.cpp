#include "mmu.hpp"

int main() {
    MMU sistema;

    // Testando acessos
    sistema.acessar(0, 1000); // Carrega na RAM
    sistema.acessar(0, 9000); // Carrega na RAM
    sistema.acessar(1, 2000); // Carrega na RAM
    
    return 0;
}