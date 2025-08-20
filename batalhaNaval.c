#include <stdio.h>

// Variáveis de tamanho.
#define NAVIO 3
#define TABULEIRO 10

int main()
{

    // Matrizes inicializadas.
    int tabuleiro[TABULEIRO][TABULEIRO] = {0};
    int navio[NAVIO] = {3};

    // Coordenadas inicias de cada navio.
    int navio1Linha = 2, navio1Coluna = 2; // Navio horizontal
    int navio2Linha = 5, navio2Coluna = 7; // Navio vertical

    // Posição navio horizontal
    if (navio1Coluna + NAVIO <= TABULEIRO)
    {
        for (int i = 0; i < NAVIO; i++)
        {
            if (tabuleiro[navio1Linha][navio1Coluna + i] == 0)
            { // Verifica se a posição já está ocupada
                tabuleiro[navio1Linha][navio1Coluna + i] = 3;
            }
            else
            {
                printf("Erro: Sobreposição detectada no navio 1!\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Erro: Navio 1 ultrapassa os limites do tabuleiro!\n");
    }

    // Posição navio vertical
    if (navio2Linha + NAVIO <= TABULEIRO)
    {
        for (int i = 0; i < NAVIO; i++)
        {
            if (tabuleiro[navio2Linha + i][navio2Coluna] == 0)
            { // Verifica se a posição já está ocupada
                tabuleiro[navio2Linha + i][navio2Coluna] = 3;
            }
            else
            {
                printf("Erro: Sobreposição detectada no navio 1!\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Erro: Navio 1 ultrapassa os limites do tabuleiro!\n");
    }

    // Imprissão das coordenadas do tabuleiro (A,2;B,4....)
    printf("  ");
    for (int i = 0; i < TABULEIRO; i++)
    {
        printf("%3d", i + 1);
    }

    printf("\n");

    for (int i = 0; i < TABULEIRO; i++)
    {
        printf("%c ", 'A' + i);
        for (int j = 0; j < TABULEIRO; j++)
        {
            printf("%3d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
