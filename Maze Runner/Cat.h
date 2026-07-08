#pragma once
#include "Character.h"
#include "Player.h"

class Cat : public Character
{
public:
    Cat(Map* level, std::string Icon, int x, int y);
    ~Cat();
    bool Update(Player* mouse);

private:
    enum Chances
    {
        move_chance = 25, //per direction so *4
        move_chance_towards_player = 7, //per direction so *4
    };
    Player* ptr_player = nullptr;
};

