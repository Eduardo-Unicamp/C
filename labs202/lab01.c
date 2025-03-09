#include <stdio.h>
#include <math.h>

//distancia euclideana para até 3 dimensões entre A(x,y,z) e B(x1,y1,z1)
double euclidean_3d(double x,double y,double z, double x1,double y1, double z1){
    double euclidean = 0;
    euclidean = sqrt(pow(x-x1,2)+pow(y-y1,2)+pow(z-z1,2));
    return euclidean;
}

//Calcula quem chega primeiro em um buraco (x,y) dados um rato(xr,yr) e um gavião(xh,yh,zh)
char first_to_reach(double x, double y,double coord[]){
    char output = ' ';
    double xr = coord[0],yr=coord[1],xh=coord[2],yh=coord[3],zh=coord[4];

    double r_dist,h_dist;
    r_dist = euclidean_3d(x,y,0,xr,yr,0);
    h_dist = euclidean_3d(x,y,0,xh,yh,zh);

    output = (r_dist<=(h_dist/2))?'r':'h';

    return output;  
}


int main(){
    int n = 0;
    double coord[5];


    scanf("%d",&n);

    while(n>=0){

        scanf(" %lf %lf %lf %lf %lf",&coord[0],&coord[1],&coord[2],&coord[3],&coord[4]);
        //printf("%lf %lf %lf %lf %lf",coord[0],coord[1],coord[2],coord[3],coord[4]);//debug
        int ignore = 0;
        for(int i = 0;i<n;i++){
            //executa a comparação para cada buraco
            double x,y;
            scanf(" %lf %lf",&x,&y);
            if((first_to_reach(x,y,coord) == 'r') && (ignore==0)){
                printf("O rato pode escapar pelo buraco (%.3lf,%.3lf).\n",x,y);
                ignore = 1;
            }
        }
        ignore==0?printf("O rato nao pode escapar.\n"):0;
            
        scanf(" %d",&n);
        
        }




    return 0;   
    }



  
