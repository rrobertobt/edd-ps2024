#include <time.h>
#include <stdlib.h>

#include "Structures/Queue/Queue.h"
#include "MainGame.h"

using namespace std;

int main() {
    srand(time(0));
    MainGame mainGame;
    mainGame.startPlaying();
}
