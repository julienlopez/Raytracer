#include "ray.hpp"

namespace Rendering
{

Ray::Ray(const Math::Point3d& origin_, const Math::Vector3d& direction_)
    : m_origin(origin_)
    , m_direction(direction_)
{
}

const Math::Point3d& Ray::origin() const
{
    return m_origin;
}

const Math::Vector3d& Ray::direction() const
{
    return m_direction;
}

} // Rendering
