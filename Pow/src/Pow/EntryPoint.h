//POW Game std 2025 (C)
#pragma once

#ifdef POW_PLATFORM_WINDOWS

extern POW::Application* POW::CreateApplication();

int main(int argc, char** argv)
{
	POW::Log::Init();
	PE_CORE_CRIT("POW ENGINE");
	PE_INFO("Client Hello");
	auto ChildApp = POW::CreateApplication();
	ChildApp->Run();
	delete ChildApp;
}

#endif // POW_PLATFORM_WINDOWS

