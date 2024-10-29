#ifndef VEC3_H
#define VEC3_H

#include <vector>
#include <sstream>

using namespace std;

using vec3_size_type = vector<float>::size_type;

namespace geo {

    class Vec3 {
    public:
        Vec3(float x, float y, float z);

        float getX() const;
        void setX(float x);
        float getY() const;
        void setY(float y);
        float getZ() const;
        void setZ(float z);

        Vec3 add(Vec3 v) const;
        Vec3 sub(Vec3 v) const;
        Vec3 mul(float s) const;
        float dot(Vec3 v) const;
        Vec3 cross(Vec3 v) const;

        bool operator==(const Vec3 & vec) const;

        friend ostream& operator<<(ostream& os, const Vec3& v) {
            os << "[ " << v.getX() << " " << v.getY() << " " << v.getZ() << " ] ^ T";
            return os;
        }

    private:
        float x;
        float y;
        float z;
    };
}
#endif // VEC3_H