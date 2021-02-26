#include "cfpch.h"
#include "OpenGLWindow.h"
#include "Crossfire/Core/Assert.h"

namespace Crossfire
{

	static uint8_t s_GLFWWindowCount = 0;

	static void GLFWErrorCallback(int error, const char* description)
	{
		CF_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	OpenGLWindow::OpenGLWindow(const WindowProps& props)
	{
		if (s_GLFWWindowCount == 0)
		{
			int succes = glfwInit();
			CF_CORE_ASSERT(succes, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		Init(props);
	}

	OpenGLWindow::~OpenGLWindow()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void OpenGLWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		CF_CORE_INFO("Creating Window {0}({1},{2})", props.Title, props.Width, props.Height);

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(m_Window, (vidmode->width - props.Width) / 2, (vidmode->height - props.Height) / 2);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void OpenGLWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void OpenGLWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool OpenGLWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}