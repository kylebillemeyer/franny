#include "franny/entity/platform.h"

using json = nlohmann::json;
using namespace franny::geo;

namespace franny::entity {

    Vec2 Platform::getDimensions() {
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
