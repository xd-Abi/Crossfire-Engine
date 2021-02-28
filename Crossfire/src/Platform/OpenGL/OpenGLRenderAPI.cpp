#include "Core/cfpch.h"
#include "OpenGLRenderAPI.h"
#include "Core/Assert.h"

#include <glad/glad.h>

namespace Crossfire
{

	void OpenGLMessageCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         CF_CORE_WARN(message); return;
		case GL_DEBUG_SEVERITY_MEDIUM:       CF_CORE_ERROR(message); return;
		case GL_DEBUG_SEVERITY_LOW:          CF_CORE_WARN(message); return;
		case GL_DEBUG_SEVERITY_NOTIFICATION: CF_CORE_TRACE(message); return;
		}

		CF_CORE_ASSERT(false, "Unknown severity level!");
	}

	void OpenGLRenderAPI::Init()
	{
	#ifdef CF_DEBUG
			
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
	#endif

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
	}

	void OpenGLRenderAPI::SetViewport(uint32_t width, uint32_t height)
	{
		glViewport(0, 0, width, height);
	}

	void OpenGLRenderAPI::SetClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

	void OpenGLRenderAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}