#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//CODIGO DE FILA COM CLONAGEM

typedef struct Elemento{
	int num;
	struct Elemento *prox;
} Elemento;


typedef struct Fila{
    struct Elemento *inicio; 
    struct Elemento *fim; 
    int num_elementos;
} Fila;

Fila* cria_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->fim = NULL;
        fi->inicio = NULL;
        fi->num_elementos=0;
    }
    return fi;
}

void enqueue(Fila *fi, int inf){
	Elemento *novoNo =(Elemento*) malloc(sizeof(Elemento));
	novoNo->num =inf;
	novoNo->prox = NULL;
	if(fi->inicio == NULL){
		fi->inicio = novoNo;
		fi->fim = novoNo;
    fi->num_elementos++;
	}else{
		fi->fim->prox = novoNo;
		fi->fim = novoNo;
    fi->num_elementos++;
	}
}		
	

void imprimir(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!\n");
	}else{
    Elemento *aux = fi->inicio;
    printf("|Primeiro|");
		while(aux != NULL){
			printf(" |%d| ", aux->num);
			aux = aux->prox;
		}
    printf("|Ultimo|");
	}
}	


int dequeue(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!\n");
    return -1;
	}else{
		Elemento *aux = fi->inicio;
    int r=aux->num;
		fi->inicio = fi->inicio->prox;
    fi->num_elementos--;
		free(aux);
    return r;
	}
}		

void esvazia_fila(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!\n");
	}else{
		Elemento *aux = fi->inicio;
		do{
			fi->inicio = fi->inicio->prox;
			free(aux);
			aux = fi->inicio;
		}while(aux != NULL);
		printf("\nFila Esvaziada!!\n");
	}
}	
void clonar_fila(Fila*fi,Fila*copia){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!\n");
	}else{
    	Elemento *aux = fi->inicio;
		while(aux != NULL){
			enqueue(copia,aux->num);
			aux = aux->prox;
		}
		printf("\nCopia realizada\n");
	}
}


int main() {
  Fila *fi = cria_fila();
  Fila *fi_copia = cria_fila();
  int opcao = 0;
  int numero;
    

	do{
		printf("\nSelecione a opção: \n");
		printf("[1] - Inserir (enqueue): \n");
		printf("[2] - Remover (dequeue): \n");
		printf("[3] - Listar: \n");
		printf("[4] - Limpa a fila: \n");
		printf("[5] - clonar a fila: \n");
		printf("[6] - mostrar a clone: \n");
		printf("Opção: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				printf("insira o numero");
				scanf("%d",&numero);
				enqueue(fi,numero);
				break;
			case 2:
				dequeue(fi);
				break;
			case 3:
				imprimir(fi);
				break;
			case 4:
			esvazia_fila(fi);
				break;
			case 5:
			clonar_fila(fi,fi_copia);
			case 6:
			imprimir(fi_copia);
				break;
			default:
				printf("\nOpção inválida.\n");
		}

	}while(opcao != -1);
	return 0;
}


