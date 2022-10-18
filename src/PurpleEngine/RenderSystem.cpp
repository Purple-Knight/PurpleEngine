#include <RenderSystem.h>
#include <Transform.h>
#include <Sprite.h>

void RenderSystem::Compute(entt::registry registry, PRenderer renderer)
{
    auto view = registry.view<Transform, Sprite>();
    for (entt::entity e : view)
    {
        auto& transform = view.get<Transform>(e);
        auto& sprite = view.get<Sprite>(e);

        sprite.Draw(renderer, transform.position.x, transform.position.y);
    }
}
