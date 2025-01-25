//Copyright POW Game std
#include "powpch.h"
#include "Application.h"
#include"Pow/Events/ApplicationEvent.h"
#include "Log.h"
#include <GLFW/glfw3.h>
POW::Application::Application()
{
	m_Window = std::unique_ptr<Window>(Window::Create());
}

POW::Application::~Application()
{
}

void POW::Application::Run()
{
	while (bRunning)
	{
		glClearColor(0, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->OnUpdate();
	};
}
