#ifndef LINE2_H
#define LINE2_H
#include "franny/geo/point2.h"

namespace franny::geo {
    class Vec2;
    class Point2;

    /**
     *
     */
    class Line2 {
    public:
        Line2(Point2 p, Vec2 v, Vec2 norm);

        /**
        * Returns the orthogonal distance of point r to the line.
        */
        float distance(Point2 r) const;

        /**
        * Returns a point on the line that closest to point r (also known as the "foot" of point r). If point r is on
        * the line, the return vector will be equivalent to r.
        */
        Point2 closestPoint(Point2 r) const;

        /**
        * Returns true if the two lines intersect. TBD points
        */
        bool intersect(Line2 l, vector<Point2> &points) const;

        // Construct line that passes through two points.
        static Line2 fromPoints(const Point2 p1, const Point2 p2) {
            const auto v = p2 - p1;
            const auto norm = v.orthogonal();

            return Line2(p1, v, norm);
        }

        // Implicit definition using a point and a vector orthogonal to the line.
        static Line2 fromImplicit(const Point2 p, const Vec2 norm) {
            const auto v = norm.orthogonal() * -1;
            return Line2(p, v, norm);
        }

    private:
        // A point on the line. Used in both parameterized and implicit formulations of the line.
        Point2 p;

        // A vector pointing in the direction of the line, which is used for parameterized formulation of the line.
        Vec2 v;

        // A vector orthogonal to the line, which is used for the implicit formulation of the line.
        Vec2 norm;
    };
}

#endif //LINE2_H
