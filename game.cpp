//
// Created by Shlomi Nissan on 11/16/19.
//

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "game.hpp"

Game::Game(GLuint width, GLuint height)
    : state(GAME_ACTIVE), keys(), width(width), height(height), resourceManager(), renderer() {
    resourceManager = ResourceManager::instance();
}

Game::~Game() {}

void Game::init() {
    resourceManager.loadShader("vertex.glsl", "fragment.glsl", "sprite");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);

    auto shader = resourceManager.getShader("sprite");
    shader.use().SetInteger("image", 0);
    shader.use().SetMatrix4("projection", projection);

    // create new sprite renderer
    renderer = SpriteRenderer(shader);

    resourceManager.loadTexture("textures/text.png", true, "logo");

}

void Game::processInput(GLfloat dt) {

}

void Game::update(GLfloat dt) {

}

void Game::render() {
    auto text_Logo = resourceManager.getTexture("logo");

    renderer.drawSprite(text_Logo,
                        glm::vec2(190, 190),
                        glm::vec2(300, 400),
                        0.0f,
                        glm::vec3(1.0f, 1.0f, 1.0f));
}
