//
// Created by Shlomi Nissan on 11/16/19.
//

#ifndef GAME_RESOURCE_MANAGER_HPP
#define GAME_RESOURCE_MANAGER_HPP

#include <unordered_map>
#include <string>
#include <GL/glew.h>
#include "texture2d.hpp"
#include "shader.hpp"

using std::string;

class ResourceManager {
private:
    ResourceManager(): shaders(), textures() {};
    std::unordered_map<std::string, Shader> shaders;
    std::unordered_map<std::string, Texture2D> textures;

    Shader loadShaderFromFile(const string& vShaderPath, const string& fShaderPath);
    string readShader(const string& path);

public:
    static ResourceManager& instance() {
        static ResourceManager INSTANCE;
        return INSTANCE;
    }
    Shader loadShader(const string& vShaderPath, const string& fShaderPath, const string& name);
};


#endif //GAME_RESOURCE_MANAGER_HPP