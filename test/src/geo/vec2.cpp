//
// Created by Kyle Billemeyer on 10/27/24.
//

#include "geo/vec2.h"

#include <iostream>
#include <doctest/doctest.h>
#include <geo/math.h>

using namespace geo;

TEST_CASE("vector") {
    SUBCASE("addition") {
        SUBCASE("with identity vector") {
            auto vec = Vec2(1, 2);
            CHECK(vec == vec + Vec2(0, 0));
        }

        SUBCASE("with non-identity vector") {
            CHECK(Vec2(1, 2) + Vec2(3, 4) == Vec2(4, 6));
        }
    }

    SUBCASE("subtraction") {
        SUBCASE("with identity vector") {
            auto vec = Vec2(1, 2);
            CHECK(vec == vec - Vec2(0, 0));
        }

        SUBCASE("with non-identity vector") {
            CHECK(Vec2(1, 2) - Vec2(3, 4) == Vec2(-2, -2));
        }
    }

    SUBCASE("multiplication") {
        SUBCASE("with identity factor") {
            auto vec = Vec2(1, 2);
            CHECK(vec == vec * 1);
        }

        SUBCASE("with non-identity factor") {
            CHECK(Vec2(1, 2) * 2 == Vec2(2, 4));
        }
    }

    SUBCASE("division") {
        SUBCASE("with identity factor") {
            auto vec = Vec2(1, 2);
            CHECK(vec == vec * 1);
        }

        SUBCASE("with non-identity factor") {
            CHECK(Vec2(1, 2) * 2 == Vec2(2, 4));
        }
    }

    SUBCASE("dot product") {
        CHECK(Vec2(1, 2).dot(Vec2(3, 4)) == 11);
    }

    SUBCASE("length") {
        CHECK(Vec2(1, 0).len() == 1);
        CHECK(isClose(Vec2(2, 2).len(), sqrt(8)));
    }

    SUBCASE("norm") {
        CHECK(Vec2(1, 0).norm() == Vec2(1, 0));
        CHECK(Vec2(3, 4).norm() == Vec2(3 / sqrt(25), 4 / sqrt(25)));
    }

    SUBCASE("linear interpolation") {
        CHECK(Vec2(0, 0).lerp(Vec2(2, 2), .5) == Vec2(1, 1));
        CHECK(Vec2(3, 5).lerp(Vec2(7, 9), .25) == Vec2(4, 6));
    }

    SUBCASE("angle between vectors") {
        CHECK(isClose(Vec2(1, 0).angle(Vec2(1, 0)), 0.0f));
        CHECK(isClose(Vec2(1, 0).angle(Vec2(0, 1)), M_PI / 2.0f));
        CHECK(isClose(Vec2(1, 0).angle(Vec2(-1, 0)), M_PI));
        CHECK(isClose(Vec2(1, 0).angle(Vec2(0, -1)), M_PI / 2.0f));
    }

    SUBCASE("project onto vector") {
        SUBCASE("vector onto itself") {
            CHECK(Vec2(3, 0).project(Vec2(3, 0)) == Vec2(3, 0));
        }

        SUBCASE("vectors forming acute angle") {
            CHECK(Vec2(3, 4).project(Vec2(4, 0)) == Vec2(3, 0));
        }

        SUBCASE("orthogonal vectors") {
            CHECK(Vec2(0, 1).project(Vec2(1, 0)) == Vec2(0, 0));
        }

        SUBCASE("vectors forming obtuse angle") {
            CHECK(Vec2(-3, 4).project(Vec2(1, 0)) == Vec2(-3, 0));
        }

        SUBCASE("opposite facing vectors") {
            CHECK(Vec2(-3, 0).project(Vec2(3, 0)) == Vec2(-3, 0));
        }
    }
}
