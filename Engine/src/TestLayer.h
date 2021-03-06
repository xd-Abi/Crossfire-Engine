#pragma once

#include <Crossfire.h>

namespace Crossfire
{

	class TestLayer : public Layer
	{

	public:

		TestLayer();
		virtual ~TestLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		void OnRender() override;
		//void OnEvent(Event & e) override;
	};
	
}