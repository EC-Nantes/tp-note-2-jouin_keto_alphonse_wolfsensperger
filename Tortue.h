#ifndef TORTUE_H
#define TORTUE_H

#include "Carte.h"
#include <forward_list>
#include <iostream>
#include <list>

using namespace std;

class Carte;

class Tortue {

protected:
  list<Carte> cartes;

public:
  Tortue();
  virtual Carte Jouer(list<Carte> *pCartes);
  list<Carte> *GetCartes();
  void AfficheCartes() const;

protected:
  bool JouerCarte(Carte *pCarte);
};

#endif