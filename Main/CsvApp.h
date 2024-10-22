#pragma once
#include "Core/EntryPoint.h"
#include "Core/Application.h"

class CsvApp :public Application
{
public:
	CsvApp(int argc, char** argv);
};

Application* CreateApplication(int argc, char** argv)
{
	return new CsvApp(argc, argv);
}