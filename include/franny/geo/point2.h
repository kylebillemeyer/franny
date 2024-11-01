#ifndef POINT2_H
#define POINT2_H

#include <vector>
#include <sstream>
#include "franny/geo/vec2.h"

using namespace std;

using vec2_size_type = vector<float>::size_type;

namespace franny::geo {

    class Point2 {
    public:
        Point2(float x, float y);

        float getX() const;
        void setX(float x);
        float getY() const;
        void setY(float y);

        Point2 operator+(Vec2 v) const;
        Point2 operator-(Vec2 v) const;
        Vec2 operator-(Point2 p) const;
        Point2 operator*(float s) const;
        Point2 operator/(float s) const;
        Point2 lerp(Point2 v, float t) const;

        bool operator==(const Point2 & p) const;

        friend ostream& operator<<(ostream& os, const Point2& p) {
            os << "Point[ " << p.getX() << " " << p.getY() << " ]";
            return os;
        }

    private:
        float x;
        float y;

        Point2 add(Point2 p) const;
    };
}
#endif // POINT2_H