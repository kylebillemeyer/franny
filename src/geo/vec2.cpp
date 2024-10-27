#include "geo/vec2.h"
#include "geo/math.h"

#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

namespace geo {
    
    Vec2::Vec2(float x, float y) {
        this->setX(x);
        this->setY(y);
    }

    float Vec2::getX() const {
        return x;
    }

    void Vec2::setX(float x) {
        this->x = x;
    }

    float Vec2::getY() const {
        return y;
    }

    void Vec2::setY(float y) {
        this->y = y;
    }

    float Vec2::dot(Vec2 v) const {
        return x * v.x + y * v.y;
    }

    bool Vec2::operator==(const Vec2 & vec) const {
        return isClose(x, vec.x) && isClose(y, vec.y);
    }
}

