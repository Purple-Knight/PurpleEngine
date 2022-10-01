#pragma once
#include <PurpleEngine.h>

static class PURPLE_ENGINE_API PMath
{
public:
	static float constexpr PI = 3.14159f;
	static float constexpr DEG2RAD = PMath::PI / 180;
	static float constexpr RAD2DEG = 180 / PMath::PI;
};