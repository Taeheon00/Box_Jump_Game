#pragma once
#pragma comment(lib, "OpenGL32")
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "MMath.hpp"
#include "Player.hpp"
#include "wall.hpp"
#include "SceenManager.hpp"

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace std;

static GLuint texName;

namespace GameManner
{
	Player* p = new Player(GL_Engine::vec3(1.0f, 0.0f, 0.0f));
	Wall* w = new Wall(GL_Engine::vec3(0.0f, 0.0f, 1.0f));
	Wall2* w2 = new Wall2(GL_Engine::vec3(0.0f, 1.0f, 1.0f));
	Wall3* w3 = new Wall3(GL_Engine::vec3(1.0f, 0.0f, 1.0f));
	GameOver* g = new GameOver(GL_Engine::vec3(1.0f, 1.0f, 0.0f));

	typedef struct tagBITMAPHEADER {
		BITMAPFILEHEADER bf;
		BITMAPINFOHEADER bi;
		RGBQUAD hRGB[256];
	}BITMAPHEADER;

	BYTE* LoadBitmapFile(BITMAPHEADER* bitmapHeader, int* imgSize, const char* filename)
	{
		FILE* fp = fopen(filename, "rb");
		if (fp == NULL)
		{
			printf("파일로딩에 실패했습니다.\n");
			return NULL;
		}
		else
		{
			fread(&bitmapHeader->bf, sizeof(BITMAPFILEHEADER), 1, fp);
			fread(&bitmapHeader->bi, sizeof(BITMAPINFOHEADER), 1, fp);
			fread(&bitmapHeader->hRGB, sizeof(RGBQUAD), 256, fp);

			int imgSizeTemp = bitmapHeader->bi.biWidth * bitmapHeader->bi.biHeight;
			*imgSize = imgSizeTemp;

			BYTE* image = (BYTE*)malloc(sizeof(BYTE) * imgSizeTemp);
			fread(image, sizeof(BYTE), imgSizeTemp, fp);
			fclose(fp);


			return image;
		}
	}

	class GameLoop
	{
	private:
		bool _isGameRunning;

	public:
		GameLoop() { }
		~GameLoop() {}
		bool w2pass = false;

		static void error_callback(int error, const char* description)
		{
			fputs(description, stderr);
		}
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GL_TRUE);
		}

		void Run()
		{
			GLFWwindow* window;
			glfwSetErrorCallback(error_callback);
			if (!glfwInit())
			{
				exit(EXIT_FAILURE);
			}
			window = glfwCreateWindow(700, 600, "Simple example", NULL, NULL);
			if (!window)
			{
				glfwTerminate();
				exit(EXIT_FAILURE);
			}
			glfwMakeContextCurrent(window);
			glfwSetKeyCallback(window, key_callback);

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			Initialize();

			while (!glfwWindowShouldClose(window))
			{

				Input(window);
				Update(window);
				Render(window);
			}
			Release(window);
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수확인
		}

	private:

		void Initialize()
		{
			glClearColor(0.0, 0.0, 0.0, 0.0);

			BITMAPHEADER originalHeader;
			int imgSize;
			BYTE* image = LoadBitmapFile(&originalHeader, &imgSize, "gameover.bmp");
			if (image == NULL) return;

			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

			glGenTextures(1, &texName);
			glBindTexture(GL_TEXTURE_2D, texName);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
				GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
				GL_NEAREST);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 512, 512, 0, GL_RED, 1, image);
		}
		void Release(GLFWwindow* window)
		{
			glfwDestroyWindow(window);
			glfwTerminate();
			exit(EXIT_SUCCESS);
		}

		void Input(GLFWwindow* window)
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				p->MoveUp();
			}
			else
			{
				p->MoveDown();
			}

			if (g->gameovercheck)
			{
				if (GetAsyncKeyState(0x52) & 0x8000 || GetAsyncKeyState(0x52) & 0x8001)
				{
					g->gameovercheck = false;
					p->Game_Restart();
					w->Game_Restart();
					w2->Game_Restart();
					w3->Game_Restart();
					w2pass = false;
				}
			}
		}
		void Update(GLFWwindow* window)
		{
			w->wall_move();
			w2->wall_move();
			w3->wall_move();

			if (w2->quad[2].x <= -1)
			{
				w2pass = true;
			}

			if (w->quad[2].x <= -1 && w2->quad[2].x <= -1)
			{
				w->Game_Restart();
			}

			if (w2->quad[2].x <= -1 && w3->quad[2].x <= -1)
			{
				w2->Game_Restart();
			}

			if (w3->quad[2].x <= -1 && w2pass)
			{
				w3->Game_Restart();
				w2pass = false;
			}

			if (g->gameovercheck)
			{
				p->gameover = true;
				w->gameover = true;
				w2->gameover = true;
				w3->gameover = true;
			}
			else
			{
				p->gameover = false;
				w->gameover = false;
				w2->gameover = false;
				w3->gameover = false;
			}

			if (p->quad[2].y <= -1.0f)
			{
				g->gameovercheck = true;
			}

			for (int i = 0; i < 4; i++)
			{
				if (p->quad[2].x < w->quad[i].x && w->quad[i].x < p->quad[1].x)
				{
					if (p->quad[2].y < w->quad[i].y && w->quad[i].y < p->quad[1].y)
					{
						g->gameovercheck = true;
					}
				}
			}
			for (int i = 0; i < 4; i++)
			{
				if (p->quad[2].x < w->quad2[i].x && w->quad2[i].x < p->quad[1].x)
				{
					if (p->quad[2].y < w->quad2[i].y && w->quad2[i].y < p->quad[1].y)
					{
						g->gameovercheck = true;
					}
				}
			}

			for (int i = 0; i < 4; i++)
			{
				if (p->quad[2].x < w2->quad[i].x && w2->quad[i].x < p->quad[1].x)
				{
					if (p->quad[2].y < w2->quad[i].y && w2->quad[i].y < p->quad[1].y)
					{
						g->gameovercheck = true;
					}
				}
			}
			for (int i = 0; i < 4; i++)
			{
				if (p->quad[2].x < w2->quad2[i].x && w2->quad2[i].x < p->quad[1].x)
				{
					if (p->quad[2].y < w2->quad2[i].y && w2->quad2[i].y < p->quad[1].y)
					{
						g->gameovercheck = true;
					}
				}
			}

			for (int i = 0; i < 4; i++)
			{
				if (p->quad[2].x < w3->quad[i].x && w3->quad[i].x < p->quad[1].x)
				{
					if (p->quad[2].y < w3->quad[i].y && w3->quad[i].y < p->quad[1].y)
					{
						g->gameovercheck = true;
					}
				}
			}
			for (int i = 0; i < 4; i++)
			{
				if (p->quad[2].x < w3->quad2[i].x && w3->quad2[i].x < p->quad[1].x)
				{
					if (p->quad[2].y < w3->quad2[i].y && w3->quad2[i].y < p->quad[1].y)
					{
						g->gameovercheck = true;
					}
				}
			}
		}
		void Render(GLFWwindow* window)
		{
			float ratio;
			int width, height;
			glfwGetFramebufferSize(window, &width, &height);
			ratio = width / (float)height;

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
			glBindTexture(GL_TEXTURE_2D, texName);

			p->Render();
			w->Render();
			w2->Render();
			w3->Render();
			g->Render();

			glfwSwapBuffers(window);

			glfwPollEvents();

		}
	};
}