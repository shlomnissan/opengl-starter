//
// Created by Shlomi Nissan on 11/16/19.
//

#ifndef GAME_TEXTURE2D_HPP
#define GAME_TEXTURE2D_HPP

#include <GL/glew.h>

class Texture2D {
private:
    unsigned int ID;
    unsigned int width, height;
    unsigned int internalFormat;
    unsigned int imageFormat;
    unsigned int wrapS;
    unsigned int wrapT;
    unsigned int filterMin;
    unsigned int filterMax;

public:
    Texture2D();
    void generate(unsigned int width, unsigned int height, unsigned char* data);
    void bind() const;

    void setInternalFormat(unsigned int internalFormat);
    void setImageFormat(unsigned int imageFormat);
};


#endif //GAME_TEXTURE2D_HPP
