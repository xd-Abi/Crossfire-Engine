#pragma once

#include "Renderer/RenderAPI.h"

namespace Crossfire
{

	class OpenGLRenderAPI : public RenderAPI
	{

	public:

		virtual void Init() override;
		virtual void SetViewport(uint32_t width, uint32_t height) override;

		virtual void SetClearColor(float r,float g, float b, float a) override;
		virtual void Clear() override;
	};
}

