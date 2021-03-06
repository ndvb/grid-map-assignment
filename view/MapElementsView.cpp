#include "MapElementsView.h"
#include "../entity/GameElement.h"
#include "../entity/GamePlayer.h"
#include "../entity/GameItem.h"
#include "../entity/repo/CharacterRepository.h"
#include "../entity/repo/ItemRepository.h"
#include "../controller/CharacterInteractionHelper.h"
#include "../controller/MapInteractionHelper.h"
#include "../service/Settings.h"

#include <vector>



using namespace std;

void MapElementsView::update() {
    summary();
}

void MapElementsView::summary() {
    if (!SETTINGS::MAP_ELEMENTS_VIEW && SETTINGS::IN_GAME) return;


    GamePlayer* gamePlayer;
    GameItem* gameItem;
    GameElement* gameElement;
    Character* character;
    Item* item;
    string strategyName;
    string locationString;
    string itemCollected;

    cout << "************ Map Elements Summary ************" << endl;
    if (SETTINGS::IN_GAME) {
        character = this->map->getUserGamePlayer()->getInGameCharacter();
        cout << "ME: " << character->getName() << " - HP: " << character->getHitPoints() << endl;
    }
    cout << "PLAYERS:" << endl;
    for(size_t i = 0; i < this->map->getGamePlayers()->size(); i++) {

        gameElement = this->map->getGamePlayers()->at(i);
        gamePlayer = static_cast<GamePlayer*>(gameElement);

        character = SETTINGS::IN_GAME?
                gamePlayer->getInGameCharacter():
                CharacterRepository::instance()->getEntity(gamePlayer->getElementReference());

        strategyName = CharacterInteractionHelper::getStrategyName(gamePlayer->getType());
        locationString = MapInteractionHelper::coordinateToString(gamePlayer->getLocation());

        cout << "    " << (i+1) << ". " << character->getName() << " - " << strategyName
            << " - " << locationString << " - HP: " <<  character->getHitPoints() << endl;
    }



    cout << "ITEMS:" << endl;
    for(size_t i = 0; i < this->map->getGameItems()->size(); i++) {

        gameElement = this->map->getGameItems()->at(i);
        gameItem = static_cast<GameItem*>(gameElement);
        item = ItemRepository::instance()->getEntity(gameItem->getElementReference());
        locationString = MapInteractionHelper::coordinateToString(gameItem->getLocation());
        itemCollected = gameItem->getCollected() ? "[Collected]" : "[Not Collected]";

        cout << "    " << (i+1) << ". " << gameItem->getElementReference() << " - " << itemCollected
            << " - " << locationString << endl;
    }
    cout << endl << endl;


}

void MapElementsView::details() {

}

