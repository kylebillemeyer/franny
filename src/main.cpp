#include <iostream>
#include <Eigen/Core>

#include "level/Level.hpp"

int main()
{

    Level level = Level("tmp/test.json");

    Entity* entity = level.getEntities()[0];
    auto p = dynamic_cast<Platform*>(entity);
    std::cout << p->getDimensions() << std::endl;

    return 0;
}