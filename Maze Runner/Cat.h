#pragma once
#include "Character.h"
#include "Player.h"

class Cat : public Character
{
public:
    Cat(Map* level, std::string Icon, int x, int y);
    ~Cat();
    void Update(Player* mouse);

private:
    enum Chances
    {
        move_chance = 20, //per direction so *4
        move_chance_towards_player = 5, //per direction so *4
    };
    Player* ptr_player = nullptr;
};

