#pragma once
#include <PurpleEngine.h>
#include <entt/entt.hpp>
#include <PRenderer.h>

class PURPLE_ENGINE_API RenderSystem
{
public:
	RenderSystem(const RenderSystem&) = delete;
	RenderSystem(RenderSystem&&) = delete;
	~RenderSystem() = default;

	RenderSystem& operator=(const RenderSystem&) = delete;
	RenderSystem& operator=(RenderSystem&&) = delete;

	void Compute(entt::registry registry, PRenderer renderer);

private:

};