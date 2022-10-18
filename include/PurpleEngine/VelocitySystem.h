#pragma once
#include <PurpleEngine.h>
#include <entt/entt.hpp>

struct PURPLE_ENGINE_API Velocity {
	int x;
	int y; 
};

class PURPLE_ENGINE_API VelocitySystem
{
public:
	VelocitySystem(const VelocitySystem&) = delete;
	VelocitySystem(VelocitySystem&&) = delete;
	~VelocitySystem() = default;

	VelocitySystem& operator=(const VelocitySystem&) = delete;
	VelocitySystem& operator=(VelocitySystem&&) = delete;

	void Compute(entt::registry registry);

private:

};
