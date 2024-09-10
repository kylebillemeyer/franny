#include <iostream>
#include <string>
#include <Eigen/Core>

#include "engine/Engine.hpp"
#include "utility/entity.hpp"

int main()
{
    auto *engine = new Engine();
    std::string path = "temp/test.json";
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
