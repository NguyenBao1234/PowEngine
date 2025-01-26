// //Copyright POW Game std
#pragma once
#include"../Core/KeyCode.h"
#include"Event.h"
#include<sstream>
namespace POW
{
	//____KEY EVENT MASTER_____________________________________________
	class KeyEvent : public Event
	{
	protected:
		KeyCode ButtonCode;
		KeyEvent(KeyCode keyCode) : ButtonCode(keyCode) {}
	public:
		KeyCode GetKeyCode() { return ButtonCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard|EventCategoryInput)
	};

	//____KEY PRESSED EVENT_____________________________________________
	class KeyPressedEvent : public KeyEvent
	{
	private:
		bool bRepeating;
	public:
		KeyPressedEvent(const KeyCode keyCode, bool bRepeat) : KeyEvent(keyCode), bRepeating(bRepeat){}

		bool IsRepeating() const { return bRepeating; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Pressed Event:" << ButtonCode << " (repeat = " << bRepeating << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};
	//____KEY RELEASED EVENT____________________________________________
	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyCode keyCode) : KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Released Event:" << ButtonCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};
	//____KEY TYPED EVENT____________________________________________
	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const KeyCode keyCode) : KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Typed Event:" << ButtonCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyTyped)
	};
}