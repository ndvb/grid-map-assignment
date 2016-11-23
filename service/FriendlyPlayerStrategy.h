#pragma once

#include "PlayerStrategy.h"

class FriendlyPlayerStrategy : public PlayerStrategy {
    public:
        void move(GamePlayer* player);
        void attack(GamePlayer* player, GamePlayer* victim);
        void freeAction(GamePlayer* player);
        bool turn(GamePlayer* player, Map* map);


};
