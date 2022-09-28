#include "ResourceManager.h"
#include <PTexture.h>
#include <iostream>

ResourceManager& ResourceManager::Instance()
{
	static ResourceManager m_instance;
	return m_instance;
}

void ResourceManager::Purge()
{
	for (const auto& texture : m_textures)
	{
		if (texture.second.use_count() == 1)
		{
			std::cout << "Erase Texture : " << texture.first << std::endl;
			m_textures.erase(texture.first);
		}
	}
}

std::shared_ptr<PTexture> ResourceManager::GetTexture(PRenderer& renderer, const std::string& path)
{
	std::shared_ptr<PTexture> texture;
	auto textureIt = m_textures.find(path);
	if (textureIt == m_textures.end())
	{
		std::cout << "Create Texture : " << path << std::endl;
		texture = std::make_shared<PTexture>(PTexture::LoadFromFile(renderer, path));
		m_textures.insert({ path, texture });
	}
	else
	{
		std::cout << "Exiting Texture : " << path << std::endl;
		texture = m_textures[path];
	}

	return texture;
}

ResourceManager::ResourceManager() : 
	m_textures()
{
}
