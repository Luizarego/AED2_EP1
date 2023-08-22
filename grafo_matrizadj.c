//Luiza Silva e Rego, 13831697

#include <stdio.h>
#include <stdlib.h>
#include "grafo_matrizadj.h"

int retornaVerticeDestino(Apontador p){
    return(p);
}

bool inicializaGrafo(Grafo* grafo, int nv){
    if(nv > MAXNUMVERTICES){
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: Numero de vertices maior que o maximo permitido de %d.\n", MAXNUMVERTICES);
        return false;
    }
    if(nv <= 0){
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: Numero de vertices deve ser positivo.\n");
        return false;
    }
    grafo->numVertices = nv;
    grafo->numArestas = 0;
    for(int i = 0; i < grafo->numVertices; i++){
        for(int j = 0; j < grafo->numVertices; j++){
            grafo->mat[i][j] = AN;
        }
    }
    return true;
}

bool verificaValidadeVertice(int v, Grafo* grafo){
    if(v > grafo->numVertices){
        fprintf(stderr, "ERRO: Numero do vertice(%d) maior que o numero total de vertices\(%d).\n", v, grafo->numVertices);
        return false;
    }
    if(v < 0){
        fprintf(stderr, "ERRO: Numero do vertice (%d) deve ser positivo.\n", v);
        return false;
    }
    return true;
}

void insereAresta(int v1, int v2, Peso peso, Grafo* grafo){
    if(!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo))){
        printf("Erro ao inserir aresta: vertice inválido!");
        return;
    }
    grafo->mat[v1][v2] = peso;
    grafo->mat[v2][v1] = peso;
    grafo->numArestas++;
}

bool existeAresta(int v1, int v2, Grafo* grafo){
    if(!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo))){
        return false;
    }
    if(grafo->mat[v1][v2] == AN){
        return false;
    }
    return true;
}

bool removeArestaObtendoPeso(int v1, int v2, Peso* peso, Grafo* grafo){
    if(!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo))){
        return false;
    }
    if(grafo->mat[v1][v2] != AN){
        *peso = grafo->mat[v1][v2];
        grafo->mat[v1][v2] = AN;
        grafo->numArestas--;
        return true;
    }
    return false;
}

bool listaAdjVazia(int v, Grafo* grafo){
    if(!verificaValidadeVertice(v, grafo)){
        return true;
    }
    for(int i = 0; i < grafo->numVertices; i++){
        if(grafo->mat[v][i] != AN){
            return false;
        }
    }
    return true;
}

Apontador proxListaAdj(int v, Grafo* grafo, Apontador atual){
    if(!verificaValidadeVertice(v, grafo)){
        return VERTICE_INVALIDO;
    }
    atual++;
    while((atual <= (grafo->numVertices - 1)) && (grafo->mat[v][atual] == AN)){
        atual++;
    }
    if(v >= grafo->numVertices || atual >= grafo->numVertices){
        return VERTICE_INVALIDO;
    }
    return atual;
}

Apontador primeiroListaAdj(int v, Grafo* grafo){
    Apontador p = proxListaAdj(v, grafo, -1);
    return p;
}

void liberaGrafo(Grafo* grafo){
    grafo = NULL;
}

void imprimeGrafo(Grafo* grafo){
    for(int i = 0; i < grafo->numVertices; i++){
        for(int j = 0; j < grafo->numVertices; j++){
            printf("%f ", grafo->mat[i][j]);
        }
        printf("\n");
    }
}

double obtemPesoAresta(int v1, int v2, Grafo* grafo){
    return grafo->mat[v1][v2];
}
