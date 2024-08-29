#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------------------------------------*
* Disciplina: Programa�ao Estruturada e Modular                                            *
*          Prof. Carlos Ver�ssimo                                                          *
*------------------------------------------------------------------------------------------*
* Objetivo do Programa: Programa em C para demonstrar a ocupa��o de um tabuleiro de xadrez *
* Data - 26/08/2024                                                                        * 
* Autor: Kauan Torres                                                                      *
*------------------------------------------------------------------------------------------*/

int main() {
	char tabuleiro[64][4]; //Vetor com a quantidade de pe�as/casas[quantidade de caracteres]
	int x;
	
	for (x = 0; x < 64; x++) {
        strcpy(tabuleiro[x], "X"); //Adicionando um X em todas as casas, para posteriormente completa-l�s
    }
    
    // Pe�as brancas
    strcpy(tabuleiro[0], "BT1"); strcpy(tabuleiro[1], "BC1"); strcpy(tabuleiro[2], "BB1");  strcpy(tabuleiro[3], "BD1"); strcpy(tabuleiro[4], "BR1"); strcpy(tabuleiro[5], "BB2"); strcpy(tabuleiro[6], "BC2"); strcpy(tabuleiro[7], "BT2");
	strcpy(tabuleiro[8], "BP1"); strcpy(tabuleiro[9], "BP2"); strcpy(tabuleiro[10], "BP3"); strcpy(tabuleiro[11], "BP4"); strcpy(tabuleiro[12], "BP5"); strcpy(tabuleiro[13], "BP6"); strcpy(tabuleiro[14], "BP7"); strcpy(tabuleiro[15], "BP8");
	
	// Pe�as pretas
	strcpy(tabuleiro[48], "PP1"); strcpy(tabuleiro[49], "PP2"); strcpy(tabuleiro[50], "PP3"); strcpy(tabuleiro[51], "PP4"); strcpy(tabuleiro[52], "PP5"); strcpy(tabuleiro[53], "PP6"); strcpy(tabuleiro[54], "PP7"); strcpy(tabuleiro[55], "PP8");
	strcpy(tabuleiro[56], "PT1"); strcpy(tabuleiro[57], "PC1");  strcpy(tabuleiro[58], "PB1");  strcpy(tabuleiro[59], "PD1"); strcpy(tabuleiro[60], "PR1"); strcpy(tabuleiro[61], "PB2"); strcpy(tabuleiro[62], "PC2"); strcpy(tabuleiro[63], "PT2");

	//Colunas do tabuleiro
     char colunas[] = "abcdefgh";
     int Ncolunas = 8;
    
    // Letras das colunas do tabuleiro
    printf("  ");
    for (x = 0; x < Ncolunas; x++) {
        printf("  %c  ", colunas[x]);
    }
    printf("\n");
    
    //Linhas do tabuleiro
    for (x = 7; x >= 0; x--) {
        printf("%d ", x + 1); // Impress�o do n�mero da linha
        
        //Impress�o das pe�as
        int y;
        for (Ncolunas = 0; Ncolunas < 8; Ncolunas++) {
            int i = x * 8 + Ncolunas; //Index das pe�as. Sendo x o n�mero da linha*8+n�mero da coluna.
            printf("%4s ", tabuleiro[i]);
        }
        printf("\n");
    }

    return 0;
}
