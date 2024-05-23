#pragma once

namespace PowEngine 
{
	struct POW_API ApplicationConfiguration
	{
		int Width, Height;
		const char* Title;
	};
	class POW_API Application
	{
	public:
		virtual ~Application() = default;
		virtual bool Init() { return true; };
		void Run();
		virtual void Shutdown() {};
	protected:
		Application() = default;
		Application(const ApplicationConfiguration&);
	private:
		ApplicationConfiguration mConfig;
	};
	extern Application* CreateApplication();
}