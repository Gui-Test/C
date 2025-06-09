#include <stdio.h>
#include <math.h>

int main(){

  int idade ;    
  
   printf("Digite a idade:\n");
   scanf("%i",idade);
   if (idade >4) {
      if (idade>=5 && idade<=7) {
         scanf("Inf A");
      }else {
         if(idade>=8 && idade<=10) {
           scanf("Inf B");
         }else {
            if(idade>=11 && idade<=13){
               scanf("Juv A");
            }else{
               if(idade>=14 && idade<=17){
                  scanf("Juv B");
               }else{
                  scanf("Adulto");
               }
            }
         }
      }
   } else{
      scanf("Nao pode competir");
   }

}
