#pragma once

#include "Base.h"

#ifdef CF_PLATFORM_WINDOWS

extern Crossfire::Application* Crossfire::CreateApplication();

int main(int argc, char** argv)
{
	//Crossfire::Log::Initialize();

	auto app = Crossfire::CreateApplication();
	app->Run();
	delete app;
}

#endif
