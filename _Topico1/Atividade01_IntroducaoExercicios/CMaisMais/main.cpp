#include <iostream>
#include <vector>

using namespace std;

int LerInteiro() {
    int numeroInt = 0;
    while (true) {
        if (!(cin >> numeroInt)) {
            cout << "Valor invalido! Digite um numero inteiro." << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
        } else {
            return numeroInt;
        }
    }
}

int LerInteiroPositivo() {
    int numeroIntPos = 0;
    while (true) {
        if (!(cin >> numeroIntPos) || numeroIntPos <= 0) {
            cout << "Valor invalido! Digite um numero inteiro positivo." << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
        } else {
            return numeroIntPos;
        }
    }
}

void AntesSequencia() {
    cout << "Informe a qtd. de valores (n) menor que 1.000.000: " << flush;
    int n = LerInteiroPositivo();

    cout << "Informe o valor a buscar (m): " << flush;
    int m = LerInteiro();

    int contador = 0;

    cout << "Informe os " << n << " valores de (n) ____" << endl;
    for (int i = 0; i < n; i++) {
        int x = LerInteiro();
        if (x == m) {
            contador++;
        }
    }

    cout << "O valor (m) apareceu " << contador << " vezes em (n)." << endl;
}

void DepoisSequencia() {
    cout << "Informe a qtd. de valores (n) menor que 1.000.000: " << flush;
    int n = LerInteiroPositivo();

    cout << "Informe os " << n << " valores de (n) ____" << endl;
    vector<int> vetorN(n);
    for (int i = 0; i < n; i++) {
        vetorN[i] = LerInteiro();
    }

    cout << "Informe o valor a buscar (m): " << flush;
    int m = LerInteiro();

    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (vetorN[i] == m) {
            contador++;
        }
    }

    cout << "O valor (m) apareceu " << contador << " vezes em (n)." << endl;
}

int main() {
    AntesSequencia();
    DepoisSequencia();
    return 0;
}