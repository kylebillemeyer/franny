//
// Created by Kyle Billemeyer on 8/31/24.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <Eigen/Dense>

using Eigen::Vector2d;

class Entity
{
protected:
    Vector2d position;
    Vector2d initialPosition;

public:
    virtual ~Entity() = default;

    Vector2d getPosition();
    Vector2d getInitialPosition();

    virtual void init() =0;
    virtual void update() =0;
    virtual void draw() =0;
};

#endif //ENTITY_H
