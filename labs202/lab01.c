#include <stdio.h>
#include <math.h>

//distancia euclideana para até 3 dimensões entre A(x,y,z) e B(x1,y1,z1)
float euclidean_3d(float x,float y,float z, float x1,float y1, float z1){
    float euclidean = 0;
    euclidean = sqrtf(powf(x-x1,2)+powf(y-y1,2)+powf(z-z1,2));
    return euclidean;
}

//Calcula quem chega primeiro em um buraco (x,y) dados um rato(xr,yr) e um gavião(xh,yh,zh)
char first_to_reach(int x, int y,float coord[]){
    char output = ' ';
    float xr = coord[0],yr=coord[1],xh=coord[2],yh=coord[3],zh=coord[4];

    float r_dist,h_dist;
    r_dist = euclidean_3d(x,y,0,xr,yr,0);
    h_dist = euclidean_3d(x,y,0,xh,yh,zh);

    output = (r_dist<=(h_dist/2))?'r':'h';

    return output;  
}


int main(){
    int n = 0;
    float coord[5];


    scanf("%d",&n);

    while(n>=0){

        scanf(" %f %f %f %f %f",&coord[0],&coord[1],&coord[2],&coord[3],&coord[4]);
        //printf("%f %f %f %f %f",coord[0],coord[1],coord[2],coord[3],coord[4]);//debug
        int ignore = 0;
        for(int i = 0;i<n;i++){
            //executa a comparação para cada buraco
            float x,y;
            scanf(" %f %f",&x,&y);
            if((first_to_reach(x,y,coord) == 'r') && (ignore==0)){
                printf("O rato pode escapar pelo buraco (%.3f,%.3f).\n",x,y);
                ignore = 1;
            }
        }
        ignore==0?printf("O rato nao pode escapar.\n"):0;
            
        scanf(" %d",&n);
        
        }




    return 0;   
    }



  
