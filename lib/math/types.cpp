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

} // Math
