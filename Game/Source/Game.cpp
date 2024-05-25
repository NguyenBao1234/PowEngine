#include"PowEngine/Core/Entry.h"
#include"Core/Logger/Logger.h"
#include"PowEngine/Window/Window.h"

class Game : public PowEngine::Application
{
public:
	Game(const PowEngine::ApplicationConfiguration& config) : PowEngine::Application(config) 
	{
	};
	virtual void OnInitClient()override 
	{
		LOG_INFO("Client Init");
	};
	virtual void OnShutdownClient() override
	{
		LOG_DEBUG("ShutDown");
	};
};
PowEngine::Application* PowEngine::CreateApplication()
{
	using namespace PowEngine;
	PowEngine::ApplicationConfiguration appConfig;
	appConfig.Width = 800;
	appConfig.Height = 600;
	appConfig.Title = "POW ENGINE alpha";
	appConfig.WindowSpec = PowEngine::EWindowPlatformSpec::GLFW;
	return new Game(appConfig);
}