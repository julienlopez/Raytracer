#pragma once

#include "math/types.hpp"

namespace Rendering
{

using Color = Math::Vector3d;

using Image = Eigen::Matrix<Color, Eigen::Dynamic, Eigen::Dynamic>;

} // Rendering
