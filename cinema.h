#ifndef CINEMA_H
#define CINEMA_H

// Struct para representar um ingresso
typedef struct Ingresso {
    int assento;
    char filme[50];
    struct Ingresso *prev;
    struct Ingresso *next;
} Ingresso;

// Lista para ingressos disponíveis e vendidos
typedef struct {
    Ingresso *head;
    Ingresso *tail;
} ListaIngressos;

// Funções para manipulação de ingressos
void inicializarLista(ListaIngressos *lista);
Ingresso* criarIngresso(char *filme, int assento);
void adicionarIngresso(ListaIngressos *lista, Ingresso *novoIngresso);
void venderIngresso(ListaIngressos *disponiveis, ListaIngressos *vendidos, char *filme, int assento);
void cancelarIngresso(ListaIngressos *disponiveis, ListaIngressos *vendidos, char *filme, int assento);
void listarIngressosDisponiveis(ListaIngressos *lista, char *filme);
void listarIngressosVendidos(ListaIngressos *lista);
void exibirMenu();
#endif
