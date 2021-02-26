#include <Crossfire.h>

class EditorApp : public Crossfire::Application
{

public:

	EditorApp()
	{
		CF_INFO("TEST");
	}

	~EditorApp()
	{

	}
};

Crossfire::Application* Crossfire::CreateApplication()
{
	return new EditorApp();
}
