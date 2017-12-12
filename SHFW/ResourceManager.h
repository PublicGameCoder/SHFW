#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <map>
#include <vector>

class ResourceManager
{
public:
	~ResourceManager();
	static ResourceManager* getManager() { if (!instance) { instance = new ResourceManager();} return instance;}
	std::vector<const char*> loadAllShaders(std::string folder_directory);
private:
	static ResourceManager* instance;
	ResourceManager();
	std::map<std::string, const char*> loadedShaders;

	std::vector<std::string> ResourceManager::getAllFilesFromFolder(std::string folder);
};

#endif // !RESOURCEMANAGER_H
