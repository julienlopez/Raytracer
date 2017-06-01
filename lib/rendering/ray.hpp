#pragma once

#include "math/types.hpp"

namespace Rendering
{

class Ray
{
public:
    Ray(const Math::Point3d& origin_, const Math::Vector3d& direction_);

    ~Ray() = default;

    Math::Point3d origin;
    Math::Vector3d direction;
};

} // Rendering
