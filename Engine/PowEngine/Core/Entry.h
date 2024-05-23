#include"Application.h"

int main()
{
	PowEngine::Application* application = PowEngine::CreateApplication();
	if (application->Init())
	{
		application->Run();
	}
	application->Shutdown();
	POW_FREE_MEMORY(application);
	return 0;
}