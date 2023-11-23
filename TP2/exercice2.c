#include <stdio.h>

struct horaire_struct{
  short heures;
  short minutes;
  short secondes;
};

typedef struct horaire_struct horaire;

horaire nouvel_horaire(short h, short m, short s){
  horaire new_time;
  new_time.heures=h;
  new_time.minutes=m;
  new_time.secondes=s;
  return new_time;
}


void afficher_horaire(horaire h) {
  printf("%dh %dm %ds\n", h.heures, h.minutes, h.secondes);
}


horaire ajout_horaire(horaire h1, horaire h2) {
  horaire result;
  int total_seconds = h1.secondes + h2.secondes + 60 * (h1.minutes + h2.minutes) + 3600 * (h1.heures + h2.heures);
  result.heures = total_seconds / 3600;
  result.minutes = (total_seconds % 3600) / 60;
  result.secondes = total_seconds % 60;

  return result;
}


horaire secondes_vers_horaire(int s) {
  horaire result;
  result.heures = s / 3600;
  result.minutes = (s % 3600) / 60;
  result.secondes = s % 60;

  return result;
}


int horaire_vers_secondes(horaire h) {
  int total_seconds = h.secondes + 60 * h.minutes + 3600 * h.heures;
  return total_seconds;
}


int main() {
  int secs=7385;
  horaire result= secondes_vers_horaire(secs);
  int result2=horaire_vers_secondes(result);
  afficher_horaire(result);
  printf("The seconds are equal to: %d",result2);
  return 0;
}
