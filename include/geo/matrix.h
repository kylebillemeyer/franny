#ifndef MATRIX_H
#define MATRIX_H

// Include necessary libraries
#include <vector>
#include <sstream>
#include <math.h>

#include "geo/vec3.h"
#include "vec2.h"

using namespace std;

using mat_size_type = vector<vector<float>>::size_type;

namespace geo {

    class Matrix {
    public:
        Matrix(mat_size_type width, mat_size_type height);

        mat_size_type getWidth() const;
        mat_size_type getHeight() const;

        vector<float> getRow(int x) const;
        vector<float> getCol(int x) const;
        float getPos(int col, int row) const;

        void setRow(int r, const vector<float> & row);
        void setCol(int c, const vector<float> & col);
        void setPos(int col, int row, float value);

        Matrix mult(const Matrix & mat) const;
        Vec2 mult(const Vec2 & vec) const;
        Vec3 mult(const Vec3 & vec) const;

        bool operator==(const Matrix &mat) const;

        static Matrix identity(const mat_size_type width, const mat_size_type height) {
            auto m = Matrix(width, height);

            for (int c = 0; c < static_cast<int>(width); c++) {
                for (int r = 0; r < static_cast<int>(height); r++) {
                    if (c == r) {
                        m.setPos(c, r, 1);
                    }
                }
            }

            return m;
        }

        static Matrix translation(const float x, const float y, const float z) {
            auto m = Matrix::identity(4, 4);
            m.setPos(3, 0, x);
            m.setPos(3, 1, y);
            m.setPos(3, 2, z);

            return m;
        }

        static Matrix scale(const float x, const float y, const float z) {
            auto m = Matrix::identity(4, 4);
            m.setPos(0, 0, x);
            m.setPos(1, 1, y);
            m.setPos(2, 2, z);

            return m;
        }

        static Matrix rotX(const float rad) {
            auto m = Matrix::identity(4, 4);
            m.setPos(1, 1, cos(rad));
            m.setPos(1, 2, sin(rad));
            m.setPos(2, 1, -sin(rad));
            m.setPos(2, 2, cos(rad));

            return m;
        }

        static Matrix rotY(const float rad) {
            auto m = Matrix::identity(4, 4);
            m.setPos(0, 0, cos(rad));
            m.setPos(0, 2, -sin(rad));
            m.setPos(2, 0, sin(rad));
            m.setPos(2, 2, cos(rad));

            return m;
        }

        static Matrix rotZ(const float rad) {
            auto m = Matrix::identity(4, 4);
            m.setPos(0, 0, cos(rad));
            m.setPos(0, 1, sin(rad));
            m.setPos(1, 0, -sin(rad));
            m.setPos(1, 1, cos(rad));

            return m;
        }

        friend ostream& operator<<(ostream& os, const Matrix& m) {
            const int height = static_cast<int>(m.getHeight());
            for (int r = 0; r < height; r++) {
                os << "[ ";

                for (const auto i: m.getRow(r)) {
                    os << i << " ";
                }

                os << "]" << endl;
            }
            return os;
        }

    private:
        // outer array represents row arrays
        // inner array represents columns elements
        vector<vector<float>> m;
    };

} // namespace matrix

#endif // MATRIX_H