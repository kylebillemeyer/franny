//
// Created by Kyle Billemeyer on 8/31/24.
//

#include <../external/nlohmann/json.hpp>
#include "Level.hpp"

using string = std::string;
using json = nlohmann::json;

Level::Level(json &properties) : Entity(properties) {
    json sp = properties.at("spawnPoint");
    spawnPoint = Vector2d(sp.at(0), sp.at(1));

    json fp = properties.at("finishPoint");
    finishPoint = Vector2d(fp.at(0), fp.at(1));
}

Vector2d Level::getSpawnPoint() {
    return spawnPoint;
}

Vector2d Level::getFinishPoint() {
    return finishPoint;
}

void Level::init() {
    position = initialPosition;
}

void Level::update() {
}

void Level::draw() {
}