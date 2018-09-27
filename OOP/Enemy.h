#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
#pragma once
#include"Character.h"

using namespace std;

class Enemy:public Character
{
public:
    Bullet Fire();
    void Move(int,int);
    void Reneder();
    void EventsController();
    void CollisionImpact(Gam    eObject* CollidedWith);

};
