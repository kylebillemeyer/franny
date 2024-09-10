//
// Created by Kyle Billemeyer on 8/31/24.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <Eigen/Dense>
#include <../external/nlohmann/json.hpp>

using Eigen::Vector2d;
using json = nlohmann::json;

class Entity
{
protected:
    std::string name;
    Vector2d position;
    Vector2d initialPosition;
    std::vector<Entity *> children;

public:
    explicit Entity(json &properties) {
        name = properties.at("name").get<std::string>();

        json ip = properties.at("initialPosition");
        initialPosition = Vector2d(ip.at(0), ip.at(1));
    }
    virtual ~Entity() = default;

    std::string getName() { return name; }
    Vector2d getPosition() { return position; }
    Vector2d getInitialPosition() { return initialPosition; }
    std::vector<Entity *> getChildren() { return children; }

    virtual void init() =0;
    virtual void update() =0;
    virtual void draw() =0;
};

#endif //ENTITY_H
