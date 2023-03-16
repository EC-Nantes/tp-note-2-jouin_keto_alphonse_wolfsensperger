#ifndef TORTUE_FACTORY_H
#define TORTUE_FACTORY_H

/* includes */

#include "TortueJoueur.h"
#include <iostream>
#include <list> // classe list (conteneur)

using namespace std;

class TortueFactory {
private:
public:
  list<Tortue> gen_turtle();
};
#endif
