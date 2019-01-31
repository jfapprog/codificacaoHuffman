/* 
 * UC: 21045-Estruturas de Dados e Algoritmos Avançados
 * e-fólio B 2017-18 (huff)
 * 
 * Aluno: 1301913 - José Póvoa
 */

#include <iostream>
#include "NoInterno.h"

using namespace std;

NoInterno::NoInterno(No* esquerda, No* direita) :
No::No(esquerda->GetFrequencia() + direita->GetFrequencia()) {
    mEsquerda = esquerda;
    mDireita = direita;
    //cout << "DEBUG: NoInterno construído" << endl;
}

NoInterno::~NoInterno() {
    delete mEsquerda;
    delete mDireita;
    //cout << "DEBUG: NoInterno " << No::GetFrequencia() << " destruído" << endl;
}

No* NoInterno::GetEsquerda() const {
    return mEsquerda;
}

void NoInterno::SetEsquerda(No* esquerda) {
    mEsquerda = esquerda;
}

No* NoInterno::GetDireita() const {
    return mDireita;
}

void NoInterno::SetDireita(No* direita) {
    mDireita = direita;
}

void NoInterno::Mostrar() const {
    cout << "Frequência: " << No::GetFrequencia() << endl;
}

