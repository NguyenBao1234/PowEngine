//POW Game std 2025 (C)
#pragma once

#ifdef POW_PLATFORM_WINDOWS

extern POW::Application* POW::CreateApplication();

int main(int argc, char** argv)
{
	auto ChildApp = POW::CreateApplication();
	ChildApp->Run();
	delete ChildApp;
}

#endif // POW_PLATFORM_WINDOWS

