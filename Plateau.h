#ifndef PLATEAU_H
#define PLATEAU_H

/* includes */
#include <iostream>
#include <list> // classe list (conteneur)

#include "Tortue.h"

#define TAILLE_PLATEAU 10

using namespace std;

class Tortue;

class Plateau {
private:
  list<Tortue> cases[TAILLE_PLATEAU]; // plateau de 10 cases
  // chaque case est une liste chainée contenant des Tortues

public:
  // constructeurs :
  Plateau(void);
  Plateau(list<Tortue> case_depart);

  // accesseurs en lecture :
  list<Tortue> getCase(int num_case) { return cases[num_case]; }
  list<Tortue>
  getDernieresTortues(void); // donne la liste chainée de la case sur laquelle
                             // se trouvent les dernières tortues

  // accesseurs en écriture :
  void setCase(list<Tortue> case_, int num_case) { cases[num_case] = case_; }

  // autres méthodes :
  void bougerTortue(Tortue *cible, int pMovement);
  int caseTrouveTortue(
      Tortue *pTortue, int *pCase,
      list<Tortue>::iterator *output); // retourne l'index de la case

  // surcharge opérateur << pour affichage :
  friend std::ostream &operator<<(std::ostream &o, Plateau const &Plateau);
};

#endif

// SPLICE !!!