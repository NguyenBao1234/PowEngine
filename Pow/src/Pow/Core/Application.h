//Copyright POW Game std
#pragma once
#include"Core.h"
#include"Pow/Events/Event.h"
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
	};

	Application* CreateApplication();
}


