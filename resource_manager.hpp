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
    std::unordered_map<std::string, Shader> shaders;
    std::unordered_map<std::string, Texture2D> textures;

    Shader loadShaderFromFile(const string& vShaderPath, const string& fShaderPath);
    string readShader(const string& path);
    Texture2D loadTextureFromFile(const string& texturePath, bool alpha);

public:
    ResourceManager(): shaders(), textures() {};
    static ResourceManager& instance() {
        static ResourceManager INSTANCE;
        return INSTANCE;
    }
    Shader loadShader(const string& vShaderPath, const string& fShaderPath, const string& name);
    Texture2D loadTexture(const string& texturePath, bool alpha, const string& name);
    Shader getShader(const string& name);
    Texture2D getTexture(const string& name);
    void clear();
};


#endif //GAME_RESOURCE_MANAGER_HPP
