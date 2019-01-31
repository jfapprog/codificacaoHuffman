/* 
 * UC: 21045-Estruturas de Dados e Algoritmos Avançados
 * e-fólio B 2017-18 (huff)
 * 
 * Aluno: 1301913 - José Póvoa
 */

#ifndef NOINTERNO_H
#define NOINTERNO_H

#include "No.h"

class NoInterno : public No {
private:
    No* mEsquerda; //membro apontador para nó à esquerda
    No* mDireita; //membro apontador para nó à direita

public:
    //construtor
    NoInterno(No* esquerda, No* direita);
    //destrutor
    virtual ~NoInterno();
    //retorna nó à esquerda
    No* GetEsquerda() const;
    //modifica nó à esquerda
    void SetEsquerda(No* esquerda);
    //retorna nó à direita
    No* GetDireita() const;
    //modifica nó à direita
    void SetDireita(No* direita);
    //escreve na saída padrão as informações do nó
    virtual void Mostrar() const;
};

#endif /* NOINTERNO_H */

