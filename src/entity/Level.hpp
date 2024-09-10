//
// Created by Kyle Billemeyer on 8/31/24.
//

#ifndef LEVEL_H
#define LEVEL_H
#include "Entity.hpp"
#include "Platform.hpp"

using Eigen::Vector2d;
using json = nlohmann::json;

class Level : public Entity {
protected:
    Vector2d spawnPoint;
    Vector2d finishPoint;

public:
    explicit Level(json &properties);

    Vector2d getSpawnPoint();
    Vector2d getFinishPoint();

    void init() override;

    void update() override;

    void draw() override;
};

#endif //LEVEL_H
