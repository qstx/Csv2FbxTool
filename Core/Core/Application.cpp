#include "pch.h"
#include "Application.h"

Application* Application::instance = nullptr;

Application::Application(int argc, char** argv)
{
	assert(instance == nullptr);
	instance = this;
	isLaunched = true;
	isRunning = true;
	window = Window::Create("Application", 1280, 720);
}

void Application::Run()
{
	while (isRunning)
	{
		window->OnUpdate();
	}
	window->OnClose();
}
