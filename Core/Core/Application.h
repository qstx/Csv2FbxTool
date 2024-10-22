#pragma once
#include "Base.h"
#include "Window.h"

class Application
{
private:
	bool isLaunched = false;
	bool isRunning = false;
	static Application* instance;
	Scope<Window> window = nullptr;
public:
	Application(int argc, char** argv);
	virtual void Run();
	void Close() { isRunning = false; }
	inline bool HasLaunched() { return isLaunched; }
	static Application* Instance() { return instance; }
};

extern Application* CreateApplication(int argc, char** argv);
