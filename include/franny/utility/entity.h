//
// Created by Kyle Billemeyer on 9/8/24.
//

#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <stack>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "franny/entity/level.h"
#include "franny/entity/entity.h"
#include "franny/utility/string.h"

using json = nlohmann::json;
using namespace franny::entity;

namespace franny::utility {
    inline Entity *parseEntityJson(json &root) {
        auto children = root.at("children");

        std::vector<Entity *> entities;
        for (auto child: children) {
            auto entity = parseEntityJson(child);
            entities.push_back(entity);
        }

        const auto type = root.at("entityType").get<std::string>();
        auto properties = root.at("properties");

        Entity *entity = nullptr;
        if (type == "Level") {
            entity = Level::fromJson(properties);
        } else if (type == "Platform") {
            entity = Platform::fromJson(properties);
        }

        return entity;
    }

    inline void applyEntityTree(Entity &rootEntity, void (*func)(Entity &entity)) {
        std::stack<Entity*> stack;
        stack.push(&rootEntity);

        while (!stack.empty()) {
            auto entity = stack.top();
            stack.pop();

            func(*entity);

            auto children = entity->getChildren();
            for (auto child: children) {
                stack.push(child);
            }
        }
    }

    inline Entity *findEntityByPath(Entity &rootEntity, const std::string &path) {
        const std::vector<std::string> pathSegments = split(path, '/');

        Entity &parent = rootEntity;
        for (auto &pathSegment: pathSegments) {
            auto children = parent.getChildren();
            for (const auto &child: children) {
                if (child->getName() == pathSegment) {
                    parent = *child;
                    break;
                }
            }

            return nullptr;
        }

        return &parent;
    }
}

#endif //ENTITY_HPP
