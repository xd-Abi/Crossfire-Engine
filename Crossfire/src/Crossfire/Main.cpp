#include "cfpch.h"
#include "Core/Base.h"
#include "Core/Application.h"
#include "glm/glm.hpp"

int main(int argc, char** argv)
{
	Crossfire::Log::Initialize();

	glm::vec4 test = glm::vec4(1, 23, 42, 42);
	CF_CORE_INFO("Testing glm: {0}, {1}, {2}, {3}", test.x, test.y, test.z, test.z);

	auto app = new Crossfire::Application();
	app->Run();
	delete app;
}