/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *                                
*---------------------------------------------------------*
* Objetivo do Programa: Refatorando p/ modularizar código *
* Data – 09/09/2024                                       * 
* Autor: Kauan Torres                                     *
*--------------------------------------------------------*/

#include <stdio.h>

// Definição da variável global
#define SIZE 8   

/*---------------------------------------------------------*
| Módulo - Inicializar o tabuleiro                        |
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
| Módulo - Impressão do tabuleiro                         |
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
| Módulo - Mover peça do tabuleiro                         |
*---------------------------------------------------------*/

void moverPecaTabuleiro(char *destinoTabuleiro, char *origemTabuleiro){
	*destinoTabuleiro = *origemTabuleiro; //Utilização de ponteiro para pegar o endereço das variavéis 
	*origemTabuleiro = '*'; //Utilização do * para melhor visualização de onde estava a peça
	
	
}


/*--------------------------------------------------------*
| Módulo principal - Controla o fluxo                     |
*--------------------------------------------------------*/

int main() {
    char tabuleiro[SIZE][SIZE]; 
    
    //Chamar modulo de inicialização
    iniciarTabuleiro(tabuleiro); 

    printf("Tabuleiro inicial:\n \n");
    //Chamar modulo de impressão de tabuleiro
    printTabuleiro(tabuleiro);

	//Chamar modulo para mover peças
	moverPecaTabuleiro(&tabuleiro[4][4], &tabuleiro[6][4]);
    printf("Apos jogada #1 das Brancas (Peao do Rei e2 para e4):\n \n");
    printTabuleiro(tabuleiro);
    
	//Repetição dos modulos, modulo para mover peças e modulo para impressão do tabuleiro
	moverPecaTabuleiro(&tabuleiro[3][4], &tabuleiro[1][4]);
    printf("Apos jogada #1 das Pretas (Peão do Rei e7 para e5):\n \n");
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

