/* 
 * UC: 21045-Estruturas de Dados e Algoritmos Avançados
 * e-fólio B 2017-18 (huff)
 * 
 * Aluno: 1301913 - José Póvoa
 */

#include <iostream>
#include <fstream>
#include <cstdio>
#include "No.h"
#include "NoInterno.h"
#include "NoFolha.h"
#include "Lista.h"

using namespace std;

No* ConstruirArvore(const int* frequencia, int dimensao) {

    //criar lista de nós
    Lista* listaNos = new Lista();

    //acrescentar à lista todos os nós folhas
    char simbolo;
    for (int i = 0; i < dimensao; i++) {
        simbolo = (char) i;
        if (frequencia[i] != 0)
            listaNos->InserirOrdenado(new NoFolha(frequencia[i], simbolo));
    }

    //construir a árvore de Huffman
    //retirando os dois nós de menor frequência
    //e unindo-os num único nó
    while (listaNos->NumeroNos() > 1) {
        //encontrar indice de nó de frequência mínima
        int indice1Minimo = listaNos->GetIndiceNoFrequenciaMinima();
        int indice2Minimo = listaNos->GetIndiceNoFrequenciaMinima(indice1Minimo);
        //determinar indice menor
        int indiceEsquerda;
        int indiceDireita;
        if (indice1Minimo < indice2Minimo) {
            indiceEsquerda = indice1Minimo;
            indiceDireita = indice2Minimo;
        } else {
            indiceEsquerda = indice2Minimo;
            indiceDireita = indice1Minimo;
        }
        //obter nós nos indices
        No* noEsquerda = listaNos->GetNo(indiceEsquerda);
        No* noDireita = listaNos->GetNo(indiceDireita);
        //construir novo nó interno
        NoInterno* novo = new NoInterno(noEsquerda, noDireita);
        //substituir nó do indice menor por novo nó
        listaNos->SetNo(indiceEsquerda, novo);
        //remover nó do indice maior
        listaNos->Remover(indiceDireita);
    }
    //copiar o nó único da lista
    //que corresponde à raiz da árvore de Huffman
    No* raiz = listaNos->GetPrimeiro();
    //retirar nó da lista
    listaNos->RemoverPrimeiro();
    //libertar memória alocada para a lista
    delete listaNos;
    //retornar nó raiz da árvore de Huffman
    return raiz;
}

void MostrarCodigos(No* raiz, int frequenciaTotal, string& codigo) {
    string codigoAtual = "";
    //converter nó para subclasse NoInterno
    NoInterno* noI = dynamic_cast<NoInterno*> (raiz);
    //se conversão tem sucesso - o nó é interno
    if (noI != NULL) {
        //acrescentar 0 ao código e tratar restante árvore à esquerda
        codigoAtual = codigo + "0";
        MostrarCodigos(noI->GetEsquerda(), frequenciaTotal, codigoAtual);
        //acrescentar 1 ao código e tratar restante árvore à direita
        codigoAtual = codigo + "1";
        MostrarCodigos(noI->GetDireita(), frequenciaTotal, codigoAtual);
    }
    //se conversão não tem sucesso - tentar subclasse NoFolha
    NoFolha* noF = dynamic_cast<NoFolha*> (raiz);
    if (noF != NULL) {
        //apresentar código hexadecimal do símbolo, probabilidade e código
        cout << showbase << hex << (int) noF->GetSimbolo() << " ";
        printf(" %-8.3g",((double) noF->GetFrequencia() / frequenciaTotal));
        cout << " " << codigo << endl;
    }
}

int main(int argc, char** argv) {

    //verificar se o número de argumentos está correto
    if (argc != 2) {
        cerr << "Sintaxe: huff <ficheiro>" << endl;
        return 1;
    }

    //abir ficheiro
    ifstream ficheiroEntrada(argv[1], ios::in);

    //verificar se ficheiro foi aberto
    if (!ficheiroEntrada) {
        cerr << "O ficheiro " << argv[1] << " não pode ser aberto!" << endl;
        return 1;
    }

    //número de letras do abecedario
    const int NUMEROSIMBOLOS = 256;

    //vetor de frequencias
    int frequencia[NUMEROSIMBOLOS] = {0};
    //caracter a ler no ficheiro de texto
    char simbolo;
    //ler ficheiro de texto e preencher vetor de frequências
    while (ficheiroEntrada.get(simbolo)) {
        int numeroSimbolo = (int) simbolo;
        if (numeroSimbolo >= 0 && numeroSimbolo < 256)
            frequencia[numeroSimbolo]++;
    }

    //fechar ficheiro
    ficheiroEntrada.close();

    //determinar número de símbolos a codificar
    int total = 0;
    for (int i = 0; i < NUMEROSIMBOLOS; i++) {
        if (frequencia[i] != 0)
            total++;
    }

    //construir árvore de Huffman
    No* raizArvore = ConstruirArvore(frequencia, NUMEROSIMBOLOS);

    //escrever número de símbolos codificados
    cout << total << endl;
    //escrever tabela: símbolo (hexadecimal), probabilidade, código
    string codigo = "";
    MostrarCodigos(raizArvore, raizArvore->GetFrequencia(), codigo);

    //libertar memória alocada para a árvore
    delete raizArvore;

    return 0;
}


