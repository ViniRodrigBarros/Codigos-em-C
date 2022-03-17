
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Elemento{
	int num;
	struct Elemento *prox;
};
typedef struct Elemento Elemento;
struct Pilha{
    struct Elemento *topo; 
};
typedef struct Pilha Pilha;

Elemento *aux;
int numtop = 0;
Pilha* cria_pilha(){
   
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo = NULL;  
    }
    return pi;
}				
void insere_elemento(Pilha *pi){
	
	Elemento *novo =(Elemento*) malloc(sizeof(Elemento));
	printf("Digite o numero a ser inserido na pilha: ");
	scanf("%d",&novo->num);
	
	novo->prox = pi->topo;
	
	pi->topo = novo;
	printf("\nNumero inserido na pilha!");
    numtop++;
}		
	
void consulta_pilha(Pilha *pi){
	/*caso a pilha esteja vazia*/
	if(pi->topo == NULL){
		printf("\nPilha Vazia!!");
	/*caso a pilha não esteja vazia*/
	}else{
		aux = pi->topo;
		do{
			printf(" |%d| ", aux->num);
			aux = aux->prox;

		} while(aux != NULL);
	}
}		
void remove_elemento_pilha(Pilha *pi){
	 if(pi->topo ==  NULL){
		printf("\nPilha Vazia!!");
	} else{
		aux = pi->topo;
		printf("%d removido!\n", pi->topo->num);
		pi->topo = pi->topo->prox;
		free(aux);
	}
}
void remover_n(Pilha *pi){
    int n;
    int i;
    printf("Insira o N \n");
    scanf("%d", &n);
    if(pi->topo == NULL ||numtop < n){
		printf("\n Erro!!");
	}
    else{
        for(i=0; i<n;i++){
            aux = pi->topo;
		    printf("%d removido!", pi->topo->num);
		    pi->topo = pi->topo->prox;
		    free(aux);    
        }
}
}
void mostrar_topo(Pilha *pi){
    aux = pi->topo;
    printf("Topo:|%d|",aux->num);

}
int main(){
    Pilha *pi = cria_pilha();
	int opcao = 0;

	do{
		printf("\nSelecione a opção: \n\n");
		printf("[1] - Inserir (enqueue): \n");
		printf("[2] - Remover (dequeue): \n");
		printf("[3] - Listar: \n");
		printf("[4] - Desempilhar N: \n");
        printf("[5] - mostrar topo\n");
		printf("[-1] - Sair. \n");
		printf("Opção: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				insere_elemento(pi);
				break;
			case 2:
				remove_elemento_pilha(pi);
				break;
			case 3:
				consulta_pilha(pi);
				break;
			case 4:
				remover_n(pi);
				break;
            case 5:
                mostrar_topo(pi);
                break;
			default:
				printf("Opção inválida.");
		}

	}while(opcao != -1);

	return 0;
}

		