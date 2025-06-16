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
    
    int sair = 0;

    printf(" _ )    \\ __ __|  \\    |     |  |    \\       \\ |    \\ \\ \\   /  \\    |   \n"); 
    printf(" _ \\   _ \\   |   _ \\   |     __ |   _ \\     .  |   _ \\ \\ \\ /  _ \\   |   \n"); 
    printf("___/ _/  _\\ _| _/  _\\ ____| _| _| _/  _\\   _|\\_| _/  _\\ \\_/ _/  _\\ ____|\n"); 
    printf("\n\n");
    printf("                                     # #  ( )                           \n");
    printf("                                  ___#_#___|__                          \n");
    printf("                              _  |____________|  _                      \n");
    printf("                       _=====| | |            | | |==== _               \n");
    printf("                 =====| |.---------------------------. | |====          \n");
    printf("   <--------------------'   .  .  .  .  .  .  .  .   '--------------/   \n");
    printf("     \\                                                             /   \n");
    printf("      \\___________________________________________________________/    \n");
    printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
    printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n\n");

    printf("Insira qualquer tecla para jogar ou '1' para sair\n");
    scanf("%i", &sair);

    system("clear");
    system("cls");

    if (sair == 1){
        exit(0);
    }

    jogar(&jogador1, &jogador2);

    return 0;

}