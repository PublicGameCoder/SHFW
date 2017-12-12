#include "ResourceManager.h"

ResourceManager::ResourceManager() {
	
}

ResourceManager::~ResourceManager() {

}

std::vector<const char*> ResourceManager::loadAllShaders(std::string folder_directory) {
	std::vector<std::string> allFiles = getAllFilesFromFolder(folder_directory);
	for each (std::string file in allFiles) {
		if (loadedShaders.find(file) != loadedShaders.end()) continue;
		std::string line, text;
		std::ifstream in(file);
		while (std::getline(in, line))
		{
			text += line + "\n";
		}
		loadedShaders.insert(std::pair<std::string, const char*>(file,text.c_str()));
	}
	std::vector<const char*> shaders;
	std::map<std::string, const char*>::iterator it;
	for (it = loadedShaders.begin();it != loadedShaders.end(); ++it)
	{
		shaders.push_back(it->second);
	}
	return shaders;
}

std::vector<std::string> ResourceManager::getAllFilesFromFolder(std::string folder) {
	std::vector<std::string> names;
	std::string search_path = folder + "/*.*";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				names.push_back(folder+"/"+fd.cFileName);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	return names;
}