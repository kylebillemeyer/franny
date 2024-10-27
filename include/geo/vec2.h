#ifndef VEC2_H
#define VEC2_H

#include <vector>
#include <sstream>

using namespace std;

using vec2_size_type = vector<float>::size_type;

namespace geo {

    class Vec2 {
    public:
        Vec2(float x, float y);

        float getX() const;
        void setX(float x);
        float getY() const;
        void setY(float y);

        float dot(Vec2 v) const;

        bool operator==(const Vec2 & vec) const;

        friend ostream& operator<<(ostream& os, const Vec2& v) {
            os << "[ " << v.getX() << " " << v.getY() << " ] ^ T";
            return os;
        }

    private:
        float x;
        float y;
    };
}
#endif // VEC2_H