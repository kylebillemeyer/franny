#ifndef LEVEL_H
#define LEVEL_H

#include "geo/vec2.h"
#include "entity/entity.h"
#include "entity/platform.h"
#include "utility/parse.h"

using json = nlohmann::json;

namespace entity {
    class Level : public Entity {
    protected:
        geo::Vec2 spawnPoint;
        geo::Vec2 finishPoint;

    public:
        Level(
            const string  name_,
            const geo::Vec2 initialPosition_,
            const geo::Vec2 spawnPoint_,
            const geo::Vec2 finishPoint_
        ):
            Entity(name_, initialPosition_),
            spawnPoint(spawnPoint_),
            finishPoint(finishPoint_) {}

        geo::Vec2 getSpawnPoint();
        geo::Vec2 getFinishPoint();

        void init() override;

        void update() override;

        void draw() override;

        static Level *fromJson(json &properties) {
            const auto name = properties.at("name").get<std::string>();

            const auto initialPosition = utility::parse::parseVec2(properties.at("initialPosition"));
            const auto spawnPoint = utility::parse::parseVec2(properties.at("spawnPoint"));
            const auto finishPoint = utility::parse::parseVec2(properties.at("finishPoint"));

            return new Level(name, initialPosition, spawnPoint, finishPoint);
        }
    };
}

#endif //LEVEL_H
