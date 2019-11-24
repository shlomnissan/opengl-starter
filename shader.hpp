//
// Created by Shlomi Nissan on 11/16/19.
//

#ifndef GAME_SHADER_HPP
#define GAME_SHADER_HPP

#include <string>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <GL/glew.h>

class Shader {
private:
    GLuint ID;
    static GLuint compileShader(GLuint type, const std::string& source);
public:
    Shader(): ID() {}
    Shader(const std::string& vertexSource, const std::string& fragmentSource, const std::string& geometrySource = "");
    Shader& use();

    void SetFloat(const std::string& name, float value, bool useShader = false);
    void SetInteger(const std::string& name, int value, bool useShader = false);
    void SetVector2f(const std::string& name, float x, float y, bool useShader = false);
    void SetVector2f(const std::string& name, const glm::vec2 &value, bool useShader = false);
    void SetVector3f(const std::string& name, float x, float y, float z, bool useShader = false);
    void SetVector3f(const std::string& name, const glm::vec3 &value, bool useShader = false);
    void SetVector4f(const std::string& name, float x, float y, float z, float w, bool useShader = false);
    void SetVector4f(const std::string& name, const glm::vec4 &value, bool useShader = false);
    void SetMatrix4(const std::string& name, const glm::mat4 &matrix, bool useShader = false);
};


#endif //GAME_SHADER_HPP
