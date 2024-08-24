#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                                   *
*-----------------------------------------------------------------------------------*
* Objetivo do Programa: Programa em C para receber as notas praticando vetores      *
* Data - 23/08/2024                                                                 * 
* Autor: Kauan Torres                                                               *
*-----------------------------------------------------------------------------------*/

float processoNotas(float *notas, int Nnotas, const char *bateria) { //Função para processar as notas, excluindo as notas dos extremos, somando as centrais.
	
	float soma = 0.0;	
    if (Nnotas > 0) {
    	
        // Maior e menor nota
        float maior = notas[0];
        float menor = notas[0];
        int maiorExcluded = 0;
        int menorExcluded = 0;
        int x = 0;
        
        for (x = 1; x < Nnotas; x++) {
            if (notas[x] > maior) {
            	maior = notas[x];
			}
            if (notas[x] < menor) {
            	menor = notas[x];
			}
        }
	
	    // Criar um novo array para armazenar as notas centrais
	    float *newArray = (float *)malloc(Nnotas * sizeof(float));
	
	    // Adicionar notas ao novo array se não forem a maior ou a menor
	    int newTamanho = 0;
	    for ( x = 0; x < Nnotas; x++) {
            if (notas[x] == maior && maiorExcluded == 0) { //Verificação para verificar apenas UMA maior nota, e UMA menor nota. 
                maiorExcluded = 1; 
            } else if (notas[x] == menor && menorExcluded == 0) {
                menorExcluded = 1; 
            } else {
                newArray[newTamanho++] = notas[x];
            }
        }
	
	    // Somar as notas centrais
	    if (newTamanho > 0) {
	        for ( x = 0; x < newTamanho; x++) {
	            soma += newArray[x];
	        }
	    }
        
	 	printf("Nota %s: %.1f\n", bateria, soma);
	 	
        // Liberar memória do novo Array
        free(newArray);
        
    } else {
        printf("Nenhuma nota informada para %s.\n", bateria);
      }
    
    return soma; //Retorna a nota final
    
}


int main() 
{

    int candidatos = 19; // Número de candidatos 19 pois começa com o candidato 0.
    int Nnotas, i = 0, x = 0;
    float *ntsraciocinio, *ntsprojetos, *ntsingles, *ntsmetodologia, *ntsjavascript; //Declaração dos vetores
    float finais[5];
    float notaFinal;
    char nomes[20][50];
    char c;

    //Alocação de mémoria dos vetores
    ntsraciocinio = (float *)malloc(100 * sizeof(float)); 
    ntsprojetos = (float *)malloc(100 * sizeof(float));  
    ntsingles = (float *)malloc(100 * sizeof(float));
	ntsmetodologia = (float *)malloc(100 * sizeof(float));
	ntsjavascript = (float *)malloc(100 * sizeof(float));     


	printf("\n\n======================================================================");
    printf("\n=================== BEM VINDO AO CALCULO DE NOTAS ====================");
    printf("\n======================================================================\n");

    for ( i = 0; i < candidatos; i++) { // For para percorrer todas as notas de cada candidato.
		
        // Candidato Geral
        printf("Digite o nome do candidato %i: \n", i); // Optei por poder colocar nome nos candidatos.
        scanf(" %[^\n]", nomes[i]);
        // Raciocínio Lógico - Quantidade de notas
        printf("Digite a quantidade de notas de Raciocinio Logico do candidato %i, (%s): \n", i, nomes[i]); //Mostrará o nome e o ID de cada candidato.
        while (1) { // Loop infinito 
            if (scanf("%d", &Nnotas) == 1) {  
            	if(Nnotas == 0){ //Caso seja 0, pule a bateria.
            		Nnotas = 0;
                    break;
				}
				if(Nnotas >= 3){ // Verificação se é maior ou igual a 3, pois o mínimo de notas são 3.
					while ((c = getchar()) != '\n' && c != EOF) {} //Limpeza do buffer de entrada
                	break;
	            } else {
		            	while ((c = getchar()) != '\n' && c != EOF) {} 
		                printf("Entrada invalida. Sao necessarias no minimo 3 notas. Digite novamente: ");
	                } 
			} else {
                while ((c = getchar()) != '\n' && c != EOF) {} 
                printf("Entrada invalida. Sao necessarias no minimo 3 notas. Digite novamente: ");
              }
    
		}
		printf("!!! As notas devem ser digitadas UMA por vez, digite uma nota e aperte enter, depois a proxima. Exemplo: 5 (enter) !!! \n");
		// Raciocínio Lógico - Notas
        if(Nnotas > 0){ //Verificação se a quantidade de notas é maior que 0.
        printf("Digite as notas de Raciocinio Logico do candidato %i, (%s): (Entre 0.0 a 10.0) \n", i, nomes[i]);	
		}
		
        for ( x = 0; x < Nnotas; x++) { //Percorrendo a quantidade de notas
            while (1) {
                if (scanf("%f", &ntsraciocinio[x]) == 1 && ntsraciocinio[x] >= 0.0 && ntsraciocinio[x] <= 10.0) { //Verificação, se é menor ou igual a 10, ou maior e igual a 0.
                    while ((c = getchar()) != '\n' && c != EOF) {} 
                    break;
                } else {
                    while ((c = getchar()) != '\n' && c != EOF) {} 
                    printf("Nota invalida. A nota deve estar entre 0.0 e 10.0. Digite novamente: ");
                  }
            }
        }
		
		//Processando notas
		finais[0] = processoNotas(ntsraciocinio, Nnotas, "Raciocinio Logico"); //Adiciona no Array medias, a media através da função de processo de notas.
        Nnotas = 0; // Retomando Nnotas para 0.
        
        // Conceitos de Gerenciamento de Projetos - Quantidade de notas
        printf("Digite a quantidade de notas de Conceitos de Gerenciamento de Projetos do candidato %i, (%s): \n", i, nomes[i]); 
        while (1) { 
            if (scanf("%d", &Nnotas) == 1) {  
            	if(Nnotas == 0){ 
            		Nnotas = 0;
                    break;
				}
				if(Nnotas >= 3){ 
					while ((c = getchar()) != '\n' && c != EOF) {} 
                	break;
	            } else {
	                while ((c = getchar()) != '\n' && c != EOF) {} 
	                printf("Entrada invalida. Sao necessarias no minimo 3 notas. Digite novamente: ");
	              } 
			} else {
                while ((c = getchar()) != '\n' && c != EOF) {} 
                printf("Entrada invalida. Sao necessarias no minimo 3 notas. Digite novamente: ");
              }
    
		}

		//Conceitos de Gerenciamento de Projetos - Notas
        if(Nnotas > 0){ 
        printf("Digite as notas de Conceitos de Gerenciamento de Projetos do candidato %i, (%s): (Entre 0.0 a 10.0) \n", i, nomes[i]);	
		}
		
        for (x = 0; x < Nnotas; x++) { 
            while (1) {
                if (scanf("%f", &ntsprojetos[x]) == 1 && ntsprojetos[x] >= 0.0 && ntsprojetos[x] <= 10.0) { 
                    while ((c = getchar()) != '\n' && c != EOF) {} 
                    break;
                } else {
                    while ((c = getchar()) != '\n' && c != EOF) {} 
                    printf("Nota invalida. A nota deve estar entre 0.0 e 10.0. Digite novamente: ");
                  }
            }
        }
		
		
		finais[1] = processoNotas(ntsprojetos, Nnotas, "Conceitos de Gerenciamento de Projetos"); 
        Nnotas = 0; 
        
        // Lingua Inglesa - Quantidade de notas
        printf("Digite a quantidade de notas de Lingua Inglesa do candidato %i, (%s): \n", i, nomes[i]); 
        while (1) { 
            if (scanf("%d", &Nnotas) == 1) {  
            	if(Nnotas == 0){ 
            		Nnotas = 0;
                    break;
				}
				if(Nnotas >= 3){ 
					while ((c = getchar()) != '\n' && c != EOF) {} 
                	break;
	            } else {
	                while ((c = getchar()) != '\n' && c != EOF) {} 
	                printf("Entrada invalida. Sao necessarias no minimo 3 notas. Digite novamente: ");
	              } 
			} else {
                while ((c = getchar()) != '\n' && c != EOF) {} 
                printf("Entrada invalida. Sao necessarias no minimo 3 notas. Digite novamente: ");
              }
    
		}

		//Lingua Inglesa - Notas
        if(Nnotas > 0){ 
        printf("Digite as notas de Lingua Inglesa do candidato %i, (%s): (Entre 0.0 a 10.0) \n", i, nomes[i]);	
		}
		
        for (x = 0; x < Nnotas; x++) { 
            while (1) {
                if (scanf("%f", &ntsingles[x]) == 1 && ntsingles[x] >= 0.0 && ntsingles[x] <= 10.0) { 
                    while ((c = getchar()) != '\n' && c != EOF) {} 
                    break;
                } else {
                    while ((c = getchar()) != '\n' && c != EOF) {} 
                    printf("Nota invalida. A nota deve estar entre 0.0 e 10.0. Digite novamente: ");
                  }
            }
        }
	
		finais[2] = processoNotas(ntsingles, Nnotas, "Lingua Inglesa");
        Nnotas = 0;
		
		// Conceitos de Metodologia Agil - Quantidade de notas
        printf("Digite a quantidade de notas de Conceitos de Metodologia Agil do candidato %i, (%s): \n", i, nomes[i]); 
        while (1) { 
            if (scanf("%d", &Nnotas) == 1) {  
            	if(Nnotas == 0){ 
            		Nnotas = 0;
                    break;
				}
				if(Nnotas >= 3){ 
					while ((c = getchar()) != '\n' && c != EOF) {} 
                	break;
	            } else {
	                while ((c = getchar()) != '\n' && c != EOF) {} 
	                printf("Entrada invalida. Sao necessarias no minimo 3 notas. Digite novamente: ");
	              } 
			} else {
                while ((c = getchar()) != '\n' && c != EOF) {} 
                printf("Entrada invalida. Sao necessarias no minimo 3 notas. Digite novamente: ");
              }
    
		}

		//Conceitos de Metodologia Agil - Notas
        if(Nnotas > 0){ 
        printf("Digite as notas de Conceitos de Metodologia Agil do candidato %i, (%s): (Entre 0.0 a 10.0) \n", i, nomes[i]);	
		}
		
        for (x = 0; x < Nnotas; x++) { 
            while (1) {
                if (scanf("%f", &ntsmetodologia[x]) == 1 && ntsmetodologia[x] >= 0.0 && ntsmetodologia[x] <= 10.0) { 
                    while ((c = getchar()) != '\n' && c != EOF) {} 
                    break;
                } else {
                    while ((c = getchar()) != '\n' && c != EOF) {} 
                    printf("Nota invalida. A nota deve estar entre 0.0 e 10.0. Digite novamente: ");
                  }
            }
        }
		
		
		finais[3] = processoNotas(ntsmetodologia, Nnotas, "Conceitos de Metodologia Agil");
        Nnotas = 0;
		
		// Linguagem Javascript - Quantidade de notas
        printf("Digite a quantidade de notas de Linguagem Javascript do candidato %i, (%s): \n", i, nomes[i]); 
        while (1) { 
            if (scanf("%d", &Nnotas) == 1) {  
            	if(Nnotas == 0){ 
            		Nnotas = 0;
                    break;
				}
				if(Nnotas >= 3){ 
					while ((c = getchar()) != '\n' && c != EOF) {} 
                	break;
	            } else {
	                while ((c = getchar()) != '\n' && c != EOF) {} 
	                printf("Entrada invalida. Sao necessarias no minimo 3 notas. Digite novamente: ");
	              } 
			} else {
                while ((c = getchar()) != '\n' && c != EOF) {} 
                printf("Entrada invalida. Sao necessarias no minimo 3 notas. Digite novamente: ");
              }
    
		}

		//Conceitos de Metodologia Agil - Notas
        if(Nnotas > 0){ 
        printf("Digite as notas de Linguagem Javascript do candidato %i, (%s): (Entre 0.0 a 10.0) \n", i, nomes[i]);	
		}
		
        for (x = 0; x < Nnotas; x++) { 
            while (1) {
                if (scanf("%f", &ntsjavascript[x]) == 1 && ntsjavascript[x] >= 0.0 && ntsjavascript[x] <= 10.0) { 
                    while ((c = getchar()) != '\n' && c != EOF) {} 
                    break;
                } else {
                    while ((c = getchar()) != '\n' && c != EOF) {} 
                    printf("Nota invalida. A nota deve estar entre 0.0 e 10.0. Digite novamente: ");
                  }
            }
        }
		
		finais[4] = processoNotas(ntsjavascript, Nnotas, "Linguagem Javascript");
        Nnotas = 0;
        
        //Exibir as saídas
        printf("Nota Raciocinio Logico=%.1f \n", finais[0]);
        printf("Nota Conceitos de gerenciamento de projetos=%.1f \n",finais[1]);
        printf("Nota Lingua Inglesa=%.1f \n",finais[2]);
        printf("Nota Conceitos de metodologia agil=%.1f \n",finais[3]);
        printf("Nota Linguagem Javascript=%.1f \n",finais[4]);
        
        //Soma das notas 
        float resultado = finais[0]+finais[1]+finais[2]+finais[3]+finais[4];
        
        printf("Nota final do candidato %i, (%s)=%2.f \n", i, nomes[i], resultado);
		  
	    //Limpar memória
	    free(ntsraciocinio);
	    free(ntsprojetos);
	    free(ntsingles);
	    free(ntsmetodologia);
	    free(ntsjavascript);
	    
	    //Realocar memória
	    ntsraciocinio = (float *)malloc(100 * sizeof(float));
	    ntsprojetos = (float *)malloc(100 * sizeof(float));
	    ntsingles = (float *)malloc(100 * sizeof(float));
	    ntsmetodologia = (float *)malloc(100 * sizeof(float));
	    ntsjavascript = (float *)malloc(100 * sizeof(float));
    }


    return 0;
}

