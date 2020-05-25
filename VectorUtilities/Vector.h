#pragma once

#include <ostream>

template <int N>
class Vector
{
public:
    Vector();
    Vector(Vector<N> const&);
    Vector(std::initializer_list<float> list);
    ~Vector();
    Vector<N> operator=(Vector<N> const&);

    Vector<N> operator+(Vector<N> const&) const;
    Vector<N> operator+=(Vector<N> const&);
    Vector<N> operator-(Vector<N> const&) const;
    Vector<N> operator-=(Vector<N> const&);

    Vector<N> operator*(float) const;
    Vector<N> operator*=(float);
    Vector<N> operator/(float) const;
    Vector<N> operator/=(float);

    // dot product
    float operator*(Vector<N> const&);

    bool operator==(Vector<N> const&) const;
    bool operator!=(Vector<N> const&) const;

    float length() const;
    void normalize();

    float x[N];

private:
    Vector(float tmp[N]);
};

Vector<3> cross(Vector<3> const& lhs, Vector<3> const& rhs)
{
    float x = lhs.x[1] * rhs.x[2] - lhs.x[2] * rhs.x[1];
    float y = lhs.x[2] * rhs.x[0] - lhs.x[0] * rhs.x[2];
    float z = lhs.x[0] * rhs.x[1] - lhs.x[1] * rhs.x[0];
    return Vector<3> {x, y, z};
}

#include "Vector.tcc"