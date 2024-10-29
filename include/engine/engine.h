#ifndef ENGINE_H
#define ENGINE_H

#include "entity/entity.h"

using entity::Entity;

namespace engine {
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
