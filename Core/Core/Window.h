#pragma once
#include <string>
#include <Windows.h>
class Window
{
private:
	WNDCLASSEXW wc;
	HWND hwnd;
public:
	Window(std::string title, int width, int height);
	static Scope<Window> Create(std::string title, int width, int height);
	void OnUpdate();
	void OnClose();
};