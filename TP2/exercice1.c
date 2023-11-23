#include <stdio.h>

void affiche_tableau(int tab[], int n){
  int i;
  int temp ;
  printf("[");
  printf("%d,",tab[0]);
  for (i=1;i<n-1;i++){
    printf(" %d,",tab[i]);
    temp=i;
  }
  printf(" %d]",tab[temp+1]);
  printf("\n");
}

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

int sassie_tab(int tableau[]){
  int temp = readInteger();
  int count =0;
  while (temp !=-1){
    tableau[count]= temp;
    count++;
    temp=readInteger();
  }
  return count;
}

int main (void){
  int my_list[100];
  int nombre_de_valeurs= sassie_tab(my_list);
  affiche_tableau(my_list, nombre_de_valeurs);
  return 0;
}

