#include <Crossfire.h>
#include <Crossfire/Core/EntryPoint.h>


	class Application : public Crossfire::Application
	{

	public:
		Application()
		{

		}

		~Application()
		{

		}
	};

	Crossfire::Application* Crossfire::CreateApplication()
	{
		return new Application();
	}
