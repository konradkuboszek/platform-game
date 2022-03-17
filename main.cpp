#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
 
int main()
{
    
    //Init game
    Game game;
    //Game loop
    while (game.running())
    {
        //Update
        if (game.win == 1)
            game.whileWin();
       else if (game.alive == 1)
            game.update();
        else if(game.alive==0)
            game.whileDead();
        //Render
        

        game.render();

    }

    return 0;
}
