#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*-----------------------------------------------------------*
* Disciplina: Programacao Estruturada e Modular              *
*          Prof. Carlos Verissimo                            *                                
*------------------------------------------------------------*
* Objetivo do Programa: Manipulando Struct                   *
* Data : 22/10/2024                                          * 
* Autor: Kauan Torres                                        *
*------------------------------------------------------------*/
 
#define MAXIMO_PRODUTOS 50
 
typedef struct {
    int Id;
    char Nome[50];
    char Desc[120];
    float Preco;
    int Quantidade;
} ProdutoEletronico;
 
 
 /*---------------------------------------------------------*
| Módulo - Inserção produto                                 |
*---------------------------------------------------------*/

void inserirProduto(int *contador, ProdutoEletronico *produtos) {
    if (*contador < MAXIMO_PRODUTOS) { 
        ProdutoEletronico novo;
        novo.Id = *contador + 1;
        
        printf("   ================================================== \n");
        printf("   |               INSERIR PRODUTO                  | \n");                        
        printf("   ================================================== \n");

        printf("Digite o nome do produto:\n");
        getchar(); 
        fgets(novo.Nome, sizeof(novo.Nome), stdin);

        printf("Digite a descricao do produto:\n");
        fgets(novo.Desc, sizeof(novo.Desc), stdin);

        printf("Digite o preco do produto:\n");
        scanf("%f", &novo.Preco); 

        printf("Digite a quantidade do produto:\n");
        scanf("%d", &novo.Quantidade);  

        produtos[*contador] = novo;  
        
        printf("   ------------------------------------------------- \n");	
        printf("    Produto adicionado:\n");
        printf("    ID: %i\n", produtos[*contador].Id);
        printf("    Nome: %s", produtos[*contador].Nome);
        printf("    Desc: %s", produtos[*contador].Desc);
        printf("    Preco: %.2f\n", produtos[*contador].Preco);
        printf("    Quantidade: %i\n", produtos[*contador].Quantidade);
        
        (*contador)++;  // Incrementa o contador de produtos

    } else {
        printf("Estoque cheio.\n");
        return;
    }
}

 /*---------------------------------------------------------*
| Módulo - Listagem produto                                 |
*---------------------------------------------------------*/

void listaProduto(int *contador,ProdutoEletronico *produtos){
    int i, j;
    ProdutoEletronico temp;

    
    for (i = 0; i < *contador - 1; i++) {
        for (j = 0; j < *contador - i - 1; j++) {
            if (strcmp(produtos[j].Nome, produtos[j + 1].Nome) > 0) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
		printf("   ================================================== \n");
        printf("   |               LISTA DE PRODUTOS                | \n");                        
        printf("   ================================================== \n");
	if(*contador>0){
		for(i=1;i<=*contador;i++){
        printf("    ID: %i\n", produtos[i-1].Id);
        printf("    Nome: %s", produtos[i-1].Nome);
        printf("    Desc: %s", produtos[i-1].Desc);
        printf("    Preco: %.2f\n", produtos[i-1].Preco);
        printf("    Quantidade: %i\n \n", produtos[i-1].Quantidade);
		printf("   ------------------------------------------------- \n");	
	}	
	} else{
		printf("    Ainda nao ha produtos cadastrados. \n");
	}
	
}

 /*---------------------------------------------------------*
| Módulo - Compra produto                                  |
*---------------------------------------------------------*/

void compraProduto(int *contador, ProdutoEletronico *produtos){
	int qtCompras;
	int idProduto;
	float valor;
	
	printf("   ================================================== \n");
    printf("   |               COMPRA DE PRODUTOS               | \n");                        
    printf("   ================================================== \n");
    
    printf("Digite o ID do item que deseja comprar: \n");
    scanf("%i",&idProduto);
    
	if(idProduto < 1 || idProduto > *contador){
		printf("Este produto nao existe \n");
		return;
	}
    
    printf("Digite a quantidade do item que deseja comprar: \n");
    scanf("%i", &qtCompras);
    
    if(qtCompras > produtos[idProduto-1].Quantidade){
    	printf("Nao ha estoque o suficiente para a quantidade desejada.\n");
    	return;
	}
	
    
    produtos[idProduto-1].Quantidade = produtos[idProduto-1].Quantidade - qtCompras;
    
    valor = qtCompras*produtos[idProduto-1].Preco;
    
    printf("   ------------------------------------------------- \n");
    printf("Compra realizada com sucesso!\n");
    printf("Item: %s", produtos[idProduto-1].Nome);
    printf("Quantidade: %i \n",qtCompras);
    printf("Valor total: %.2f \n", valor);
}

 
/*---------------------------------------------------------*
| Módulo - Modulo principal                                |
*---------------------------------------------------------*/
 
int main() {
    int opcao;
    int contador=0;
    ProdutoEletronico produtos[MAXIMO_PRODUTOS];
    
    do {
        printf("   ================================================== \n");
        printf("   |                                                | \n");     
        printf("   |     LOJINHA DE ELETRONICOS KAUAN TORRES        | \n");                    
        printf("   |                                                | \n");
        printf("   ================================================== \n");
        printf("   |  Digite a opcao o numero da opcao que deseja:  | \n");
        printf("   |                                                | \n");
        printf("   |  (1) - INSERIR produto                         | \n");
        printf("   |  (2) - COMPRA on-line                          | \n");
        printf("   |  (3) - LISTA de produtos                       | \n");
        printf("   |  (0) - SAIR                                    | \n");
        printf("   |                                                | \n");
        printf("   ================================================== \n");
 
        scanf("%i", &opcao);
        switch(opcao) {
            case 1:
                inserirProduto(&contador, produtos); //Chama modulo inserção produto
                break;
            case 2:
            	compraProduto(&contador, produtos); //Chama modulo compra produto
                break;
            case 3:
                listaProduto(&contador, produtos); //Chama modulo lista produto
                break;			
        }
 
        if(opcao > 3 || opcao < 0) {
            printf("    Opcao invalida. \n");
        }
    } while(opcao != 0);
    
    return 0;	
}
