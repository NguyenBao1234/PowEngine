#include"PowEngine/Core/Entry.h"
#include"Core/Logger/Logger.h"

class Game : public PowEngine::Application
{
public:
	Game(const PowEngine::ApplicationConfiguration& config) : PowEngine::Application(config) 
	{
	};
	virtual bool Init()override 
	{
		LOG_INFO("Client Init");
		return true;
	};
	virtual void Shutdown() override
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
	return new Game(appConfig);
}