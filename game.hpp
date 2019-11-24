//
// Created by Shlomi Nissan on 11/16/19.
//

#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <array>
#include <memory>

#include "resource_manager.hpp"
#include "sprite_renderer.hpp"

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

class Game {
private:
    GameState state;
    ResourceManager resourceManager;
    SpriteRenderer renderer;

    bool keys[1024];
    unsigned int width, height;
public:
    Game(GLuint width, GLuint height);
    ~Game();

    void init();
    void processInput(GLfloat dt);
    void update(GLfloat dt);
    void render();
};


#endif //GAME_GAME_HPP
