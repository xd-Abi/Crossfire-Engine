#pragma once

namespace Crossfire
{

	class Mesh
	{
	
	public:

		virtual ~Mesh() = default;

		virtual void Draw() = 0;
		virtual void SetVertices(Vec<float> vetices, uint32_t dimension) = 0;
		virtual void SetIndices(Vec<uint32_t> indices) = 0;

		static Ref<Mesh> Create();
	};


}
