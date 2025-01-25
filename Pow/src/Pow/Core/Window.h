//Copyright POW Game std
#pragma once
#include"powpch.h"
#include"Pow/Core/Core.h"
#include "Pow/Events/Event.h"


namespace POW
{
	struct WindowProperties
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProperties(const std::string& title = "Pow Engine",uint32_t width = 1280,uint32_t height = 720) : Title(title), Width(width), Height(height)
		{
		}
	};
	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};
}

