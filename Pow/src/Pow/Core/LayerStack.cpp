#include "powpch.h"
#include "LayerStack.h"

namespace POW
{
	LayerStack::~LayerStack()
	{
		for (Layer* ElementLayer : StackOfLayers)
		{
			ElementLayer->OnDetach();
			delete ElementLayer; //destruct & giai phong memory
		}
	}
//________________________________________________________________________________
	void LayerStack::PushLayer(Layer* layer)
	{
		StackOfLayers.emplace(begin() + indexLayer, layer);
		indexLayer++;
	}
//________________________________________________________________________________
	void LayerStack::PushOverlay(Layer* overlay)
	{
		StackOfLayers.emplace_back(overlay);
	}
//________________________________________________________________________________
	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(begin(), begin() + indexLayer, layer);
		if (it != end())
		{
			layer->OnDetach();
			StackOfLayers.erase(it);
			indexLayer--;
		}
	}
//________________________________________________________________________________
	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(begin() + indexLayer, end(), overlay);
		if (it != end())
		{
			overlay->OnDetach();
			StackOfLayers.erase(it);
			indexLayer--;
		}
	}
}