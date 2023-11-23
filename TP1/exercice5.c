#include <stdio.h>

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

void pyramide(n){
  int i;
  int j;
  int k;
  for(i=1;i<n+1;i++){
    for(j=0;j<n-i;j++){
      printf(" ");
    }
    for(k=0;k<i;k++){
      printf("* ");
    }
    printf("\n");
  }
}

int main (void){
  int temp = readInteger();
  while (temp>-1){
    pyramide(temp);
    temp=readInteger();
  }
  return 0;
}
