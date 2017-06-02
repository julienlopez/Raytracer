#include "types.hpp"

namespace Math
{

double norm2(const Eigen::Vector3d& v)
{
    return v.transpose() * v;
}

Eigen::Vector3d normalize(const Eigen::Vector3d& v)
{
    return v / std::sqrt(norm2(v));
}

Eigen::Vector3d createPoint(const double x, const double y, const double z)
{
    Eigen::Vector3d res;
    res(0) = x;
    res(1) = y;
    res(2) = z;
    return res;
}

} // Math
