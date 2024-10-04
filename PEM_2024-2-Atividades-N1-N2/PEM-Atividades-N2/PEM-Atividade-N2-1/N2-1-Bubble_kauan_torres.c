#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------*
* Disciplina: Programa�ao Estruturada e Modular           *
*          Prof. Carlos Ver�ssimo                         *                                
*---------------------------------------------------------*
* Objetivo do Programa: Bubble Sort em C                  *
* Data : 04/10/2024                                       * 
* Autor: Kauan Torres e Lucas Borges                      *
*--------------------------------------------------------*/

/*---------------------------------------------------------*
| 					MELHORIAS                              |
*---------------------------------------------------------*/

//1. Modulariza��o do c�digo
//2. Pedir entrada de n numeros em vez de um array j� feito
//3. Cria��o da fun��o de change (troca das posi��es)
//4. Defini��o de um nome de mais f�cil entendimento das variav�is 
//5. Utiliza��o de ponteiros

/*----------------------------------------------------------------------------------------------------*
| Declara��o antecipada das fun��es (estava dando erro se n�o declarasse antes                       |
*----------------------------------------------------------------------------------------------------*/
void printArray(int array[], int size);
void bubbleSort(int array[], int n);
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
| M�dulo - Realizar o BubbleSort                           |
*---------------------------------------------------------*/
void bubbleSort(int array[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                change(&array[j], &array[j + 1]);
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
    int n, i;

    printf("Quantos numeros deseja inserir? ");
    scanf("%d", &n);

    int array[n];

    printf("Insira %d numeros:\n", n);
    for (i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Array original: ");
    // Chama modulo para printar array
    printArray(array, n);

    // Chama modulo para realizar o bubbleSort
    bubbleSort(array, n);

    printf("Array ordenado: ");
    // Chama modulo para printar array
    printArray(array, n);

    return 0;
}

