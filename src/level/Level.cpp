//
// Created by Kyle Billemeyer on 8/31/24.
//

#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Level.hpp"

using string = std::string;
using json = nlohmann::json;

Level::Level(const std::string & path) {
    std::ifstream f(path);
    json data = json::parse( f );

    json sp = data.at("spawnPoint");
    spawnPoint = Vector2d(sp.at(0), sp.at(1));

    json fp = data.at("finishPoint");
    finishPoint = Vector2d(fp.at(0), fp.at(1));

    entities = std::vector<Entity*>();
    for (json config : data.at("entityConfigs")) {
        string entityType = config.at("entityType").get<string>();
        json properties = config.at("properties");

        Entity *entity;
        if (entityType == "Platform") {
            entity = new Platform(properties);
        }

        entities.push_back(entity);
    }
}

Vector2d Level::getSpawnPoint() {
    return spawnPoint;
}

Vector2d Level::getFinishPoint() {
    return finishPoint;
}

std::vector<Entity*> Level::getEntities() {
    return entities;
}