#include <stdio.h>
#include <stdlib.h>
int main(){
//percorrendo e prenchendo uma matriz
    int mat[3][3];
    int i,j;
    for(i=0; i<3;i++){
        for(j=0; j<3;j++){
            printf("digite o valor de mat[%d][%d]:",i,j);
            scanf("%d",&mat[i][j]);
        }  
    }
//printando uma matriz
    for(i=0; i<3;i++){
        for(j=0; j<3;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
//diagonal
    printf("diagonal principal");
    for(i=0; i<3;i++){
        printf("\n");
        for(j=0; j<3;j++){
            if(i==j){
                printf("%d ",mat[i][j]);
            }
            else{
                printf(" ");
            }
        }
    }
    return 0;
}



