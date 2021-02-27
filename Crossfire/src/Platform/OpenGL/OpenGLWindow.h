#pragma once

#include "Crossfire/Core/Window.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Crossfire 
{

	class OpenGLWindow : public Window
	{
	public:

		OpenGLWindow(const WindowProps& props);
		virtual ~OpenGLWindow();

		void OnUpdate() override;
		void OnDraw() override;

		unsigned int GetWidth() const override { return m_Data.Width; }
		unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		void* GetNativeWindow() const override{ return m_Window; }

	private:

		virtual void Init(const WindowProps& props);
	
	private:

		GLFWwindow* m_Window;
		
	struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}


