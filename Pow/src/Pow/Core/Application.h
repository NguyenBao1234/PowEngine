//Copyright POW Game std
#pragma once
#include"Core.h"
#include"Pow/Events/Event.h"
#include"Pow/Events/ApplicationEvent.h"
#include"Pow/Core/Window.h"

namespace POW
{
	class POW_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;//bcz just this class use this
		bool bRunning = true;
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	};

	Application* CreateApplication();
}


