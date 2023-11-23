#include <stdio.h>

void incremente(int *a) {
  (*a)++;
}

void echange(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int trier(int *a, int *b) {
  if (*a > *b) {
    echange(a, b);
    return 1;
  }
  return 0;
}

int main() {
  int num1 = 10;
  int num2 = 15;
  int result;
  printf("Before incrementing: %d\n", num1);
  incremente(&num1);
  printf("After incrementing: %d\n", num1);
 printf("Before swapping: %d, %d\n", num1, num2);
  echange(&num1, &num2);
  printf("After swapping: %d, %d\n", num1, num2);
  printf("Before sorting: %d, %d\n", num1, num2);
  result= trier(&num1, &num2);
  printf("After sorting: %d, %d\n", num1, num2);
  printf("Swap occurred: %s\n", result ? "Yes" : "No");

  return 0;
}
