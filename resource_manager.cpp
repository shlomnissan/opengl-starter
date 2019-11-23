//
// Created by Shlomi Nissan on 11/16/19.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include "resource_manager.hpp"
#include "vendor/SOIL/SOIL.h"

//region private

Shader ResourceManager::loadShaderFromFile(const string &vShaderPath, const string &fShaderPath) {
    std::string vertexCode = readShader(vShaderPath);
    std::string fragmentCode = readShader(fShaderPath);

    Shader shader(vertexCode, fragmentCode);
    return shader;
}

string ResourceManager::readShader(const string &path) {
    try {
        std::ifstream shader("shaders/" + path);
        if (!shader) {
            std::cerr << "Unable to open shaders/" + path << '\n';
        } else {
            std::stringstream shaderStream;
            shaderStream << shader.rdbuf();
            shader.close();
            return shaderStream.str();
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cerr << "Error:Shader: Failed to read shader files\n";
    }
    return "";
}

Texture2D ResourceManager::loadTextureFromFile(const string &texturePath, bool alpha) {
    Texture2D texture;
    if (alpha) {
        texture.setInternalFormat(GL_RGBA);
        texture.setImageFormat(GL_RGBA);
    }
    int width, height;
    unsigned char* image = SOIL_load_image(texturePath.c_str(), &width, &height, 0, alpha ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);

    if (image) {
        texture.generate(width, height, image);
    } else {
        std::cerr << "Error:Texture: Failed to load texture " << texturePath << '\n';
    }

    SOIL_free_image_data(image);
    return texture;
}

//endregion

//region public

Shader ResourceManager::loadShader(const string &vShaderPath,
                                   const string &fShaderPath,
                                   const string &name) {
    shaders[name] = loadShaderFromFile(vShaderPath, fShaderPath);
    return shaders[name];
}

Texture2D ResourceManager::loadTexture(const string &texturePath,
                                       bool alpha,
                                       const string &name) {
    textures[name] = loadTextureFromFile(texturePath, alpha);
    return textures[name];
}

//endregion
