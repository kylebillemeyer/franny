//
// Created by Kyle Billemeyer on 8/31/24.
//

#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "../entity/Entity.hpp"
#include "../entity/Platform.hpp"

using Eigen::Vector2d;
using json = nlohmann::json;

class Level
{
    Vector2d spawnPoint;
    Vector2d finishPoint;
    std::vector<Entity*> entities;

public:
    explicit Level(const std::string & path);

    Vector2d getSpawnPoint();
    Vector2d getFinishPoint();
    std::vector<Entity*> getEntities();
};

#endif //LEVEL_H
