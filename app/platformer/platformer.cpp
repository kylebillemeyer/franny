#include <iostream>
#include <string>

#include "engine/engine.h"
#include "utility/entity.h"

int main()
{
    auto *engine = new engine::Engine();
    std::string path = "tmp/test.json";
    engine->load(path);

    std::cout << engine->getRootEntity()->getName() << std::endl;
    const auto platform = utility::entity::findEntityByPath(*engine->getRootEntity(), "TestPlatform");
    std::cout << platform->getName() << std::endl;

    engine->init();
    engine->run();
    engine->stop();
    delete engine;

    return 0;
}
