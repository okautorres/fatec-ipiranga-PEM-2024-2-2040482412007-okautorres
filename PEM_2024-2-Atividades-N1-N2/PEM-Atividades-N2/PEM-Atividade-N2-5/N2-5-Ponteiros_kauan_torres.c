#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*-----------------------------------------------------------*
* Disciplina: Programacao Estruturada e Modular              *
*          Prof. Carlos Verissimo                            *                                
*------------------------------------------------------------*
* Objetivo do Programa: N2-5- Utilizando ponteiros           *
* Data : 04/11/2024                                          * 
* Autor: Kauan Torres                                        *
*------------------------------------------------------------*/

 
typedef struct { //Defini��o do Struct
    int ID;
    char nome[50];
    int qtEstoque;
    double valor;        
} Produto;


/*---------------------------------------------------------*
| M?dulo - Inserir produto                                 |
*---------------------------------------------------------*/

void inserirProduto(int *contador, Produto *produtos){
     int ID;
     
     ID = *contador + 1; //ID do produto sempre ser� contador +1, auto-incremento.
     produtos[ID].ID = ID;
     
    printf("================================================== \n");
    printf("Digite o nome do produto: \n");
    fgets(produtos[ID].nome, 50, stdin);
    printf("Digite a quantidade do produto:\n");
    scanf("%i", &produtos[ID].qtEstoque);
    printf("Digite o valor do produto: (Exemplo: 34.99)\n");
    scanf("%lf", &produtos[ID].valor);
    
    
    *contador = *contador + 1; //Depois que o produto � inserido, acrescenta 1 no contador.
    
    printf("Produto inserido corretamente.\n ");
    printf("================================================== \n");
    printf("ID: %i\n", produtos[ID].ID);
    printf("Nome: %s", produtos[ID].nome);
    printf("Quantidade no estoque: %i\n", produtos[ID].qtEstoque);
    printf("Valor: %.2lf\n \n", produtos[ID].valor);
    
     getchar();     
}

/*---------------------------------------------------------*
| M?dulo - Modulo consulta geral                           |
*---------------------------------------------------------*/

void consultaGeral(int contador, Produto *produtos) {
     int i;
     if(contador <= 0){
       printf("Nao ha nenhum produto cadastrado. \n");
       return;
     }
    printf("================================================== \n");
    printf("Lista de produtos: \n \n");
    
    for(i = 1; i <= contador; i++){
          printf("ID: %i\n", produtos[i].ID);
          printf("Nome: %s", produtos[i].nome);
          printf("Quantidade no estoque: %i\n", produtos[i].qtEstoque);
          printf("Valor: %.2lf\n \n", produtos[i].valor);
    }
    
}

/*---------------------------------------------------------*
| M?dulo - Modulo consulta produto                         |
*---------------------------------------------------------*/

void consultarProduto(int contador, Produto *produtos) {
     int ID;
     printf("Digite o ID do produto a ser consultado: \n");
     scanf("%i",&ID);
    printf("================================================== \n");
     if (ID > contador || ID == 0) {
        printf("Este produto nao existe. \n");
        return;
     }
     printf("ID: %i\n", produtos[ID].ID);
     printf("Nome: %s", produtos[ID].nome);
     printf("Quantidade no estoque: %i\n", produtos[ID].qtEstoque);
     printf("Valor: %.2lf\n \n", produtos[ID].valor);

}

/*---------------------------------------------------------*
| M?dulo - Modulo alterar  produto                         |
*---------------------------------------------------------*/

void alterarProduto(int contador, Produto *produtos){
     int ID, opcao;
     printf("   ================================================== \n");
     printf("Digite o codigo do produto que deseja alterar: \n");
     scanf("%i",&ID);
     getchar();
     if (ID > contador || ID == 0) {
        printf("Este produto nao existe. \n");
        return;
     }
     
     printf("Produto selecionado: \n");
     printf("ID: %i\n", produtos[ID].ID);
     printf("Nome: %s", produtos[ID].nome);
     printf("Quantidade no estoque: %i\n", produtos[ID].qtEstoque);
     printf("Valor: %.2lf\n \n", produtos[ID].valor);
     
     printf("Qual a opcao que deseja alterar no produto ? \n");
     printf("(1) - Nome\n");
     printf("(2) - Quantidade estoque\n");
     printf("(3) - Valor\n");
     printf("(0) - Cancelar \n");
     scanf("%i",&opcao);
         getchar();
     switch(opcao) {
            case 1:
                printf("Digite o novo nome do produto: \n");
                fgets(produtos[ID].nome, 50, stdin);
                break;
            case 2:
                 printf("Digite a nova quantidade do produto:\n");
                 scanf("%i", &produtos[ID].qtEstoque);
                break;
            case 3:
               printf("Digite o novo valor do produto: (Exemplo: 34.99)\n");
                 scanf("%lf", &produtos[ID].valor);
                break;
            case 0:
                 return;
                 break;
        }
     
}


/*---------------------------------------------------------*
| M?dulo - Modulo excluir  produto                         |
*---------------------------------------------------------*/

void excluirProduto(int *contador, Produto *produtos){
    int ID, resposta, i;
     printf("   ================================================== \n");
     printf("Digite o codigo do produto que deseja excluir: \n");
     scanf("%i",&ID);
     
     getchar();
     
     if (ID > *contador || ID == 0 || produtos[ID].ID == 0) {
        printf("Este produto nao existe. \n");
        return;
     }
     
     printf("Produto selecionado: \n");
     printf("ID: %i\n", produtos[ID].ID);
     printf("Nome: %s", produtos[ID].nome);
     printf("Quantidade no estoque: %i\n", produtos[ID].qtEstoque);
     printf("Valor: %.2lf\n \n", produtos[ID].valor);
     
     printf("Tem certeza que deseja excluir este item ? (1) - SIM | (2) - NAO \n");
     scanf("%i", &resposta);
     
     if(resposta != 1){
     	printf("A resposta seria somente (1) - SIM | (2) - NAO.\n");
     return;
     }

    for(i = ID; i < *contador; i++) {
        produtos[i] = produtos[i + 1]; //Aqui, basicamente fiz com que todos os produtos a direita do produto selecionado, voltem um ID. Para ocupar a vaga do ID selecionado.  
        produtos[i].ID = i;  // Aqui o ID do anterior � colocado depois que houve a troca.
    }
    
    produtos[*contador].ID = 0; //Anulo o produto final, pois o que sobra j� foi trocado para a posi��o anterior
    strcpy(produtos[*contador].nome, "");
    produtos[*contador].qtEstoque = 0;
    produtos[*contador].valor = 0;
     
        
     (*contador)--;
     
     
}

/*---------------------------------------------------------*
| M?dulo - Modulo vender produto                           |
*---------------------------------------------------------*/

void venderProduto(int contador, Produto *produtos){
     int ID, qtvenda, descontotemp;
     double valor, desconto;
     printf("   ================================================== \n");
     printf("Digite o codigo do produto que deseja vender: \n");
     scanf("%i",&ID);
     
     getchar();
     
     if (ID > contador || ID == 0) {
        printf("Este produto nao existe. \n");
        return;
     }
     
     printf("Produto selecionado: \n");
     printf("ID: %i\n", produtos[ID].ID);
     printf("Nome: %s", produtos[ID].nome);
     printf("Quantidade no estoque: %i\n", produtos[ID].qtEstoque);
     printf("Valor: %.2lf\n \n", produtos[ID].valor);
     
     printf("Quantas unidades do produto deseja vender ? \n");
     scanf("%i", &qtvenda);
     getchar();
     
     if(qtvenda > produtos[ID].qtEstoque){
       printf("Nao ha esta quantidade no estoque. \n");
       return;
     }
      produtos[ID].qtEstoque =  produtos[ID].qtEstoque - qtvenda;
      
      printf("Qual a porcentagem de desconto que quer aplicar? Exemplo: (12) sem porcentagem. \n");
      scanf("%i", &descontotemp);
      
      valor = produtos[ID].valor*qtvenda;
      
      if(descontotemp != 0){
               desconto = valor - ((valor*descontotemp)/100);
               printf("Total da venda:  \n");
               printf("Quantidade: %i\n", qtvenda);
               printf("Valor: %.2lf\n", desconto);
               return;
                      }
      
      
      
      printf("Total da venda:  \n");
      printf("Quantidade: %i\n", qtvenda);
      printf("Valor: %.2lf\n", valor);
     
}


/*---------------------------------------------------------*
| M?dulo - Modulo principal                                |
*---------------------------------------------------------*/

int main() {
    int opcao;
    int contador = 0;
    int totalCadastros = 0;
    Produto produtos[50];
    
    do {
        printf("   ================================================== \n");
        printf("   |                                                | \n");     
        printf("   |            Loja de produtos eletro             | \n");                    
        printf("   |          feita por Kauan Torres                | \n");
        printf("   ================================================== \n");
        printf("   |  Digite a opcao o numero da opcao que deseja:  | \n");
        printf("   |                                                | \n");
        printf("   |  (1) - INCLUIR produto                         | \n");
        printf("   |  (2) - CONSULTA produto                        | \n");
        printf("   |  (3) - CONSULTA TODOS produtos                 | \n");
        printf("   |  (4) - ALTERAR produto                         | \n");
        printf("   |  (5) - EXCLUIR produto                         | \n");
        printf("   |  (6) - VENDER produto                          | \n");
        printf("   |  (0) - SAIR                                    | \n");
        printf("   |                                                | \n");
        printf("   ================================================== \n");
        scanf("%i", &opcao);
        
        getchar();
       
        switch(opcao) {
            case 1:
                inserirProduto(&contador, produtos); // Chama m?dulo inser??o produto
                break;
            case 2:
                consultarProduto(contador, produtos); // Chama m?dulo consulta produto
                break;
            case 3:
                consultaGeral(contador, produtos); // Chama m?dulo consulta geral
                break;
            case 4:
                 alterarProduto(contador, produtos); // Chama m?dulo alterar produto
                 break;
            case 5:
                 excluirProduto(&contador, produtos); // Chama m?dulo excluir produto
                 break;
             case 6:
                  venderProduto(contador, produtos); // Chama m?dulo vender produto
                 break;
        }

        if(opcao > 6 || opcao < 0) {
            printf("    Opcao invalida. \n");
        }
    } while(opcao != 0);

    return 0;
}
