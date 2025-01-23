//Copyright POW Game std
#pragma once
#include"Event.h"
#include"../Core/MouseCode.h"
#include <sstream>
namespace POW
{
	//____MOUSE MOVED EVENT____________________________________________________________________
	class MouseMovedEvent : public Event
	{
	private:
		float MouseX, MouseY;
	public:
		MouseMovedEvent(const float X, const float Y) : MouseX(X), MouseY(Y) {}
		float GetX() { return MouseX; }
		float GetY() { return MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Move Event: X = " << MouseX << ", Y = " << MouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};
	//____MOUSE SCROLLED EVENT______________________________________________________________________
	class MouseScrolledEvent : public Event
	{
	private:
		float OffsetX, OffsetY;
	public:
		MouseScrolledEvent(const float offsetX, const float offsetY):OffsetX(offsetX),OffsetY(offsetY){}

		float GetOffsetX() const { return OffsetX; }
		float GetOffsetY() const { return OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Scrolled Event: Offset X = " << OffsetX << ", Offset Y = " << OffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	//____MOUSE BUTTON EVENT MASTER______________________________________________
	class MouseButtonEvent : public Event
	{
	protected:
		MouseButtonEvent(const MouseCode button) : ButtonCode(button) {}
		MouseCode ButtonCode;
	public:
		//Get Keycode of Mouse
		MouseCode GetMouseButton() const { return ButtonCode; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
	};
	//____MOUSE BUTTON PRESSED EVENT_____________________________________________________
	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const MouseCode button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << ButtonCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
	//____MOUSE BUTTON RELEASED EVENT____________________________________________
	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const MouseCode button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << ButtonCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
