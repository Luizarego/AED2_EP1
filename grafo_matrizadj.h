//Luiza Silva e Rego, 13831697

#ifndef GRAFO_MATRIZADJ_H_INCLUDED
#define GRAFO_MATRIZADJ_H_INCLUDED

#include <stdbool.h>

#define MAXNUMVERTICES 100
#define AN -1
#define VERTICE_INVALIDO -1

typedef double Peso;

typedef int Apontador;

typedef struct {
    Peso mat[MAXNUMVERTICES][MAXNUMVERTICES];
    int numVertices;
    int numArestas;
}Grafo;

bool inicializaGrafo(Grafo* grafo, int nv);
bool verificaValidadeVertice(int v, Grafo* grafo);
bool listaAdjVazia(int v, Grafo* grafo);
Apontador proxListaAdj(int v, Grafo* grafo, Apontador atual);
Apontador primeiroListaAdj(int v, Grafo* grafo);
bool existeAresta(int v1, int v2, Grafo* grafo);
void insereAresta(int v1, int v2, Peso peso, Grafo* grafo);
bool removeArestaObtendoPeso(int v1, int v2, Peso* peso, Grafo* grafo);
void liberaGrafo(Grafo* grafo);
void imprimeGrafo(Grafo* grafo);
double obtemPesoAresta(int v1, int v2, Grafo* grafo);
bool buscaProfundidade(Grafo* grafo, int* antecessor, int vInicial);
int retornaVerticeDestino(Apontador p);

#endif // GRAFO_MATRIZADJ_H_INCLUDED
