//(C) POW Game std 2025
#pragma once
#include"Core.h"


namespace POW
{
	class POW_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}


