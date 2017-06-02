#include "raytracer.hpp"

#include "ray.hpp"
#include "scene.hpp"

#include "primitive/iprimitive.hpp"

namespace Rendering
{

RayTracer::RayTracer(unsigned long pixelWidth, unsigned long pixelHeight, double width, double height, double depth)
    : m_pixel_width(pixelWidth)
    , m_pixel_height(pixelHeight)
    , width(width)
    , height(height)
    , depth(depth)
{
    origin.fill(0.);
    direction.fill(0.);
    direction(2) = 1;
    updateParameters();
}

RayTracer::~RayTracer() = default;

Image RayTracer::draw() const
{
    Image res{Eigen::Index(m_pixel_height), Eigen::Index(m_pixel_width)};
    for(std::size_t j = 0; j < m_pixel_height; ++j)
    {
        for(std::size_t i = 0; i < m_pixel_width; ++i)
        {
            res(j, i) = computeColor(generateRay(i, j));
        }
    }
    return res;
}

void RayTracer::setViewer(double width, double height, const Math::Vector3d& origin, const Math::Vector3d& direction)
{
    this->width = width;
    this->height = height;
    this->origin = origin;
    this->direction = direction;

    updateParameters();
}

void RayTracer::setResolution(unsigned long pixelWidth, unsigned long pixelHeight)
{
    m_pixel_width = pixelWidth;
    m_pixel_height = pixelHeight;
    updateParameters();
}

void RayTracer::setScene(Scene* scene)
{
    m_scene = scene;
}

Ray RayTracer::generateRay(const std::size_t x, const std::size_t y) const
{
    Math::Vector3d dir
        = Math::createPoint(precompWidth * (x - m_pixel_width / 2.), precompHeight * (y - m_pixel_height / 2.), depth);
    return Ray(origin, Math::normalize(dir));
}

Color RayTracer::computeColor(const Ray& ray) const
{
    Color color;
    color.fill(0.);
    double distance;
    const auto index = m_scene->getFirstCollision(ray, distance);
    if(index)
    {
        Math::Vector3d normal;
        auto& primitive = m_scene->getPrimitive(*index);
        primitive.computeColorNormal(ray, distance, color, normal);
    }
    return color;
}

void RayTracer::updateParameters()
{
    precompWidth = width / m_pixel_width;
    precompHeight = height / m_pixel_height;
}

} // Rendering
