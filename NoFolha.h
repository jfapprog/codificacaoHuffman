/* 
 * UC: 21045-Estruturas de Dados e Algoritmos Avançados
 * e-fólio B 2017-18 (huff)
 * 
 * Aluno: 1301913 - José Póvoa
 */

#ifndef NOFOLHA_H
#define NOFOLHA_H

#include "No.h"

class NoFolha : public No {
private:
    char mSimbolo; //membro simbolo

public:
    //construtor
    NoFolha(int frequencia, char simbolo);
    //destrutor
    virtual ~NoFolha();
    //retorna o símbolo
    char GetSimbolo() const;
    //modifica o símbolo
    void SetSimbolo(char simbolo);
    //escreve na saída padrão as informações do nó
    virtual void Mostrar() const;
};

#endif /* NOFOLHA_H */

