#include <Model.h>
#include <PRenderer.h>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

Model::Model(const std::string& modelPath) :
	m_texturePath(),
	m_indices(),
	m_vertices()
{
	nlohmann::json json(modelPath);
	std::string content;

	std::cout << json.accept(content) << std::endl;
	//m_texturePath = json["texture"];
	//m_indices = json["indices"];
	//m_vertices = json["vertices"];

	//std::printf(m_texturePath.c_str());
}

void Model::Draw(PRenderer& renderer, int x, int y)
{
}
