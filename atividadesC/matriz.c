#include <stdio.h>
#define L 5
#define C 4
int main(){
    int m[L][C],lin, col ;

    for ( lin = 0; lin < L; lin++){
        for ( col = 0 ; col < C; col++){
        scanf("%i" , &m[lin][col]);
        }
    }

    for ( lin=0; lin < L; lin++){
        for (col=0; col < C; col++){
            if ( m[lin][col] > 0) {
                printf(" %i", m[lin][col]);
            }
        }
    }

return 0;
}