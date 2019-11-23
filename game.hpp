//
// Created by Shlomi Nissan on 11/16/19.
//

#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <array>

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

class Game {
private:
    GameState state;
    GLboolean keys[1024];
    GLuint width, height;
public:
    Game(GLuint width, GLuint height);
    ~Game();

    void init();
    void processInput(GLfloat dt);
    void update(GLfloat dt);
    void render();
};


#endif //GAME_GAME_HPP
