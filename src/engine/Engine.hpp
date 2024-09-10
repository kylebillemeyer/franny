//
// Created by Kyle Billemeyer on 8/31/24.
//

#ifndef ENGINE_H
#define ENGINE_H
#include "../entity/Entity.hpp"

using Eigen::Vector2d;

class Engine
{
    Entity* rootEntity = nullptr;


public:
    Engine();

    Entity* getRootEntity();

    void load(std::string &rootEntityPath);
    void init();
    void run();
    void stop();
};

#endif //ENGINE_H
