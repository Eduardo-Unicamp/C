#include <stdio.h>

int main(){

    int n,f;
    char c;
//scanf: vai procurar termos entre parenteses separados por vigula, espaços são para consumir brancos(tabs,enter,space), le enquanto estiver lendo 3 entradas no formato especificado
        while(scanf(" ( %d , %d , %c ) ", &n,&f,&c)==3){
            printf("%4d |",n);//printf com n ocupando 4 casas (alinhado à direita, pra esquerda coloca -)
            for(int i=0;i<f;i++)
                printf("%c",c);
            printf(" %d\n",f);
        }


    return 0;
}