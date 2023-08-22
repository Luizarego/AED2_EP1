//Luiza Silva e Rego, 13831697

#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj.h"

int retornaVerticeDestino(Apontador p){
    return(p->vdest);
}

double obtemPesoAresta(int v1, int v2, Grafo* grafo){
    Apontador q;
    q = grafo->listaAdj[v1];
    while((q != NULL) && (q->vdest != v2)){
        q = q->prox;
    }
    if(q != NULL) return q->peso;
    return -1;
}

void imprimeGrafo(Grafo* grafo){
    Apontador p;
    for(int i = 0; i < grafo->numVertices; i++){
        p = grafo->listaAdj[i];
        while(p){
            printf("%f ", p->peso);
            p = p->prox;
        }
        printf("\n");
    }
}

bool inicializaGrafo(Grafo* grafo, int nv){

    if(nv <= 0){
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: Numero de vertices deve ser positivo.\n");
        return false;
    }

    grafo->numVertices = nv;
    if(!(grafo->listaAdj = (Apontador*)calloc(nv+1, sizeof(Apontador)))){
        fprintf(stderr, "ERRO: Falha na alocacao de memoria na funcao inicializaGrafo.\n");
        return false;
    }

    grafo->numArestas = 0;
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

bool listaAdjVazia(int v, Grafo* grafo){
    if(!verificaValidadeVertice(v, grafo)){
        return false;
    }
    return(grafo->listaAdj[v] == NULL);
}

Apontador proxListaAdj(int v, Grafo* grafo, Apontador atual){
    if(atual == NULL){
        fprintf(stderr, "atual == NULL\n");
        return VERTICE_INVALIDO;
    }
    return(atual->prox);
}

Apontador primeiroListaAdj(int v, Grafo* grafo){ //transformar em apontador
    return(grafo->listaAdj[v]);
}

bool existeAresta(int v1, int v2, Grafo* grafo){
    Apontador q;

    if(!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo))){
        return false;
    }

    q = grafo->listaAdj[v1];
    while((q != NULL) && (q->vdest != v2)){
        q = q->prox;
    }
    if(q != NULL) return true;
    return false;
}

void insereAresta(int v1, int v2, Peso peso, Grafo* grafo){
    Apontador p;

    if(!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo))){
        return;
    }
    if(!(p = (Apontador)calloc(1, sizeof(Aresta)))){
        fprintf(stderr, "ERRO: falha na alocacao de memoria na funcao insereAresta\n");
        return;
    }
    p->vdest = v2;
    p->peso = peso;
    p->prox = grafo->listaAdj[v1];
    grafo->listaAdj[v1] = p;
    grafo->numArestas++;

    Apontador q;
    if(!(q = (Apontador)calloc(1, sizeof(Aresta)))){
        fprintf(stderr, "ERRO: falha na alocacao de memoria na funcao insereAresta\n");
        return;
    }
    q->vdest = v1;
    q->peso = peso;
    q->prox = grafo->listaAdj[v2];
    grafo->listaAdj[v2] = q;
}

bool removeArestaObtendoPeso(int v1, int v2, Peso* peso, Grafo* grafo){
    Apontador q, ant;

    if(!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo))){
        return AN;
    }

    q = grafo->listaAdj[v1];
    while((q != NULL) && (q->vdest != v2)){
        ant = q;
        q = q->prox;
    }

    if(q != NULL){
        if(grafo->listaAdj[v1] == q){
            grafo->listaAdj[v1] = q->prox;
        }
        else{
            ant->prox = q->prox;
        }
        *peso = q->peso;
        q->prox = NULL;
        free(q);
        q = NULL;
        return true;
    }
    return false;
}

void liberaGrafo(Grafo* grafo){
    int v;
    Apontador p;

    for(v = 0; v <= grafo->numVertices; v++){
        while((p = grafo->listaAdj[v]) != NULL){
            grafo->listaAdj[v] = p->prox;
            p->prox = NULL;
            free(p);
        }
    }
    grafo->numVertices = 0;
    free(grafo->listaAdj);
    grafo->listaAdj = NULL;
}
