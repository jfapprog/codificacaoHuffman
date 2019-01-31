/* 
 * UC: 21045-Estruturas de Dados e Algoritmos Avançados
 * e-fólio B 2017-18 (huff)
 * 
 * Aluno: 1301913 - José Póvoa
 */

#include <iostream>
#include "NoFolha.h"

using namespace std;

NoFolha::NoFolha(int frequencia, char simbolo) :
No::No(frequencia) {
    mSimbolo = simbolo;
    // cout << "DEBUG: NoFolha " << No::GetFrequencia() << " construído" << endl;
}

NoFolha::~NoFolha() {
    // cout << "DEBUG: NoFolha  " << No::GetFrequencia() << " destruído" << endl;
}

char NoFolha::GetSimbolo() const {
    return mSimbolo;
}

void NoFolha::SetSimbolo(char simbolo) {
    mSimbolo = simbolo;
}

void NoFolha::Mostrar() const {
    cout << "Frequência: " << No::GetFrequencia() << endl;
    cout << "Símbolo: " << mSimbolo << endl;
}

