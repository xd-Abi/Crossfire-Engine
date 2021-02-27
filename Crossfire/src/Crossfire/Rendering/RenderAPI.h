#pragma once

namespace Crossfire
{
	class RenderAPI
	{

	public:

		enum API
		{
			OpenGL = 1,
			DirectX = 2
		};

	public:

		virtual ~RenderAPI() = default;
		
		virtual void Init() = 0;
		virtual void Clear() = 0;
		virtual void SetClearColor(float r, float g, float b, float a) = 0;
		virtual void SetViewport(uint32_t width, uint32_t height) = 0;

		static Scope<RenderAPI> Create(API api);

	private:

		static API s_API;
	};
}