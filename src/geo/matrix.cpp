#include "franny/geo/matrix.h"
#include "franny/utility/math.h"

#include <vector>
#include <stdexcept>
#include <sstream>
#include <iostream>

using namespace std;
using namespace franny::utility;

namespace franny::geo {

    Matrix::Matrix(const mat_size_type width, const mat_size_type height) {
        m = vector(height, vector<float>(width));
    }

    mat_size_type Matrix::getWidth() const {
        return m[0].size();
    }

    mat_size_type Matrix::getHeight() const {
        return m.size();
    }

    vector<float> Matrix:: getRow(const int x) const {
        const int width = static_cast<int>(getWidth());

        vector<float> r(width, 0);
        for (int c = 0; c < width; c++) {
            r[c] = m[x][c];
        }

        return r;
    }

    float Matrix::getPos(int col, int row) const {
        return m[row][col];
    }

    vector<float> Matrix::getCol(const int x) const {
        const int height = static_cast<int>(getHeight());

        vector<float> c(height, 0);
        for (int i = 0; i < height; i++) {
            c[i] = m[i][x];
        }

        return c;
    }

    void Matrix::setRow(const int r, const vector<float> & row) {
        if (getWidth() != row.size()) {
            throw invalid_argument("Matrix width does not match row size");
        }

        m[r] = row;
    }

    void Matrix::setCol(const int c, const vector<float> & col) {
        if (getHeight() != col.size()) {
            throw invalid_argument("Matrix height does not match column size");
        }

        const int height = static_cast<int>(getHeight());
        for (int i = 0; i < height; i++) {
            m[i][c] = col[i];
        }
    }

    void Matrix::setPos(const int col, const int row, const float value) {
        m[row][col] = value;
    }

    Matrix Matrix::transpose() const {
        auto t = Matrix(getWidth(), getHeight());

        const int width = static_cast<int>(getWidth());
        const int height = static_cast<int>(getHeight());

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                t.setPos(i, j, getPos(j, i));
            }
        }

        return t;
    }

    Matrix Matrix::operator*(const Matrix & mat) const {
        if (getWidth() != mat.getHeight()) {
            std::stringstream ss;
            ss << "Left matrix of width " << getWidth() << " does not match right matrix of height "<< mat.getHeight();
            throw invalid_argument(ss.str());
        }

        auto res = Matrix(mat.getWidth(), getHeight());

        const int width = static_cast<int>(res.getWidth());
        const int height = static_cast<int>(res.getHeight());

        for (int c = 0; c < width; c++) {
            for (int r = 0; r < height; r++) {
                res.setPos(c, r, dot(getRow(r), mat.getCol(c)));
            }
        }

        return res;
    }

    Vec2 Matrix::operator*(const Vec2 & vec) const {
        auto res = (*this) * Vec3(vec.getX(), vec.getY(), 0);
        return Vec2(res.getX(), res.getY());
    }

    Vec3 Matrix::operator*(const Vec3 & vec) const {
        auto hom = Matrix(1, 4);
        hom.setCol(0, vector<float>{ vec.getX(), vec.getY(), vec.getZ(), 1 });

        auto res = (*this) * hom;
        auto v = Vec3(res.getPos(0, 0), res.getPos(0, 1), res.getPos(0, 2));

        return v;
    }

    float *Matrix::rowMajor() const {
        const int height = static_cast<int>(getHeight());
        const int width = static_cast<int>(getWidth());

        auto *arr = new float[width*height];

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                const auto index = i*width + j;
                arr[index] = m[i][j];
            }
        }

        return arr;
    }

    bool Matrix::operator==(const Matrix &mat) const {
        if (getWidth() != mat.getWidth() || getHeight() != mat.getHeight()) {
            return false;
        }

        const int width = static_cast<int>(getWidth());
        const int height = static_cast<int>(getHeight());
            for (int row = 0; row < height; row++) {
                for (int col = 0; col < width; col++) {
                    if (!isClose(m[row][col], mat.m[row][col])) {
                        return false;
                    }
                }
            }

            return true;
        }
}