#include "geo/point2.h"

#include <cmath>

#include "utility/math.h"

#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;
using namespace utility;

namespace geo {
    Point2::Point2(float x, float y) {
        this->setX(x);
        this->setY(y);
    }

    float Point2::getX() const {
        return x;
    }

    void Point2::setX(float x) {
        this->x = x;
    }

    float Point2::getY() const {
        return y;
    }

    void Point2::setY(float y) {
        this->y = y;
    }

    Point2 Point2::operator+(Vec2 v) const {
        return Point2(x + v.getX(), y + v.getY());
    }

    Point2 Point2::operator-(Vec2 v) const {
        return Point2(x - v.getX(), y - v.getY());
    }

    Vec2 Point2::operator-(Point2 v) const {
        return Vec2(x - v.x, y - v.y);
    }

    Point2 Point2::operator*(float s) const {
        return Point2(x * s, y * s);
    }

    Point2 Point2::operator/(float s) const {
        return Point2(x / s, y / s);
    }

    Point2 Point2::lerp(Point2 p, float t) const {
        return ((*this) * (1 - t)).add(p * t);
    }

    bool Point2::operator==(const Point2 &p) const {
        return isClose(x, p.x) && isClose(y, p.y);
    }

    Point2 Point2::add(Point2 p) const {
      return Point2(x + p.x, y + p.y);
    }
}
