//Copyright POW Game std
#pragma once

#ifdef POW_PLATFORM_WINDOWS

extern POW::Application* POW::CreateApplication();

int main(int argc, char** argv)
{
	POW::Log::Init();
	PE_CORE_CRIT("POW ENGINE");
	PE_TRACE("Client Hello");
	auto ChildApp = POW::CreateApplication();
	ChildApp->Run();
	delete ChildApp;
}

#endif // POW_PLATFORM_WINDOWS

