#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo_listaadj.h"

#define MAX_VERTICES 100
#define INF 999999


/*Código para a Busca em Profundidade.*/
void visitaBuscaEmProfundidade(int vertice, Grafo* grafo, int* antecessor, char* cor){
    cor[vertice] = 'c';
    Apontador apontador = primeiroListaAdj(vertice, grafo);

    while(apontador != VERTICE_INVALIDO) {
        int verticeDestino = retornaVerticeDestino(apontador);
        if(cor[verticeDestino] == 'b'){
            antecessor[verticeDestino] = vertice;
            visitaBuscaEmProfundidade(verticeDestino, grafo, antecessor, cor);
        }
        apontador = proxListaAdj(vertice, grafo, apontador);
    }

    cor[vertice] = 'p';
}

bool buscaEmProfundidade(Grafo* grafo, int* antecessor, int verticeInicial){
    /*Nota: o esquema de cores é branco ('b'), cinza ('c') e preto ('p').*/
    int numeroDeVertices = grafo->numVertices;
    char cor[numeroDeVertices];

    for(int i = 0; i < numeroDeVertices; i++){
        cor[i] = 'b';
        antecessor[i] = -1;
    }

    visitaBuscaEmProfundidade(verticeInicial, grafo, antecessor, cor);

    return true;
}


/*Código para a Árvore Geradora Máxima com Algoritmo de Kruskal.*/
typedef struct{
    double peso;
    int entrada;
    int saida;
}ElementoDeKruskal;


void ordena(ElementoDeKruskal* A, int tamanhoDeA){
    for(int i = 0; i < tamanhoDeA; i++){
        for(int j = 0; j < tamanhoDeA; j++){
            if(A[i].peso > A[j].peso){
                ElementoDeKruskal aux = A[i];
                A[i] = A[j];
                A[j] = aux;
            }
        }
    }
}

void fazUniao(int* pai, int* ranque, int x){
    pai[x] = x;
    ranque[x] = 0;
}

int achaRaiz(int* pai, int x){
    if(pai[x] != x){
        pai[x] = achaRaiz(pai, pai[x]);
    }
    return(pai[x]);
}

void junta(int* pai, int* ranque, int x, int y){
    if(ranque[x] > ranque[y]){
        pai[y] = x;
    }
    else{
        pai[x] = y;
        if(ranque[x] == ranque[y]){
            ranque[y] = ranque[y] + 1;
        }
    }
}

void uniao(int* pai, int* ranque, int x, int y){
    junta(pai, ranque, achaRaiz(pai, x), achaRaiz(pai, y));
}

void mostraElementoDeKruskal(ElementoDeKruskal* arestas, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d %d %f\n", arestas[i].entrada, arestas[i].saida, arestas[i].peso);
    }
}

void AGMKruskal(Grafo* grafo, Grafo* grafoResp){
    int numeroDeVertices = grafo->numVertices;
    int numeroDeArestas = grafo->numArestas;
    inicializaGrafo(grafoResp, numeroDeVertices);
    int ranque[numeroDeVertices + 1];
    int pai[numeroDeVertices + 1];

    for(int i = 0; i <= numeroDeVertices; i++){
        fazUniao(pai, ranque, i);
    }

    ElementoDeKruskal arestas[((numeroDeArestas) * 2) + 1];
    int tamanho = 0;

    for(int i = 0; i <= numeroDeVertices; i++){
        Apontador apontador = primeiroListaAdj(i, grafo);
        while(apontador != VERTICE_INVALIDO){
            arestas[tamanho].entrada = i;
            int destino = retornaVerticeDestino(apontador);
            arestas[tamanho].saida = destino;
            arestas[tamanho].peso = obtemPesoAresta(i, destino, grafo);
            tamanho++;
            apontador = proxListaAdj(i, grafo, apontador);
        }
    }

    ordena(arestas, tamanho);

    for(int i = 0; i < tamanho; i++){
        int x = arestas[i].entrada;
        int y = arestas[i].saida;

        if(achaRaiz(pai, x) != achaRaiz(pai, y)){
            insereAresta(x, y, arestas[i].peso, grafoResp);
            uniao(pai, ranque, x, y);
        }
    }
}



int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Erro nos argumentos esperados pela main!");
    }

    FILE* entrada = fopen(argv[1], "r");
    if (!entrada) {
       printf("Erro na abertura do arquivo de entrada!");
    }

    int numVertices, numArestas, numConsultas;
    if (fscanf(entrada, "%d %d %d", &numVertices, &numArestas, &numConsultas) != 3){
        printf("Erro no escaneamento do conteúdo do arquivo de entrada!");
    }

    int a, b;
    float c;

    Grafo grafo;
    Grafo grafo2;
    inicializaGrafo(&grafo, numVertices);
    inicializaGrafo(&grafo2, numVertices);

    for(int i = 0; i < numArestas; i++){
       if (fscanf(entrada, "%d %d %f", &a, &b, &c) != 3){
            printf("Erro no escaneamento do conteúdo do arquivo de entrada!");
       }
       else{
           insereAresta(a, b, c, &grafo);
       }
    }

    AGMKruskal(&grafo, &grafo2);

    int ant[grafo.numVertices];

    FILE* saida;
    saida = fopen("saida.txt", "w");
    if (!saida) {
       printf("Erro na abertura do arquivo de saida!");
    }

    int v1, v2;
    for(int i = 0; i < numConsultas; i++){
        if(fscanf(entrada, "%d %d", &v1, &v2) != 2){
            printf("Erro no escaneamento do conteúdo do arquivo de entrada!");
        }
        else{
            buscaEmProfundidade(&grafo2, ant, v1);
            float menor = 999;
            int i = v2;
            while(i != v1){
                if(obtemPesoAresta(i, ant[i], &grafo2) < menor) menor = obtemPesoAresta(i, ant[i], &grafo2);
                i = ant[i];
            }
            if(menor >= 2.5 && menor < 3.0){
                menor = 2.5;
            }
            if(menor >= 3.0 && menor < 3.5){
                menor = 3.0;
            }
            if(menor >= 3.5 && menor < 4.0){
                menor = 3.5;
            }
            if (menor >= 4.0 && menor < 4.5){
                menor = 4.0;
            }
            if(menor >= 4.5){
                menor = 4.5;
            }

            fprintf(saida, "%.1f", menor);
            fprintf(saida, "\n");
        }
    }

    fclose(entrada);

    fclose(saida);

    return 0;
}
