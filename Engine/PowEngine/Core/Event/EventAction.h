#pragma once
#include"EventContext.h"

namespace PowEngine
{
	//truyen CallBack thi nen execute callback nhu the nao khi Event xay ra
	template<typename T> using EventCallback = std::function<bool(const T&)>;

	class POW_API IEventAction
	{
	public:
		virtual ~IEventAction() = default;
		virtual bool Execute(const EventContext*) = 0;
	};


	template<typename T>
	class POW_API EventAction : public IEventAction
	{
	private:
		EventCallback<T> mCallback;
	public:
		EventAction(const EventCallback<T>& callback) : mCallback(callback) {}
		virtual bool Execute(const EventContext* eventContext) override
		{
			POW_STATIC_ASSERT(std::is_base_of<EventContext, T>::value && "Invalid Event Context");
			return mCallback(*(T*)eventContext);
		};
	};
}