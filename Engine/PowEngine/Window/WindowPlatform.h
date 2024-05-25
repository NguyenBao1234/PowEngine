#pragma once
#include"Window.h"

namespace PowEngine
{
	class WindowPlatform
	{
	public:
		static NativeWindow* Create(EWindowPlatformSpec spec);
	private:
		WindowPlatform() = default;
		~WindowPlatform() = default;
		WindowPlatform(WindowPlatform&) = default;
	};
}