#pragma once
#include "GLFW/glfw3.h"

struct Event
{
	int key{ 0 };
	int action{ 0 };
} event;

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	event.key = key;
	event.action = action;
}

