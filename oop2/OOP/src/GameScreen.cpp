#include "GameScreen.h"

#include "Hero.h"
GameScreen::GameScreen(SDL_Event* e,SDL_Window* gWindow,SDL_Renderer* gRenderer,string Path,int width, int height,Hero* h,List<GameObjects*>* mainList)
{

    this->mainList = mainList;
    this->Background = new Sprites(gWindow,gRenderer,Path,1,0,0,600,600,width,height,"");
    ButtonsList[0] = new Button(gRenderer,gWindow,"Data\\Buttons\\Images\\Pause0.png",{10,10},{50,50});
    this->e = e;
    Enable = false;
    hero = h;
}


bool GameScreen::IsMoved()
{
return moved;
}

bool GameScreen::IsEnable()
{
    return Enable;
}


void GameScreen::setEnabled(bool e)
{
    Enable = e;
}



int GameScreen::getButtonPresed()
{
    int ButtonCount = -1;
    if (ButtonsList[0]->IsClicked(e))
    {
        ButtonCount = 0;


    }
    return ButtonCount;
}


void GameScreen::Render()
{
    if (hero->IsMoved() && !(mainList->HasTank))
    {
        moved = true;
        move(2);
    }
    else
        {
            moved= false;
        }
    this->Background->render();
    this->ButtonsList[0]->Render();
}

void GameScreen::move(int x)
{
    Background->moveSpriteArea(x);
}


Point GameScreen::getSize()
{
    return Size;
}


GameScreen::~GameScreen()
{
        delete Background;//SPRITE
        delete ButtonsList[0];//ARRAY
}
