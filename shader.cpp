//
// Created by Shlomi Nissan on 11/16/19.
//

#include <iostream>

#include "shader.hpp"

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
