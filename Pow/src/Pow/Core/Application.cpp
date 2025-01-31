//Copyright POW Game std
#include "powpch.h"
#include "Application.h"
#include "Log.h"
#include <GLFW/glfw3.h>

namespace POW
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (bRunning)
		{
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer* layer : mLayerStackObj) layer->OnUpdate();
			m_Window->OnUpdate();
		};
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		PE_CORE_INFO(" On Begin Event{0}",e.ToString());
		//Xu ly event tu lop tren cung tro xuong ( e.g., HUD > UI > GameEnvi )
		for (auto it = mLayerStackObj.rbegin(); it != mLayerStackObj.rend(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.bHandled)break;
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		PE_CORE_INFO("Application Stop running")
		bRunning = false;
		return true;
	}

}
