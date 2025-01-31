//Copyright POW Game std
#pragma once
#include "Pow/Core/Core.h"
#include "Pow/Events/Event.h"

namespace POW
{
	class POW_API Layer
	{
	public:
		Layer(const std::string& name = "Layer") :sDebugName(name) {};
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return sDebugName; }
	protected:
		std::string sDebugName;
	};
}

