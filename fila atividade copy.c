#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Elemento{
	char num[30];
	struct Elemento *prox;
};
typedef struct Elemento Elemento;

struct Fila{
    struct Elemento *inicio; 
    struct Elemento *fim; 
};
typedef struct Fila Fila;

Fila* cria_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
	
        fi->fim = NULL;
        fi->inicio = NULL;
    }
    return fi;
}					
Elemento *aux;	
void insere_elemento(Fila *fi){
	
	Elemento*novo =(Elemento*) malloc(sizeof(Elemento));
	printf("Digite o nome a ser inserido na fila: ");
	scanf("%s",&novo->num);
	novo->prox = NULL;
	
	if(fi->inicio == NULL){
		fi->inicio = novo;
		fi->fim = novo;
	
	}else{
		fi->fim->prox = novo;
		fi->fim = novo;
	}
	printf("\nNome inserido na fila!");

}		

void consulta_fila(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
		aux = fi->inicio;
		do{
			printf("| %s |", aux->num);
			aux = aux->prox;
		} while(aux != NULL);
	}
	
}			

void remove_elemento_fila(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
		aux = fi->inicio;
		printf("%s removido!", fi->inicio->num);
		fi->inicio = fi->inicio->prox;
		free(aux);
	}
}	
    
void esvazia_fila(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
		aux = fi->inicio;
		do{
			fi->inicio = fi->inicio->prox;
			free(aux);
			aux = fi->inicio;
		}while(aux != NULL);
		printf("\nFila Esvaziada!!");
	}
	
}		
		
int main(){
    Fila *fi = cria_fila();
	int opcao = 0;

	do{
		printf("Selecione a opção: \n\n");
		printf("[1] - Inserir (enqueue): \n");
		printf("[2] - Remover (dequeue): \n");
		printf("[3] - Listar: \n");
		printf("[4] - Limpa a fila: \n");
		printf("[-1] - Sair. \n");
		printf("Opção: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				insere_elemento(fi);
				break;
			case 2:
				remove_elemento_fila(fi);
				break;
			case 3:
				consulta_fila(fi);
				break;
			case 4:
				esvazia_fila(fi);
				break;
			default:
				printf("Opção inválida.");
		}

	}while(opcao != -1);

	return 0;
}





