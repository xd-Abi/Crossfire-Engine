#pragma once

#include "Renderer/Mesh.h"

namespace Crossfire
{

	class OpenGLMesh : public Mesh
	{

	public:

		OpenGLMesh();
		~OpenGLMesh() override;

		void Draw() override;
		void SetVertices(Vec<float> vetices, uint32_t demension) override;
		void SetIndices(Vec<uint32_t> indices) override;

	private:

		uint32_t m_Vao;
		uint32_t m_Vbo;
		uint32_t m_Ibo;
		uint32_t m_DrawCount;
	};

}