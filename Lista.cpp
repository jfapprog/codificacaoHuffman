/* 
 * UC: 21045-Estruturas de Dados e Algoritmos Avançados
 * e-fólio B 2017-18 (huff)
 * 
 * Aluno: 1301913 - José Póvoa
 */

#include "Lista.h"

using namespace std;

Lista::Lista() {
    mPrimeiro = 0;
    //cout << "DEBUG: Lista construída" << endl;
}

Lista::~Lista() {
    this->Esvaziar();
    //cout << "DEBUG: Lista destruída" << endl;
}

bool Lista::Vazia() const {
    return (mPrimeiro == 0);
}

void Lista::Esvaziar() {
    //remover nó do início enquanto não está vazia
    while (!(this->Vazia()))
        this->RemoverPrimeiro();
}

int Lista::NumeroNos() const {
    //se está vazia o número de elementos é zero
    if (this->Vazia())
        return 0;
    //se não, percorrer lista e contabilizar elementos
    int contador = 0;
    NoLista* iterador = mPrimeiro;
    while (iterador != 0) {
        contador++;
        iterador = iterador->mSeguinte;
    }
    return contador;
}

void Lista::InserirOrdenado(No* noArvore) {
    //se a lista está vazia mPrimeiro passa a ser o novo nó
    if (this->Vazia()) {
        mPrimeiro = new NoLista(noArvore);
        return;
    }
    //se tem frequência menor que o mPrimeiro, mPrimeiro passa a ser o novo nó
    if (noArvore->GetFrequencia() < mPrimeiro->mNoArvore->GetFrequencia()) {
        mPrimeiro = new NoLista(noArvore, mPrimeiro);
        return;
    }
    //se a lista não está vazia
    //percorrer lista até encontrar posição de colocação
    NoLista* iterador = mPrimeiro;
    while (iterador->mSeguinte != 0 &&
            noArvore->GetFrequencia() >= iterador->mSeguinte->mNoArvore->GetFrequencia()) {
        iterador = iterador->mSeguinte;
    }
    //inserir após paragem
    iterador->mSeguinte = new NoLista(noArvore, iterador->mSeguinte);
}

int Lista::GetIndiceNoFrequenciaMinima() const {
    //se lista está vazia, retornar -1
    if (Vazia())
        return -1;
    //se não, percorrer lista
    int freqMinima = mPrimeiro->mNoArvore->GetFrequencia();
    int indMinimo = 0;
    NoLista* iterador = mPrimeiro->mSeguinte;
    int indice = 1;
    while (iterador != 0) {
        if (iterador->mNoArvore->GetFrequencia() < freqMinima) {
            freqMinima = iterador->mNoArvore->GetFrequencia();
            indMinimo = indice;
        }
        iterador = iterador->mSeguinte;
        indice++;
    }
    return indMinimo;
}

int Lista::GetIndiceNoFrequenciaMinima(int indice) const {
    //se lista está vazia, retornar -1
    if (Vazia())
        return -1;
    //se não, percorrer lista
    int freqMinima = mPrimeiro->mNoArvore->GetFrequencia();
    int indMinimo = 0;
    NoLista* iterador = mPrimeiro->mSeguinte;
    int ind = 1;
    //se indice é 0, adiantar 1
    if (indice == 0) {
        freqMinima = mPrimeiro->mSeguinte->mNoArvore->GetFrequencia();
        indMinimo = 1;
        iterador = mPrimeiro->mSeguinte->mSeguinte;
        ind = 2;
    }
    while (iterador != 0) {
        if (ind != indice) { //só comparar se não for igual ao indice
            if (iterador->mNoArvore->GetFrequencia() < freqMinima) {
                freqMinima = iterador->mNoArvore->GetFrequencia();
                indMinimo = ind;
            }
        }
        iterador = iterador->mSeguinte;
        ind++;
    }
    return indMinimo;
}

No* Lista::GetNo(int indice) const {
    //se a lista está vazia, retornar 0
    if (Vazia())
        return 0;
    //se não, percorrer lista até ao indice
    int ind = 0;
    NoLista* iterador = mPrimeiro;
    while (iterador != 0) {
        if (indice == ind)
            return iterador->mNoArvore;
        iterador = iterador->mSeguinte;
        ind++;
    }
    //se chegar ao fim, retornar 0
    return 0;
}

void Lista::SetNo(int indice, No* noArvore) {
    //se a lista está vazia, não fazer nada
    if (Vazia())
        return;
    //se não, percorrer lista
    NoLista* iterador = mPrimeiro;
    int ind = 0;
    while (iterador != 0) {
        //quando encontrar o índice substitui
        if (ind == indice) {
            iterador->mNoArvore = noArvore;
        }
        iterador = iterador->mSeguinte;
        ind++;
    }
}

void Lista::Remover(int indice) {
    //se a lista está vazia, não remover
    if (Vazia()) {
        return;
    }
    //se indice é o topo, remover topo
    if (indice == 0) {
        this->RemoverPrimeiro();
        return;
    }
    //se não, percorrer lista até ao indice
    NoLista* iterador = mPrimeiro->mSeguinte;
    NoLista* anterior = mPrimeiro;
    int ind = 1;
    while (iterador != 0) {
        //se o indice é igual, atualizar mSeguinte e remover 
        if (ind == indice) {
            anterior->mSeguinte = iterador->mSeguinte;
            delete iterador;
            return;
        }
        //se não, avançar
        iterador = iterador->mSeguinte;
        anterior = anterior->mSeguinte;
        ind++;
    }
}

void Lista::RemoverPrimeiro() {
    //se está vazia, não faz nada
    if (this->Vazia())
        return;
    //se não, guardar primeiro
    NoLista* apagar = mPrimeiro;
    //mPrimeiro passa a ser o seu seguinte
    mPrimeiro = mPrimeiro->mSeguinte;
    //apagar nó
    delete apagar;
}

No* Lista::GetPrimeiro() const {
    return mPrimeiro->mNoArvore;
}

void Lista::Mostrar() const {
    //se a lista está vazia, escrever na saída padrão essa informação
    if (this->Vazia()) {
        cout << "A lista está vazia" << endl;
        return;
    }
    //se não, escrever o número de nós na lista
    cout << "### Lista com " << this->NumeroNos() << " nós. ###" << endl;
    //percorrer lista e escrever frequência de cada nó
    NoLista* iterador = mPrimeiro;
    while (iterador != 0) {
        cout << iterador->mNoArvore->GetFrequencia() << " ";
        iterador = iterador->mSeguinte;
    }
    cout << endl;
}
