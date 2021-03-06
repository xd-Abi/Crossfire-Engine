#include <Crossfire.h>
#include <Crossfire/Core/EntryPoint.h>


	class EngineApplication : public Crossfire::Application
	{

	public:
		EngineApplication()
		{

		}

		~EngineApplication()
		{

		}
	};

	Crossfire::Application* Crossfire::CreateApplication()
	{
		return new EngineApplication();
	}
