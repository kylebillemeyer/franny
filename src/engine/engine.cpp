#include <fstream>

#include "engine/Engine.h"
#include "utility/entity.h"

using entity::Entity;

namespace engine {
    Engine::Engine() = default;

    void Engine::load(std::string &rootEntityPath) {
        std::ifstream f("tmp/test.json");
        json data = json::parse( f );
        rootEntity = utility::entity::parseEntityJson(data);
    }

    void initHelp(Entity &entity) {
        return entity.init();
    }

    void Engine::init() {
        utility::entity::applyEntityTree(*rootEntity, initHelp);
    }

    void updateHelp(Entity &entity) {
        return entity.update();
    }
    void drawHelp(Entity &entity) {
        return entity.draw();
    }

    void Engine::run() {
        while (true) {
            utility::entity::applyEntityTree(*rootEntity, updateHelp);
            utility::entity::applyEntityTree(*rootEntity, drawHelp);
        }
    }

    void Engine::stop() {
        delete rootEntity;
    }

    Entity* Engine::getRootEntity() {
        return rootEntity;
    }
}