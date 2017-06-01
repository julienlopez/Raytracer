#pragma once

#include <eigen3/Eigen/Dense>

namespace Math
{

using Point3d = Eigen::Vector3d;
using Vector3d = Eigen::Vector3d;

double norm2(const Eigen::Vector3d& v);

Eigen::Vector3d normalize(const Eigen::Vector3d& v);

} // Math
