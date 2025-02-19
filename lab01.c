#include <stdio.h>
#include <stdlib.h>


void imprimir_matriz(int **matriz,int n,int m){
    printf("impressao da matriz");
    for(int i = 0;i<n;i++){
        printf("\n");
        for(int j = 0;j<m;j++){
            printf(" %i",matriz[i][j]);
        }
    }
}

//Cria uma submatriz rxs a partir deo elemento (i,j) da matriz n x m passada
//i e j aqui sao as coordenadas do primeiro elemento da matriz em relação à matriz geral N x M e r e s sao as dimensoes da submatriz
int ** create_submatriz(int **matriz,int i, int j, int r, int s){
    //aloca submatriz dinamicamente
    int **submatriz = malloc(r*sizeof(int*));
    for(int x = 0;x<r;x++){
        submatriz[x] = malloc(s*sizeof(int));
    }


    int end_i,end_j;
    end_i = i+r;
    end_j = j+s;
    //valores inicias de i e j a nao serem alterados 
    int i0 = i;
    int j0 = j;

    for(i;i<end_i;i++){
        for(j=j0;j<end_j;j++){//se nao reinicializar o j quando for para o proximo loop de i ele nao vai estaer no valor inicial mais
                submatriz[i-i0][j-j0] = matriz[i][j];
        }
    }
    return submatriz;
    //dar freeeee
    for(int x = 0;x<r;x++){
        free(submatriz[x]);
    }
    free(submatriz);
}   

int calcular_soma(int **matriz, int n, int m){
   
    int soma = 0;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            soma+=(int)matriz[i][j];
        }
    }
    return soma;
}


int max_value(int * array,int size){
    int max = 0;

    for(int i=0;i<size;i++){
        max = (array[i]>max) ? array[i]:max;
    }
    return max;
}


int submatriz_soma_max(int **matriz,int r,int s,int n,int m){
     //indice pro começo e outro pro fim isso pra cada eixo
    int *lista_de_somas;
    lista_de_somas = malloc(10000*sizeof(int));
    int position = 0;//pro append improvisado


    for(int i=0;i<=n-r;i++){
        for(int j=0;j<=m-s;j++){
            //p cada (i,j) valido cria uma submatriz rxs a partir daquele ponto
            lista_de_somas[position] = calcular_soma(create_submatriz(matriz,i,j,r,s),r,s);
            position++;//append improvisado
            

        }
    }
    return max_value(lista_de_somas,position);
}



int main(){
    //ler valores de n,m,r,s 
    int n,m,r,s;
    scanf("%i %i %i %i",&n,&m,&r,&s);
    //alocar matriz dinamicamente
    int **matriz = malloc(1000 * sizeof(int *));
    for (int i = 0; i < 1000; i++) {
        matriz[i] = malloc(1000 * sizeof(int));
    }
    //ler matriz
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%i",&matriz[i][j]);

        }
        
    }

    //
    //print_submatriz(matriz,1,1,2,2);//a partir do elemento (1,1) - zero conta - imprimir uma matriz 2x2 - 0 nao conta

    int res = submatriz_soma_max(matriz,r,s,n,m);
    printf("%d",res);







    //
    for(int i = 0;i<1000;i++){
        free(matriz[i]);
    }
    free(matriz);
//LEMBRAR DE DAR FREE 
    return 0;
}