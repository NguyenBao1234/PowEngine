#include "WindowPlatform.h"

#include "pch.h"

namespace PowEngine 
{

	NativeWindow* WindowPlatform::Create(EWindowPlatformSpec spec)
	{
		NativeWindow* window = nullptr;
		switch (spec)
		{
		case EWindowPlatformSpec::GLFW: window = new GLFWPlatformWindow();
		case EWindowPlatformSpec::SDL: POW_ASSERT("SDL Window not supported");
		case EWindowPlatformSpec::None: POW_ASSERT("Unknown Window detected");
		default: POW_ASSERT("Unknown Window detected");
		}
		return dynamic_cast<NativeWindow*>(window);
	}
}
