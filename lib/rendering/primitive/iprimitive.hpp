#pragma once

#include "rendering/types.hpp"

namespace Rendering
{

class Ray;

namespace Primitive
{

    class IPrimitive
    {
    public:
        virtual ~IPrimitive() = default;

        bool intersect(const Ray& ray, double& distance) const;

        void computeColorNormal(const Ray& ray, double distance, Color& color, Math::Vector3d& normal) const;

    protected:
        IPrimitive() = default;

    private:
        virtual bool impl_intersect(const Ray& ray, double& distance) const = 0;

        virtual void impl_computeColorNormal(const Ray& ray, double distance, Color& color,
                                             Math::Vector3d& normal) const = 0;
    };

} // Primitive

} // Rendering
