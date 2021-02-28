#include "Core/cfpch.h"
#include "Core/Base.h"
#include "Core/Application.h"

int main(int argc, char** argv)
{
	Crossfire::Log::Initialize();

	auto app = new Crossfire::Application();
	app->Run();
	delete app;
}