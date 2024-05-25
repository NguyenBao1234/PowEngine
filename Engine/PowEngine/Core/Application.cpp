#include "Application.h"
#include"Core/Logger/Logger.h"
//#define GLAD_GL_IMPLEMENTATION
#include"glad/gl.h"
#include"GLFW/glfw3.h"
#include"Window/WindowPlatform.h"

namespace PowEngine 
{
	Application::Application(const ApplicationConfiguration& config) : mConfig(config), mEventDispatcher()
	{
		mNativeWindow.reset(WindowPlatform::Create(config.WindowSpec));
	}

	bool Application::Init()
	{
		//set up cu phap cho Log ra man hinh
		Logger::Init();
		if (!mNativeWindow->Init(mConfig, &mEventDispatcher)) 
		{
			return false;
		}
		mEventDispatcher.AddEventListener<WindowResizedEvent>(BIND_EVENT_FUNCTION(OnWindowResizedEvent));
		return true;
	}

	void Application::Run()
	{
		CORE_LOG_INFO("{0} is Running: {1},{2}", mConfig.Title, mConfig.Width, mConfig.Height);
		OnInitClient();

		while (!mNativeWindow->ShouldClose())
		{
			mNativeWindow->SwapBuffer();

			mNativeWindow->PollEvent();
		}

		OnShutdownClient();
	}

	void Application::Shutdown()
	{
		mNativeWindow->Shutdown();
	}
	
	bool Application::OnWindowResizedEvent(const WindowResizedEvent& eventContext)
	{
		CORE_LOG_TRACE("(Width: {0}, Height: {1})", eventContext.GetWidth(), eventContext.GetHeight());
		return false;
	}
}