#include <stdio.h>
#include <stdlib.h>
void print_file(FILE *fichier){
char c;
while ( (c=getc(fichier)) != EOF) fputc(c,stdout);
}
int main(int argc, char* argv[]) {
int i;
FILE * fichiers;
char * nom_fichier;
if (argc==1) { /* argv[0] : nom du programme */
print_file(stdin); /* stdin : entrée standard */
} else {
for (i=1; i<argc; i++) {
nom_fichier = argv[i];
if ((fichier=fopen(nom_fichier,"r")) == NULL) {
fprintf(stderr,"Erreur lecture %s\n",nom_fichier);
exit(1);
}
print_file(fichier);
fclose(fichier);
}
}
return 0;
}
