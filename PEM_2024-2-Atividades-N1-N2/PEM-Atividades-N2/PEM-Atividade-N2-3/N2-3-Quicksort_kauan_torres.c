#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------------------*
* Disciplina: Programa�ao Estruturada e Modular              *
*          Prof. Carlos Ver�ssimo                            *                                
*------------------------------------------------------------*
* Objetivo do Programa: Quicksort e esquema da mem�ria       *
* Data : 13/10/2024                                          * 
* Autor: Kauan Torres                                        *
*------------------------------------------------------------*/

/*--------------------------------------------------------------------*
| M�dulo - Realizar a parti��o do array, maiores que pivot e menores  |
*---------------------------------------------------------------------*/
int partition(int array[], int left, int right) {
    int pivot = array[right]; 
    int i = left - 1, j;
    for (j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i = i+1;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    int temp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = temp;
    
    return i + 1;
}

/*---------------------------------------------------------*
| M�dulo - Quicksort                                       |�
*---------------------------------------------------------*/
void quicksort(int array[], int left, int right) {
    if (left < right) {
        int pivot = partition(array, left, right);
        quicksort(array, left, pivot - 1);  
        quicksort(array, pivot + 1, right); 
    }
}

/*---------------------------------------------------------*
| M�dulo - Printar array                                   |
*---------------------------------------------------------*/
void printarArray(int array[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/*---------------------------------------------------------*
| M�dulo - Modulo principal                                |
*---------------------------------------------------------*/
int main() {
    int array[] = {100, 70, 90, 60, 10, 40, 30};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Array original: ");
    printarArray(array, size); // Modulo de printar array

    quicksort(array, 0, size - 1); // Modulo quicksort

    printf("Array ordenado: ");
    printarArray(array, size);

    return 0;
}

