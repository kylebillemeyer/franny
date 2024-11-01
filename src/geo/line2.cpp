#include "franny/geo/line2.h"

#include <cmath>
#include <franny/utility/math.h>

using namespace franny::utility;

namespace franny::geo {
    Line2::Line2(Point2 p, Vec2 v, Vec2 norm): p(p), v(v), norm(norm) {}

    float Line2::distance(Point2 r) const {
        return norm.dot(r - p) / norm.len();
    }

    Point2 Line2::closestPoint(Point2 r) const {
        auto w = r - p;
        auto t = v.dot(w) / pow(v.len(), 2);

        return p + v * t;
    }

    bool Line2::intersect(Line2 l, vector<Point2> &points) const {
        // Refer to "A Geometry Toolbox" pg. 57 for derivation of this methodology

        // Use the dot product to get the angle between this line's normal vector and the other line's direction vector.
        auto cos_theta = norm.dot(l.v) / (norm.len() * v.len());

        // If cos_theta is close to zero then theta is ~90 degrees, meaning the two lines are parallel.
        if (isClose(cos_theta, 0)) {
            // If the other lines starting point is on this line, then the two lines overlap.
            auto d = distance(l.p);
            if (!isClose(d, 0)) {
                return false;
            }

            points = vector { p, l.p };
        } else {
            // Solve for the parameter t along the other line where the intersection occurs.
            auto c1 = norm.getX() * p.getX() + norm.getY() * p.getY();
            auto c2 = norm.getX() * l.p.getX() + norm.getY() * l.p.getY();
            auto t = (c1 - c2) / norm.dot(l.v);

            // Plug t into the other lines parameterized form
            auto p_inter = l.p + l.v * t;

            points = vector { p_inter };
        }
        return true;
    }
}
