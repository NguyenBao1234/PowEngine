//Copyright POW Game std
#include"Pow/Core/Window.h"
#include<GLFW/glfw3.h>
#pragma once
namespace POW
{
	class WindowsWindow : public Window
	{
	private:
		GLFWwindow* m_Window;//m =member
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool bVSync;

			EventCallbackFn EventCallback;
		};
		WindowData wData;
	public:
		WindowsWindow(const WindowProperties& props);
		~WindowsWindow();
		// Inherited via Window
		virtual void OnUpdate() override;
		virtual uint32_t GetWidth() const override { return wData.Width; }
		virtual uint32_t GetHeight() const override { return wData.Height; }
		virtual void SetEventCallback(const EventCallbackFn& callback) override { wData.EventCallback = callback; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override { return wData.bVSync; }
		virtual void* GetNativeWindow() const override { return m_Window; }


	private:
		virtual void Init(const WindowProperties& props);
		virtual void ShutDown();

	};
}

