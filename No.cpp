/* 
 * UC: 21045-Estruturas de Dados e Algoritmos Avançados
 * e-fólio B 2017-18 (huff)
 * 
 * Aluno: 1301913 - José Póvoa
 */

#include <iostream>
#include "No.h"

using namespace std;

No::No(int frequencia) {
    mFrequencia = frequencia;
    //cout << "DEBUG: No construído" << endl;
}

No::~No() {
    //cout << "DEBUG: No destruído" << endl;
}

int No::GetFrequencia() const {
    return mFrequencia;
}

void No::SetFrequencia(int frequencia) {
    mFrequencia = frequencia;
}

void No::Mostrar() const {
    cout << "Frequência: " << mFrequencia << endl;
}

