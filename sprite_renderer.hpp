//
// Created by Shlomi Nissan on 11/23/19.
//

#ifndef GAME_SPRITE_RENDERER_HPP
#define GAME_SPRITE_RENDERER_HPP

#include "shader.hpp"
#include "texture2d.hpp"

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class SpriteRenderer {
private:
    Shader shader;
    unsigned int quadVAO;

    void initRenderData();
public:
    SpriteRenderer();
    SpriteRenderer(Shader& shader);
    ~SpriteRenderer();

    void drawSprite(Texture2D& texture,
                    glm::vec2 position,
                    glm::vec2 size = glm::vec2(10, 10),
                    float rotate = 0.0f,
                    glm::vec3 color = glm::vec3(1.0f));
};


#endif //GAME_SPRITE_RENDERER_HPP
