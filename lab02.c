#include <stdio.h>
#include <stdlib.h>



void imprimir_clientes(int lista[][2], int numero_de_elementos){//função para debug, apagar depois
    for(int i = 0;i<numero_de_elementos;i++){
        printf("Chegada: %d   tempo de atendimento: %d\n",lista[i][0],lista[i][1]);
    }
}

//função vai ser chamada em lista[i] e portanto é uma sublista
int momento_de_finalizacao(int sublista[2], int numero_de_elementos){
    int fin = 0;
    //finalização
    //primeiro fin é t+d
    //segundo fin é max(t,fin_do_anterior)+ d


    if(/*for o primeiro*/){
    fin = t+d;
    }else{
        fin = max(t,momento_de_finalizacao(lista[i-1],2));
    }


}






int espera_media(int lista[][2], int numero_de_elementos){

    //tempos de espera
    //primeiro elemento espera igual a 0
    //segundo espera = min(0,T - a hora de finalização do último)

}


int main(){
    //read inputs
    int c,n;

    scanf("%d %d",&c,&n);

    int lista_de_espera[n][2];


    for(int i = 0;i<n;i++){//adiciona elementos na lista de clientes(cada cliente dado por um array de 2 elementos)
        int t, d;
        scanf("%d %d", &t, &d);
        lista_de_espera[i][0] = t;
        lista_de_espera[i][1] = d;
    }

    //para 1 atendente
    
    





    //ideias
    //para cada cliente o tempo para finalizar o atendimento é o max(tempo de inicio, tempo de termino do ultimo) + tempo de execução da tarefa(d)
    //p/ cd cliente o tempo de espera é minimo(0,T menos a hora de finalização do último) pois se a diferença for menor que 0 n houve espera
    
    // tempo de espera medio =  soma dos tempos de espera/N

    //nº espera+10min --> itera sobre as esperas e procura maior que 10



    return 0;
}