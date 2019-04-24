
#include "introduction.h"

int introduction(tGame *Space)
{
//Creation de quelques couleurs SDL, normale qu'il y est des warnings si on ne les utilises pas.
SDL_Color black = {0,0,0,255}; //noire
SDL_Color white = {255,255,255,255}; //blanc
SDL_Color grey = {60,60,60,255}; //blanc
SDL_Color red = {255,0,0,255}; //rouge
SDL_Color green = {0,255,0,255}; //vert
SDL_Color blue = {0,0,255,255}; //bleu

//Tableau de caractère des chemins de nos images, CF le répertoire des images.
char cSprite[100][100]={"./Assets/Images/darkSpace.png","./Assets/Images/comptoirePrimo.png"};

tSprite Primo;//On déclare un sprite avec lequel le joueur peut interagir,
setFullSprite(&Primo, 900, 394, 416,416, cSprite[1], 0);//on l'initialise.

while(Space->nGameState==1)//Grosse boucle du jeu qui tourne tant que le joueur ne quitte pas.
{

    affichSpriteDecor(Space,cSprite,0,0,0,WINDOW_WIDTH,WINDOW_LENGTH);
    affichSprite(Space,&Primo);

    //On vérifie que le joueur joue et qu'il ne souhaite pas quitter la fenêtre.
    handleEvents(Space);

    testClicked(&Primo);
    if (Primo.nClicked == 1)
    {
        return 1;
    }


    //On affiche tout
    SDL_RenderPresent(Space->pRenderer);
    SDL_RenderClear(Space->pRenderer);//Ecoute, moi du futur, j'ai la solution pour le lag dégeulasse quand le tete est affiché, je cré une variable pour le SDL delay de mon render,
                                        //quand je veux afficher du texte il faut le mettent le nombre de tic voulu et bim pb règlé
}
return 0;
}
