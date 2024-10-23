#pragma once
#include "Core/Application.h"
#include "Core/Logger.h"

int main(int argc, char** argv)
{
	Logger::Init();

	Application* app = CreateApplication(argc, argv);

	app->Run();

	delete app;
}