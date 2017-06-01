#pragma once

#include "iprimitive.hpp"

namespace Rendering
{

namespace Primitive
{

    class Sphere : public IPrimitive
    {
    public:
        Sphere(const Math::Point3d& center, double radius, const Color& color);

    private:
        Math::Point3d m_center;
        double m_radius;
        Color m_color;

        virtual bool impl_intersect(const Ray& ray, double& distance) const override;

        virtual void impl_computeColorNormal(const Ray& ray, double distance, Color& color,
                                             Math::Vector3d& normal) const override;
    };

} // Primitive

} // Rendering
