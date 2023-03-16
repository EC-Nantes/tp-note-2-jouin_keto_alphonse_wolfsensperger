#ifndef CARTE_H
#define CARTE_H

/* includes */
#include <iostream>
#include <list> // classe list (conteneur)

#include "Plateau.h"
#include "Tortue.h"

using namespace std;

class Plateau;
class Tortue;

class Carte {
private:
  Tortue *tortue;
  Plateau *plateau; // lien vers le plateau

public:
  // constructeur :
  Carte();

  // accesseur en lecture :
  Tortue *getTortue(void) { return tortue; }
  Plateau *getPlateau(void) { return plateau; }

  // accesseur en écriture :
  void setTortue(Tortue *tortue) { this->tortue = tortue; }
  void setPlateau(Plateau *pPlateau);

  // méthodes virtuelles :
  virtual string getEffet(void) const;
  virtual void jouer(void);

  // surcharge opérateur << pour affichage :
  // friend std::ostream &operator<<(std::ostream &o, Carte const &Carte);
};

class CartePlusPlus : public Carte {
private:
  string effet = " avance de 2";

public:
  // constructeur :
  CartePlusPlus(void);

  // accesseur en lecture :
  string getEffet(void) { return effet; }

  // autres méthodes :
  void jouer(void);
};

class CartePlus : public Carte {
private:
  string effet = " avance de 1 case";

public:
  // constructeur :
  CartePlus(void);

  // accesseur en lecture :
  string getEffet(void) { return effet; }

  // autres méthodes :
  void jouer(void);
};

class CarteMoins : public Carte {
private:
  string effet = " recule de 1 case";

public:
  // constructeur :
  CarteMoins(void);

  // accesseur en lecture :
  string getEffet(void) { return effet; }

  // autres méthodes :
  void jouer(void);
};

class CarteHautHaut : public Carte {
private:
  string effet =
      "la dernière tortue avance de 2 cases, sil y en a plusieurs empilées le "
      "joueur choisi soit de les déplacer toutes soit celle de son choix";

public:
  // constructeur :
  CarteHautHaut(void);

  // accesseur en lecture :
  string getEffet(void) { return effet; }

  // autres méthodes :
  void jouer(void);
};

class CarteHaut : public Carte {
private:
  string effet =
      "la dernière tortue avance d'une case, s'il y en a plusieurs empilées le "
      "joueur choisi soit de les déplacer toutes soit celle de son choix";

public:
  // constructeur :
  CarteHaut();

  // accesseur en lecture :
  string getEffet(void) { return effet; }

  // autres méthodes :
  void jouer(void);
};
#endif
