#pragma once
#include <PurpleEngine.h>
#include <SDL.h>
#include <string>
#include <vector>

class PRenderer;

class PURPLE_ENGINE_API Model
{
public:
	Model(const Model&) = delete;
	Model(Model&&) = delete;
	Model(const std::string& modelPath);
	~Model() = default;

	Model& operator=(const Model&) = delete;
	Model& operator=(Model&&) = delete;

	void Draw(PRenderer& renderer, int x, int y);

private:
	std::string m_texturePath;
	std::vector<int> m_indices;
	std::vector<SDL_Vertex> m_vertices;

};