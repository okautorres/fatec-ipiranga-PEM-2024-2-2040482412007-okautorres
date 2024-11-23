
/*-----------------------------------------------------------*
* Disciplina: Programacao Estruturada e Modular              *
*          Prof. Carlos Verissimo                            *                                
*------------------------------------------------------------*
* Objetivo do Programa: N2-7- An�lise cr�tica de codigo      *
* Data : 23/11/2024                                          * 
* Autor da refatora��o: Kauan Torres                         *
*------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXPRODUTOS 50  // Define a constante para o n�mero m�ximo de produtos

typedef struct {
    int ID;  // Identificador �nico do produto
    char nomeProduto[50];  // Nome do produto
    int quantidadeEmEstoque;  // Quantidade dispon�vel em estoque
    double valorDoProduto;  // Pre�o do produto
} Produto;

// Fun��es principais para o gerenciamento dos produtos
void cadastrarProduto(Produto *listaProdutos, int *contadorProduto);  // Fun��o para cadastrar um novo produto
void alterarProduto(Produto *listaProdutos, int contadorProduto);  // Fun��o para alterar dados de um produto
void consultarProduto(Produto *listaProdutos, int contadorProduto);  // Fun��o para consultar dados de um produto
void excluirProduto(Produto *listaProdutos, int *contadorProduto);  // Fun��o para excluir um produto
void imprimirDados(Produto *listaProdutos);  // Fun��o para imprimir dados de um produto
void venderProduto(Produto *listaProdutos, int contadorProduto);  // Fun��o para vender um produto
void imprimirLista(Produto *listaProdutos, int contadorProduto);  // Fun��o para imprimir lista de produtos
void descontoProduto(Produto *listaProdutos, int contadorProduto);  // Fun��o para aplicar desconto em um produto

/*---------------------------------------------------------*
| M�dulo - Modulo cadastro produto                         |
*---------------------------------------------------------*/
void cadastrarProduto(Produto *listaProdutos, int *contadorProduto) {
    // Preenche os dados do produto e adiciona � lista
    Produto *produto = &listaProdutos[*contadorProduto];
    produto->ID = *contadorProduto + 1;  // Atribui um ID �nico
    printf("\nDigite o nome do produto: ");
    scanf(" %[^\n]", produto->nomeProduto);  // L� o nome do produto
    printf("Digite a quantidade em estoque do produto (Somente numeros naturais): ");
    scanf(" %i", &produto->quantidadeEmEstoque);  // L� a quantidade em estoque
    // Valida a quantidade (n�o pode ser negativa)
    while (produto->quantidadeEmEstoque < 0) {
        printf("A quantidade digitada esta errada. Digite novamente: ");
        scanf(" %d", &produto->quantidadeEmEstoque);
    }
    printf("Digite o valor do produto: ");
    scanf(" %lf", &produto->valorDoProduto);  // L� o valor do produto
    // Valida o valor (n�o pode ser negativo)
    while (produto->valorDoProduto < 0) {
        printf("O valor digitado esta errado. Digite novamente: ");
        scanf(" %lf", &produto->valorDoProduto);
    }
    (*contadorProduto)++;  // Incrementa o contador de produtos
    printf("Produto adicionado com sucesso!\n\n");
}

/*---------------------------------------------------------*
| M�dulo - Modulo imprimir dados                           |
*---------------------------------------------------------*/
void imprimirDados(Produto *listaProdutos) {
    // Exibe os dados de um produto
    printf("\nID: %d\n", listaProdutos->ID);
    printf("Nome: %s\n", listaProdutos->nomeProduto);
    printf("Quantidade em estoque: %d\n", listaProdutos->quantidadeEmEstoque);
    printf("Valor do produto: %.2f\n\n", listaProdutos->valorDoProduto);
}

/*---------------------------------------------------------*
| M�dulo - Modulo alterar produto                          |
*---------------------------------------------------------*/
void alterarProduto(Produto *listaProdutos, int contadorProduto) {
    // Altera os dados de um produto existente
    int ID;
    printf("\nDigite o ID do produto que ser� alterado: ");
    scanf(" %d", &ID);
    for (int i = 0; i < contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            printf("\nDados atuais do produto:\n");
            imprimirDados(&listaProdutos[i]);

            int opcaoAlteracao;
            printf("\nO que voc� deseja alterar?\n");
            printf("1. Nome\n");
            printf("2. Quantidade em estoque\n");
            printf("3. Valor\n");
            printf("Digite a op��o desejada (1/2/3): ");
            scanf(" %d", &opcaoAlteracao);

            // Altera��es baseadas na escolha do usu�rio
            switch(opcaoAlteracao) {
                case 1:
                    printf("\nDigite o novo nome do produto: ");
                    scanf(" %[^\n]", listaProdutos[i].nomeProduto);
                    break;
                case 2:
                    printf("Digite a nova quantidade em estoque do produto: ");
                    scanf(" %d", &listaProdutos[i].quantidadeEmEstoque);
                    while (listaProdutos[i].quantidadeEmEstoque < 0) {
                        printf("A quantidade digitada esta errada. Digite novamente: ");
                        scanf(" %d", &listaProdutos[i].quantidadeEmEstoque);
                    }
                    break;
                case 3:
                    printf("Digite o novo valor do produto: ");
                    scanf(" %lf", &listaProdutos[i].valorDoProduto);
                    while (listaProdutos[i].valorDoProduto < 0) {
                        printf("O valor digitado esta errado. Digite novamente: ");
                        scanf(" %lf", &listaProdutos[i].valorDoProduto);
                    }
                    break;
                default:
                    printf("Opcao invalida. Nenhuma alteracao foi realizada.\n");
                    return;
            }

            printf("Produto alterado com sucesso!\n\n");
            return;
        }
    }
    printf("Produto com o ID %d nao encontrado.\n\n", ID);
}

/*---------------------------------------------------------*
| M�dulo - Modulo consultar produto                        |
*---------------------------------------------------------*/
void consultarProduto(Produto *listaProdutos, int contadorProduto){
    // Verifica se n�o h� produtos cadastrados na lista
    if(contadorProduto == 0) {
        printf("\nNao ha produtos cadastrados.\n\n");
        return; // Se n�o houver produtos, sai da fun��o
    }

    int ID;
    // Solicita o ID do produto que o usu�rio deseja consultar
    printf("\nDigite o ID do produto que deseja consultar: ");
    scanf(" %d", &ID);

    // Loop para encontrar o produto pelo ID
    for(int i = 0; i < contadorProduto; i++){
        // Se o produto for encontrado, exibe os dados
        if(listaProdutos[i].ID == ID){
            imprimirDados(&listaProdutos[i]);
            return; // Se encontrado, a fun��o � finalizada
        }
    }
    // Caso o produto n�o seja encontrado
    printf("Produto com o ID %d nao encontrado.\n\n", ID);
}


/*---------------------------------------------------------*
| M�dulo - Modulo excluir produto                          |
*---------------------------------------------------------*/
void excluirProduto(Produto *listaProdutos, int *contadorProduto){
    // Verifica se n�o h� produtos cadastrados na lista
    if(*contadorProduto == 0) {
        printf("\nNao ha produtos cadastrados.\n\n");
        return; // Se n�o houver produtos, sai da fun��o
    }

    int ID;
    // Solicita o ID do produto que o usu�rio deseja excluir
    printf("\nDigite o ID do produto que deseja excluir: ");
    scanf(" %d", &ID);

    // Loop para encontrar o produto pelo ID
    for(int i = 0; i < *contadorProduto; i++){
        // Se o produto for encontrado, realiza a exclus�o
        if(listaProdutos[i].ID == ID){
            // Move todos os produtos seguintes uma posi��o para a esquerda para "excluir" o produto
            for(int j = i; j < *contadorProduto - 1; j++){
                listaProdutos[j] = listaProdutos[j + 1];
            }
            (*contadorProduto)--; // Diminui o contador de produtos
            printf("Produto excluido com sucesso!\n\n");
            return; // A fun��o � finalizada ap�s excluir o produto
        }
    }
    // Caso o produto n�o seja encontrado
    printf("Produto com o ID %d nao encontrado.\n\n", ID);
}


/*---------------------------------------------------------*
| M�dulo - Modulo vender produto                           |
*---------------------------------------------------------*/
void venderProduto(Produto *listaProdutos, int contadorProduto) {
    // Realiza a venda de um produto
    int ID, quantidade;
    
    // Solicita o ID do produto que o usu�rio deseja vender
    printf("\nDigite o ID do produto que deseja vender: ");
    scanf(" %d", &ID);

    // Verifica se o produto existe
    int produtoExistente = 0;
    for (int i = 0; i < contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            produtoExistente = 1;
            break;  // Produto encontrado
        }
    }
    
    // Se o produto n�o existe
    if (!produtoExistente) {
        printf("Produto com o ID %d nao encontrado.\n\n", ID);
        return;
    }

    // Solicita a quantidade a ser vendida, se o produto existir
    printf("Digite a quantidade que ser� vendida: ");
    scanf(" %d", &quantidade);

    // Valida a quantidade
    while (quantidade <= 0) {
        printf("A quantidade deve ser maior ou igual a 1. Digite novamente: ");
        scanf(" %d", &quantidade);
    }

    // Procura o produto e verifica o estoque
    for (int i = 0; i < contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            if (listaProdutos[i].quantidadeEmEstoque >= quantidade) {
                // Calcula o valor da venda
                printf("Preco da venda: %.2f\n", listaProdutos[i].valorDoProduto * quantidade);
                listaProdutos[i].quantidadeEmEstoque -= quantidade;  // Atualiza o estoque
                printf("Produto vendido com sucesso!\n\n");
                return;
            } else {
                printf("Estoque insuficiente para realizar a venda.\n\n");
                return;
            }
        }
    }
}

/*---------------------------------------------------------*
| M�dulo - Modulo desconto produto                         |
*---------------------------------------------------------*/
void descontoProduto(Produto *listaProdutos, int contadorProduto) {
    // Aplica um desconto em um produto
    int ID;
    printf("\nDigite o ID do produto que recebera desconto: ");
    scanf(" %d", &ID);
    for (int i = 0; i < contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            double desconto;
            printf("\nDigite o desconto (exemplo: 45 para 45%%): ");
            scanf(" %lf", &desconto);
            // Aplica o desconto
            listaProdutos[i].valorDoProduto -= listaProdutos[i].valorDoProduto * (desconto / 100);
            printf("Novo valor do produto: %.2f\n", listaProdutos[i].valorDoProduto);
            printf("Desconto aplicado com sucesso!\n\n");
            return;
        }
    }
    printf("Produto com o ID %d nao encontrado.\n\n", ID);
}

/*---------------------------------------------------------*
| M�dulo - Modulo imprimir lista                           |
*---------------------------------------------------------*/
void imprimirLista(Produto *listaProdutos, int contadorProduto) {
    // Verifica se n�o h� produtos cadastrados na lista
    if (contadorProduto == 0) {
        printf("\nNao ha produtos cadastrados.\n\n");
        return; // Se n�o houver produtos, sai da fun��o
    }

    // Exibe o t�tulo da lista
    printf("\n------------- Lista de todos os produtos cadastrados -------------\n\n");

    // Loop para imprimir todos os produtos cadastrados
    for (int i = 0; i < contadorProduto; i++) {
        // Exibe os dados completos do produto
        printf("ID: %d\n", listaProdutos[i].ID);
        printf("Nome: %s\n", listaProdutos[i].nomeProduto);
        printf("Quantidade em estoque: %d\n", listaProdutos[i].quantidadeEmEstoque);
        printf("Valor: %.2f\n", listaProdutos[i].valorDoProduto);
        printf("\n");  // Linha em branco para separar os produtos
    }
}


/*---------------------------------------------------------*
| M�dulo - Principal                                       |
*---------------------------------------------------------*/
int main() {
    Produto listaProdutos[MAXPRODUTOS];  // Vetor para armazenar os produtos
    int contadorProduto = 0;  // Contador de produtos cadastrados
    int opcao;

    do {
        printf("------ * MENU * ------\n");
        printf("1. Cadastrar produto\n");
        printf("2. Alterar dados do produto\n");
        printf("3. Consultar produto\n");
        printf("4. Excluir produto\n");
        printf("5. Consultar lista de produtos\n");
        printf("6. Vender produto\n");
        printf("7. Dar desconto a um produto\n");
        printf("8. Encerrar o programa\n");
        printf("Escolha uma opcao: ");
        scanf(" %d", &opcao);

        switch(opcao){
            case 1: cadastrarProduto(listaProdutos, &contadorProduto);
                    break;
            case 2: alterarProduto(listaProdutos, contadorProduto);
                    break;
            case 3: consultarProduto(listaProdutos, contadorProduto);
                    break;
            case 4: excluirProduto(listaProdutos, &contadorProduto);
                    break;
            case 5: imprimirLista(listaProdutos, contadorProduto);
                    break;
            case 6: venderProduto(listaProdutos, contadorProduto);
                    break;
            case 7: descontoProduto(listaProdutos, contadorProduto);
                    break;
            case 8: printf("\nObrigado por usar o programa!\n");
                    break;
            default: printf("\nOpcao invalida. Tente novamente.\n");
                     break;
        }
    } while(opcao != 8);

    return 0;
}

