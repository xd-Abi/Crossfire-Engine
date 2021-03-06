#pragma once

namespace Crossfire
{

	class Shader
	{
	
	public:
		virtual ~Shader() = default;
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		// TODO: Read shaders from File
		//static Ref<Shader> CreateFromFile(const std::string& filePath);
		static Ref<Shader> Create(const std::string& vertexShader, const std::string& fragmentShader);
	};

}