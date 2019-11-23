//
// Created by Shlomi Nissan on 11/16/19.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include "resource_manager.hpp"

Shader ResourceManager::loadShaderFromFile(const string &vShaderPath, const string &fShaderPath) {
    std::string vertexCode = readShader(vShaderPath);
    std::string fragmentCode = readShader(fShaderPath);

    Shader shader(vertexCode, fragmentCode);
    return shader;
}

string ResourceManager::readShader(const string &path) {
    try {
        std::ifstream shader("shaders/" + path);
        std::stringstream shaderStream;
        shaderStream << shader.rdbuf();
        shader.close();

        return shaderStream.str();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cerr << "Error:Shader: Failed to read shader files\n";
    }
    return "";
}

Shader ResourceManager::loadShader(const string &vShaderPath,
                                   const string &fShaderPath,
                                   const string &name) {
    shaders[name] = loadShaderFromFile(vShaderPath, fShaderPath);
    return shaders[name];
}
