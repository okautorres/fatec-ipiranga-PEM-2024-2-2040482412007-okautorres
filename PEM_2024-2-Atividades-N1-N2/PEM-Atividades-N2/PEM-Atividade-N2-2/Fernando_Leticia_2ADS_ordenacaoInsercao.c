#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ordena um array usando o algoritmo de ordena��o por inser��o
void ordenacaoInsercao(int numeros[], int quantidade, int *trocas, int *ciclos) {
    int i, elemento, posicao;
    for (i = 1; i < quantidade; i++) {
        elemento = numeros[i]; // Elemento a ser inserido
        posicao = i - 1;

        // Move elementos maiores para a direita
        while (posicao >= 0 && numeros[posicao] > elemento) {
            numeros[posicao + 1] = numeros[posicao];
            posicao--;
            (*ciclos)++;  // Conta o n�mero de compara��es/ciclos
        }

        // Verifica se houve uma troca, ou seja, se o elemento n�o estava na posi��o correta inicialmente
        if (posicao + 1 != i) {
            (*trocas)++;  // Conta a troca de posi��o do elemento
        }

        numeros[posicao + 1] = elemento; // Insere o elemento na posi��o correta
    }
}

// Imprime o array
void imprimirArray(int numeros[], int quantidade) {
    int i;
    for (i = 0; i < quantidade; i++)
        printf("%d ", numeros[i]);
    printf("\n");
}

int main() {
    // CLOCK INICIO
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int numeros[] = {5, 3, 8, 4, 2,
                     115, 113, 118, 114, 112,
                     125, 123, 128, 124, 122,
                     35, 33, 38, 34, 32,
                     45, 43, 48, 44, 42,
                     55, 53, 58, 54, 52,
                     65, 63, 68, 64, 62,
                     75, 73, 78, 74, 72,
                     85, 83, 88, 84, 82,
                     95, 93, 98, 94, 92,
                     15, 13, 18, 14, 12,
                     25, 23, 28, 24, 22
                    };

    int quantidadeNumeros = sizeof(numeros) / sizeof(numeros[0]);
    int trocas = 0, ciclos = 0;  // Contadores de trocas e ciclos

    printf("Array original: ");
    imprimirArray(numeros, quantidadeNumeros);

    ordenacaoInsercao(numeros, quantidadeNumeros, &trocas, &ciclos); // Ordena o array e conta trocas/ciclos

    printf("Array ordenado: ");
    imprimirArray(numeros, quantidadeNumeros);

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execu��o: %f segundos\n", cpu_time_used);

    // Exibe o n�mero de trocas e ciclos
    printf("Quantidade de trocas: %d\n", trocas);
    printf("Quantidade de ciclos (compara��es): %d\n", ciclos);

    return 0;
}

