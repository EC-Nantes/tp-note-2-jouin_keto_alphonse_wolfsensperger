// Nos bibliothèques

#include <iostream>
#include <stdio.h>
#include "MAE.h"

using namespace std;

int main() {
  cout << "-------------"
       << "TP 2 TORTUE (CORRECTION)--------"
       << "---------------------------------------------------------" << endl;
    MAE machine;

    for (int i = 0; i < 15; i++) 
    {
        machine.executeState();
        std::cout << "Tour " << i + 1 << std::endl;
         machine.executeState();
    }
  return 0;
}

// S'il y'a des templates faire que des .h