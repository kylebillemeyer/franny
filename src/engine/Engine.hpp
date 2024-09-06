//
// Created by Kyle Billemeyer on 8/31/24.
//

#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include <Eigen/Dense>
#include "../entity/Entity.hpp"
#include "../level/Level.hpp"

using Eigen::Vector2d;

class Engine
{
private:
    Level activeLevel;
    std::vector<Entity> entities;

public:
    Engine();

    Level getActiveLevel();
    std::vector<Entity> getEntities();

    void init();
    void loop();
    void addEntity();
};

#endif //ENGINE_H
