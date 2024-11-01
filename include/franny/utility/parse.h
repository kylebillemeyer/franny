//
// Created by bille on 10/25/2024.
//

#ifndef PARSE_H
#define PARSE_H

#include <franny/geo/vec2.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace franny::geo;

namespace franny::utility {
    inline Vec2 parseVec2(json &root) {
        return Vec2(root.at(0).get<float>(), root.at(1).get<float>());
    }
}

#endif //PARSE_H
