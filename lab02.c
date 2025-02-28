#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (((a)>(b)) ? (a):(b))


void imprimir_clientes(int lista[][2], int numero_de_elementos){//função para debug, apagar depois
    for(int i = 0;i<numero_de_elementos;i++){
        printf("Chegada: %d   tempo de atendimento: %d\n",lista[i][0],lista[i][1]);
    }
}


//talvez usar struct ao inves de matriz


//ideia: criar uma nova lista igual a primiera mas incluido tambem o tempo de finalização, mas talvez seja desnecessario 



typedef struct{
    float mean;
    int waiting10;
}results;


results espera_media(int lista_de_espera[][2], int numero_de_elementos){
    int fin = 0;
    int espera = 0;

    int soma_esperas = 0;
    int maior10 = 0;

    //tempos de espera
    //primeiro elemento espera igual a 0
    //segundo espera = max(0, hora de finalização do último - T )
   
    for(int i = 0; i<numero_de_elementos;i++){
        int t = lista_de_espera[i][0];
        int d = lista_de_espera[i][1];
       

        if(i == 0/*for o primeiro*/){
            espera = 0;
            fin = t+d;
        }
        else{
            espera = max(0,fin - t);//espera = max(0, fin[anterior] - T )
            fin = max(t,fin)+d;//fin do atual
            
        }
        printf("\n%d %d %d\n",i,espera,fin);//debugging


        //soma de esperas pra media
        soma_esperas+=espera;
        //maior que 10 min
        maior10 = (espera>10) ? maior10+=1 : maior10;

    }
    //debugging
    printf("\ndebugging\n");
    
    printf("\n%d %d\n", soma_esperas,maior10);

    printf("\ndebugging\n");

    //pra poder retornar 2 valores
    results result;
    result.mean = (float)(soma_esperas/(float)numero_de_elementos);
    result.waiting10 = maior10;

    return result;

//ENTAO O NUMERO QUE ESPEROU MAIS QUE 10 TÁ CERTO MAS A MEDIA E A SOMA DE ESPERAS ESTAO AMBOS ERRADOS
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
    float mean;
    int waiting10;

    results result = espera_media(lista_de_espera,n);
    mean = result.mean;
    waiting10 = result.waiting10;

    //output
    printf("Espera media para %d clientes: %.1f minutos",n,mean);
    printf("Numero de clientes que esperaram mais que 10 minutos: %d",waiting10);



    //ideias
    //para cada cliente o tempo para finalizar o atendimento é o max(tempo de inicio, tempo de termino do ultimo) + tempo de execução da tarefa(d)
    //p/ cd cliente o tempo de espera é max(0,hora de finalização do último - T) pois se a diferença for menor que 0 n houve espera
    
    // tempo de espera medio =  soma dos tempos de espera/N

    //nº espera+10min --> itera sobre as esperas e procura maior que 10



    return 0;
}