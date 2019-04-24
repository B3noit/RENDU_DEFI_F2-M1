
#include "sprite.h"


/*****************************************
Principe : On demande le point d'origine d'une image et son chemin, que l'on affiche avec une texture.

Entr�e : La structure du jeu, une chaine pourle chemin avec un entier son num�ro de cellule,
         2 entiers pour son point d'origine et 2 entiers pour la laargeur et longueur.
.
Sortie : L'affichage de l'image.

Note :
*************************************/
void affichSpriteDecor(tGame *tGame, char cChemin[4][100], int nSprite, int nOrigineX, int nOrigineY, int nWidthSprite, int nLengthSprite)
{//VAR
    SDL_Rect rectangleDest;
    SDL_Rect rectangleSource;

    tGame->pSurface = NULL;
    tGame->pSurface = IMG_Load(cChemin[nSprite]);

    if(tGame->pSurface)
    {

        tGame->pTexture = NULL;
        tGame->pTexture = SDL_CreateTextureFromSurface(tGame->pRenderer,tGame->pSurface); // Pr�paration du sprite
        SDL_FreeSurface(tGame->pSurface); // Lib�ration de la ressource occup�e par le sprite

        if(tGame->pTexture)
        {
            rectangleSource.x=0;
            rectangleSource.y=0;
            rectangleSource.w=nWidthSprite;
            rectangleSource.h=nLengthSprite;

            SDL_QueryTexture(tGame->pTexture,NULL,NULL,NULL,NULL);

            //D�finition du rectangle dest pour dessiner Bitmap
            rectangleDest.x=nOrigineX;
            rectangleDest.y=nOrigineY;//debut y
            rectangleDest.w=rectangleSource.w; //Largeur
            rectangleDest.h=rectangleSource.h; //Hauteur

            SDL_RenderCopy(tGame->pRenderer, tGame->pTexture, &rectangleSource, &rectangleDest);

            SDL_DestroyTexture(tGame->pTexture);// Destruction de la texture, pour en lib�rer la m�moire.
        }
    }
}



/*****************************************
Principe : On demande le point d'origine d'une image et son chemin, que l'on affiche avec une texture.

Entr�e : La structure du jeu et la structure du sprite concern�.
.
Sortie : L'affichage de l'image.

Note :
*************************************/
void affichSprite(tGame *tGame, tSprite *tSprite)
{//VAR
    SDL_Rect rectangleDest;
    SDL_Rect rectangleSource;

    tGame->pSurface = NULL;
    tGame->pSurface = IMG_Load(tSprite->cChemin);

    if(tGame->pSurface)
    {

        tGame->pTexture = NULL;
        tGame->pTexture = SDL_CreateTextureFromSurface(tGame->pRenderer,tGame->pSurface); // Pr�paration du sprite
        SDL_FreeSurface(tGame->pSurface); // Lib�ration de la ressource occup�e par le sprite

        if(tGame->pTexture)
        {
            rectangleSource.x=0;
            rectangleSource.y=0;
            rectangleSource.w=tSprite->nWidthSprite;
            rectangleSource.h=tSprite->nLengthSprite;

            SDL_QueryTexture(tGame->pTexture,NULL,NULL,NULL,NULL);

            //D�finition du rectangle dest pour dessiner Bitmap
            rectangleDest.x=tSprite->nOrigineX;
            rectangleDest.y=tSprite->nOrigineY;//debut y
            rectangleDest.w=rectangleSource.w; //Largeur
            rectangleDest.h=rectangleSource.h; //Hauteur

            SDL_RenderCopy(tGame->pRenderer, tGame->pTexture, &rectangleSource, &rectangleDest);

            SDL_DestroyTexture(tGame->pTexture);// Destruction de la texture, pour en lib�rer la m�moire.
        }
    }
}


//////////////////////////GET ET SET
//POINT D'ORIGINE
/*****************************************
Principe : La fonction retourne l'abscisse du point d'origine de l'image.

Entr�e : la structure du sprite.
.
Sortie : l'abscisse du point d'origine de l'image.

Note :
*************************************/
int getSpriteOrigineX(tSprite *tSprite)
{
    return tSprite->nOrigineX;
}
/*****************************************
Principe : La procedure affecte une valeur �l'abscisse du point d'origine de l'image.

Entr�e : la structure du sprite et un entier.

Sortie : une nouvelle abscisse du point d'origine de l'image.

Note :
*************************************/
void setSpriteOrigineX(tSprite *tSprite, int nOrigineX)
{
    tSprite->nOrigineX = nOrigineX;
}
/*****************************************
Principe : La fonction retourne l'ordonn�e du point d'origine de l'image.

Entr�e : la structure du sprite.
.
Sortie : l'ordonn�e du point d'origine de l'image.

Note :
*************************************/
int getSpriteOrigineY(tSprite *tSprite)
{
    return tSprite->nOrigineY;
}
/*****************************************
Principe : La procedure affecte une valeur � l'ordonn�e du point d'origine de l'image.

Entr�e : la structure du sprite et un entier.

Sortie : une nouvelle ordonn�e du point d'origine de l'image.

Note :
*************************************/
void setSpriteOrigineY(tSprite *tSprite, int nOrigineY)
{
    tSprite->nOrigineY = nOrigineY;
}


//LARGEUR ET LONGEUR
/*****************************************
Principe : La fonction retourne la largeur de l'image.

Entr�e : la structure du sprite.
.
Sortie : la largeur de l'image.

Note :
*************************************/
int getSpriteWidth(tSprite *tSprite)
{
    return tSprite->nWidthSprite;
}
/*****************************************
Principe : La procedure affecte une valeur � la largeur de l'image.

Entr�e : la structure du sprite et un entier.

Sortie : une nouvelle largeur de l'image.

Note :
*************************************/
void setSpriteWidth(tSprite *tSprite, int nWidth)
{
    tSprite->nWidthSprite = nWidth;
}
/*****************************************
Principe : La fonction retourne la longueur de l'image.

Entr�e : la structure du sprite.
.
Sortie : la longueur de l'image.

Note :
*************************************/
int getSpriteLength(tSprite *tSprite)
{
    return tSprite->nLengthSprite;
}
/*****************************************
Principe : La procedure affecte une valeur � la longueur de l'image.

Entr�e : la structure du sprite et un entier.

Sortie : une nouvelle longueur de l'image.

Note :
*************************************/
void setSpriteLength(tSprite *tSprite, int nLength)
{
    tSprite->nLengthSprite = nLength;
}


//CHEMIN DE L'IMAGE
/*****************************************
Principe : La procedure affecte un nouveau chemin � l'image.

Entr�e : la structure du sprite et une cha�ne de caract�re.

Sortie : un nouveau chemin et donc une autre image.

Note :
*************************************/
void setSpriteChemin(tSprite *tSprite, char cChemin[100])
{
    strcpy(tSprite->cChemin, cChemin);
}


//LA "CLICKABILLITE"
/*****************************************
Principe : La fonction retourne l�tat du nClicked de l'image.

Entr�e : la structure du sprite.
.
Sortie : Le nClicked de l'image, 1 ou 0.

Note :
*************************************/
int getSpriteClicked(tSprite *tSprite)
{
    return tSprite->nClicked;
}
/*****************************************
Principe : La procedure affecte un nouvel �tat au nClicked de l'image.

Entr�e : la structure du sprite et un entier, soit 1 ou 0.

Sortie : un nouvel �tat de nClicked soit 1 ou 0

Note :
*************************************/
void setSpriteClicked(tSprite *tSprite, int nClicked)
{
    tSprite->nClicked = nClicked;
}

/*****************************************
Principe : La procedure affecte des valeurs � toutes les propri�t�s d'une structure Sprite.

Entr�e : la structure du sprite,5 entiers(coordonn�es du point d'origine, largeur et longueur, et le nClicked),et une chaine de caract�re

Sortie : De nouvelles valeurs pour toutes les propri�t�s de la structure.

Note : Cette proc�dure est aussi utile pour initialiser une image, donc on n'a pas de procedure "initSprite".
*************************************/
void setFullSprite(tSprite *tSprite, int nOrigineX, int nOrigineY, int nWidth, int nLength, char cChemin[100], int nClicked)
{
    setSpriteOrigineX(tSprite, nOrigineX);
    setSpriteOrigineY(tSprite, nOrigineY);
    setSpriteWidth(tSprite, nWidth);
    setSpriteLength(tSprite, nLength);
    setSpriteChemin(tSprite, cChemin);
    setSpriteClicked(tSprite, nClicked);
}

/*****************************************
Principe : La procedure affecte des valeurs aux coordonn�es du point d'origine de l'imagelui permettant ainsi de se d�placer.

Entr�e : la structure du sprite et 2 entiers(abscisse et ordonn�e).

Sortie : de nouvelle coordonn�es pour le point d'origine de l'image, donc une nouvelle position.

Note :
*************************************/
void moveSprite(tSprite *tSprite, int nOrigineX, int nOrigineY)
{
    setSpriteOrigineX(tSprite, nOrigineX);
    setSpriteOrigineY(tSprite, nOrigineY);
}
