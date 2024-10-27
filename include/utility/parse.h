//
// Created by bille on 10/25/2024.
//

#ifndef PARSE_H
#define PARSE_H

#include <geo/vec2.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace utility::parse {
    inline geo::Vec2 parseVec2(json &root) {
        return geo::Vec2(root.at(0).get<float>(), root.at(1).get<float>());
    }
}

#endif //PARSE_H
