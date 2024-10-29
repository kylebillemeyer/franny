//
// Created by Kyle Billemeyer on 10/27/24.
//

#include "geo/vec2.h"
#include "geo/point2.h"

#include <iostream>
#include <doctest/doctest.h>
#include <geo/math.h>

using namespace geo;

TEST_CASE("point") {
    SUBCASE("addition") {
        SUBCASE("with identity vector") {
            auto p = Point2(1, 2);
            CHECK((p == p + Vec2(0, 0)));
        }

        SUBCASE("with non-identity vector") {
            CHECK((Point2(1, 2) + Vec2(3, 4) == Point2(4, 6)));
        }
    }

    SUBCASE("subtraction") {
        SUBCASE("with identity vector") {
            auto p = Point2(1, 2);
            CHECK((p == p - Vec2(0, 0)));
        }

        SUBCASE("with non-identity vector") {
            CHECK((Point2(1, 2) - Vec2(3, 4) == Point2(-2, -2)));
        }
    }

    SUBCASE("multiplication") {
        SUBCASE("with identity factor") {
            auto p = Point2(1, 2);
            CHECK((p == p * 1));
        }

        SUBCASE("with non-identity factor") {
            CHECK((Point2(1, 2) * 2 == Point2(2, 4)));
        }
    }

    SUBCASE("division") {
        SUBCASE("with identity factor") {
            auto p = Point2(1, 2);
            CHECK((p == p * 1));
        }

        SUBCASE("with non-identity factor") {
            CHECK((Point2(1, 2) * 2 == Point2(2, 4)));
        }
    }

    SUBCASE("linear interpolation") {
        CHECK((Point2(0, 0).lerp(Point2(2, 2), .5) == Point2(1, 1)));
        CHECK((Point2(3, 5).lerp(Point2(7, 9), .25) == Point2(4, 6)));
    }
}
