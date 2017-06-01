#pragma once

#include "types.hpp"

namespace Rendering
{

class Ray;
class Scene;

class RayTracer
{
public:
    RayTracer(unsigned long pixelWidth, unsigned long pixelHeight, double width, double height, double depth);

    ~RayTracer();

    Image draw() const;

    void setViewer(double width, double height, const Math::Vector3d& origin, const Math::Vector3d& direction);

    void setResolution(unsigned long pixelWidth, unsigned long pixelHeight);

    void setScene(Scene* scene);

private:
    Math::Point3d origin;
    Math::Vector3d direction;
    std::size_t m_pixel_width;
    std::size_t m_pixel_height;
    double width;
    double height;
    double depth;

    double precompWidth;
    double precompHeight;

    Scene* m_scene = nullptr;

    Ray generateRay(const std::size_t x, const std::size_t y) const;

    Color computeColor(const Ray& ray) const;

    void updateParameters();
};

} // Rendering
