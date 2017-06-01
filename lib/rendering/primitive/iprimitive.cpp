#include "iprimitive.hpp"

namespace Rendering
{

namespace Primitive
{

    bool IPrimitive::intersect(const Ray& ray, double& distance) const
    {
        return impl_intersect(ray, distance);
    }

    void IPrimitive::computeColorNormal(const Ray& ray, double distance, Color& color, Math::Vector3d& normal) const
    {
        return impl_computeColorNormal(ray, distance, color, normal);
    }

} // Primitive

} // Rendering
