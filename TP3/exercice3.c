#include <stdio.h>
#include <stdlib.h>

typedef struct bulletin_struct {
    int *notes;
    int taille;
    int n;
} bulletin;

bulletin nouveau(int taille) {
    bulletin newBulletin;
    newBulletin.notes = (int *)malloc(taille * sizeof(int));
    newBulletin.taille = taille;
    newBulletin.n = 0;
    return newBulletin;
}

void liberer_memoire(bulletin b) {
    free(b.notes);
}

int ajout_simple_without_pointer(bulletin b, int note) {

    if (note < 0 || note > 20) return -1;

    if (b.n >= b.taille) return -2;

    b.notes[b.n] = note;
    b.n++;
    return 0;
}

int main() {
  bulletin studentGrades = nouveau(5);
  int result1 = ajout_simple_without_pointer(studentGrades, 15);

  int result2 = ajout_simple_without_pointer(studentGrades, 25);

  int result3 = ajout_simple_without_pointer(studentGrades, 18);

  int result4 = ajout_simple_without_pointer(studentGrades, 22);

  printf("New bulletin created with size %d\n", studentGrades.taille);
  printf("Add grade result: %d\n", result1);
  printf("Add invalid grade result: %d\n", result2);
  printf("Add grade result: %d\n", result3);
  printf("Add invalid grade result: %d\n", result4);
  liberer_memoire(studentGrades);

  return 0; return 0;
}
