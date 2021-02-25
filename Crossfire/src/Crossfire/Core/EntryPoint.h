#pragma once

#include "Crossfire/Core/Base.h"

#ifdef CF_PLATFORM_WINDOWS

extern Crossfire::Application* Crossfire::CreateApplication();

int main(int argc, char** argv)
{

	Crossfire::Log::Initialize();

	CF_CORE_INFO("Starting Crossfire Engine");

	auto app = Crossfire::CreateApplication();
	app->Run();
	delete app;
}

#endif