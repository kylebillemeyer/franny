//
// Created by Kyle Billemeyer on 10/27/24.
//

#include "geo/vec2.h"

#include <cmath>
#include <iostream>
#include <doctest/doctest.h>
#include <utility/math.h>
#include <geo/line2.h>

using namespace geo;
using namespace utility;

TEST_CASE("Line2") {
    SUBCASE("distance") {
        SUBCASE("to point on line") {
            auto line = Line2::fromPoints(Point2(0, 0), Point2(2, 2));
            CHECK((0 == line.distance(Point2(1, 1))));
        }

        SUBCASE("to point on 'right' of line") {
            auto line = Line2::fromPoints(Point2(0, 0), Point2(2, 2));
            auto d = line.distance(Point2(1, 0));
            CHECK(isClose(-sqrt(2) / 2, d));
        }

        SUBCASE("to point on 'left' of line") {
            auto line = Line2::fromPoints(Point2(0, 0), Point2(2, 2));
            auto d = line.distance(Point2(0, 1));
            CHECK(isClose(sqrt(2) / 2, d));
        }
    }

    SUBCASE("closest point (foot)") {
        SUBCASE("to point on line") {
            auto line = Line2::fromPoints(Point2(0, 0), Point2(2, 2));
            CHECK((Point2(1, 1) == line.closestPoint(Point2(1, 1))));
        }

        SUBCASE("to point on 'right' of line") {
            auto line = Line2::fromPoints(Point2(0, 0), Point2(2, 2));
            auto p = line.closestPoint(Point2(2, 0));
            CHECK((Point2(1, 1) == p));
        }

        SUBCASE("to point on 'left' of line") {
            auto line = Line2::fromPoints(Point2(0, 0), Point2(2, 2));
            auto p = line.closestPoint(Point2(0, 2));
            CHECK((Point2(1, 1) == p));
        }
    }

    SUBCASE("intersection with line") {
        SUBCASE("lines intersect at one point") {
            auto line1 = Line2::fromPoints(Point2(0, 0), Point2(2, 2));
            auto line2 = Line2::fromImplicit(Point2(1, 1), Vec2(2, 2));

            vector<Point2> points;
            auto doesIntersect = line1.intersect(line2, points);

            CHECK(doesIntersect);
            CHECK((points.size() == 1));
            CHECK((Point2(1, 1) == points[0]));
        }

        SUBCASE("lines intersect at no points (parellel)") {
            auto line1 = Line2::fromPoints(Point2(0, 0), Point2(2, 2));
            auto line2 = Line2::fromPoints(Point2(0, 1), Point2(2, 3));

            vector<Point2> points;
            auto doesIntersect = line1.intersect(line2, points);

            CHECK(!doesIntersect);
            CHECK((points.size() == 0));
        }

        SUBCASE("lines intersect at all points (overlap)") {
            auto line1 = Line2::fromPoints(Point2(0, 0), Point2(2, 2));
            auto line2 = Line2::fromPoints(Point2(1, 1), Point2(2, 2));

            vector<Point2> points;
            auto doesIntersect = line1.intersect(line2, points);

            CHECK(doesIntersect);
            CHECK((points.size() == 2));
            CHECK((Point2(0, 0) == points[0]));
            CHECK((Point2(1, 1) == points[1]));
        }
    }
}
