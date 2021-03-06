#include "Core/cfpch.h"
#include "OpenGLShader.h"

#include "glad/glad.h"

namespace Crossfire
{

	OpenGLShader::OpenGLShader(const std::string& vertexShader, const std::string& fragmentShader)
	{
		m_ID = glCreateProgram();
		
		std::unordered_map<GLenum, std::string> shaderSources;
		shaderSources[GL_VERTEX_SHADER] = vertexShader;
		shaderSources[GL_FRAGMENT_SHADER] = fragmentShader;

		Compile(shaderSources);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_ID);
	}

	void OpenGLShader::Compile(const std::unordered_map<GLenum, std::string>& shaderSource)
	{
		
		std::array<GLenum, 2> glShaderIDs;

		int glShaderIndex = 0;

		for (auto& kv : shaderSource)
		{
			GLenum type = kv.first;
			const std::string& source = kv.second;

			GLuint shader = glCreateShader(type);
			const GLchar* sourceCStr = source.c_str();
			glShaderSource(shader, 1, &sourceCStr, 0);
			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(shader);

				CF_CORE_ERROR("{0}", infoLog.data());
				CF_CORE_ASSERT(false, "Shader compilation failed!");
			}

			glAttachShader(m_ID, shader);
		}

	
		glLinkProgram(m_ID);

		GLint isLinked = 0;
		glGetProgramiv(m_ID, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_ID, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(m_ID, maxLength, &maxLength, &infoLog[0]);
			glDeleteProgram(m_ID);

			for (auto id : glShaderIDs)
				glDeleteShader(id);

			CF_CORE_ERROR("{0}", infoLog.data());
			CF_CORE_ASSERT(false, "Shader link failure!");
			return;
		}

		for (auto shaderID : glShaderIDs)
		{
			glDetachShader(m_ID, shaderID);
			glDeleteShader(shaderID);
		}
	}

	void OpenGLShader::Bind()
	{
		glUseProgram(m_ID);
	}

	void OpenGLShader::Unbind()
	{
		glUseProgram(0);
	}
}