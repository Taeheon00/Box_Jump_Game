#pragma once
#include "MMath.hpp"
#include <GLFW/glfw3.h>

class Player {
public:
    GL_Engine::vec2 coord;
    GL_Engine::vec2 quad[4];
    float size;
    GL_Engine::vec3 color;
    bool gameover = false;

    Player(GL_Engine::vec3 col)
    {
        coord = GL_Engine::vec2(0, 0);
        size = 0.1f;
        color = col;

        quad[0] = GL_Engine::vec2(-size, size);
        quad[1] = GL_Engine::vec2(size, size);
        quad[2] = GL_Engine::vec2(-size, -size);
        quad[3] = GL_Engine::vec2(size, -size);
    }
    ~Player()
    {

    }

    void MoveUp()
    {
        if (gameover)
        {
            coord.y = 0.0f;
        }
        else
        {
            coord.y = 0.005f;
            if (quad[2].y >= 0.8f)
            {
                coord.y = 0.0f;
            }
        }
    }

    void MoveDown()
    {
        if (gameover)
        {
            coord.y = 0.0f;
        }
        else
        {
            coord.y = -0.005f;
        }
    }

    void Game_Restart()
    {
        size = 0.1f;

        quad[0] = GL_Engine::vec2(-size, size);
        quad[1] = GL_Engine::vec2(size, size);
        quad[2] = GL_Engine::vec2(-size, -size);
        quad[3] = GL_Engine::vec2(size, -size);
    }

    void Render()
    {
        quad[0] = quad[0] + coord;
        quad[1] = quad[1] + coord;
        quad[2] = quad[2] + coord;
        quad[3] = quad[3] + coord;

        glBegin(GL_TRIANGLES);
        glColor4f(color.x, color.y, color.z, 1.0f);
        glVertex3f(quad[0].x, quad[0].y, 0.0f);
        glVertex3f(quad[1].x, quad[1].y, 0.0f);
        glVertex3f(quad[2].x, quad[2].y, 0.0f);

        glVertex3f(quad[1].x, quad[1].y, 0.0f);
        glVertex3f(quad[3].x, quad[3].y, 0.0f);
        glVertex3f(quad[2].x, quad[2].y, 0.0f);

        glEnd();

    }

};