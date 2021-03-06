#include "Core/cfpch.h"
#include "Window.h"

#include "Platform/OpenGL/OpenGLWindow.h"

namespace Crossfire
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
		return CreateScope<OpenGLWindow>(props);
	}
}