#ifndef ENTITY_H
#define ENTITY_H

#include <nlohmann/json.hpp>
#include <utility>
#include "geo/vec2.h"

using json = nlohmann::json;

namespace entity {
    class Entity {
    protected:
        std::string name;
        geo::Vec2 position;
        geo::Vec2 initialPosition;
        std::vector<Entity *> children;

    public:
        explicit
        Entity(const string  name_, const geo::Vec2 initialPosition_):
            name(name_),
            position(initialPosition_),
            initialPosition(initialPosition_) {}

        virtual ~Entity() = default;

        std::string getName() { return name; }
        geo::Vec2 getPosition() const { return position; }
        geo::Vec2 getInitialPosition() const { return initialPosition; }
        std::vector<Entity *> getChildren() { return children; }

        virtual void init() =0;

        virtual void update() =0;

        virtual void draw() =0;
    };
}

#endif //ENTITY_H
