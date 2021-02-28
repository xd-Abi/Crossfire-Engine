#include "Core/cfpch.h"
#include "OpenGLMesh.h"

#include <GL/glew.h>

namespace Crossfire
{

	OpenGLMesh::OpenGLMesh()
	{
		glCreateVertexArrays(1, &m_Vao);
		glCreateBuffers(1, &m_Vbo);
		glCreateBuffers(1, &m_Ibo);

		m_DrawCount = 0;
	}

	OpenGLMesh::~OpenGLMesh()
	{
		glDeleteBuffers(1, &m_Vbo);
		glDeleteBuffers(1, &m_Ibo);
		glDeleteVertexArrays(1, &m_Vao);
	}

	void OpenGLMesh::Draw()
	{
		glBindVertexArray(m_Vao);
		glDrawElements(GL_TRIANGLES, m_DrawCount, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

	void OpenGLMesh::SetVertices(Vec<float> vertices, uint32_t dimension)
	{
		glBindVertexArray(m_Vao);


		glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, dimension, GL_FLOAT, GL_FALSE, 0, 0);
	}

	void OpenGLMesh::SetIndices(Vec<uint32_t> indices)
	{

		m_DrawCount = indices.size() * sizeof(indices[0]);

		glBindVertexArray(m_Vao);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_DrawCount, &indices[0], GL_STATIC_DRAW);
	}
}
