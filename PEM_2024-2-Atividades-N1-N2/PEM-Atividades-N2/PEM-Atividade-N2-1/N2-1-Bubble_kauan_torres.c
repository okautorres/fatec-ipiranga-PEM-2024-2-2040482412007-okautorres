#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *                                
*---------------------------------------------------------*
* Objetivo do Programa: Bubble Sort em C                  *
* Data : 27/09/2024                                       * 
* Autor: Kauan Torres                                     *
*--------------------------------------------------------*/

/*---------------------------------------------------------*
| Módulo - Printar o array                                 |
*---------------------------------------------------------*/

void printArray(int array[], int size) {
	int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/*---------------------------------------------------------*
| Módulo - Realizar o BubbleSort                           |
*---------------------------------------------------------*/

void bubbleSort(int array[], int n) {
		int i,j;
    for (i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                change(&array[j], &array[j + 1]);
            }
        }
    }
}

/*---------------------------------------------------------*
| Módulo - Mudar posições                                  |
*---------------------------------------------------------*/

void change(int *xp, int *yp) {
    int temporary = *xp;
    *xp = *yp;
    *yp = temporary;
}

/*---------------------------------------------------------*
| Módulo - Modulo principal                                |
*---------------------------------------------------------*/

int main() {
    int n,i;
    int array[n];
    
    printf("Quantos numeros deseja inserir ? ");
    scanf("%d", &n);


    printf("Insira %d numeros:\n", n);
    for ( i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Array original: ");
    //Chama modulo para printar array
    printArray(array, n);

    //Chama modulo para realizar o bubbleSort
    bubbleSort(array, n);

    
    printf("Array ordenado: ");
    //Chama modulo para printar array
    printArray(array, n);

    return 0;
}

