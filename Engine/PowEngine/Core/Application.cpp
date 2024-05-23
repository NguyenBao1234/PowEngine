#include "Application.h"
#include"Core/Logger/Logger.h"


namespace PowEngine {
	void Application::Run()
	{
		CORE_LOG_INFO("{0} is Running: {1},{2}", mConfig.Title, mConfig.Width, mConfig.Height);
	}
	Application::Application(const ApplicationConfiguration& config) : mConfig(config)
	{
		Logger::Init();
	}
}