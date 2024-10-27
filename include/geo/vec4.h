#ifndef VEC4_H
#define VEC4_H

#include <vector>

using namespace std;

using vec4_size_type = vector<float>::size_type;

namespace geo {

    class Vec4 {
    public:
        Vec4(float x, float y, float z, float w=1.0F);

        float getX() const;
        void setX(float x);
        float getY() const;
        void setY(float y);
        float getZ() const;
        void setZ(float z);
        float getW() const;
        void setW(float w);

    private:
        float x;
        float y;
        float z;
        float w;
    };
}

#endif