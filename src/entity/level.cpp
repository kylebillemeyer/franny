#include <nlohmann/json.hpp>
#include "franny/entity/level.h"

using string = std::string;
using json = nlohmann::json;
using namespace franny::geo;

namespace franny::entity {

    Vec2 Level::getSpawnPoint() {
        return spawnPoint;
    }

    Vec2 Level::getFinishPoint() {
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