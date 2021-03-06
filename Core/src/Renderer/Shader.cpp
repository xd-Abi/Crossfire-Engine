#include "Core/cfpch.h"
#include "Shader.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Crossfire
{

	Ref<Shader> Shader::Create(const std::string& vertexShader, const std::string& fragmentShader)
	{
		return CreateRef<OpenGLShader>(vertexShader, fragmentShader);
	}
}