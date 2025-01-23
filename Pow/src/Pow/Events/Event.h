//Copyright POW Game std

#pragma once
#include"Pow/Core/Core.h"
#include <functional>
#include <string>

namespace POW
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};
	//Macro for quick define specify envent :
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; } 

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	//__________________________________________________________________________________________
	class Event
	{
	public:
		virtual ~Event() = default;

		bool bHandled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category; // use '&' - AND bitwise
		}
	};
	//__________________________________________________________________________________________
	class EventDispatcher
	{
	private:
		Event& m_Event;//prefix "m" = member

	public:
		EventDispatcher(Event& event) : m_Event(event){}

		// F will be deduced by the compiler
		template<typename T> using EventFn = std::function<bool(T&)>;//Nhan Tham so T, tra ve kieu bool

		template<typename T> bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.bHandled |= func(static_cast<T&> & m_Event); //...= ... | ,,, ;
				return true;
			}
			return false;
		}
	};
	//__________________________________________________________________________________________
	// Ham duoi co the goi bang cu phap nhanh vi du nhu "std::cout << myEvent;" thay vi "operator<<(std::cout, myEvent);"
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}