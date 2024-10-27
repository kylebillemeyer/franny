#include "geo/vec4.h"

#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

namespace geo {
    
    Vec4::Vec4(float x, float y, float z, float w /*=1.0F*/) {
        this->setX(x);
        this->setY(y);
        this->setZ(z);
        this->setW(w);
    }

    float Vec4::getX() const {
        return x;
    }

    void Vec4::setX(float x) {
        this->x = x;
    }

    float Vec4::getY() const {
        return y;
    }

    void Vec4::setY(float y) {
        this->y = y;
    }

    float Vec4::getZ() const {
        return z;
    }

    void Vec4::setZ(float z) {
        this->z = z;
    }

    float Vec4::getW() const {
        return w;
    }

    void Vec4::setW(float w) {
        this->w = w;
    }
}

