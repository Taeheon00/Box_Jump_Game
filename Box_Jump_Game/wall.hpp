#pragma once
#include "MMath.hpp"
#include <GLFW/glfw3.h>

class Wall {
public:
    GL_Engine::vec2 coord;
    GL_Engine::vec2 quad[4];
    GL_Engine::vec2 quad2[4];
    GL_Engine::vec3 color;
    bool gameover = false;
    bool pass = false;

    Wall(GL_Engine::vec3 col)
    {
        coord = GL_Engine::vec2(0, 0);
        color = col;

        quad[0] = GL_Engine::vec2(1.0f, 1.0f);
        quad[1] = GL_Engine::vec2(1.2f, 1.0f);
        quad[2] = GL_Engine::vec2(1.0f, 0.0f);
        quad[3] = GL_Engine::vec2(1.2f, 0.0f);

        quad2[0] = GL_Engine::vec2(1.0f, -0.6f);
        quad2[1] = GL_Engine::vec2(1.2f, -0.6f);
        quad2[2] = GL_Engine::vec2(1.0f, -1.0f);
        quad2[3] = GL_Engine::vec2(1.2f, -1.0f);
    }
    ~Wall()
    {

    }

    void wall_move()
    {
        if (gameover)
        {
            coord.x = -0.0f;
        }
        else
        {
            coord.x = -0.001f;
        }
    }

    void Render()
    {
        quad[0] = quad[0] + coord;
        quad[1] = quad[1] + coord;
        quad[2] = quad[2] + coord;
        quad[3] = quad[3] + coord;

        quad2[0] = quad2[0] + coord;
        quad2[1] = quad2[1] + coord;
        quad2[2] = quad2[2] + coord;
        quad2[3] = quad2[3] + coord;

        glBegin(GL_TRIANGLES);
        glColor4f(color.x, color.y, color.z, 1.0f);
        glVertex3f(quad[0].x, quad[0].y, 0.0f);
        glVertex3f(quad[1].x, quad[1].y, 0.0f);
        glVertex3f(quad[2].x, quad[2].y, 0.0f);

        glVertex3f(quad[1].x, quad[1].y, 0.0f);
        glVertex3f(quad[3].x, quad[3].y, 0.0f);
        glVertex3f(quad[2].x, quad[2].y, 0.0f);

        glEnd();
        glBegin(GL_TRIANGLES);
        glColor4f(color.x, color.y, color.z, 1.0f);
        glVertex3f(quad2[0].x, quad2[0].y, 0.0f);
        glVertex3f(quad2[1].x, quad2[1].y, 0.0f);
        glVertex3f(quad2[2].x, quad2[2].y, 0.0f);

        glVertex3f(quad2[1].x, quad2[1].y, 0.0f);
        glVertex3f(quad2[3].x, quad2[3].y, 0.0f);
        glVertex3f(quad2[2].x, quad2[2].y, 0.0f);

        glEnd();
    }

    void Game_Restart()
    {
        quad[0] = GL_Engine::vec2(1.0f, 1.0f);
        quad[1] = GL_Engine::vec2(1.2f, 1.0f);
        quad[2] = GL_Engine::vec2(1.0f, 0.0f);
        quad[3] = GL_Engine::vec2(1.2f, 0.0f);

        quad2[0] = GL_Engine::vec2(1.0f, -0.6f);
        quad2[1] = GL_Engine::vec2(1.2f, -0.6f);
        quad2[2] = GL_Engine::vec2(1.0f, -1.0f);
        quad2[3] = GL_Engine::vec2(1.2f, -1.0f);
    }

};

class Wall2 {
public:
    GL_Engine::vec2 coord;
    GL_Engine::vec2 quad[4];
    GL_Engine::vec2 quad2[4];
    GL_Engine::vec3 color;
    bool gameover = false;

    Wall2(GL_Engine::vec3 col)
    {
        coord = GL_Engine::vec2(0, 0);
        color = col;

        quad[0] = GL_Engine::vec2(2.0f, 1.0f);
        quad[1] = GL_Engine::vec2(2.2f, 1.0f);
        quad[2] = GL_Engine::vec2(2.0f, 0.5f);
        quad[3] = GL_Engine::vec2(2.2f, 0.5f);

        quad2[0] = GL_Engine::vec2(2.0f, -0.2f);
        quad2[1] = GL_Engine::vec2(2.2f, -0.2f);
        quad2[2] = GL_Engine::vec2(2.0f, -1.0f);
        quad2[3] = GL_Engine::vec2(2.2f, -1.0f);
    }
    ~Wall2()
    {

    }

    void wall_move()
    {
        if (gameover)
        {
            coord.x = -0.0f;
        }
        else
        {
            coord.x = -0.001f;
        }
    }

    void Render()
    {
        quad[0] = quad[0] + coord;
        quad[1] = quad[1] + coord;
        quad[2] = quad[2] + coord;
        quad[3] = quad[3] + coord;

        quad2[0] = quad2[0] + coord;
        quad2[1] = quad2[1] + coord;
        quad2[2] = quad2[2] + coord;
        quad2[3] = quad2[3] + coord;

        glBegin(GL_TRIANGLES);
        glColor4f(color.x, color.y, color.z, 1.0f);
        glVertex3f(quad[0].x, quad[0].y, 0.0f);
        glVertex3f(quad[1].x, quad[1].y, 0.0f);
        glVertex3f(quad[2].x, quad[2].y, 0.0f);

        glVertex3f(quad[1].x, quad[1].y, 0.0f);
        glVertex3f(quad[3].x, quad[3].y, 0.0f);
        glVertex3f(quad[2].x, quad[2].y, 0.0f);

        glEnd();
        glBegin(GL_TRIANGLES);
        glColor4f(color.x, color.y, color.z, 1.0f);
        glVertex3f(quad2[0].x, quad2[0].y, 0.0f);
        glVertex3f(quad2[1].x, quad2[1].y, 0.0f);
        glVertex3f(quad2[2].x, quad2[2].y, 0.0f);

        glVertex3f(quad2[1].x, quad2[1].y, 0.0f);
        glVertex3f(quad2[3].x, quad2[3].y, 0.0f);
        glVertex3f(quad2[2].x, quad2[2].y, 0.0f);

        glEnd();
    }

    void Game_Restart()
    {
        quad[0] = GL_Engine::vec2(2.0f, 1.0f);
        quad[1] = GL_Engine::vec2(2.2f, 1.0f);
        quad[2] = GL_Engine::vec2(2.0f, 0.5f);
        quad[3] = GL_Engine::vec2(2.2f, 0.5f);

        quad2[0] = GL_Engine::vec2(2.0f, -0.2f);
        quad2[1] = GL_Engine::vec2(2.2f, -0.2f);
        quad2[2] = GL_Engine::vec2(2.0f, -1.0f);
        quad2[3] = GL_Engine::vec2(2.2f, -1.0f);
    }

};

class Wall3 {
public:
    GL_Engine::vec2 coord;
    GL_Engine::vec2 quad[4];
    GL_Engine::vec2 quad2[4];
    GL_Engine::vec3 color;
    bool gameover = false;

    Wall3(GL_Engine::vec3 col)
    {
        coord = GL_Engine::vec2(0, 0);
        color = col;

        quad[0] = GL_Engine::vec2(3.0f, 1.0f);
        quad[1] = GL_Engine::vec2(3.2f, 1.0f);
        quad[2] = GL_Engine::vec2(3.0f, -0.3f);
        quad[3] = GL_Engine::vec2(3.2f, -0.3f);

        quad2[0] = GL_Engine::vec2(3.0f, -0.8f);
        quad2[1] = GL_Engine::vec2(3.2f, -0.8f);
        quad2[2] = GL_Engine::vec2(3.0f, -1.0f);
        quad2[3] = GL_Engine::vec2(3.2f, -1.0f);
    }
    ~Wall3()
    {

    }

    void wall_move()
    {
        if (gameover)
        {
            coord.x = -0.0f;
        }
        else
        {
            coord.x = -0.001f;
        }
    }

    void Render()
    {
        quad[0] = quad[0] + coord;
        quad[1] = quad[1] + coord;
        quad[2] = quad[2] + coord;
        quad[3] = quad[3] + coord;

        quad2[0] = quad2[0] + coord;
        quad2[1] = quad2[1] + coord;
        quad2[2] = quad2[2] + coord;
        quad2[3] = quad2[3] + coord;

        glBegin(GL_TRIANGLES);
        glColor4f(color.x, color.y, color.z, 1.0f);
        glVertex3f(quad[0].x, quad[0].y, 0.0f);
        glVertex3f(quad[1].x, quad[1].y, 0.0f);
        glVertex3f(quad[2].x, quad[2].y, 0.0f);

        glVertex3f(quad[1].x, quad[1].y, 0.0f);
        glVertex3f(quad[3].x, quad[3].y, 0.0f);
        glVertex3f(quad[2].x, quad[2].y, 0.0f);

        glEnd();
        glBegin(GL_TRIANGLES);
        glColor4f(color.x, color.y, color.z, 1.0f);
        glVertex3f(quad2[0].x, quad2[0].y, 0.0f);
        glVertex3f(quad2[1].x, quad2[1].y, 0.0f);
        glVertex3f(quad2[2].x, quad2[2].y, 0.0f);

        glVertex3f(quad2[1].x, quad2[1].y, 0.0f);
        glVertex3f(quad2[3].x, quad2[3].y, 0.0f);
        glVertex3f(quad2[2].x, quad2[2].y, 0.0f);

        glEnd();
    }

    void Game_Restart()
    {
        quad[0] = GL_Engine::vec2(3.0f, 1.0f);
        quad[1] = GL_Engine::vec2(3.2f, 1.0f);
        quad[2] = GL_Engine::vec2(3.0f, -0.3f);
        quad[3] = GL_Engine::vec2(3.2f, -0.3f);

        quad2[0] = GL_Engine::vec2(3.0f, -0.8f);
        quad2[1] = GL_Engine::vec2(3.2f, -0.8f);
        quad2[2] = GL_Engine::vec2(3.0f, -1.0f);
        quad2[3] = GL_Engine::vec2(3.2f, -1.0f);
    }

};