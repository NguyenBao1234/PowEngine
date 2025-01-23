//Copyright POW Game std
#pragma once

#include"../Events/Event.h"
#include<sstream>

namespace POW
{
	//_______WINDOW_RESIZE_EVENT__________
	class WindowResizeEvent : public Event
	{
	private:
		unsigned int Width, Height;
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : Width(width), Height(height) {}

		unsigned int GetWidth() const { return Width; }
		unsigned int GetHeight() const { return Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << Width << ", " << Height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	//______WINDOW_CLOSE_EVENT___________
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	//_______APP_TICK_EVENT____________
	class AppTickEvent : public Event
	{
	public:
		AppTickEvent() = default;
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	//_____APP_UPDATE_EVENT____________
	class AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	//_____APP_RENDER_EVENT____________
	class AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}