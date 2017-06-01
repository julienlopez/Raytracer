#include "sphere.hpp"

#include "rendering/ray.hpp"

namespace Rendering
{

namespace Primitive
{

    Sphere::Sphere(const Math::Point3d& center, double radius, const Color& color)
        : m_center(center)
        , m_radius(radius)
        , m_color(color)
    {
    }

    bool Sphere::impl_intersect(const Ray& ray, double& distance) const
    {
        const auto A = 1.;
        const auto B = (ray.direction().transpose() * (ray.origin() - m_center));
        const auto C = Math::norm2(ray.origin() - m_center) - std::pow(m_radius, 2);

        const auto delta = (B * B - A * C);

        if(delta < 0.) return false;
        const auto disc = std::sqrt(delta);
        if(distance = -(B + disc) < 0.) distance = -(B - disc);
        return true;
    }

    void Sphere::impl_computeColorNormal(const Ray& ray, double distance, Color& color, Math::Vector3d& normal) const
    {
        const auto collide = ray.origin() + distance * ray.direction();
        normal = Math::normalize(collide - m_center);

        color = m_color;
    }

} // Primitive

} // Rendering
