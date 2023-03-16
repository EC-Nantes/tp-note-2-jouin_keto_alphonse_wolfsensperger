#include "Tortue.h"

Tortue::Tortue() {
  // rien
}

void Tortue::AfficheCartes() const {
  int i = 0;
  cout << "Cartes du joueur :" << endl;
  for (auto const &carte : cartes) {
    cout << "[" << i << "] - " << endl;
    // cout << " - " << carte << endl;
  }
}

list<Carte> *Tortue::GetCartes() { return &cartes; }

/*bool Tortue::JouerCarte(Carte *pCarte) {
  list<Tortue>::iterator it;
  for (it = cartes.begin(); it < cartes.end(); it++) {
    if (it == pCarte) {
      pCarte->jouer();
      cartes.remove(*pCarte);
      return true;
    }
  }
}*/

bool Tortue::JouerCarte(Carte *pCarte) {
  for (auto it = cartes.begin(); it != cartes.end(); ++it) {
    if (&(*it) == pCarte) {
      pCarte->jouer();
      cartes.erase(it);
      return true;
    }
  }
  return false;
}
