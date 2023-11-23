#include <stdio.h>

void affiche(){
  int i;
  int count1 = 1;
  int count2 = 0;
  for (i=1;i<11;i++){
    while(count2<10){
      if (count1<10){
        printf(" %d   ",count1);
      }
      else if (count1<99){
        printf("%d   ",count1);
      }
      else {
        printf("%d  ",count1);
      }
      count1++;
      count2++;
    }
    printf("\n");
    count2=0;
  }
}
int main(void){
  affiche();
  return 0;
}
