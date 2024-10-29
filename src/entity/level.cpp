#include <nlohmann/json.hpp>
#include "entity/level.h"

using string = std::string;
using json = nlohmann::json;

namespace entity {

    geo::Vec2 Level::getSpawnPoint() {
        return spawnPoint;
    }

    geo::Vec2 Level::getFinishPoint() {
        return finishPoint;
    }

    void Level::init() {
        position = initialPosition;
    }

    void Level::update() {
    }

    void Level::draw() {
    }

}