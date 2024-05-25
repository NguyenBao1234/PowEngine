#pragma once
#include"pch.h"
#include"Window/Window.h"
#include"Event/EventDispatcher.h"

namespace PowEngine 
{
	struct POW_API ApplicationConfiguration
	{
		int Width, Height;
		const char* Title;
		EWindowPlatformSpec WindowSpec;
	};
	class POW_API Application
	{
	public:
		virtual ~Application() = default;
		bool Init();
		virtual void OnInitClient()=0;
		void Run();
		void Shutdown();
		virtual void OnShutdownClient() = 0;
	protected:
		Application() = default;
		Application(const ApplicationConfiguration&);
	private:
		ApplicationConfiguration mConfig;
		Unique<NativeWindow> mNativeWindow;
		EventDispatcher mEventDispatcher;
	private:
		bool OnWindowResizedEvent(const WindowResizedEvent&);
	};
	extern Application* CreateApplication();
}