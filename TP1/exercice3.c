#include <stdio.h>
/*
  void vide_buffer(){
  while(getchar()!='\n');
  }*/

void vider_buffer(){
  char c;
  while((c=getchar())!='\n'&&c!=EOF);
}

int readInteger() {

  int intValue = 0;
  int c;
  printf("entier> ");
  while ((c = getchar()) != '\n' && c != EOF) {
    if (c >= '0' && c <= '9') {
      intValue = intValue * 10 + (c - '0');
    }
    else {
      vider_buffer();
      return -1;
    }
  }
  return intValue;
}

void parite(){
  int temp = readInteger();
  if (temp!=-1){
    if(temp % 2 ==0){
      printf("L'entier %d est impair\n", temp);
    }
    else{
      printf("Ce n'est pas un entier\n");
    }
  }
  else{
    printf("L'entree ne correspond pas a un nombre \n");
  }
}

int moyenne_stdin(){
  int temp = readInteger();
  int count = 0;
  int sum  =0;
  int result;
  while (temp !=-1){
    if (temp>-1 && temp<21){
      count++;
      sum+= temp;
    }
    temp= readInteger();
  }
  result = sum/count;
  return result;
}

void div_euclid(){
  int a;
  int b;
  int division;
  int remainder;
  printf("Entrer le premiere entier \n");
  a= readInteger();
  printf("Entrer le deuxieme entier \n");
  b= readInteger();
  if (a!=-1 && b!=-1){
    if (b!=0){
      division= a/b;
      remainder= a%b;
      printf("Le resultat de le division euclid est: \n%d = %d * %d + %d \n", a,division,b,remainder );
    }
    else{
      printf("On peux pas divise par zero");
    }
  }

}
void div_euclid_decimal(){
  int a;
  int b;
  float division;
  printf("Entrer le premiere entier \n");
  a= readInteger();
  printf("Entrer le deuxieme entier \n");
  b= readInteger();
  if (a!=-1 && b!=-1){
    if (b!=0){
      division= (float)a/b;
      printf("Le resultat de le division euclid decimal est: \n%d = %.2f * %d \n", a,division,b );
    }
    else{
      printf("On peux pas divise par zero \n");
    }
  }
}

void division(){
  int a;
  int b;
  printf("Entrer le premiere entier \n");
  a= readInteger();
  printf("Entrer le deuxieme entier \n");
  b= readInteger();
  if (a!=-1 && b!=-1){
    if (b!=0){
      if (a%b==0){
        int division= a/b;
        printf("%d/%d = %d \n",a,b,division);
      }
      else{
        float division= (float)a/b;
        printf("%d/%d = %.2f \n",a,b,division);
      }
    }
    else{
      printf("On peux pas divise par zero \n");
    }
  }
}

int main(void) {
  /*printf("Le moyenne est %d \n", moyenne_stdin());*/
  division();
  return 0;
}
