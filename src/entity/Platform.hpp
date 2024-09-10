//
// Created by Kyle Billemeyer on 8/31/24.
//

#ifndef PLATFORM_H
#define PLATFORM_H

#include <nlohmann/json.hpp>

#include "Entity.hpp"

using json = nlohmann::json;

using Eigen::Vector2d;

class Platform : public Entity {
protected:
    Vector2d dimensions;

public:
    explicit Platform(json &properties);

    Vector2d getDimensions();

    void init() override;

    void update() override;

    void draw() override;
};

#endif //PLATFORM_H
