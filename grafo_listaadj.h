//Luiza Silva e Rego, 13831697

#ifndef GRAFO_LISTAADJ_H_INCLUDED
#define GRAFO_LISTAADJ_H_INCLUDED

#include <stdbool.h>

#define VERTICE_INVALIDO NULL
#define AN -1

typedef double Peso;

typedef struct str_aresta{
    int vdest;
    Peso peso;
    struct str_aresta* prox;
} Aresta;

typedef Aresta* Apontador;

typedef struct{
    Apontador* listaAdj;
    int numVertices;
    int numArestas;
} Grafo;

bool inicializaGrafo(Grafo* grafo, int nv);
bool verificaValidadeVertice(int v, Grafo* grafo);
bool listaAdjVazia(int v, Grafo* grafo);
Apontador proxListaAdj(int v, Grafo* grafo, Apontador atual);
Aresta* primeiroListaAdj(int v, Grafo* grafo); //transformar em apontador
bool existeAresta(int v1, int v2, Grafo* grafo);
void insereAresta(int v1, int v2, Peso peso, Grafo* grafo);
bool removeArestaObtendoPeso(int v1, int v2, Peso* peso, Grafo* grafo);
void liberaGrafo(Grafo* grafo);
void imprimeGrafo(Grafo* grafo);
double obtemPesoAresta(int v1, int v2, Grafo* grafo);
bool buscaProfundidade(Grafo* grafo, int* antecessor, int vInicial);
int retornaVerticeDestino(Apontador p);


#endif // GRAFO_LISTAADJ_H_INCLUDED
