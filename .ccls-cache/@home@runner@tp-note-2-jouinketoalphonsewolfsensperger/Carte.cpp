#include "Carte.h"

using namespace std;

// Constructeurs :
void CartePlusPlus::jouer(void) { getPlateau()->bougerTortue(getTortue(), +2); }

void CartePlus::jouer(void) {
  Tortue *tortue_sel = getTortue();
  if (getTortue() == NULL) { // si carte neutre
    // demander à l'utilisateur de choisir une tortue
    // tortue_sel = tortue choisie;
  }
  getPlateau()->bougerTortue(tortue_sel, +1);
}

void CarteMoins::jouer(void) {
  Tortue *tortue_sel = getTortue();
  if (getTortue() == NULL) { // si carte neutre
    // demander à l'utilisateur de choisir une tortue
    // tortue_sel = tortue choisie;
  }
  getPlateau()->bougerTortue(tortue_sel, -1);
}

void CarteHautHaut::jouer(void) {
  Tortue *tortue_sel = getTortue();
  if (getTortue() == NULL) { // si carte neutre
    list<Tortue> tortues = getPlateau()->getDernieresTortues();
    // demander à l'utilisateur de choisir une tortue parmi les tortues de la
    // liste chainnée de tortues tortue_sel = tortue choisie;
  }
  getPlateau()->bougerTortue(tortue_sel, +2);
}

void CarteHaut::jouer(void) {
  Tortue *tortue_sel = getTortue();
  if (getTortue() == NULL) { // si carte neutre
    list<Tortue> tortues = getPlateau()->getDernieresTortues();
    // demander à l'utilisateur de choisir une tortue parmi les tortues de la
    // liste chainnée de tortues tortue_sel = tortue choisie;
  }
  getPlateau()->bougerTortue(tortue_sel, +1);
}

// Surcharge opérateur << pour affichage :

/*
std::ostream &operator<<(std::ostream &o, Carte &Carte) {
  o << Carte.getTortue() << Carte.getEffet() << endl;
  return o;
}
*/

void Carte::setPlateau(Plateau *pPlateau) { this->plateau = pPlateau; }

Carte::Carte() {}
