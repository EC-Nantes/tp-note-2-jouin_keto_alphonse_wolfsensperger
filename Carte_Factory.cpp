#include "Carte_Factory.h"

// On a des classes filles pour  chacun des effets
// Puis on utilise des constructeurs pour générer le deck

// YANIS : VOILA pour votre shuffle, enft shuffle peut mélanger que des vecteurs
// et pas des listes
template <typename T>
void shuffleDeck(std::list<T> &lst) // shuffle contents of a list
{
  // create a vector of (wrapped) references to elements in the list
  // http://en.cppreference.com/w/cpp/utility/functional/reference_wrapper
  std::vector<std::reference_wrapper<const T>> vec(lst.begin(), lst.end());

  // shuffle (the references in) the vector
  std::shuffle(vec.begin(), vec.end(), std::mt19937{std::random_device{}()});

  // copy the shuffled sequence into a new list
  std::list<T> shuffled_list{vec.begin(), vec.end()};

  // swap the old list with the shuffled list
  lst.swap(shuffled_list);
}

list<Carte> CarteFactory::gen_deck() {
  list<Carte> DeckYanis; // Pour que ça compile
  list<Carte> *Deck;
  for (int cpt = 0; cpt < 5; cpt++) {
    CartePlusPlus *carte_PlusPlus = new CartePlusPlus();
    // CartePlusPlus.setTortue(nullptr);
    Deck->push_back(*carte_PlusPlus);
  }
  for (int cpt = 0; cpt < 30; cpt++) {
    CartePlus *carte_Plus = new CartePlus();
    Deck->push_back(*carte_Plus);
  }

  for (int cpt = 0; cpt < 12; cpt++) {
    CarteMoins *carteMoins = new CarteMoins();
    Deck->push_back(*carteMoins);
  }

  for (int cpt = 0; cpt < 2; cpt++) {
    CarteHautHaut *carteHautHaut = new CarteHautHaut();
    Deck->push_back(*carteHautHaut);
  }

  for (int cpt = 0; cpt < 3; cpt++) {
    CarteHaut *carteHaut = new CarteHaut();
    Deck->push_back(*carteHaut);
  }
  // Puis on shuffle
  random_device rd;
  mt19937 g(rd());
  // shuffle(Deck->begin(), Deck->end(), g);
  shuffleDeck(DeckYanis);
  return *Deck;
}

void CarteFactory::attrib_carte(Tortue *tortue, list<Carte> *Deck) {
  // On attribue aussi les cartes
  list<Carte> *main;
  main = tortue->GetCartes();
  for (int i = 0; i < 5; i++) {
    main->splice(main->begin(), *Deck, Deck->begin(), next(Deck->begin(), 5));
  }
}

void CarteFactory::pioche(Tortue *tortue, list<Carte> *pioche) {
  // On attribue aussi les cartes
  /*
  Yanis : DECK OUT OF SCOPE
  pioche->splice(pioche->begin(), *Deck, Deck->begin(),next(Deck->begin(), 1));
  */
  // On ajoute l'élément en fin de liste
}