#pragma once
#include <map>
#include <string>
#include <memory>

class PTexture;
class PRenderer;

class ResourceManager
{
public:
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager(ResourceManager&&) = delete;
	~ResourceManager() = default;

	ResourceManager& operator=(const ResourceManager&) = delete;
	ResourceManager& operator=(ResourceManager&&) = delete;

	static ResourceManager& Instance();
	void Purge();
	std::shared_ptr<PTexture> GetTexture(PRenderer& renderer, const std::string& path);

private:
	ResourceManager();
	std::map<std::string, std::shared_ptr<PTexture>> m_textures;
};