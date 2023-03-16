#ifndef CARTE_FACTORY_H
#define CARTE_FACTORY_H

/* includes */
#include "Carte.h"
#include "Tortue.h"
#include <algorithm>
#include <iostream>
#include <list> // classe list (conteneur)
#include <random>

using namespace std;

class CarteFactory {

private:
public:
  list<Carte> gen_deck();
  void attrib_carte(Tortue *tortue, list<Carte> *Deck);
  void pioche(Tortue *tortue, list<Carte> *main);
};
#endif
