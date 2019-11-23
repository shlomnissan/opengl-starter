//
// Created by Shlomi Nissan on 11/16/19.
//

#ifndef GAME_SHADER_HPP
#define GAME_SHADER_HPP

#include <string>
#include <GL/glew.h>

class Shader {
private:
    GLuint ID;
    static GLuint compileShader(GLuint type, const std::string& source);
public:
    Shader(): ID() {}
    Shader(const std::string& vertexSource, const std::string& fragmentSource, const std::string& geometrySource = "");
    Shader& use();
};


#endif //GAME_SHADER_HPP
