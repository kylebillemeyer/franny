#ifndef PLATFORM_H
#define PLATFORM_H

#include <nlohmann/json.hpp>

#include "franny/entity/entity.h"
#include "franny/geo/vec2.h"
#include "franny/utility/parse.h"

using json = nlohmann::json;

namespace franny::entity {

    class Platform : public Entity {
    protected:
        geo::Vec2 dimensions;

    public:
        Platform(
            const string  name_,
            const geo::Vec2 initialPosition_,
            const geo::Vec2 dimensions_
        ):
            Entity(name_, initialPosition_),
            dimensions(dimensions_) {}

        geo::Vec2 getDimensions();

        void init() override;

        void update() override;

        void draw() override;

        static Platform *fromJson(json &properties) {
            const auto name = properties.at("name").get<std::string>();
            const auto initialPosition = utility::parseVec2(properties.at("initialPosition"));
            const auto dimensions = utility::parseVec2(properties.at("dimensions"));

            return new Platform(name, initialPosition, dimensions);
        }
    };
}

#endif //PLATFORM_H
