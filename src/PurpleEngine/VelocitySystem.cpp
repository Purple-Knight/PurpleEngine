#include <VelocitySystem.h>
#include <Transform.h>

void VelocitySystem::Compute(entt::registry registry)
{
    auto view = registry.view<Transform, Velocity>();
    for (entt::entity e : view)
    {
        auto& transform = view.get<Transform>(e);
        auto& velocity = view.get<Velocity>(e);

        transform.SetPosition(transform.position.x + velocity.x, transform.position.y + velocity.y);
    }
}
