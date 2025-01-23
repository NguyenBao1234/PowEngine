//Copyright POW Game std
#include "powpch.h"
#include "Application.h"
#include"Pow/Events/ApplicationEvent.h"
#include "Log.h"

POW::Application::Application()
{
}

POW::Application::~Application()
{
}

void POW::Application::Run()
{
	WindowCloseEvent winEvent = WindowCloseEvent();
	PE_INFO(winEvent.ToString());
	while (true);
}
