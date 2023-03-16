#include "Tortue_Factory.h"
#include <iostream>

// On a des classes filles pour  chacun des effets
// Puis on utilise des constructeurs pour générer le deck

list<Tortue> TortueFactory::gen_turtle() {
  // YANIS : ATTENTION j'ai modifié pour avoir un return output pour pas avoir
  // d'erreur de compil mais jsp si c'est ce que vous vouliez faire.

  list<Tortue> output;

  for (int cpt = 0; cpt < 5; cpt++) {
    TortueJoueur tortue = TortueJoueur();  // YANIS : J'ai changé ça aussi
    output.push_back(tortue);
  }

  return output;
}