#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define LIN 4
#define COL 12
#define STR 250

//FUNÇÕES
void calcula_amplitude(int v[LIN][COL]){
    int amplitude = 0;
     for (int j = 0;j < COL;j++){
        amplitude = v[2][j]-v[1][j];
        printf("Mes: %i \n", (j+1));
        printf("Amplitude Termica: %i °C\n\n", amplitude);
    }
}

void calcula_pluv(int v[LIN][COL]){
    float pluviometrica = 0;
    for (int j = 0;j < COL;j++){
      pluviometrica += v[3][j];  
    }
    pluviometrica /= 12;
    printf("Pluviometrica Anual: %f mm\n\n",pluviometrica);
}

void printstr(char s[STR]){
    for (int i = 0;i < STR;i++){
        printf("%c",s[i]);
    }
    printf("\n");
}

//Queria usar mas não funcionou
/*char mkreverse(char s[STR],char reverse[STR]){
    int contra = STR;
    for (int i = 0;i < STR;i++){
        contra--;
        reverse[i] = s[contra];
    }
    return reverse;
}*/

void palidromo(char s[STR],char reverse[STR]){

    int contra = STR;
    for (int i = 0;i < STR;i++){
        contra--;
        reverse[i] = s[contra];
    }
    printstr(reverse);

    //infelizmente acho que não está funcionando por causa do espaço entre as strings, 
    //tipo:
    //string = "ovo       "
    //reverse = "      ovo" 
    int sim = 0;
    for (int i = 0;i < STR;i++){
        if (reverse[i] == s[i]){
        sim = 1;
        }else
        printf("Nao e palidromo\n");
        break;
    }
    if (sim == 1){
        printf("E um palidromo\n");
    }
}


//CÓDIGO PRINCIPAL
int main(){
    //1 Questão
    int clima[LIN][COL] = {{1,2,3,4,5,6,7,8,9,10,11,12},
                        {26,22,21,19,16,14,13,0,16,17,19,21},
                        {50,28,27,25,23,21,21,20,22,24,25,27},
                        {294,262,213,125,111,109,92,91,152,160,166,195}};

    calcula_amplitude(clima);
    calcula_pluv(clima);

    //2 Questão
    char string[STR] = "ovo",reverse[STR];
    
    //QUE ÓDIO, eu não tenho ideia de como fazer scanf de uma string
    //scanf(" %c",string);
    printstr(string);
    palidromo(string,reverse);
    return 0;
    
}
