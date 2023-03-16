#ifndef MAE_H
#define MAE_H

enum class State {
    INIT_STATE,
    GAME_STATE,
    END_STATE
};

class MAE {
public:
    void setState(State newState);
    void executeState();
    MAE ();
private:
    State currentState;
    int carte;

    void gen_turtle();
    void random_position();
    void jouer1(int carte1);
    void jouer2(int carte2);
    void gagner();
};

#endif
