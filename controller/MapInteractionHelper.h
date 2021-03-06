#pragma once

#include "../entity/Map.h"
#include "../controller/ItemEditor.h"

class MapInteractionHelper {
    public:
        static Coordinate readMapLocation(Map* map, std::string message, std::string defaultLocation);
        static std::string readMapLocationWhileInGame(Map* map, std::string message, std::string defaultLocation);
        static Coordinate convertToCoordinate(Map* map, std::string location);
        static std::string coordinateToString(Coordinate* point);
        static std::string coordinateToString(Coordinate point);
        static Map* selectMap();
    private:
        MapInteractionHelper();


};
