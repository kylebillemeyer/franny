#include "geo/vec3.h"
#include "geo/math.h"

#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

namespace geo {
    
    Vec3::Vec3(float x, float y, float z) {
        this->setX(x);
        this->setY(y);
        this->setZ(z);
    }

    float Vec3::getX() const {
        return x;
    }

    void Vec3::setX(float x) {
        this->x = x;
    }

    float Vec3::getY() const {
        return y;
    }

    void Vec3::setY(float y) {
        this->y = y;
    }

    float Vec3::getZ() const {
        return z;
    }

    void Vec3::setZ(float z) {
        this->z = z;
    }

    float Vec3::dot(Vec3 v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    Vec3 Vec3::cross(Vec3 v) const {
        return Vec3(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }

    bool Vec3::operator==(const Vec3 & vec) const {
        return isClose(x, vec.x) && isClose(y, vec.y) && isClose(z, vec.z);
    }
}

