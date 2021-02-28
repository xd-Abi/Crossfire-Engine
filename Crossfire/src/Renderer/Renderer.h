#pragma once

#include "RenderAPI.h"
#include "Core/Window.h"

namespace Crossfire
{

	class Renderer
	{

	public:

		static void Init();
		static void OnRender();
		static void OnWindowResize(uint32_t width, uint32_t height);
		static void SetClearColor(float r, float g, float b, float a);

	private:

		static Scope<RenderAPI> s_RenderAPI;
		static Window& s_Window;
	};
}

