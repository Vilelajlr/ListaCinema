#include <stdio.h>
#include <string.h>
#include "cinema.c"

int main() {
    ListaIngressos disponiveis, vendidos;
    inicializarLista(&disponiveis);
    inicializarLista(&vendidos);

    // Inicializa os ingressos disponíveis para dois filmes
    char filme1[] = "Filme A";
    char filme2[] = "Filme B";
    for (int i = 1; i <= 10; i++) {
        adicionarIngresso(&disponiveis, criarIngresso(filme1, i));
        adicionarIngresso(&disponiveis, criarIngresso(filme2, i));
    }

    int opcao, assento;
    char filmeEscolhido[50];

    do {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Vender Ingresso
                printf("Escolha um filme (Filme A ou Filme B): ");
                scanf("%s", filmeEscolhido);
                
                // Exibir assentos disponíveis antes de pedir para o usuário escolher
                printf("Assentos disponíveis para o filme %s:\n", filmeEscolhido);
                listarIngressosDisponiveis(&disponiveis, filmeEscolhido);
                
                printf("Digite o número do assento (1-10): ");
                scanf("%d", &assento);
                venderIngresso(&disponiveis, &vendidos, filmeEscolhido, assento);
                break;

            case 2: // Cancelar Ingresso
                printf("Escolha um filme (Filme A ou Filme B): ");
                scanf("%s", filmeEscolhido);
                printf("Digite o número do assento a cancelar: ");
                scanf("%d", &assento);
                cancelarIngresso(&disponiveis, &vendidos, filmeEscolhido, assento);
                break;

            case 3: // Listar Ingressos Disponíveis
                printf("Escolha um filme (Filme A ou Filme B): ");
                scanf("%s", filmeEscolhido);
                listarIngressosDisponiveis(&disponiveis, filmeEscolhido);
                break;

            case 4: // Exibir Ingressos Vendidos
                listarIngressosVendidos(&vendidos);
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
