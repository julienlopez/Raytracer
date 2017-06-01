#pragma once

#include <memory>
#include <vector>

#include <boost/optional.hpp>

namespace Rendering
{

class Ray;

namespace Primitive
{
    class IPrimitive;
}

class Scene
{
public:
    using IPrimitivePointer_t = std::unique_ptr<Primitive::IPrimitive>;

    Scene();

    ~Scene();

    std::size_t count() const;

    /**
     * @pre index < count()
     */
    Primitive::IPrimitive& getPrimitive(std::size_t index);

    /**
     * @pre index < count()
     */
    IPrimitivePointer_t removePrimitive(std::size_t index);

    boost::optional<std::size_t> getFirstCollision(const Ray& ray, double& distance) const;

    void addPrimitive(IPrimitivePointer_t primitive);

private:
    std::vector<IPrimitivePointer_t> m_primitives;
};

} // Rendering
