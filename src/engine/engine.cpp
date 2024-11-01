#include <fstream>

#include "franny/engine/engine.h"
#include "franny/utility/entity.h"

using namespace franny::entity;
using namespace franny::utility;

namespace franny::engine {
    Engine::Engine() = default;

    void Engine::load(std::string &rootEntityPath) {
        std::ifstream f("tmp/test.json");
        json data = json::parse( f );
        rootEntity = parseEntityJson(data);
    }

    void initHelp(Entity &entity) {
        return entity.init();
    }

    void Engine::init() {
        applyEntityTree(*rootEntity, initHelp);
    }

    void updateHelp(Entity &entity) {
        return entity.update();
    }
    void drawHelp(Entity &entity) {
        return entity.draw();
    }

    void Engine::run() {
        while (true) {
            applyEntityTree(*rootEntity, updateHelp);
            applyEntityTree(*rootEntity, drawHelp);
        }
    }

    void Engine::stop() {
        delete rootEntity;
    }

    Entity* Engine::getRootEntity() {
        return rootEntity;
    }
}
