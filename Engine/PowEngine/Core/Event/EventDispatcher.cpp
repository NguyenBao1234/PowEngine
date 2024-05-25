#include"EventDispatcher.h"

namespace PowEngine
{
	EventDispatcher::EventDispatcher()
	{

	}
	EventDispatcher::~EventDispatcher()
	{
		//tham chieu tang perf thay vi tao ban sao auto
		for (auto& pair : mEventActionMap)
		{
			for (auto eventAction : pair.second)
			{
				POW_FREE_MEMORY(eventAction);
			}
			pair.second.clear();
		}
		mEventActionMap.clear();
	}
}