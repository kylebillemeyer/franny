#ifndef ENGINE_H
#define ENGINE_H

#include "franny/entity/entity.h"

using namespace franny::entity;

namespace franny::engine {
    class Engine
    {
        Entity* rootEntity = nullptr;


    public:
        Engine();

        Entity* getRootEntity();

        void load(std::string &rootEntityPath);
        void init();
        void run();
        void stop();
    };
}

#endif //ENGINE_H
