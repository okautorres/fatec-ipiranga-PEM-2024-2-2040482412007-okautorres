/*--------------------------------------------------------*
* Disciplina: Programa�ao Estruturada e Modular           *
*          Prof. Carlos Ver�ssimo                         *                                
*---------------------------------------------------------*
* Objetivo do Programa: Refatorando p/ modularizar c�digo *
* Data � 09/09/2024                                       * 
* Autor: Kauan Torres                                     *
*--------------------------------------------------------*/

#include <stdio.h>

// Defini��o da vari�vel global
#define SIZE 8   

/*---------------------------------------------------------*
| M�dulo - Inicializar o tabuleiro                        |
*---------------------------------------------------------*/

void iniciarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    int i, j;
    char tabuleiroInicial[SIZE][SIZE] = { 
        {'t', 'c', 'b', 'd', 'r', 'b', 'c', 't'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'}
    };
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = tabuleiroInicial[i][j];
        }
    }
}

/*---------------------------------------------------------*
| M�dulo - Impress�o do tabuleiro                         |
*---------------------------------------------------------*/

void printTabuleiro(char tabuleiro[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*---------------------------------------------------------*
| M�dulo - Mover pe�a do tabuleiro                         |
*---------------------------------------------------------*/

void moverPecaTabuleiro(char *destinoTabuleiro, char *origemTabuleiro){
	*destinoTabuleiro = *origemTabuleiro; //Utiliza��o de ponteiro para pegar o endere�o das variav�is 
	*origemTabuleiro = '*'; //Utiliza��o do * para melhor visualiza��o de onde estava a pe�a
	
	
}


/*--------------------------------------------------------*
| M�dulo principal - Controla o fluxo                     |
*--------------------------------------------------------*/

int main() {
    char tabuleiro[SIZE][SIZE]; 
    
    //Chamar modulo de inicializa��o
    iniciarTabuleiro(tabuleiro); 

    printf("Tabuleiro inicial:\n \n");
    //Chamar modulo de impress�o de tabuleiro
    printTabuleiro(tabuleiro);

	//Chamar modulo para mover pe�as
	moverPecaTabuleiro(&tabuleiro[4][4], &tabuleiro[6][4]);
    printf("Apos jogada #1 das Brancas (Peao do Rei e2 para e4):\n \n");
    printTabuleiro(tabuleiro);
    
	//Repeti��o dos modulos, modulo para mover pe�as e modulo para impress�o do tabuleiro
	moverPecaTabuleiro(&tabuleiro[3][4], &tabuleiro[1][4]);
    printf("Apos jogada #1 das Pretas (Pe�o do Rei e7 para e5):\n \n");
    printTabuleiro(tabuleiro);

	moverPecaTabuleiro(&tabuleiro[4][2], &tabuleiro[7][5]);
    printf("Apos jogada #2 das Brancas (Bispo do Rei f1 para c4):\n \n");
    printTabuleiro(tabuleiro);

	moverPecaTabuleiro(&tabuleiro[2][2], &tabuleiro[0][1]);
    printf("Apos jogada #2 das Pretas (Cavalo da Dama b8 para c6):\n");
    printTabuleiro(tabuleiro);

	moverPecaTabuleiro(&tabuleiro[3][7], &tabuleiro[7][3]);
    printf("Apos jogada #3 das Brancas (Dama d1 para h5):\n \n");
    printTabuleiro(tabuleiro);

	moverPecaTabuleiro(&tabuleiro[2][5], &tabuleiro[0][6]);
    printf("Apos jogada #3 das Pretas (Cavalo do Rei g8 para f6):\n \n");
    printTabuleiro(tabuleiro);
    
    moverPecaTabuleiro(&tabuleiro[1][5], &tabuleiro[3][7]);
    printf("Apos jogada #4 das Brancas (Dama h5 captura Peao f7 - Xeque Mate):\n \n");
    printTabuleiro(tabuleiro);

    return 0;
}

