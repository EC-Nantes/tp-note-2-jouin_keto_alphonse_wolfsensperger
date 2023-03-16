#include "MAE.h"
#include "Carte_Factory.h"
#include "Tortue_Factory.h"
#include <cstdlib>
#include <iostream>

list<Tortue> *turtlelist;
list<Carte> *deck;

Tortue *Donatello = new Tortue();
Tortue *Michelangelo = new Tortue();
Tortue *Splintero = new Tortue();
Tortue *Leonardo = new Tortue();
Tortue *Raphaello = new Tortue();
MAE::MAE() : currentState(State::INIT_STATE) {}

void MAE::setState(State newState) { currentState = newState; }

void MAE::executeState() {
  TortueFactory tortueFactory;
  CarteFactory CarteFactory;
  *deck = CarteFactory.gen_deck();
  
  switch (currentState) {
    case State::INIT_STATE:
      std::cout << "INIT_STATE" << std::endl;
      *turtlelist = tortueFactory.gen_turtle();
  
      *Donatello = turtlelist->front();
      turtlelist->pop_front();
      CarteFactory.attrib_carte(Donatello,deck);
  
      *Raphaello = turtlelist->front();
      turtlelist->pop_front();
      CarteFactory.attrib_carte(Raphaello,deck);
  
      *Michelangelo = turtlelist->front();
      turtlelist->pop_front();
      CarteFactory.attrib_carte(Michelangelo,deck);
      
      *Leonardo = turtlelist->front();
      turtlelist->pop_front();
      CarteFactory.attrib_carte(Leonardo,deck);


      *Splintero = turtlelist->front();
      turtlelist->pop_front();
      CarteFactory.attrib_carte(Splintero,deck);
      setState(State::GAME_STATE);
      break;
    
    case State::GAME_STATE:
      std::cout << "GAME_STATE" << std::endl;
      if (int casePlateau = 0 < 10) {
        
        Raphaello->Jouer(Raphaello->GetCartes());        
        Leonardo->Jouer(Leonardo->GetCartes());
        Michelangelo->Jouer(Michelangelo->GetCartes());
        Donatello->Jouer(Donatello->GetCartes());
        Splintero->Jouer(Splintero->GetCartes());
      } else {
        setState(State::END_STATE);
      }
      break;
    case State::END_STATE:
      std::cout << "END_STATE" << std::endl;
      gagner();
      break;
    default:
      break;
  }
}

void MAE::gen_turtle() { std::cout << "Générer une tortue" << std::endl; }

void MAE::random_position() {
  std::cout << "Positionner la tortue sur un emplacement aléatoire"
            << std::endl;
}

void MAE::jouer1(int carte1) {
  std::cout << "Jouer la carte 1 : " << carte1 << std::endl;
}

void MAE::jouer2(int carte2) {
  std::cout << "Jouer la carte 2 : " << carte2 << std::endl;
  carte++;
}

void MAE::gagner() { std::cout << "Gagner le jeu !" << std::endl; }
