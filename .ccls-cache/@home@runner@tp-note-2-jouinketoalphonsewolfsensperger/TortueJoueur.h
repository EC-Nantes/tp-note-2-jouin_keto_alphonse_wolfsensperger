#ifndef TORTUEJOUEUR_H
#define TORTUEJOUEUR_H

#include "Tortue.h"

class TortueJoueur : public Tortue {

public:
  TortueJoueur();

public:
  Carte Jouer(list<Carte> *pCartes);
};

#endif