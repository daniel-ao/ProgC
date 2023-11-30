#include <stdio.h>
#include <stdlib.h>

int longueur (char s[]) {
  int i = 0;
  for (i = 0; s[i] != '\0'; i++);
  return i;
}
char *copieChaine (char s[]) {
  int i = 0;
  char *copie = malloc((longueur(s)+1) * sizeof(char));
  for (i = 0; s[i] != '\0'; i++) {
    copie[i] = s[i];
  }
  copie[i] = '\0';
  return copie;
}
void question1() {
  char *testString = "Hello, World!";

  printf("Length of the string: %d\n",longueur(testString));
}

char *concateneChaines (char s1[], char s2[]) {
  int i = 0;
  int j = 0;
  char *concat = malloc((longueur(s1) + longueur(s2) + 1) * sizeof(char));
  for (i = 0; s1[i] != '\0'; i++) {
    concat[i] = s1[i];
  }
  for (j = 0; s2[j] != '\0'; j++) {
    concat[i + j] = s2[j];
  }
  concat[i + j] = '\0';
  return concat;
}


void testConcatener() {
  char *string1 = "Hello, ";
  char *string2 = "World!";
  char *result = concateneChaines(string1, string2);
  printf("String 1: %s\n", string1);
  printf("String 2: %s\n", string2);
  printf("Concatenation of String 1 and String 2: %s\n", result);
  free(result);
}


void testCopieChaine() {
  char *originalString = "Hello, World!";
  int originalLength = longueur(originalString);
  char *copiedString = copieChaine(originalString);
  printf("Original Length: %lu\n", (unsigned long)originalLength);
  printf("Original: %s\n", originalString);
  printf("Copied:   %s\n", copiedString);
  printf("Copied Length: %lu\n", (unsigned long)longueur(copiedString));

  free(copiedString);
}

int main() {

  testCopieChaine();
  testConcatener();


  return 0;
}
