#include <stdio.h>


struct TableauDynamique {
    int *memoire;
    int taille;
    int n;

struct TableauDynamique *nouveauTableau(int taille) {
    struct TableauDynamique *nouveauTab = (struct TableauDynamique *)malloc(sizeof(struct TableauDynamique));

    nouveauTab->memoire = (int *)malloc(taille * sizeof(int));
    nouveauTab->taille = taille;
    nouveauTab->n = 0;


    return nouveauTab;
}

int main(void){

}
