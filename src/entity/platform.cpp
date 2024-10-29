#include "entity/platform.h"

using json = nlohmann::json;

namespace entity {

    geo::Vec2 Platform::getDimensions() {
        return dimensions;
    }

    void Platform::init() {
        position = initialPosition;
    }

    void Platform::update() {
    }

    void Platform::draw() {
    }

}
