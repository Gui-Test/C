#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(int argc, char const *argv[]){
    int i,j, v[N] = {1,2,3,4,5,6,7,8,9,10};
    int rem;

    scanf("%d", &rem );

    for(i=0;i<N;i++){
        if(v[i] == rem){
            for(j=i;j<N-1;j++){
                v[j] = v[j+1];
            }
            break;
        }
    }

    for(i=0;i<N-1;i++){
        printf("%d ", v[i]);
    }

    return 0;
}


