/* 
 * UC: 21045-Estruturas de Dados e Algoritmos Avançados
 * e-fólio B 2017-18 (huff)
 * 
 * Aluno: 1301913 - José Póvoa
 */

#ifndef NO_H
#define NO_H

class No {
private:
    int mFrequencia; //membro frequência
public:
    //construtor
    explicit No(int frequencia);
    //destrutor
    virtual ~No();
    //retorna a frequência do nó
    int GetFrequencia() const;
    //modifica a frequência do nó
    void SetFrequencia(int frequencia);
    //escreve na saída padrão as informações do nó
    virtual void Mostrar() const;
};

#endif /* NO_H */

