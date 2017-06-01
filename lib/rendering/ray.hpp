#pragma once

#include "math/types.hpp"

namespace Rendering
{

class Ray
{
public:
    Ray(const Math::Point3d& origin_, const Math::Vector3d& direction_);

    ~Ray() = default;

    const Math::Point3d& origin() const;

    const Math::Vector3d& direction() const;

    Math::Vector3d& direction();

private:
    Math::Point3d m_origin;
    Math::Vector3d m_direction;
};

} // Rendering
