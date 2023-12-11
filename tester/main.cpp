#include "Game/game.h"

using namespace GameTest;

int main()
{
    Game* game = new Game();
    
    if (game != nullptr)
    {
        game->Play();
        delete game;
    }

    return 0;
}