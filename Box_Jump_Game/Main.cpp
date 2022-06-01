#define _CRT_SECURE_NO_WARNINGS
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "GameManager.hpp"

int main(void)
{
	GameManner::GameLoop GLoop;
	GLoop.Run();
}