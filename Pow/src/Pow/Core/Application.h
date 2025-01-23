//Copyright POW Game std
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


