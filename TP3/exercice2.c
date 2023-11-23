#include <stdio.h>
#include <stdlib.h>
size_t longueur(const char *chaine) {
    size_t length = 0;

    while (chaine[length] != '\0') {
        length++;
    }
    return length;
}

char* copieChaine(const char *chaine) {

    size_t length = longueur(chaine);
    size_t i;
    char *copiedString = (char *)malloc((length + 1) * sizeof(char));

    for (i = 0; i <= length; i++) {
        copiedString[i] = chaine[i];
    }

    return copiedString;
}

void question1() {
    const char *testString = "Hello, World!";

    printf("Length of the string: %lu\n", (unsigned long)longueur(testString));
}

char* concatener(const char *chaine1, const char *chaine2) {

    char *copiedString1 = copieChaine(chaine1);
    size_t i;

    size_t length2 = longueur(chaine2);


    char *concatenatedString = (char *)realloc(copiedString1, (length2 + longueur(copiedString1) + 1) * sizeof(char));

    for (i = 0; i <= length2; i++) {
        concatenatedString[longueur(copiedString1) + i] = chaine2[i];
    }

    return concatenatedString;
}

void testConcatener() {
    const char *string1 = "Hello, ";
    const char *string2 = "World!";

    char *result = concatener(string1, string2);

    printf("Concatenated: %s\n", result);

    free(result);
}


void testCopieChaine() {
    const char *originalString = "Hello, World!";
    size_t originalLength = longueur(originalString);
    char *copiedString = copieChaine(originalString);
    printf("Original Length: %lu\n", (unsigned long)originalLength);
    printf("Original: %s\n", originalString);
    printf("Copied:   %s\n", copiedString);
    printf("Copied Length: %lu\n", (unsigned long)longueur(copiedString));

    free(copiedString);
}

int main() {

   /* testCopieChaine();*/
  testConcatener();


    return 0;
}
