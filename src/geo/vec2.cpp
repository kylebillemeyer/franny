#include "geo/vec2.h"

#include <cmath>

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

    Vec2 Vec2::operator+(Vec2 v) const {
        return Vec2(x + v.x, y + v.y);
    }

    Vec2 Vec2::operator-(Vec2 v) const {
        return Vec2(x - v.x, y - v.y);
    }

    Vec2 Vec2::operator*(float s) const {
        return Vec2(x * s, y * s);
    }

    Vec2 Vec2::operator/(float s) const {
        return Vec2(x / s, y / s);
    }

    float Vec2::dot(Vec2 v) const {
        return x * v.x + y * v.y;
    }

    float Vec2::len() const {
        return sqrt(x * x + y * y);
    }

    Vec2 Vec2::norm() const {
        auto l = len();
        return Vec2(x / l, y / l);
    }

    Vec2 Vec2::lerp(Vec2 v, float t) const {
        return ((*this) * (1 - t)) + (v * t);
    }

    float Vec2::angle(Vec2 v) const {
        auto n = dot(v);
        auto d = len() * v.len();

        if (isClose(d, 0)) {
            throw invalid_argument("Angle between vectors can't be calculated when one vec is close to zero length");
        }

        return acos(n / d);
    }

    Vec2 Vec2::project(Vec2 v) const {
        auto s = dot(v) / pow(v.len(), 2);
        return v * s;
    }

    bool Vec2::operator==(const Vec2 &vec) const {
        return isClose(x, vec.x) && isClose(y, vec.y);
    }
}
