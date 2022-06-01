#pragma once
#include "MMath.hpp"
#include "Player.hpp"
#include "wall.hpp"
#include <GLFW/glfw3.h>

Player* p = new Player(GL_Engine::vec3(1.0f, 0.0f, 0.0f));
Wall* w = new Wall(GL_Engine::vec3(0.0f, 0.0f, 1.0f));
Wall2* w2 = new Wall2(GL_Engine::vec3(0.0f, 0.0f, 1.0f));
Wall3* w3 = new Wall3(GL_Engine::vec3(0.0f, 0.0f, 1.0f));

class GameOver {
public:
    GL_Engine::vec2 coord;
    GL_Engine::vec2 quad[4];
    float size;
    GL_Engine::vec3 color;
    bool gameovercheck = false;
    float alpha = 0.0f;

    GameOver(GL_Engine::vec3 col)
    {
        coord = GL_Engine::vec2(0, 0);
        size = 0.9f;
        color = col;

        quad[0] = GL_Engine::vec2(size, size);
        quad[1] = GL_Engine::vec2(size, -size);
        quad[2] = GL_Engine::vec2(-size, size);
        quad[3] = GL_Engine::vec2(-size, -size);

    }
    ~GameOver()
    {

    }

    void Render()
    {
        if (gameovercheck)
        {
            alpha = 1.0f;
        }
        else
        {
            alpha = 0.0f;
        }
        quad[0] = quad[0] + coord;
        quad[1] = quad[1] + coord;
        quad[2] = quad[2] + coord;
        quad[3] = quad[3] + coord;

        glBegin(GL_TRIANGLES);
        glColor4f(color.x, color.y, color.z, alpha);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(quad[0].x, quad[0].y, 0.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(quad[1].x, quad[1].y, 0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(quad[2].x, quad[2].y, 0.0f);

        glTexCoord2f(1.0f, 0.0f); glVertex3f(quad[1].x, quad[1].y, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(quad[3].x, quad[3].y, 0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(quad[2].x, quad[2].y, 0.0f);

        glEnd();
        glFlush();
        glDisable(GL_TEXTURE_2D);
    }

};