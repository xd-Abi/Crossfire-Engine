#pragma once

#include "Crossfire/Renderer/Shader.h"
#include "glad/glad.h"

namespace Crossfire
{
	class OpenGLShader : public Shader
	{

	public:
	
		OpenGLShader(const std::string& vertexShader, const std::string& fragmentShader);
		~OpenGLShader() override;

		void Bind() override;
		void Unbind() override;

	private:

		void Compile(const std::unordered_map<GLenum, std::string>& shaderSource);

	private:

		uint32_t m_ID;
		GLint m_Shaders[];
	};

}