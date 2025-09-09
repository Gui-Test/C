#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<time.h>


//int mapa (int map);
int main(){
int TAM = 7;

char tabuleiro [TAM][TAM];


int i, j;
char agua = 'o';
int mn=-1;


    
    printf("   1 2 3 4 5 6 7");
    for(i=0; i<TAM; i++){
        printf("\n %c", 'A' + i);
        for(j=0;j<TAM;j++){
            printf(" %c", '~');
        }
    }
    
    

    return 0;
}


//int mapa(){
//    int nm;
//
//    nm = rand() % 2;
//
//    if(nm=0){
//        return 0;
//    }else{ if(nm=1){
//        return 1;
//    }
//

//    }

//}