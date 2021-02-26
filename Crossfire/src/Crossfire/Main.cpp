#include "cfpch.h"

#include "Core/Application.h"


int main(int argc, char** argv)
{
	Crossfire::Log::Initialize();

	CF_CORE_INFO("Welcome!");
	CF_INFO("TEST");

	Crossfire::Application* app = new Crossfire::Application();
	app->Run();
	delete app;
}