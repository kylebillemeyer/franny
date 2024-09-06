//
// Created by Kyle Billemeyer on 9/5/24.
//

#include "Platform.hpp"

using json = nlohmann::json;

Platform::Platform(json properties) {
    json ip = properties.at("initialPosition");
    initialPosition = Vector2d(ip.at(0), ip.at(1));

    json d = properties.at("dimensions");
    dimensions = Vector2d(d.at(0), d.at(1));
}

Vector2d Platform::getDimensions() {
    return dimensions;
}

void Platform::init() {
    position = initialPosition;
}

void Platform::update() {
}

void Platform::draw() {
}
