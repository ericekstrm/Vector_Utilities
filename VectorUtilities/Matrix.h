#pragma once

#include <type_traits>

template<int row, int col>
class Matrix
{
public:
    Matrix();
    Matrix(Matrix<row, col> const&);
    ~Matrix();
    Matrix<row, col> operator=(Matrix<row, col> const&);

    Matrix<row, col> operator*(float) const;
    Matrix<row, col> operator*=(float);
    Matrix<row, col> operator/(float) const;
    Matrix<row, col> operator/=(float);

    template <int N>
    Matrix<row, N> operator*(Matrix<col, N> const&) const;

    Vector<row> operator*(Vector<col> const&) const;

    bool operator==(Matrix<row, col> const&) const;
    bool operator!=(Matrix<row, col> const&) const;

    Matrix<row, col> inverse() const;
    float determinant() const;
    Matrix<col, row> transpose() const;

    float m[row][col];

private:
    Matrix(float tmp[row][col]);
};

/*template<int row, int col>
typename std::enable_if_t<row == col, float>
Matrix<row, col>::determinant() const
{

}*/

#include "Matrix.tcc"
