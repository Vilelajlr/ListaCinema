#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cinema.h"

void inicializarLista(ListaIngressos *lista) {
    lista->head = NULL;
    lista->tail = NULL;
}

Ingresso* criarIngresso(char *filme, int assento) {
    Ingresso *novo = (Ingresso*) malloc(sizeof(Ingresso));
    novo->assento = assento;
    strcpy(novo->filme, filme);
    novo->prev = NULL;
    novo->next = NULL;
    return novo;
}

void adicionarIngresso(ListaIngressos *lista, Ingresso *novoIngresso) {
    if (lista->tail == NULL) {
        lista->head = novoIngresso;
        lista->tail = novoIngresso;
    } else {
        lista->tail->next = novoIngresso;
        novoIngresso->prev = lista->tail;
        lista->tail = novoIngresso;
    }
}

void venderIngresso(ListaIngressos *disponiveis, ListaIngressos *vendidos, char *filme, int assento) {
    Ingresso *temp = disponiveis->head;
    
    while (temp != NULL) {
        if (temp->assento == assento && strcmp(temp->filme, filme) == 0) {
            if (temp->prev != NULL) temp->prev->next = temp->next;
            if (temp->next != NULL) temp->next->prev = temp->prev;
            if (temp == disponiveis->head) disponiveis->head = temp->next;
            if (temp == disponiveis->tail) disponiveis->tail = temp->prev;

            adicionarIngresso(vendidos, temp);
            printf("Ingresso vendido com sucesso!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Ingresso não encontrado!\n");
}

void cancelarIngresso(ListaIngressos *disponiveis, ListaIngressos *vendidos, char *filme, int assento) {
    Ingresso *temp = vendidos->head;
    
    while (temp != NULL) {
        if (temp->assento == assento && strcmp(temp->filme, filme) == 0) {
            if (temp->prev != NULL) temp->prev->next = temp->next;
            if (temp->next != NULL) temp->next->prev = temp->prev;
            if (temp == vendidos->head) vendidos->head = temp->next;
            if (temp == vendidos->tail) vendidos->tail = temp->prev;

            adicionarIngresso(disponiveis, temp);
            printf("Ingresso cancelado com sucesso!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Ingresso não encontrado!\n");
}

void listarIngressosDisponiveis(ListaIngressos *lista, char *filme) {
    Ingresso *temp = lista->head;
    printf("Ingressos disponíveis para o filme %s:\n", filme);
    while (temp != NULL) {
        if (strcmp(temp->filme, filme) == 0) {
            printf("Assento: %d\n", temp->assento);
        }
        temp = temp->next;
    }
}

void listarIngressosVendidos(ListaIngressos *lista) {
    Ingresso *temp = lista->head;
    printf("Ingressos vendidos:\n");
    while (temp != NULL) {
        printf("Filme: %s, Assento: %d\n", temp->filme, temp->assento);
        temp = temp->next;
    }
}

void exibirMenu() {
    printf("\n1. Vender Ingresso\n");
    printf("2. Cancelar Ingresso\n");
    printf("3. Listar Ingressos Disponíveis para um Filme\n");
    printf("4. Exibir Ingressos Vendidos\n");
    printf("5. Sair\n");
}
