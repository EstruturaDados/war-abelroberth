#include <stdio.h>
#include <string.h>

#define TAM 5
#define MAX 50

struct Territorio {
    char nome[MAX];
    char cor[MAX];
    int tropas;
};

int main() {
    struct Territorio mapa[TAM];

    printf("=== Cadastro de Territorios ===\n");

    for (int i = 0; i < TAM; i++) {
        printf("\nTerritorio %d:\n", i + 1);

        // Limpar buffer antes do fgets (caso haja 'enter' pendente)
        fflush(stdin);

        printf("Nome do territorio: ");
        fgets(mapa[i].nome, MAX, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0'; // remove \n

        printf("Cor do exercito: ");
        fgets(mapa[i].cor, MAX, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Numero de tropas: ");
        scanf("%d", &mapa[i].tropas);

        getchar(); // consumir o '\n' deixado pelo scanf
    }

    // Exibição dos dados:
    printf("\n\n=== Estado Atual do Mapa ===\n");
    for (int i = 0; i < TAM; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exercito: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
    }

    return 0;
}
