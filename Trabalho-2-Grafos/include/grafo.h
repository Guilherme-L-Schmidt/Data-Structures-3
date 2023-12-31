// Guilherme Lorete Schmidt - 13676857
// Emanuel Percinio Goncalves de Oliveira - 13676878

#ifndef GRAFO
#define GRAFO

typedef struct aresta_grafo aresta_grafo;

#include "lista_grafo.h"
#include "registros_dados.h"

// Definir estrutura para vertice do grafo
typedef struct  {
    char *nomeTecOrigem;
    int grupo;
    int grau_entrada;
    int grau_saida;
    int grau;
    lista lista_arestas;
} vertice_grafo;

// Definir estrutura para aresta do grafo
struct aresta_grafo{
    vertice_grafo *tecDestino;
    int peso;
};

// Definir estrutura para grafo de tecnologias
typedef struct {
    int num_vertices;
    int num_arestas;
    vertice_grafo **lista_vertices;
} grafo;


/******** Funcoes para manipulacao do grafo ********/
void inicializa_grafo(grafo *g, int num_tecnologias);
void cria_vertice(vertice_grafo *vertice, string tecnologia, int grupo);
void cria_aresta(aresta_grafo *aresta, vertice_grafo *vertice, int peso);
int busca_binaria_vertices(grafo g, char* nomeTec);
void insere_aresta(grafo *g, string tecnologiaOrigem, int grupo, string tecnologiaDestino, int grupo2, int peso);
void libera_grafo(grafo g);

#endif