#include "scene.hpp"

#include "primitive/iprimitive.hpp"

#include <gsl/gsl_assert>

namespace Rendering
{

Scene::Scene() = default;

Scene::~Scene() = default;

std::size_t Scene::count() const
{
    return m_primitives.size();
}

Primitive::IPrimitive& Scene::getPrimitive(std::size_t index)
{
    Expects(index < count());
    return *m_primitives[index];
}

auto Scene::removePrimitive(std::size_t index) -> IPrimitivePointer_t
{
    Expects(index < count());
    auto it = begin(m_primitives) + index;
    auto primitive = std::move(*it);
    m_primitives.erase(it);
    return primitive;
}

boost::optional<size_t> Scene::getFirstCollision(const Ray& ray, double& distance) const
{
    auto min_dist = std::numeric_limits<double>::max();
    boost::optional<size_t> min_primitive;

    for(auto it = m_primitives.begin(); it != m_primitives.end(); ++it)
    {
        double distance;
        if((*it)->intersect(ray, distance))
        {
            min_primitive = it - begin(m_primitives);
            min_dist = distance;
        }
    }

    if(min_primitive)
    {
        distance = min_dist;
    }
    return min_primitive;
}

void Scene::addPrimitive(IPrimitivePointer_t primitive)
{
    m_primitives.push_back(std::move(primitive));
}

} // Rendering
