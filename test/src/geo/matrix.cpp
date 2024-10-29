#include <string>
#include <iostream>

#include "doctest/doctest.h"
#include "geo/matrix.h"

#include <geo/vec2.h>

using namespace geo;

TEST_CASE("matrix") {
    SUBCASE("matrix multiplication") {
        SUBCASE("with identity matrix") {
            auto m1 = Matrix(3, 3);
            m1.setRow(0, vector<float>{1, 2, 3});
            m1.setRow(1, vector<float>{4, 5, 6});
            m1.setRow(2, vector<float>{7, 8, 9});

            auto m2 = Matrix::identity(3, 3);

            Matrix actual = m1.mult(m2);
            CHECK(actual == m1);

            actual = m2.mult(m1);
            CHECK(actual == m1);
        }

        SUBCASE("with two square matrices") {
            auto m1 = Matrix(2, 2);
            m1.setRow(0, vector<float>{3, 4});
            m1.setRow(1, vector<float>{1, 2});

            auto m2 = Matrix(2, 2);
            m2.setRow(0, vector<float>{6, 2});
            m2.setRow(1, vector<float>{3, 2});

            Matrix actual = m1.mult(m2);
            Matrix expected = Matrix(2, 2);
            expected.setRow(0, vector<float>{30, 14});
            expected.setRow(1, vector<float>{12, 6});
            CHECK(actual == expected);

            actual = m2.mult(m1);
            expected = Matrix(2, 2);
            expected.setRow(0, vector<float>{20, 28});
            expected.setRow(1, vector<float>{11, 16});
            CHECK(actual == expected);
        }

        SUBCASE("with two rectangular matrices") {
            auto m1 = Matrix(3, 2);
            m1.setRow(0, vector<float>{1, 2, 3});
            m1.setRow(1, vector<float>{4, 5, 6});

            auto m2 = Matrix(2, 3);
            m2.setRow(0, vector<float>{10, 11});
            m2.setRow(1, vector<float>{20, 21});
            m2.setRow(2, vector<float>{30, 31});

            auto actual = m1.mult(m2);
            auto expected = Matrix(2, 2);
            expected.setRow(0, vector<float>{140, 146});
            expected.setRow(1, vector<float>{320, 335});
            CHECK(actual == expected);
        }

        SUBCASE("with matrices of incompatible sizes") {
            auto m1 = Matrix(2, 2);
            m1.setRow(0, vector<float>{3, 4});
            m1.setRow(1, vector<float>{1, 2});

            auto m2 = Matrix(4, 4);
            m2.setRow(0, vector<float>{6, 2, 4, 9});
            m2.setRow(1, vector<float>{3, 2, 1, 3});
            m2.setRow(1, vector<float>{3, 2, 1, 3});
            m2.setRow(1, vector<float>{3, 2, 1, 3});

            CHECK_THROWS_AS(m1.mult(m2), std::invalid_argument&);
        }
    }

    SUBCASE("Vec2 multiplication") {
        SUBCASE("with identity translation") {
            auto m = Matrix::translation(0, 0, 0);
            auto v = Vec2(1, 2);

            auto actual = m.mult(v);

            CHECK(actual == v);
        }

        SUBCASE("with non-identity translation") {
            auto m = Matrix::translation(1, 2, 0);
            auto v = Vec2(1, 2);

            auto actual = m.mult(v);
            auto expected = Vec2(2, 4);

            CHECK(actual == expected);
        }

        SUBCASE("with identity scaling") {
            auto m = Matrix::scale(1, 1, 0);
            auto v = Vec2(1, 2);

            auto actual = m.mult(v);

            CHECK(actual == v);
        }

        SUBCASE("with non-identity scaling") {
            auto m = Matrix::scale(2, 2, 0);
            auto v = Vec2(1, 2);

            auto actual = m.mult(v);
            auto expected = Vec2(2, 4);

            CHECK(actual == expected);
        }

        SUBCASE("with identity z-rotation") {
            auto m = Matrix::rotZ(0.0F);
            auto v = Vec2(1, 1);

            auto actual = m.mult(v);

            CHECK(actual == v);
        }

        SUBCASE("with non-identity z-rotation") {
            auto m = Matrix::rotZ(M_PI / 2.0F);
            auto v = Vec2(1, 1);

            auto actual = m.mult(v);
            auto expected = Vec2(-1, 1);

            CHECK(actual == expected);
        }
    }

    SUBCASE("Vec3 multiplication") {
        SUBCASE("with identity translation") {
            auto m = Matrix::translation(0, 0, 0);
            auto v = Vec3(1, 2, 3);

            auto actual = m.mult(v);

            CHECK(actual == v);
        }

        SUBCASE("with non-identity translation") {
            auto m = Matrix::translation(1, 2, 3);
            auto v = Vec3(1, 2, 3);

            auto actual = m.mult(v);
            auto expected = Vec3(2, 4, 6);

            CHECK(actual == expected);
        }

        SUBCASE("with identity scaling") {
            auto m = Matrix::scale(1, 1, 1);
            auto v = Vec3(1, 2, 3);

            auto actual = m.mult(v);

            CHECK(actual == v);
        }

        SUBCASE("with non-identity scaling") {
            auto m = Matrix::scale(2, 2, 2);
            auto v = Vec3(1, 2, 3);

            auto actual = m.mult(v);
            auto expected = Vec3(2, 4, 6);

            CHECK(actual == expected);
        }

        SUBCASE("with identity x-rotation") {
            auto m = Matrix::rotX(0.0F);
            auto v = Vec3(1, 1, 1);

            auto actual = m.mult(v);

            CHECK(actual == v);
        }

        SUBCASE("with non-identity x-rotation") {
            auto m = Matrix::rotX(M_PI / 2.0F);
            auto v = Vec3(1, 1, 1);

            auto actual = m.mult(v);
            auto expected = Vec3(1, -1, 1);

            CHECK(actual == expected);
        }

        SUBCASE("with identity y-rotation") {
            auto m = Matrix::rotY(0.0F);
            auto v = Vec3(1, 1, 1);

            auto actual = m.mult(v);

            CHECK(actual == v);
        }

        SUBCASE("with non-identity y-rotation") {
            auto m = Matrix::rotY(M_PI / 2.0F);
            auto v = Vec3(1, 1, 1);

            auto actual = m.mult(v);
            auto expected = Vec3(1, 1, -1);

            CHECK(actual == expected);
        }

        SUBCASE("with identity z-rotation") {
            auto m = Matrix::rotZ(0.0F);
            auto v = Vec3(1, 1, 1);

            auto actual = m.mult(v);

            CHECK(actual == v);
        }

        SUBCASE("with non-identity z-rotation") {
            auto m = Matrix::rotZ(M_PI / 2.0F);
            auto v = Vec3(1, 1, 1);

            auto actual = m.mult(v);
            auto expected = Vec3(-1, 1, 1);

            CHECK(actual == expected);
        }
    }
}
