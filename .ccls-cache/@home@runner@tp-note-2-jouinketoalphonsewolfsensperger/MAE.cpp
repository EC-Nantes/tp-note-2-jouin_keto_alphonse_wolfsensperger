#include "MAE.h"
#include <iostream>
#include <cstdlib>

MAE::MAE() : currentState(State::INIT_STATE) {}

void MAE::setState(State newState) {
    currentState = newState;
}

void MAE::executeState() {
    switch (currentState) {
        case State::INIT_STATE:
            std::cout << "INIT_STATE" << std::endl;
            gen_turtle();
            attrib_carte();
            random_position();
            setState(State::GAME_STATE);
            break;
        case State::GAME_STATE:
            std::cout << "GAME_STATE" << std::endl;
            if (carte < 10) {
                int carte1 = rand() % 10 + 1;
                int carte2 = rand() % 10 + 1;
                jouer1(carte1);
                jouer2(carte2);
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

void MAE::gen_turtle() {
    std::cout << "Générer une tortue" << std::endl;
}

void MAE::attrib_carte() {
    carte = 1;
    std::cout << "Attribuer une carte" << std::endl;
}

void MAE::random_position() {
    std::cout << "Positionner la tortue sur un emplacement aléatoire" << std::endl;
}

void MAE::jouer1(int carte1) {
    std::cout << "Jouer la carte 1 : " << carte1 << std::endl;
}

void MAE::jouer2(int carte2) {
    std::cout << "Jouer la carte 2 : " << carte2 << std::endl;
    carte++;
}

void MAE::gagner() {
    std::cout << "Gagner le jeu !" << std::endl;
}
