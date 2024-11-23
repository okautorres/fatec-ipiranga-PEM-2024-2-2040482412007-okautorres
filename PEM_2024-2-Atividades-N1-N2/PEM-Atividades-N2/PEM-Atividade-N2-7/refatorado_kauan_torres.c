
/*-----------------------------------------------------------*
* Disciplina: Programacao Estruturada e Modular              *
*          Prof. Carlos Verissimo                            *                                
*------------------------------------------------------------*
* Objetivo do Programa: N2-7- Análise crítica de codigo      *
* Data : 23/11/2024                                          * 
* Autor da refatoração: Kauan Torres                         *
*------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXPRODUTOS 50  // Define a constante para o número máximo de produtos

typedef struct {
    int ID;  // Identificador único do produto
    char nomeProduto[50];  // Nome do produto
    int quantidadeEmEstoque;  // Quantidade disponível em estoque
    double valorDoProduto;  // Preço do produto
} Produto;

// Funções principais para o gerenciamento dos produtos
void cadastrarProduto(Produto *listaProdutos, int *contadorProduto);  // Função para cadastrar um novo produto
void alterarProduto(Produto *listaProdutos, int contadorProduto);  // Função para alterar dados de um produto
void consultarProduto(Produto *listaProdutos, int contadorProduto);  // Função para consultar dados de um produto
void excluirProduto(Produto *listaProdutos, int *contadorProduto);  // Função para excluir um produto
void imprimirDados(Produto *listaProdutos);  // Função para imprimir dados de um produto
void venderProduto(Produto *listaProdutos, int contadorProduto);  // Função para vender um produto
void imprimirLista(Produto *listaProdutos, int contadorProduto);  // Função para imprimir lista de produtos
void descontoProduto(Produto *listaProdutos, int contadorProduto);  // Função para aplicar desconto em um produto

/*---------------------------------------------------------*
| Módulo - Modulo cadastro produto                         |
*---------------------------------------------------------*/
void cadastrarProduto(Produto *listaProdutos, int *contadorProduto) {
    // Preenche os dados do produto e adiciona à lista
    Produto *produto = &listaProdutos[*contadorProduto];
    produto->ID = *contadorProduto + 1;  // Atribui um ID único
    printf("\nDigite o nome do produto: ");
    scanf(" %[^\n]", produto->nomeProduto);  // Lê o nome do produto
    printf("Digite a quantidade em estoque do produto (Somente numeros naturais): ");
    scanf(" %i", &produto->quantidadeEmEstoque);  // Lê a quantidade em estoque
    // Valida a quantidade (não pode ser negativa)
    while (produto->quantidadeEmEstoque < 0) {
        printf("A quantidade digitada esta errada. Digite novamente: ");
        scanf(" %d", &produto->quantidadeEmEstoque);
    }
    printf("Digite o valor do produto: ");
    scanf(" %lf", &produto->valorDoProduto);  // Lê o valor do produto
    // Valida o valor (não pode ser negativo)
    while (produto->valorDoProduto < 0) {
        printf("O valor digitado esta errado. Digite novamente: ");
        scanf(" %lf", &produto->valorDoProduto);
    }
    (*contadorProduto)++;  // Incrementa o contador de produtos
    printf("Produto adicionado com sucesso!\n\n");
}

/*---------------------------------------------------------*
| Módulo - Modulo imprimir dados                           |
*---------------------------------------------------------*/
void imprimirDados(Produto *listaProdutos) {
    // Exibe os dados de um produto
    printf("\nID: %d\n", listaProdutos->ID);
    printf("Nome: %s\n", listaProdutos->nomeProduto);
    printf("Quantidade em estoque: %d\n", listaProdutos->quantidadeEmEstoque);
    printf("Valor do produto: %.2f\n\n", listaProdutos->valorDoProduto);
}

/*---------------------------------------------------------*
| Módulo - Modulo alterar produto                          |
*---------------------------------------------------------*/
void alterarProduto(Produto *listaProdutos, int contadorProduto) {
    // Altera os dados de um produto existente
    int ID;
    printf("\nDigite o ID do produto que será alterado: ");
    scanf(" %d", &ID);
    for (int i = 0; i < contadorProduto; i++) {
        if (listaProdutos[i].ID == ID) {
            printf("\nDados atuais do produto:\n");
            imprimirDados(&listaProdutos[i]);

            int opcaoAlteracao;
            printf("\nO que você deseja alterar?\n");
            printf("1. Nome\n");
            printf("2. Quantidade em estoque\n");
            printf("3. Valor\n");
            printf("Digite a opção desejada (1/2/3): ");
            scanf(" %d", &opcaoAlteracao);

            // Alterações baseadas na escolha do usuário
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
| Módulo - Modulo consultar produto                        |
*---------------------------------------------------------*/
void consultarProduto(Produto *listaProdutos, int contadorProduto){
    // Verifica se não há produtos cadastrados na lista
    if(contadorProduto == 0) {
        printf("\nNao ha produtos cadastrados.\n\n");
        return; // Se não houver produtos, sai da função
    }

    int ID;
    // Solicita o ID do produto que o usuário deseja consultar
    printf("\nDigite o ID do produto que deseja consultar: ");
    scanf(" %d", &ID);

    // Loop para encontrar o produto pelo ID
    for(int i = 0; i < contadorProduto; i++){
        // Se o produto for encontrado, exibe os dados
        if(listaProdutos[i].ID == ID){
            imprimirDados(&listaProdutos[i]);
            return; // Se encontrado, a função é finalizada
        }
    }
    // Caso o produto não seja encontrado
    printf("Produto com o ID %d nao encontrado.\n\n", ID);
}


/*---------------------------------------------------------*
| Módulo - Modulo excluir produto                          |
*---------------------------------------------------------*/
void excluirProduto(Produto *listaProdutos, int *contadorProduto){
    // Verifica se não há produtos cadastrados na lista
    if(*contadorProduto == 0) {
        printf("\nNao ha produtos cadastrados.\n\n");
        return; // Se não houver produtos, sai da função
    }

    int ID;
    // Solicita o ID do produto que o usuário deseja excluir
    printf("\nDigite o ID do produto que deseja excluir: ");
    scanf(" %d", &ID);

    // Loop para encontrar o produto pelo ID
    for(int i = 0; i < *contadorProduto; i++){
        // Se o produto for encontrado, realiza a exclusão
        if(listaProdutos[i].ID == ID){
            // Move todos os produtos seguintes uma posição para a esquerda para "excluir" o produto
            for(int j = i; j < *contadorProduto - 1; j++){
                listaProdutos[j] = listaProdutos[j + 1];
            }
            (*contadorProduto)--; // Diminui o contador de produtos
            printf("Produto excluido com sucesso!\n\n");
            return; // A função é finalizada após excluir o produto
        }
    }
    // Caso o produto não seja encontrado
    printf("Produto com o ID %d nao encontrado.\n\n", ID);
}


/*---------------------------------------------------------*
| Módulo - Modulo vender produto                           |
*---------------------------------------------------------*/
void venderProduto(Produto *listaProdutos, int contadorProduto) {
    // Realiza a venda de um produto
    int ID, quantidade;
    
    // Solicita o ID do produto que o usuário deseja vender
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
    
    // Se o produto não existe
    if (!produtoExistente) {
        printf("Produto com o ID %d nao encontrado.\n\n", ID);
        return;
    }

    // Solicita a quantidade a ser vendida, se o produto existir
    printf("Digite a quantidade que será vendida: ");
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
| Módulo - Modulo desconto produto                         |
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
| Módulo - Modulo imprimir lista                           |
*---------------------------------------------------------*/
void imprimirLista(Produto *listaProdutos, int contadorProduto) {
    // Verifica se não há produtos cadastrados na lista
    if (contadorProduto == 0) {
        printf("\nNao ha produtos cadastrados.\n\n");
        return; // Se não houver produtos, sai da função
    }

    // Exibe o título da lista
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
| Módulo - Principal                                       |
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

