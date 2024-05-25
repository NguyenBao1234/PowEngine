#pragma once
#include "EventAction.h"

namespace PowEngine
{
	using EventActionList = std::vector<IEventAction*>;

	class POW_API EventDispatcher
	{
		friend class Application;

	public:
		~EventDispatcher();

		template <typename T>
		void AddEventListener(const EventCallback<T>& callback)
		{
			POW_STATIC_ASSERT(std::is_base_of < EventContext, T>::value&&"add invalid Event context");

			const char* eventType = typeid(T).name();

			IEventAction* eventAction = new EventAction<T>(callback);

			mEventActionMap[eventType].emplace_back(eventAction);
		};

		template <typename T>
		void DispatchEventListener( T& eventContext)
		{
			POW_STATIC_ASSERT(std::is_base_of<EventContext, T>::value && "Dispatcher invalid event context");
			const char* eventType = typeid(T).name();
			POW_ASSERT(mEventActionMap.find(eventType) != mEventActionMap.end() && "Unknown event type");
			for (auto eventAction : mEventActionMap.at(eventType))
			{
				if (eventAction->Execute(&eventContext))
				{
					break;
				}
			}
		}
	private:
		EventDispatcher();
	private:
		std::unordered_map<const char*, EventActionList> mEventActionMap;
	};
}