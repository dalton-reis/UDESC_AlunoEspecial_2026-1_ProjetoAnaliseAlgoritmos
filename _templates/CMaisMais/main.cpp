#include <iostream>
// Exibe uma mensagem no terminal, lê um valor inteiro e mostra o valor informado pelo usuário.

//FIXME: usa o terminal externo e não integrado ao VSCode ./.vscode/launch.json "externalConsole": true,
int main() {
    std::cout << "Olá, mundo! Exemplo em C++ executado com sucesso, e com acentuação." << std::endl;
    std::cout << "Valor: ";
    int valor;
    std::cin >> valor;
    std::cout << "Valor lido: " << valor << std::endl;
    return 0;
}
