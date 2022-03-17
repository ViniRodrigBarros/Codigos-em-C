#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
int n;
int i,j;
int cont = 0;
scanf("%d",&n); 
int mat[n][n];

for(i=0; i<n;i++){
    cont=0;
        for(j=0; j<n;j++){
            cont++;
            mat[i][j]=cont;
        }  
    } 
 for(i=0; i<n;i++){
        printf("\n");
        for(j=0; j<n;j++){
            if(i==0){
                printf("%d ",mat[i][j]);
            }
            else if(i<=j){
                printf("%d ",mat[i][j]);
            }
            else{
                printf("  ");
            }
        }
    }    
    return 0;
}



