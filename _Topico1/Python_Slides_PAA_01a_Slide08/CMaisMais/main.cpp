/**
 * Prompt CODEX:
 * Criar código que use a função "pesquisa" da imagem (image.png).
 * Criar uma nova função para popular o vetor v com números inteiros positivos aleatórios.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>

// Estrutura para armazenar dados
struct Estrutura {
    int chave;
};

// Função de busca linear: procura por um elemento no vetor
int pesquisa(Estrutura *v, int n, int chave) {
    int i;
    for (i = 0; i < n; i++)
        if (v[i].chave == chave)
            return i;
    return -1;
}

// Função para popular o vetor com números inteiros positivos aleatórios
void popularVetor(Estrutura *v, int n, int maxValor) {
    for (int i = 0; i < n; i++) {
        v[i].chave = rand() % maxValor + 1;  // Gera números de 1 a maxValor
    }
}

int main() {
    std::setlocale(LC_ALL, "");
    srand(time(0));  // Inicializa o gerador de números aleatórios
    
    const int TAMANHO = 10;
    Estrutura vetor[TAMANHO];
    
    // Popular o vetor com números aleatórios de 1 a 50
    popularVetor(vetor, TAMANHO, 50);
    
    std::cout << "Vetor populado com números aleatórios:" << std::endl;
    for (int i = 0; i < TAMANHO; i++) {
        std::cout << "vetor[" << i << "].chave = " << vetor[i].chave << std::endl;
    }
    
    std::cout << std::endl;
    
    // Testando a função pesquisa
    int chaveProcurada = vetor[5].chave;  // Pega um elemento conhecido
    int resultado = pesquisa(vetor, TAMANHO, chaveProcurada);
    
    if (resultado != -1) {
        std::cout << "Chave " << chaveProcurada << " encontrada no índice " << resultado << std::endl;
    } else {
        std::cout << "Chave " << chaveProcurada << " não encontrada!" << std::endl;
    }
    
    // Testando pesquisa com valor que provavelmente não existe
    int chaveNaoEsperada = 999;
    resultado = pesquisa(vetor, TAMANHO, chaveNaoEsperada);
    
    if (resultado != -1) {
        std::cout << "Chave " << chaveNaoEsperada << " encontrada no índice " << resultado << std::endl;
    } else {
        std::cout << "Chave " << chaveNaoEsperada << " não encontrada!" << std::endl;
    }
    
    return 0;
}
