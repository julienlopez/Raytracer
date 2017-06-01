#include "ray.hpp"

namespace Rendering
{

Ray::Ray(const Math::Point3d& origin_, const Math::Vector3d& direction_)
    : origin(origin_)
    , direction(direction_)
{
}

} // Rendering
