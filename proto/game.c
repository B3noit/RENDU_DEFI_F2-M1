
#include "game.h"

/***********************
Principe L'�tat du jeu est initialis� � 1, il nous sert de bool�en, si l'utilisateur ferme la fen�tre il passe � 0.

Entr�e :L'�tat du jeu, tGame.nGameState .
.
Sortie : L'�tat du jeu.

Note :
**********************/
void handleEvents(tGame *tGame)
{
//VAR
SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
              tGame->nGameState=0;
              break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: tGame->nGameState=0; break;

                    default : break;
                }
                break;

        default : break;

        }
    }
}
