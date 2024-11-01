#ifndef MATH_H
#define MATH_H
#include <stdexcept>
#include <vector>

namespace utility {
    inline float dot(const std::vector<float> & l, const std::vector<float> & r) {
        if (l.size() != r.size()) {
            throw std::invalid_argument("row and col vectors must have same size");
        }

        float res = 0;
        for (size_t i = 0; i < l.size(); i++) {
            res += l[i] * r[i];
        }

        return res;
    }

    inline bool isClose(const float l, const float r, const float tol = 0.00001) {
        return abs(l - r) < tol;
    }
}

#endif //MATH_H
