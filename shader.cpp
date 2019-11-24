//
// Created by Shlomi Nissan on 11/16/19.
//

#include <iostream>
#include <glm/gtc/type_ptr.hpp>
#include "shader.hpp"

//region private

GLuint Shader::compileShader(GLuint type, const std::string &source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        char message[length];
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        glGetShaderInfoLog(id, length, &length, message);

        std::string typeStr = "vertex";
        if (type == GL_FRAGMENT_SHADER) typeStr = "fragment";
        if (type == GL_GEOMETRY_SHADER) typeStr = "geometry";
        std::cerr << "Failed to compile " << typeStr << " " << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

//endregion

//region public

Shader::Shader(const std::string &vertexSource, const std::string &fragmentSource, const std::string &geometrySource) {
    auto vs = compileShader(GL_VERTEX_SHADER, vertexSource);
    auto fs = compileShader(GL_FRAGMENT_SHADER, fragmentSource);
    auto gs = GLuint();

    if (!geometrySource.empty()) {
        gs = compileShader(GL_GEOMETRY_SHADER, geometrySource);
    }

    this->ID = glCreateProgram();
    glAttachShader(this->ID, vs);
    glAttachShader(this->ID, fs);
    if (!geometrySource.empty()) {
        glAttachShader(this->ID, gs);
    }

    glLinkProgram(this->ID);
    glValidateProgram(this->ID);

    glDeleteShader(vs);
    glDeleteShader(fs);
    if (!geometrySource.empty()) {
        glDeleteShader(gs);
    }
}

Shader &Shader::use() {
    glUseProgram(this->ID);
    return *this;
}

//endregion

//region utilities

void Shader::SetFloat(const std::string& name, float value, bool useShader) {
    if (useShader) { use(); }
    glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value);
}

void Shader::SetInteger(const std::string& name, int value, bool useShader) {
    if (useShader) { use(); }
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value);
}

void Shader::SetVector2f(const std::string& name, float x, float y, bool useShader) {
    if (useShader) { use(); }
    glUniform2f(glGetUniformLocation(this->ID, name.c_str()), x, y);
}

void Shader::SetVector2f(const std::string& name, const glm::vec2 &value, bool useShader) {
    if (useShader) { use(); }
    glUniform2f(glGetUniformLocation(this->ID, name.c_str()), value.x, value.y);
}

void Shader::SetVector3f(const std::string& name, float x, float y, float z, bool useShader) {
    if (useShader) { use(); }
    glUniform3f(glGetUniformLocation(this->ID, name.c_str()), x, y, z);
}

void Shader::SetVector3f(const std::string& name, const glm::vec3 &value, bool useShader) {
    if (useShader) { use(); }
    glUniform3f(glGetUniformLocation(this->ID, name.c_str()), value.x, value.y, value.z);
}

void Shader::SetVector4f(const std::string& name, float x, float y, float z, float w, bool useShader) {
    if (useShader) { use(); }
    glUniform4f(glGetUniformLocation(this->ID, name.c_str()), x, y, z, w);
}

void Shader::SetVector4f(const std::string& name, const glm::vec4 &value, bool useShader) {
    if (useShader) { use(); }
    glUniform4f(glGetUniformLocation(this->ID, name.c_str()), value.x, value.y, value.z, value.w);
}

void Shader::SetMatrix4(const std::string& name, const glm::mat4 &matrix, bool useShader) {
    if (useShader) { use(); }
    glUniformMatrix4fv(glGetUniformLocation(this->ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
}

//endregion