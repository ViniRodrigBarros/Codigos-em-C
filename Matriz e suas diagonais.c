#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
    int k;
    scanf("%d",&k);
    int mat[k][k];
    int i,j;
    int cont = 1;
     for(i=0; i<k;i++){
        for(j=0; j<k;j++){
            mat[i][j]=cont;
            cont++;
        }  
    }
    //printando uma matriz
    printf("Matriz:\n");
    for(i=0; i<k;i++){
        for(j=0; j<k;j++){
            printf(" %d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("Diagonal Principal:\n");
    for(i=0; i<3;i++){
        printf("\n");
        for(j=0; j<3;j++){
            if(i==j){
                printf(" %d ",mat[i][j]);
            }
            else{
                printf("  ");
            }
        }
    }
    printf("Diagonal Secundaria:\n");
    for(i=0; i<3;i++){
        printf("\n");
        for(j=0; j<3;j++){
            if((i+j)==(k-1)){
                printf(" %d ",mat[i][j]);
            }
            else{
                printf("  ");
            }
        }
    }
    return 0;
}



