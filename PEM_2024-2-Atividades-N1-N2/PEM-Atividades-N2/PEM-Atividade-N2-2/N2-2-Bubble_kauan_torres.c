#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*-----------------------------------------------------------*
* Disciplina: Programa�ao Estruturada e Modular              *
*          Prof. Carlos Ver�ssimo                            *                                
*------------------------------------------------------------*
* Objetivo do Programa: Compara��o insertion com bubble sort *
* Data : 07/10/2024                                          * 
* Autor: Kauan Torres                                        *
*------------------------------------------------------------*/

/*---------------------------------------------------------*
| Declara��o antecipada das fun��es                        |
*---------------------------------------------------------*/
void printArray(int array[], int size);
void bubbleSort(int array[], int n, int *trocas, int *ciclos);
void change(int *xp, int *yp);

/*---------------------------------------------------------*
| M�dulo - Printar o array                                 |
*---------------------------------------------------------*/
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/*---------------------------------------------------------*
| M�dulo - Realizar o BubbleSort com contagem de trocas e ciclos  |
*---------------------------------------------------------*/
void bubbleSort(int array[], int n, int *trocas, int *ciclos) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*ciclos)++; // Conta ciclos (compara��es)
            if (array[j] > array[j + 1]) {
                change(&array[j], &array[j + 1]);
                (*trocas)++; // Conta trocas
            }
        }
    }
}

/*---------------------------------------------------------*
| M�dulo - Mudar posi��es                                  |
*---------------------------------------------------------*/
void change(int *xp, int *yp) {
    int temporary = *xp;
    *xp = *yp;
    *yp = temporary;
}

/*---------------------------------------------------------*
| M�dulo - Modulo principal                                |
*---------------------------------------------------------*/
int main() {

    // CLOCK INICIO
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Inicializa array
    int array[] = {5, 3, 8, 4, 2,
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

    // Calcula o n�mero de elementos no array
    int n = sizeof(array) / sizeof(array[0]);

    // Vari�veis para contar trocas e ciclos
    int trocas = 0, ciclos = 0;

    printf("Array original: ");
    // Chama modulo para printar array
    printArray(array, n);

    // Chama modulo para realizar o bubbleSort com contagem
    bubbleSort(array, n, &trocas, &ciclos);

    printf("Array ordenado: ");
    // Chama modulo para printar array
    printArray(array, n);

    // Exibe contagem de trocas e ciclos
    printf("N�mero de trocas: %d\n", trocas);
    printf("N�mero de ciclos (compara��es): %d\n", ciclos);

    // CLOCK FIM
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execu��o: %f segundos\n", cpu_time_used);

    return 0;
}

