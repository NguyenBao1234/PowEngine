//Copyright POW Game std
#pragma once
#include "Layer.h"

namespace POW
{
	class POW_API LayerStack
	{
	private:
		std::vector<Layer*> StackOfLayers;
		unsigned int indexLayer = 0;
	public:
		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		//Viet tat va cho Support Range-based:
		auto begin() { return StackOfLayers.begin(); }
		auto end() { return StackOfLayers.end(); }
		std::vector<Layer*>::reverse_iterator rbegin() { return StackOfLayers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return StackOfLayers.rend(); }
	};
}

