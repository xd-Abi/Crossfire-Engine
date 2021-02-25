#include <Crossfire.h>

class Sandbox : public Crossfire::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{

	}
};

Crossfire::Application* Crossfire::CreateApplication()
{
	return new Sandbox();
}