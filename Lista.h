/* 
 * UC: 21045-Estruturas de Dados e Algoritmos Avançados
 * e-fólio B 2017-18 (huff)
 * 
 * Aluno: 1301913 - José Póvoa
 */

#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "No.h"

using namespace std;

class NoLista {
public:
    No* mNoArvore; //membro nó árvore
    NoLista* mSeguinte; //membro nó lista seguinte

    NoLista() {
        mSeguinte = 0;
        //cout << "DEBUG: NoLista vazio contruído!" << endl;
    }

    NoLista(No* noArvore, NoLista* seguinte = 0) {
        mNoArvore = noArvore;
        mSeguinte = seguinte;
        //cout << "DEBUG: NoLista "
        //        << mNoArvore->GetFrequencia() << " construído!" << endl;

    }

    virtual ~NoLista() {
        //cout << "DEBUG: NoLista"
        //        << mNoArvore->GetFrequencia() << " construído!" << endl;
    }
};

class Lista {
private:
    NoLista* mPrimeiro; //membro nó topo da lista

public:
    //construtor
    Lista();
    //destrutor
    virtual ~Lista();
    //retorna true se a lista está vazia
    bool Vazia() const;
    //elimina todos os nós da lista
    void Esvaziar();
    //retorna o número de nós na lista
    int NumeroNos() const;
    //insere um NoArvore na lista, ordenado pela frequência
    void InserirOrdenado(No* noArvore);
    //retorna indice do NoArvbore de frequência mínima
    int GetIndiceNoFrequenciaMinima() const;
    //retorna indice do NoArvore de frequencia mínima excepto indice indicado
    int GetIndiceNoFrequenciaMinima(int indice) const;
    //retorna um apontador para o NoArvore de indice indicado
    No* GetNo(int indice) const;
    //alterar NoArvore do indice indicado
    void SetNo(int indice, No* noArvore);
    //remove o NoLista com o indice indicado
    void Remover(int indice);
    //retorna um apontador para o nó no topo da lista
    No* GetPrimeiro() const;
    //retira o nó do topo da lista
    void RemoverPrimeiro();
    //escreve na saída padrão a lista de nós
    void Mostrar() const;   

};

#endif /* LISTA_H */

