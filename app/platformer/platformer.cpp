#include <iostream>
#include <string>

#include "franny/engine/engine.h"
#include "franny/utility/entity.h"

using namespace franny::engine;
using namespace franny::utility;

int main()
{
    auto *engine = new Engine();
    std::string path = "tmp/test.json";
    engine->load(path);

    std::cout << engine->getRootEntity()->getName() << std::endl;
    const auto platform = findEntityByPath(*engine->getRootEntity(), "TestPlatform");
    std::cout << platform->getName() << std::endl;

    engine->init();
    engine->run();
    engine->stop();
    delete engine;

    return 0;
}
