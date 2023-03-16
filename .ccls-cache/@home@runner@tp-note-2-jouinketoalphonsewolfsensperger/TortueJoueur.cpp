#include "TortueJoueur.h"

TortueJoueur::TortueJoueur() : Tortue(){}

Carte TortueJoueur::Jouer(list<Carte> *pCartes) {
  int carte_choisie = -1;
  Carte carteJouee;

  cartes.splice(cartes.begin(), *pCartes);
  AfficheCartes();

  do {
    cout << "Quelle carte souhaitez-vous jouer ? : " << endl;
    cin >> carte_choisie;
  } while (carte_choisie < 0 || carte_choisie >= cartes.size());

  list<Carte>::iterator it = cartes.begin();
  advance(it, carte_choisie);
  carteJouee = *it;

  JouerCarte(&carteJouee);

  return carteJouee;
}