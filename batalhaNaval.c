#include <stdio.h>

// Variáveis de tamanho.
#define NAVIO 3
#define TABULEIRO 10

int main()
{
    // Matrizes inicializadas.
    int tabuleiro[TABULEIRO][TABULEIRO] = {0};
    int navio[NAVIO];
    int cone[NAVIO][NAVIO];
    // int cruz[][];
    // int octaedro[][];

    // Coordenadas inicias de cada navio.
    int navio1Linha = 2, navio1Coluna = 2; // Navio horizontal
    int navio2Linha = 5, navio2Coluna = 8; // Navio vertical

    int navio3Linha = 4, navio3Coluna = 0; // Navio diagonal
    int navio4Linha = 7, navio4Coluna = 4; // Navio diagonal

    int coneLinha = 0, coneColuna = 3;
    int cruzLinha = 6, cruzColuna = 2;
    int centroLinha = 4, centroColuna = 7;

    // Posição navio horizontal
    if (NAVIO <= TABULEIRO)
    {
        for (int i = 0; i < NAVIO; i++)
        {
            if (tabuleiro[navio1Linha][navio1Coluna + i] == 0)
            { // Verifica se a posição já está ocupada
                tabuleiro[navio1Linha][navio1Coluna + i] = NAVIO;
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

    // Posição navio vertical.
    if (NAVIO <= TABULEIRO)
    {
        for (int i = 0; i < NAVIO; i++)
        {
            if (tabuleiro[navio2Linha + i][navio2Coluna] == 0)
            { // Verifica se a posição já está ocupada
                tabuleiro[navio2Linha + i][navio2Coluna] = NAVIO;
            }
            else
            {
                printf("Erro: Sobreposição detectada no navio 2!\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Erro: Navio 2 ultrapassa os limites do tabuleiro!\n");
    }

    // Posição navio diagonal decrescente
    if (NAVIO <= TABULEIRO)
    {
        for (int i = 0; i < NAVIO; i++)
        {
            if (tabuleiro[navio3Linha + i][navio3Coluna] == 0)
            {
                // Verifica se a posição já está ocupada
                tabuleiro[navio3Linha + i][navio3Coluna + i] = NAVIO;
            }
            else
            {
                printf("Erro: Sobreposição detectada no navio 3!");
            }
        }
    }
    else
    {
        printf("Erro: Navio 3 ultrapassa os limites do tabuleiro!\n");
    }

    // Posição navio diagonal crescente
    if (NAVIO <= TABULEIRO)
    {
        for (int i = 0; i < NAVIO; i++)
        {
            if (tabuleiro[navio4Linha + i][navio4Coluna] == 0)
            {
                // Verifica se a posição já está ocupada
                tabuleiro[navio4Linha - i][navio4Coluna + i] = NAVIO;
            }
            else
            {
                printf("Erro: Sobreposição detectada no navio 4!");
            }
        }
    }
    else
    {
        printf("Erro: Navio 4 ultrapassa os limites do tabuleiro!\n");
    }

    // Habilidade em cone.
    if (NAVIO < TABULEIRO)
    {
        for (int i = 0; i < NAVIO; i++)
        {
            for (int j = -i; j <= i; j++)
            {
                if (tabuleiro[coneLinha + i][coneColuna + j] == 0)
                {
                    tabuleiro[coneLinha + i][coneColuna + j] = NAVIO;
                }
                else
                {
                    tabuleiro[coneLinha + i][coneColuna + j] = 5;
                }
            }
        }
    }

    // Habilidade em cruz
    if (NAVIO < TABULEIRO)
    {
        for (int i = -2; i < NAVIO; i++)
        {

            for (int j = 0; j < NAVIO; j++)
            {
                if (tabuleiro[cruzLinha + i][cruzColuna] == 0)
                {
                    tabuleiro[cruzLinha + i][cruzColuna] = NAVIO;
                    tabuleiro[cruzLinha][cruzColuna + i] = NAVIO;
                }
                else
                {
                    tabuleiro[cruzLinha + i][cruzColuna] = 5;
                    tabuleiro[cruzLinha][cruzColuna + i] = 5;
                }
            }
        }
    }

    for (int i = 0; i < NAVIO; i++)
    {
        for (int j = -i; j <= i; j++)
        {
            tabuleiro[centroLinha + i][centroColuna + j] = 5;
        }
    }

    for (int i = NAVIO - 2; i >= 0; i--) 
    {
        for (int j = -i; j <= i; j++)
        {
            tabuleiro[centroLinha + (2 * NAVIO - 2 - i)][centroColuna + j] = 5;
        }
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
