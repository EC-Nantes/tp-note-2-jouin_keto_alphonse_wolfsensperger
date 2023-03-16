#include "Plateau.h"

using namespace std;

// Constructeur :

Plateau::Plateau(list<Tortue> case_depart) { setCase(case_depart, 0); }

// Accesseur en lecture :

list<Tortue> Plateau::getDernieresTortues(void) {
  for (int i = 0; i < TAILLE_PLATEAU;
       i++) { // explorer chaque case du début à la fin
    return getCase(i);
    if (getCase(i).empty() ==
        false) { // à la première case contenant une ou des tortues
      break;     // cesser l'execution de la méthode
    }
  }
  return cases[0]; // YANIS : ATTENTION ICI, j'ai ajouté ça psk sinon il y avais
                   // pas de return à la fonction
} // donne la liste chainée de la case sur laquelle se trouvent les dernières
  // tortues

void Plateau::bougerTortue(Tortue *cible, int pMovement) {
  list<Tortue>::iterator it;
  int caseTortue = -1;

  caseTrouveTortue(cible, &caseTortue, &it);

  int move = caseTortue + pMovement;

  if (move >= TAILLE_PLATEAU - 1) {
    move = TAILLE_PLATEAU - 1;
  }

  if (caseTortue >= 0) {
    cases[move].splice(cases[move].end(), cases[caseTortue], it);
  }
}

int Plateau::caseTrouveTortue(Tortue *pTortue, int *pCase,
                              list<Tortue>::iterator *output) {
  list<Tortue>::iterator it;
  for (int i = 0; i < TAILLE_PLATEAU; i++) {
    for (it = cases[i].begin(); it != cases[i].end(); it++) {
      output = &it;
      *pCase = i;
    }
  }
  *pCase = -1;
  return 0;
}

// Surcharge opérateur << pour affichage :

std::ostream &operator<<(std::ostream &o, Carte &Carte) {
  o << Carte.getTortue() << Carte.getEffet() << endl;
  return o;
}