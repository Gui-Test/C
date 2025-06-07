#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "naval.h"

int main(){
    
    setlocale(LC_ALL,"pt_PT.UTF-8");
    srand(time(NULL));

    Jogador jogador1 = {0, 0, 0};
    Jogador jogador2 = {0, 0, 0}; 

    jogar(&jogador1, &jogador2);

    return 0;

}