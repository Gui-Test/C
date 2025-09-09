#include <stdio.h> //biblioteca do C
#include "agt.h" //biblioteca local

int fatorial(int valor){
    int i,fat=1; 
    for( i= 1 ; i <= valor ; i++){
		fat = fat * i ;
}
return fat;
}